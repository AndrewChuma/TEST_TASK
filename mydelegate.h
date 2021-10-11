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
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    AnimateLabel * fadeRow;
    QTableView *myWidget;
    bool isOneCellInEditMode;
    QPersistentModelIndex currentEditedCellIndex;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

public slots:
    void cellEntered(const QModelIndex &index);
};

#endif // MYDELEGATE_H
