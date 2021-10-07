#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QLineEdit>
class MyTable;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Append();
    void editData();

public:
    MyTable *m_table_model;
    QLineEdit *ip_addr;

};

#endif // MAINWINDOW_H
