#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QLineEdit>
#include "mytable.h"
#include <QLabel>
#include "animatelabel.h"


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Append();
    void makePort();
    void makeIP();


public:
    AnimateLabel * an_label;
    QPropertyAnimation *green_to_white;
    MyTable *m_table_model;
    QLineEdit *ip_addr;
    QLineEdit * m_port_edit;
    QTime * rec_time;
    QHash<MyTable::columns, QVariant> m_data;

};

#endif // MAINWINDOW_H
