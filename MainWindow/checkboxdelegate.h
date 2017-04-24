#ifndef CHECKBOXDELEGATE_H
#define CHECKBOXDELEGATE_H

#include <QStyledItemDelegate>

class CheckBoxDelegate : public QStyledItemDelegate
{
public:
    CheckBoxDelegate(QObject *parent);
    ~CheckBoxDelegate();


protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

};

#endif // CHECKBOXDELEGATE_H
