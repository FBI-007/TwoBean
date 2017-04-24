#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QDebug>
#include "MBTitleBar.h"
#include "const.h"

#ifdef Q_OS_WIN
#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
#endif

#define  IconSize   27, 22

MBTitleBar::MBTitleBar(QWidget *parent)
    : QWidget(parent)
{
    setFixedHeight(30);

    m_pIconLabel      = new QLabel(this);
    m_pTitleLabel     = new QLabel(this);
    m_pMinimizeButton = new QPushButton(this);
    m_pMaximizeButton = new QPushButton(this);
    m_pCloseButton    = new QPushButton(this);
    m_pSearchButton   = new QPushButton(this);

    m_pIconLabel->setFixedSize(20, 20);
    m_pIconLabel->setScaledContents(true);

    //m_pTitleLabel->setForegroundRole(QPalette::HighlightedText);                // 焦点时高亮色
    m_pTitleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);   //-?-

    m_pSearchButton  ->setFixedSize(IconSize);
    m_pMinimizeButton->setFixedSize(IconSize);
    m_pMaximizeButton->setFixedSize(IconSize);
    m_pCloseButton   ->setFixedSize(IconSize);

    m_pSearchButton  ->setIconSize(QSize(IconSize));
    m_pMinimizeButton->setIconSize(QSize(IconSize));
    m_pMaximizeButton->setIconSize(QSize(IconSize));
    m_pCloseButton   ->setIconSize(QSize(IconSize));
    m_pSearchButton  ->setIcon(QIcon(":Icon/icons/title_min.png"));
    m_pMinimizeButton->setIcon(QIcon(":Icon/icons/title_min.png"));
    m_pMaximizeButton->setIcon(QIcon(":Icon/icons/title_max.png"));
    m_pCloseButton   ->setIcon(QIcon(":Icon/icons/title_close.png"));

    m_pTitleLabel    ->setObjectName("whiteLabel");
    m_pSearchButton  ->setObjectName("SearchButton");
    m_pMinimizeButton->setObjectName("minimizeButton");
    m_pMaximizeButton->setObjectName("maximizeButton");
    m_pCloseButton   ->setObjectName("closeButton");

    m_pSearchButton  ->setToolTip(tr("Search"));
    m_pMinimizeButton->setToolTip(tr("Minimize"));
    m_pMaximizeButton->setToolTip(tr("Maximize"));
    m_pCloseButton   ->setToolTip(tr("Close"));

    QPalette pal(palette());
    pal.setColor(QPalette::WindowText, Qt::white);
    pal.setColor(QPalette::Background, Color_Black64);
    setAutoFillBackground(true);
    setPalette(pal);

    QHBoxLayout *pLayout = new QHBoxLayout(this);
    pLayout->addWidget(m_pIconLabel);
    pLayout->addSpacing(10);
    pLayout->addWidget(m_pTitleLabel);
    pLayout->addWidget(m_pSearchButton);
    pLayout->addWidget(m_pMinimizeButton);
    pLayout->addWidget(m_pMaximizeButton);
    pLayout->addWidget(m_pCloseButton);
    pLayout->setSpacing(0);
    pLayout->setContentsMargins(5, 0, 5, 0);
    setLayout(pLayout);

    connect(m_pSearchButton,   SIGNAL(clicked(bool)), this, SIGNAL(searchClicked()));
    connect(m_pMinimizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pMaximizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pCloseButton,    SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

MBTitleBar::~MBTitleBar(){}

void MBTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    emit m_pMaximizeButton->clicked();
}

//void TitleBar::mousePressEvent(QMouseEvent *event)
//{
//#ifdef Q_OS_WIN
//    if (ReleaseCapture())
//    {
//        QWidget *pWindow = this->window();
//        if (pWindow->isTopLevel())
//        {
//           SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
//        }
//    }
//       event->ignore();
//#else
//#endif
//}

bool MBTitleBar::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type())
    {
    case QEvent::WindowTitleChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            m_pTitleLabel->setText(pWidget->windowTitle());
            return true;
        }
    }
    case QEvent::WindowIconChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            QIcon icon = pWidget->windowIcon();
            m_pIconLabel->setPixmap(icon.pixmap(m_pIconLabel->size()));
            return true;
        }
    }
    case QEvent::WindowStateChange:
    case QEvent::Resize:
        updateMaximize();
        return true;
    }
    return QWidget::eventFilter(obj, event);
}

void MBTitleBar::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        if (pButton == m_pMinimizeButton)
        {
            pWindow->showMinimized();
        }
        else if (pButton == m_pMaximizeButton)
        {
            pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
        }
        else if (pButton == m_pCloseButton)
        {
            pWindow->close();
        }
    }
}

void MBTitleBar::updateMaximize()
{
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        bool bMaximize = pWindow->isMaximized();
        if (bMaximize)
        {
            m_pMaximizeButton->setToolTip(tr("Restore"));
            m_pMaximizeButton->setProperty("maximizeProperty", "restore");
        }
        else
        {
            m_pMaximizeButton->setProperty("maximizeProperty", "maximize");
            m_pMaximizeButton->setToolTip(tr("Maximize"));
        }

        m_pMaximizeButton->setStyle(QApplication::style());
    }
}
