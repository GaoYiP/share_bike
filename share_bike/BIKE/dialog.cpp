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

    //logo设置
    trayicon = new QIcon;
    trayicon->addFile(QStringLiteral(":/icon/tray.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui->num->setText(QString("%1").arg(bike_count));
    //server building...........................................................................
    bike_server = new Server(this);
    bike_server->listen(QHostAddress::Any, 7777);
    //..........................................................................................
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(clearMsg()));

    QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    DB.open();
    QSqlQuery *query = new QSqlQuery;
    QString create_sql = "create table if not exists BIKE(BIKE_localtion varchar(30) NOT NULL, IP_Addr varchar(30) UNIQUE NOT NULL, STATUS bool)";
    query->prepare(create_sql);
    if(!query->exec())
    {
        qDebug()<<"Table BIKE Create failed";
        qDebug()<<query->lastError();
        DB.close();
        return ;
    }
    query->exec("create table password(pwd varchar primary key)");
    query->exec("select count (*) from BIKE");
    qint32 bike_total=0;
    if(query->first())
    {
        bike_total = query->value(0).toInt();
        qDebug()<< "bike_total from database :" <<bike_total;
    }
    DB.close();
    ui->bike_total->setText(QString("%1").arg(bike_total));

    //显示表格
    model = new QSqlRelationalTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    //set table
    model->setTable("BIKE");
    //select data
    model->select();
    //set model
    ui->database->setModel(model);
    //set column 5 's width to 200
    ui->database->setColumnWidth(model->fieldIndex("BIKE"), 150);
    connect(ui->upload, SIGNAL(clicked()), this, SLOT(ask_ok_sql()));
    vidio = new Widget;
    vidio->setFixedSize(923,564);
    vidio->hide();
    //connect(ui->addrCheckBox, SIGNAL(stateChanged(int)), this, SLOT(on_show_cam_stateChanged(int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showConnection()
{
    bike_count++;
    int num = ui->bike_total->text().toInt() - bike_count;
    ui->num->setText(QString("%1").arg(num));
}

void Dialog::showDisconnection(int socketDescriptor)
{
    bike_count--;

    /* remove disconnect socketdescriptor from list */
    bike_server->socketList.removeAll(socketDescriptor);

    //change connect number while connection is disconnecting
    ui->num->setText(QString("%1").arg(bike_count));

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
    msg = QString::fromLocal8Bit(data);

    //cut the recieve msg......................................
    QStringList list=msg.split("#");
    bool ret = 0;
    if(list[1]=="locked")
        ret = checkSignIn(list[0]);
    else
        ret = checkSignUp(list[0],list[1]);
    QString return_msg=list[0];
    if(ret){
        return_msg+="#true";
        qDebug() << return_msg;
    }
    else{
        return_msg+="#false";
        qDebug() << return_msg;
    }
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

bool Dialog::checkSignIn(QString ip)
{
    sqlite_operation *mysql = new sqlite_operation();
    bool ret=mysql->up_bike_status(ip);
    return ret;
}

bool Dialog::checkSignUp(QString ip, QString MARK)
{
    sqlite_operation *mysql = new sqlite_operation();
    bool ret=mysql->up_bike_mark(ip,MARK);
    if(ret==1){
        QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
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
    return true;
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

void Dialog::ask_ok_sql()
{
//    model->database().transaction();//开始事务操作
//    if(model->submitAll())
//    {
//        model->database().commit();//提交
//    }
//    else
//    {
//        model->database().rollback();//回滚
//        QMessageBox::warning(this,tr("tableModel"),
//                            tr("数据库错误: %1")
//                            .arg(model->lastError().text()));
//    }
}
