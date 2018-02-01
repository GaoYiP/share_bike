#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QBuffer>
#include <tcpServer-yes/mythread.h>
#include <QMap>
#include <QtGui>
#include <QSystemTrayIcon>
#include <QMenu>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

private slots:
    void acceptConnection();
    void showImg(QByteArray data);
    void showTime();

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void mouseDoubleClickEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent * e);
    void closeEvent(QCloseEvent *e);
    
private:
    Ui::Widget *ui;
    QTcpServer tcpServer;
    QTcpSocket *tcpServerConnection;

    QMap<int,int> socketMap;

    int screenNo[4];
    int socketNo;   

    int labelWidth;
    int labelHeight;
    int labelX;
    int labelY;
    QSystemTrayIcon *trayIcon;
    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QMenu   *trayIconMenu;
    bool flag = false;
};

#endif // WIDGET_H
