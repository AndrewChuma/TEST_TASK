#ifndef MYTABLE_H
#define MYTABLE_H

#include <QObject>
#include <QAbstractTableModel>


class MyTable : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyTable();
    virtual ~MyTable();

signals:

public slots:
};

#endif // MYTABLE_H
