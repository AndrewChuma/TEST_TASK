#include "mytable.h"
#include <QAbstractItemModel>
#include <QAbstractTableModel>
#include <QDebug>
MyTable::MyTable(int nRows, int nColumns, QObject *pobj):QAbstractTableModel (pobj), m_nRows(nRows), m_nColumns(nColumns)
{

}
int MyTable::rowCount(const QModelIndex &parent) const
{
    return m_nRows;
}

int MyTable::columnCount(const QModelIndex &parent) const
{
    return m_nColumns;
}

QVariant MyTable::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()){
        return QVariant();
    }
    QString str = QString("%1, %2").arg(index.row() + 1).arg(index.column() + 1);
    qDebug()<<index;
    return (role == Qt::DisplayRole || role == Qt::EditRole) ? m_hash.value(index, QVariant(str)) : QVariant();
}

bool MyTable::setData(const QModelIndex &index, const QVariant &value, int nRole)
{
    if (!index.isValid() && nRole == Qt::EditRole)
    {
        m_hash[index] = value;
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

Qt::ItemFlags MyTable::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    return index.isValid() ? (flags | Qt::ItemIsEditable) : flags;
}
MyTable::~MyTable()
{

}
