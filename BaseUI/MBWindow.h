#ifndef TBWINDOW_H
#define TBWINDOW_H

#include "baseui_global.h"
#include "MBTitleBar.h"

class BASEUISHARED_EXPORT MBWindow : public QDialog//QWidget
{
    Q_OBJECT
public:
    explicit MBWindow(QWidget *parent = 0);

signals:
    void searchClicked();

public slots:

protected:
    void paintEvent(QPaintEvent *event);

    inline void setFrameWidth(int width){ m_iFrameWidth = width;}

protected:
    QVBoxLayout *m_pLayout;
    MBTitleBar  *m_pTitleBar;
    int         m_iFrameWidth;

};

#endif // TBWINDOW_H
