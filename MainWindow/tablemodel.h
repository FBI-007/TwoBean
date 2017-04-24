#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

struct FileRecord{
    QString strFilePath;
    bool    bChecked;
};


class TableModel : public QAbstractTableModel
{
public:
    explicit TableModel(QObject *parent = 0);
    ~TableModel();

    void updateData(QList<FileRecord> recordList);

protected:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;


protected:
    QList<FileRecord> m_recordList;
};

#endif // TABLEMODEL_H
