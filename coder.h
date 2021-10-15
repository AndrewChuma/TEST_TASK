#ifndef CODER_H
#define CODER_H

#include <QObject>
#include <QByteArray>
class Coder
{
public:
    Coder();


public:
    void waitingStart();
    void decode(QByteArray *);

public slots:
    void waitingEnd();


public:
    QByteArray * main_array;
};

#endif // CODER_H
