#ifndef TBTITLEBAR_H
#define TBTITLEBAR_H

#include "baseui_global.h"

class QLabel;
class QPushButton;

class BASEUISHARED_EXPORT MBTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit MBTitleBar(QWidget *parent = 0);
    ~MBTitleBar();

signals:
    void searchClicked();

protected:

    // 双击标题栏进行界面的最大化/还原
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

    // 进行鼠界面的拖动
//    virtual void mousePressEvent(QMouseEvent *event);

    // 设置界面标题与图标
    virtual bool eventFilter(QObject *obj, QEvent *event);

private slots:

    // 进行最小化、最大化/还原、关闭操作
    void onClicked();

private:

    // 最大化/还原
    void updateMaximize();

private:
    QLabel *m_pIconLabel;
    QLabel *m_pTitleLabel;
    QPushButton *m_pMinimizeButton;
    QPushButton *m_pMaximizeButton;
    QPushButton *m_pCloseButton;
    QPushButton *m_pSearchButton;
};

#endif // TBTITLEBAR_H
