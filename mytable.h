#ifndef MYTABLE_H
#define MYTABLE_H

#include <QObject>
#include <QAbstractTableModel>


class MyTable : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyTable();
    MyTable(int nRows, int nColumns, QObject * pobj = nullptr);
    virtual ~MyTable();

public:
    QVariant data(const QModelIndex &index, int nRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int nRole);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
signals:

public slots:
private:
    int m_nRows;
    int m_nColumns;
    QHash<QModelIndex, QVariant> m_hash;
};

#endif // MYTABLE_H
