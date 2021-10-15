#include "myserver.h"

#include "myserver.h"
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include "coder.h"
MyServer::MyServer(QObject *parent):QObject (parent), m_port(80)
{
    m_tcpserver = new QTcpServer(this);

    if(!m_tcpserver->listen(QHostAddress::AnyIPv4, 0)){
        qDebug()<<"Unable to start server";
        m_tcpserver->close();
        return;
    }else{
        qDebug()<<m_tcpserver->serverPort();
        qDebug()<<"OK";

    }
    connect(m_tcpserver, SIGNAL(newConnection()), this, SLOT(onConnected()));
}
void MyServer::onConnected()
{
    QTcpSocket* clientSock = m_tcpserver->nextPendingConnection();
    Coder new_coder;
    socket_coder_hash[clientSock->socketDescriptor()] = new_coder;
        qDebug()<<clientSock->peerAddress();
        qDebug()<<clientSock->socketDescriptor();
    connect(clientSock, SIGNAL(disconnected()), clientSock, SLOT(deleteLater()));
    connect(clientSock, SIGNAL(readyRead()), this, SLOT(readData()));


}

void MyServer::readData()
{

    QTcpSocket * rclientSock = qobject_cast<QTcpSocket*>(sender());
    QByteArray client_reception;
    while(rclientSock->bytesAvailable()){
        client_reception.push_back(rclientSock->readAll());
       }
    socket_coder_hash[rclientSock->socketDescriptor()].decode(&client_reception);
    qDebug()<<rclientSock->socketDescriptor();
    qDebug()<<client_reception;
}
