#ifndef MBSEARCHBAR_H
#define MBSEARCHBAR_H

#include "baseui_global.h"
#include <QLineEdit>

class BASEUISHARED_EXPORT MBSearchBar : public QLineEdit
{
    Q_OBJECT
public:
    explicit MBSearchBar(QWidget *parent);

signals:
    void searchClicked();

};

#endif // MBSEARCHBAR_H
