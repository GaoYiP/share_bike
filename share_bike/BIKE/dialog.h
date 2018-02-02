#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QString>
#include "sqlite_operation.h"
#include "server.h"
#include <QSqlRelationalTableModel>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QCloseEvent>
#include <widget.h>

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
    void clearMsg();
    bool checkSignIn(QString ip);
    bool checkSignUp(QString ip, QString MARK);
    void trayiconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_show_cam_stateChanged(int arg1);
    void ask_ok_sql();

protected:
    void closeEvent(QCloseEvent *e);

private:
    Ui::Dialog *ui;

    int bike_count, bike_total;

    Server *bike_server;

    QTimer *timer;

    QSqlRelationalTableModel *model;
    QSystemTrayIcon *trayIcon;
    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QMenu   *trayIconMenu;
    bool flag = false;
    Widget *vidio;
    QIcon *trayicon;
};

#endif // DIALOG_H
