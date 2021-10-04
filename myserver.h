#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>

class QTcpServer;

class MyServer: public QObject
{
    Q_OBJECT
public:
    MyServer(QObject *parent=nullptr);
public slots:
    void onConnected();
    void readData();

private:
    uint16_t m_port;
    QTcpServer *m_tcpserver;
};

#endif // MYSERVER_H
