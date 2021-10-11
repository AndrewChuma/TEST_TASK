#include "mydelegate.h"
#include "animatelabel.h"
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QTableView>
#include <QDebug>
MyDelegate::MyDelegate(QObject * parent): QStyledItemDelegate(parent)
{

}


void MyDelegate :: paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    QRect rect = option.rect;

    painter->setBrush(QColor(Qt::green));
    painter->drawRect(rect);
    painter->drawText(0, 0, qvariant_cast<QString>(index.data(Qt::DisplayRole)));

}


MyDelegate::~MyDelegate()
{

}
