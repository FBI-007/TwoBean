#ifndef DOWNLOADPAGE_H
#define DOWNLOADPAGE_H

class QTableView;
class QWidget;

#include "mbwindow.h"
#include "mbsearchbar.h"

class TBDownloadPage : public MBWindow
{
    Q_OBJECT
public:
    explicit TBDownloadPage(QWidget *parent = 0);

signals:

protected slots:
    void showHideSearch();
    void search();

protected:
    void initTableBar();


protected:
    MBSearchBar *m_pSearchLineEdit;
    QTableView  *m_pTableView;

    int         m_iSearchBtnDown = -1;
};

#endif // DOWNLOADPAGE_H
