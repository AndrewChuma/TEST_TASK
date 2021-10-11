#include "mytable.h"
#include <QAbstractItemModel>
#include <QAbstractTableModel>
#include <QDebug>
#include <QBrush>
#include "animatelabel.h"
#include <QLabel>
MyTable::MyTable(QObject *pobj):QAbstractTableModel (pobj)
{

}
int MyTable::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return data_rows.count();
}

int MyTable::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return CRC;
}

QVariant MyTable::data(const QModelIndex &index, int role) const
{


    if (!index.isValid() || data_rows.count() <= index.row()){
        return QVariant();
    }

    return (role == Qt::DisplayRole || role == Qt::EditRole) ? data_rows[index.row()][columns(index.column())]:QVariant();

}



QVariant MyTable::headerData(int section, Qt::Orientation orientation, int role) const
{


    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {

        return columns_names[section];
    }
    //return QVariant();
}
/*
Qt::ItemFlags MyTable::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    return index.isValid() ? (flags | Qt::ItemIsEditable) : flags;
}

bool MyTable::setData(const QModelIndex &index, const QVariant &value, int nRole)
{
    if (index.isValid() && nRole == Qt::EditRole)
    {
        data_rows[index.row()][columns(index.column())] = value;
        emit dataChanged(index, index);
        return true;
    }

    return false;
}
*/
void MyTable::appendData(QHash<columns, QVariant> & data)
{

    int rows = data_rows.count();

    beginInsertRows(QModelIndex(), rows, rows);
    data_rows.append(data);
    endInsertRows();
}


MyTable::~MyTable()
{

}
