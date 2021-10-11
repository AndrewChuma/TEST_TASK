#include "mydelegate.h"
#include "animatelabel.h"
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QTableView>

MyDelegate::MyDelegate(QObject * parent): QStyledItemDelegate(parent)
{
    if(QTableView *tableView = qobject_cast<QTableView *>(parent))
        {
            myWidget = tableView;
            fadeRow = new AnimateLabel(myWidget);


            connect(myWidget, SIGNAL(entered(QModelIndex)),
                                  this, SLOT(cellEntered(QModelIndex)));
            isOneCellInEditMode = false;
        }
}
QWidget * MyDelegate :: createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.model()->headerData(index.column(), Qt::Horizontal, Qt::UserRole).toInt() == 1) {
            AnimateLabel * fade_cell = new AnimateLabel(parent);
            fade_cell->setText(index.data().toString());
            return fade_cell;
        } else {
            return QStyledItemDelegate::createEditor(parent, option, index);
        }
}

void MyDelegate :: paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    if( index.model()->headerData(index.column(), Qt::Horizontal, Qt::UserRole).toInt() == 1 )
       {
           fadeRow->setGeometry(option.rect);
           fadeRow->setText(index.data().toString());
           if (option.state == QStyle::State_Selected)
                        painter->fillRect(option.rect, option.palette.highlight());
           QPixmap map = QPixmap::grabWidget(fadeRow);
           painter->drawPixmap(option.rect.x(),option.rect.y(),map);
       } else {
           QStyledItemDelegate::paint(painter,option, index);
       }
}

void MyDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
void MyDelegate::cellEntered(const QModelIndex &index)
{
    if(index.model()->headerData(index.column(), Qt::Horizontal, Qt::UserRole) == 1)
    {
        if(isOneCellInEditMode)
        {
            myWidget->closePersistentEditor(currentEditedCellIndex);
        }
        myWidget->openPersistentEditor(index);
        isOneCellInEditMode = true;
        currentEditedCellIndex = index;
    } else {
        if(isOneCellInEditMode)
        {
            isOneCellInEditMode = false;
            myWidget->closePersistentEditor(currentEditedCellIndex);
        }
    }
}


MyDelegate::~MyDelegate()
{

}
