#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QString>
#include "sqlite_operation.h"
#include "server.h"
#include <QSqlRelationalTableModel>

namespace Ui {
    class Dialog;
}

class Server;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

signals:
    void sendData(QByteArray data, int id);

public slots:
    void revData(QString peerHost, QByteArray data);
private slots:
    void showConnection();
    void showDisconnection(int socketDescriptor);
    void sendMsg();
    void clearMsg();
    bool checkSignIn(QString name,QString passward);
    bool checkSignUp(QString name,QString passward);
    int getBikeLocation();
    int askBikeUnlock(QString);


private:
    Ui::Dialog *ui;

    int user_count, user_total;

    Server *user_server;

    QTimer *timer;

    QSqlRelationalTableModel *model;
};

#endif // DIALOG_H
