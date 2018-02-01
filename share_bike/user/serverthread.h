#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include <QObject>
#include <QtNetwork>
#include <QDebug>
#include <dialog.h>

#include "mysocket.h"

class Dialog;
class Socket;

class serverThread : public QThread
{
    Q_OBJECT
public:
    serverThread(int socketDes, QObject *parent = 0);
    ~serverThread();
    void run();

public:
    int socketDescriptor;    

signals:
    void revData(QString, QByteArray);
    void sendDat(QByteArray data, int id);
    void disconnectTCP(int );

private slots:   
    void sendData(QByteArray data, int id);
    void recvData(QString, QByteArray);
    void disconnectToHost();

private:
    MySocket *socket;
    Dialog *dialog;

};

#endif // SERVERTHREAD_H
