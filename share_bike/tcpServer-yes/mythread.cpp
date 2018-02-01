#include "mythread.h"


MyThread::MyThread(QTcpSocket *socketDescriptor, QObject *parent):
QThread(parent),tcpServerConnection(socketDescriptor)
{
    totalBytes = 0;
    bytesReceived = 0;

}


void MyThread::run()
{
    connect(tcpServerConnection, SIGNAL(readyRead()),this, SLOT(receiveFile()));
    connect(tcpServerConnection,SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));  
   // exec();
}


void MyThread::receiveFile()
{

    if(tcpServerConnection->bytesAvailable() < 5)
    {
         tcpServerConnection->read((char*)&data_size,4);

         emit bytesArrived(data);
         qDebug()<<"receiveFile---"<<data.size();
         data.clear();
    }else{
        data = data.append(tcpServerConnection->readAll());
    }

}

void MyThread::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "tcpServerConnection->errorString()";
    tcpServerConnection->close();
    emit error(socketError);
}


