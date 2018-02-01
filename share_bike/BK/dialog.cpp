#include <QMessageBox>

#include "dialog.h"
#include "ui_dialog.h"
#include "sqlite_operation.h"
#define W  360
#define H  380


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog), bike_count(0), timer(new QTimer)
{
    ui->setupUi(this);
    trayicon = new QIcon;
    trayicon->addFile(QStringLiteral(":/icon/tray.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui->num->setText(QString("%1").arg(bike_count));
    //server building...........................................................................
    bike_server = new Server(this);
    bike_server->listen(QHostAddress::Any, 7777);
    //..........................................................................................
    connect(ui->sendBtn, SIGNAL(clicked()), this, SLOT(sendMsg()));
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(clearMsg()));
    //connect(ui->show_cam, SIGNAL(clicked(true)), this, SLOT(on_show_cam_clicked(true)));
    QSqlDatabase DB;
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    DB.open();
    QString str=QString("select count (*) from BIKE");
    QSqlQuery *query = new QSqlQuery;
    query->exec(str);
    qint32 bike_total=0;
    if(query->first())
    {
        bike_total = query->value(0).toInt();
        qDebug()<< "bike_total from database :" <<bike_total;
    }
    DB.close();
    ui->bike_total->setText(QString("%1").arg(bike_total));
    model = new QSqlRelationalTableModel(ui->database);
    //set table
    model->setTable("BIKE");
    //select data
    model->select();
    //set model
    ui->database->setModel(model);
    //set column 5 's width to 200
    ui->database->setColumnWidth(model->fieldIndex("BIKE"), 150);

    vidio = new Widget;
    vidio->hide();
    connect(ui->addrCheckBox, SIGNAL(stateChanged(int)), this, SLOT(on_show_cam_stateChanged(int)));
    //connect(vidio, SIGNAL(closeEvent()), this, SLOT(ui->show_cam->setCheckState(Qt::Unchecked)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showConnection()
{
    bike_count++;
    int num = ui->bike_total->text().toInt() - bike_count;
    /* add socket object that join in */
    ui->objectBox->addItem(QString("%1").arg(bike_server->socketList.last()));
    /* change connect number while connection is connecting */
    ui->num->setText(QString("%1").arg(num));
}

void Dialog::showDisconnection(int socketDescriptor)
{
    bike_count--;

    /* remove disconnect socketdescriptor from list */
    bike_server->socketList.removeAll(socketDescriptor);

    /* reload combobox */
    ui->objectBox->clear();

    for (int i = 0; i < bike_server->socketList.size(); i++)
    {
         ui->objectBox->addItem(QString("%1").arg(bike_server->socketList.at(i)));
    }

    //change connect number while connection is disconnecting
    ui->num->setText(QString("%1").arg(bike_count));

}

void Dialog::sendMsg()
{
    /* if send message is null return */
    if (ui->sendMsg->text() == "") {
        QMessageBox::information(NULL,
                        tr("注意"),
                        tr("发送内容不能为空！"),
                        QMessageBox::Yes);
        return;
    }
    else {
        /* send original data */
        emit sendData(ui->sendMsg->text().toLocal8Bit(), ui->objectBox->currentText().toInt());
    }

    ui->sendMsg->setText("");
}

void stringToHtmlFilter(QString &str)
{
   str.replace("&","&amp;");
   str.replace(">","&gt;");
   str.replace("<","&lt;");
   str.replace("\"","&quot;");
   str.replace("\'","&#39;");
   str.replace(" ","&nbsp;");
   str.replace("\n","<br>");
   str.replace("\r","<br>");
}

void stringToHtml(QString &str, QColor color)
{
    QByteArray data;

    if (str.isEmpty()) {
        return;
    }

    data.append(color.red());
    data.append(color.green());
    data.append(color.blue());
    QString strColor(data.toHex());

    str = QString("<span style=\" color:#%1;\">%2</span>").arg(strColor).arg(str);
}

void Dialog::revData(QString peerAddr, QByteArray data)
{
    QString msg;

    if (ui->addrCheckBox->isChecked()) {
        ui->msg->append(QString::fromLocal8Bit(data));
        qDebug() << "check 1 @@@@@@@@@" <<  data;
        //qDebug() << "check 2 @@@@@@@@@" <<  peerAddr;
        return ;
    }

    msg = QString::fromLocal8Bit(data);

    //cut the recieve msg......................................
    QStringList list=msg.split("#");
    bool ret = 0;
    if(list[0]=="regist")     //注册
        ret = checkSignUp(list[1],list[2]);
    else if(list[0]=="login")  //登录
        ret = checkSignIn(list[1],list[2]);
    else
        return;
    QString return_msg=list[0];
    if(ret){
        return_msg+="#true";
        qDebug() << return_msg;
    }
    else{
        return_msg+="#false";
        qDebug() << return_msg;
    }

    emit sendData(return_msg.toLocal8Bit(), ui->objectBox->currentText().toInt());
    //......................................................................................
    peerAddr.insert(peerAddr.size(), ": ");
    stringToHtmlFilter(peerAddr);
    stringToHtml(peerAddr, QColor(255, 0, 0));

    msg.prepend(peerAddr);
    ui->msg->append(msg);    
}

void Dialog::clearMsg()
{
    ui->msg->clear();
}

bool Dialog::checkSignIn(QString name,QString passward)
{
    sqlite_operation *mysql = new sqlite_operation();
    bool ret=mysql->loguser(name,passward);
    return ret;
}

bool Dialog::checkSignUp(QString ip, QString STATUS)
{
    sqlite_operation *mysql = new sqlite_operation();
    bool ret=mysql->signup(ip,STATUS);
    //
    if(ret){
        QSqlDatabase DB;
        DB = QSqlDatabase::addDatabase("QSQLITE");
        DB.setDatabaseName("../../BIKE.db");
        DB.open();
        QString str=QString("select count (*) from BIKE");
        QSqlQuery *query = new QSqlQuery;
        query->exec(str);
        qint32 bike_total=0;
        if(query->first())
        {
            bike_total = query->value(0).toInt();
            qDebug()<< "bike_total from database :" <<bike_total;
        }
        DB.close();
        ui->bike_total->setText(QString("%1").arg(bike_total));
    }

    return ret;
}

void Dialog::trayiconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
        //单击托盘图标
    case QSystemTrayIcon::DoubleClick:
        //双击托盘图标
        this->showNormal();
        this->raise();
        break;
    default:
        break;
    }
}

