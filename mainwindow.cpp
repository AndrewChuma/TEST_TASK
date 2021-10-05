#include "mainwindow.h"

#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
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
    QTableWidget * m_table = new QTableWidget(5, coll_names.length());
    m_table->setHorizontalHeaderLabels(coll_names);

    QTableWidgetItem * new_item = new QTableWidgetItem(QString("First Cell"));

    new_item->setTextColor("blue");
    m_table->setItem(0, 0, new_item);



    main_layout->setStretch(0,1);main_layout->setStretch(1,1);main_layout->setStretch(2,2);
    connect_layout->addWidget(connect);
    connect_layout->addWidget(m_port);
    connect_layout->addWidget(m_address);
    table_layout->addWidget(m_table);
    main_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->addLayout(table_layout);
    main_layout->addLayout(connect_layout);



    setLayout(main_layout);



}

MainWindow::~MainWindow()
{

}
