#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include "animatelabel.h"
#include <QTableView>
#include <QStyledItemDelegate>
class MyDelegate : public QStyledItemDelegate
{
public:

    MyDelegate(QObject *parent = nullptr);
    virtual ~MyDelegate();


public:

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;



};

#endif // MYDELEGATE_H
