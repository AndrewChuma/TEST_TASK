#include "mainwindow.h"

#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{


    QGridLayout *main_layout = new QGridLayout;
    QPushButton *connect = new QPushButton("Create Server");
    QLabel *m_port = new QLabel("Port");
    QLabel *m_address = new QLabel("IP addr");
    main_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->addWidget(connect, 0, 2);
    main_layout->addWidget(m_address, 0, 0);
    main_layout->addWidget(m_port, 0, 1);


    setLayout(main_layout);


}

MainWindow::~MainWindow()
{

}
