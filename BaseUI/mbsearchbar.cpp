#include "MBSearchBar.h"
#include <QPushButton>
#include <QMessageBox>

#define  TextMargin  3

MBSearchBar::MBSearchBar(QWidget *parent)
    : QLineEdit (parent)
{
    QPushButton *pSearchBtn = new QPushButton(this);

    pSearchBtn->setCursor(Qt::PointingHandCursor);
    pSearchBtn->setFixedSize(22, 22);
    pSearchBtn->setToolTip(QStringLiteral("搜索"));
    pSearchBtn->setStyleSheet("QPushButton{border-image:url(:/images/icon_search_normal);\
                                           background:transparent;} \
                               QPushButton:hover{border-image:url(:/images/icon_search_hover)} \
                               QPushButton:pressed{border-image:url(:/images/icon_search_press)}");

    //防止文本框输入内容位于按钮之下
    //QMargins margins = textMargins();
    //setTextMargins(margins.left(), margins.top(), pSearchButton->width(), margins.bottom());
    setTextMargins(TextMargin *2, TextMargin, pSearchBtn->width() +TextMargin, TextMargin);
    setPlaceholderText(QStringLiteral("请输入搜索内容"));

    QHBoxLayout *pSearchLayout = new QHBoxLayout(this);
    pSearchLayout->addStretch();
    pSearchLayout->addWidget(pSearchBtn);
    pSearchLayout->setSpacing(2);
    pSearchLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(pSearchLayout);

    connect(pSearchBtn, SIGNAL(clicked(bool)), this, SIGNAL(searchClicked()));
}
