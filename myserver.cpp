#include "myserver.h"

#include "myserver.h"
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
MyServer::MyServer(QObject *parent):QObject (parent), m_port(80)
{
    m_tcpserver = new QTcpServer(this);

    if(!m_tcpserver->listen(QHostAddress("192.168.0.10"), m_port)){
        qDebug()<<"Unable to start server";
        m_tcpserver->close();
        return;
    }else{
        qDebug()<<"OK";

    }
    connect(m_tcpserver, SIGNAL(newConnection()), this, SLOT(onConnected()));
}
void MyServer::onConnected()
{
    QTcpSocket* clientSock = m_tcpserver->nextPendingConnection();
        qDebug()<<clientSock->peerAddress();
    connect(clientSock, SIGNAL(disconnected()), clientSock, SLOT(deleteLater()));
    connect(clientSock, SIGNAL(readyRead()), this, SLOT(readData()));


}

void MyServer::readData()
{
    QString rcvStr;
    QTcpSocket * rclientSock = qobject_cast<QTcpSocket*>(sender());
    QByteArray client_reception;
    while(rclientSock->bytesAvailable()){
        client_reception.push_back(rclientSock->readAll());
       }

    qDebug()<<client_reception;
}
