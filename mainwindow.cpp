#include "mainwindow.h"
#include "mytable.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableView>
#include <QStringList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{

    setMinimumSize(600, 400);

    QStringList coll_names = {"ip_addr", "port", "received time", "type", "size", "version", "payload", "CRC"};
    QHBoxLayout * main_layout = new QHBoxLayout;
    QVBoxLayout * table_layout = new QVBoxLayout;
    QVBoxLayout * connect_layout = new QVBoxLayout;
    QPushButton *connect = new QPushButton("Create Server");
    QLabel *m_port = new QLabel("Port");
    QLabel *m_address = new QLabel("IP addr");
    MyTable *m_table_model = new MyTable(2, 10);

    QTableView *tableView = new QTableView;
    tableView->setModel(m_table_model);
    m_table_model->insertRow(3);



    main_layout->setStretch(0,1);main_layout->setStretch(1,1);main_layout->setStretch(2,2);
    connect_layout->addWidget(connect);
    connect_layout->addWidget(m_port);
    connect_layout->addWidget(m_address);
    table_layout->addWidget(tableView);
    main_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->addLayout(table_layout);
    main_layout->addLayout(connect_layout);



    setLayout(main_layout);



}

MainWindow::~MainWindow()
{

}
