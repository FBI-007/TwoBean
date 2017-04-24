#include <QMouseEvent>

#include "MBWindow.h"
#include "framelesshelper.h"
#include <QIcon>
#include <QPainter>
#include <qmath.h>

#define  FrameWidth  5

MBWindow::MBWindow(QWidget *parent)
{
    m_pTitleBar = new MBTitleBar(this);
    m_iFrameWidth = FrameWidth;

    FramelessHelper *pHelper = new FramelessHelper(this);
    pHelper->activateOn(this);              //激活当前窗体
    pHelper->setTitleHeight(m_pTitleBar->height());  //设置窗体的标题栏高度
    pHelper->setWidgetMovable(true);        //设置窗体可移动
    pHelper->setWidgetResizable(true);      //设置窗体可缩放
//  pHelper->setRubberBandOnMove(true);     //设置橡皮筋效果-可移动
    pHelper->setRubberBandOnResize(true);   //设置橡皮筋效果-可缩放

    // 设置无边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    // 标题栏
    installEventFilter(m_pTitleBar);

    resize(400, 300);
    setMinimumSize(400, 300);

    setWindowTitle("Pokemon");
    setWindowIcon(QIcon(":Icon/icons/logo.png"));

    QPalette pal(palette());
    pal.setColor(QPalette::WindowText, Qt::white);
    pal.setColor(QPalette::Background, Color_Black48);
    setAutoFillBackground(true);
    setPalette(pal);

    m_pLayout = new QVBoxLayout(this);
    m_pLayout->addWidget(m_pTitleBar);
    m_pLayout->setSpacing(0);                   // 内部控件间距
//    m_pLayout->setMargin(m_iFrameWidth);        // Layout整体的外边距
    m_pLayout->setContentsMargins(m_iFrameWidth, 0, m_iFrameWidth, m_iFrameWidth);
    setLayout(m_pLayout);

    // 背景透明
    //setAttribute(Qt::WA_TranslucentBackground, true);

    connect(m_pTitleBar, SIGNAL(searchClicked()), this, SIGNAL(searchClicked()));
}


void MBWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);           // false :调色,颜色是否叠加

    for(int i=0; i<m_iFrameWidth; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);                          // 填充矩形线
        path.addRect(i, i, this->width() - i*2 -1, this->height() - i*2 -1);
        painter.setPen(Color_Black64);
        painter.drawPath(path);
    }
}
