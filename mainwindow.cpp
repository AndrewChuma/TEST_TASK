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
#include <QPropertyAnimation>
#include <mydelegate.h>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{

    setMinimumSize(800, 600);


    QVBoxLayout * main_layout = new QVBoxLayout;
    QGridLayout * connect_layout = new QGridLayout;


    QPushButton *pbAddData = new QPushButton("Add string");
    QLabel *m_port = new QLabel("Port");
    an_label = new AnimateLabel;
    an_label->setText("AnimePort");
    QLabel *m_address = new QLabel("IP addr");
    ip_addr = new QLineEdit;
    m_port_edit = new QLineEdit;
    rec_time = new QTime;

    m_table_model = new MyTable;
    QTableView *tableView = new QTableView(this);
    tableView->setModel(m_table_model);
    MyDelegate * fadeRow = new MyDelegate(this);

    tableView->setItemDelegate(fadeRow);


    main_layout->setStretch(0,1);main_layout->setStretch(1,1);main_layout->setStretch(2,2);
    connect_layout->addWidget(m_address, 0, 0);
    connect_layout->addWidget(ip_addr, 0, 1);
    connect_layout->addWidget(an_label, 1, 0);
    connect_layout->addWidget(m_port_edit, 1, 1);

    connect_layout->addWidget(pbAddData, 2, 2);




    main_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->addWidget(tableView, Qt::AlignTop);
    main_layout->addLayout(connect_layout);



    setLayout(main_layout);
    connect(pbAddData, SIGNAL(clicked()), this, SLOT(Append()));
    connect(m_port_edit, SIGNAL(editingFinished()), SLOT(makePort()));
    connect(ip_addr, SIGNAL(editingFinished()), SLOT(makeIP()));

    green_to_white = new QPropertyAnimation(an_label, "backColor");

    green_to_white->setDuration(10000);
    green_to_white->setStartValue(QColor(Qt::green));
    green_to_white->setEndValue(QColor(Qt::white));
    green_to_white->start();


}

void MainWindow::Append()
{


        qDebug()<<m_data[MyTable::columns::IP];
        m_data[MyTable::columns::TIME] = rec_time->currentTime();
        m_table_model->appendData(m_data);

}

void MainWindow::makePort()
{
    m_data[MyTable::columns::PORT] = m_port_edit->text();
    qDebug()<<m_data[MyTable::columns::PORT];
}

void MainWindow::makeIP()
{
    m_data[MyTable::columns::IP] = ip_addr->text();
    qDebug()<<m_data[MyTable::columns::IP];
}
MainWindow::~MainWindow()
{

}
