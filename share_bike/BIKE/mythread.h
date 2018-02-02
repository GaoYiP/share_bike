#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QAbstractSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QBuffer>
#include <QtNetwork>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QTcpSocket *tcpSocket, QObject *parent);
    void run();
    
signals:
    void error(QTcpSocket::SocketError socketError);
    void bytesArrived(QString, QByteArray);
    void sendSocketNo(qint64);

public slots:
    void receiveFile();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *tcpServerConnection;
    qint64 totalBytes;
    qint64 bytesReceived;
    QByteArray inBlock;
    QBuffer buffer;

    QByteArray data;
    long data_size;

    qint64 socketNo;
};

#endif // MYTHREAD_H