void Dialog::closeEvent(QCloseEvent *e)
{
    e->ignore();
    this->hide();
    if(flag==false)
    {
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(*trayicon);
        trayIcon->setToolTip(tr("单车数据库"));

        QString titlec=tr("单车数据库");
        QString textc=tr("单车数据库：正在后台在监控");
        trayIcon->setVisible(true);
        trayIcon->showMessage(titlec,textc,QSystemTrayIcon::Information,5000);

        //添加单/双击鼠标相应
        connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this,SLOT(trayiconActivated(QSystemTrayIcon::ActivationReason)));

        //创建监听行为
        minimizeAction = new QAction(tr("最小化 (&I)"), this);
        connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
        restoreAction = new QAction(tr("还原 (&R)"), this);
        connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
        quitAction = new QAction(tr("退出 (&Q)"), this);
        connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

        //创建右键弹出菜单
        trayIconMenu = new QMenu(this);
        trayIconMenu->addAction(minimizeAction);
        trayIconMenu->addAction(restoreAction);
        trayIconMenu->addSeparator();
        trayIconMenu->addAction(quitAction);
        trayIcon->setContextMenu(trayIconMenu);
        flag = true;
    }
}

void Dialog::on_show_cam_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        vidio->setGeometry(0,0,916,542);
        vidio->show();
    }
    else // 未选中 - Qt::Unchecked
    {
        vidio->hide();
    }
}
