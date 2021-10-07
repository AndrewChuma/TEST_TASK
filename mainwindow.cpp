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
#include <QTime>
#include <QLineEdit>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{

    setMinimumSize(800, 600);


    QVBoxLayout * main_layout = new QVBoxLayout;
    QGridLayout * connect_layout = new QGridLayout;

    QPushButton *pbAddData = new QPushButton("Add string");
    QLabel *m_port = new QLabel("Port");
    QLabel *m_address = new QLabel("IP addr");
    ip_addr = new QLineEdit;


    m_table_model = new MyTable;
    QTableView *tableView = new QTableView;
    tableView->setModel(m_table_model);




    main_layout->setStretch(0,1);main_layout->setStretch(1,1);main_layout->setStretch(2,2);
    connect_layout->addWidget(m_address, 0, 0);
    connect_layout->addWidget(ip_addr, 0, 1);
    connect_layout->addWidget(m_port, 1, 0);

    connect_layout->addWidget(pbAddData, 2, 2);


    main_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->addWidget(tableView, Qt::AlignTop);
    main_layout->addLayout(connect_layout);



    setLayout(main_layout);
    connect(pbAddData, SIGNAL(clicked()), SLOT(Append()));
    connect(ip_addr, SIGNAL(editingFinished()), SLOT(editData()));


}

void MainWindow::Append()
{

        QStringList to_send = {"192.168.0.20", "80", QTime::currentTime().toString()};
        m_table_model->appendData(to_send);
}

void MainWindow::editData()
{

}
MainWindow::~MainWindow()
{

}
