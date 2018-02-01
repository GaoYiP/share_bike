#include <QMessageBox>

#include "dialog.h"
#include "ui_dialog.h"
#include "sqlite_operation.h"
#include <QTimer>
#include <serverthread.h>




Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog), user_count(0), timer(new QTimer)
{
    ui->setupUi(this);
    ui->num->setText(QString("%1").arg(user_count));

    //server building...........................................................................
    user_server = new Server(this);
    user_server->listen(QHostAddress::Any, 8888);

    //..........................................................................................
    connect(ui->sendBtn, SIGNAL(clicked()), this, SLOT(sendMsg()));
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(clearMsg()));
    //connect(timer, SIGNAL(timeout()), this, SLOT(sendLoopMessage()));  //备用槽

    QSqlDatabase DB;
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    DB.open();
    QString str=QString("select count (*) from USER");
    QSqlQuery *query = new QSqlQuery;
    query->exec(str);
    qint32 user_total=0;
    if(query->first())
    {
        user_total = query->value(0).toInt();
        qDebug()<< "user_total from database :" <<user_total;
    }
    DB.close();
    ui->user_total->setText(QString("%1").arg(user_total));
    model = new QSqlRelationalTableModel(ui->database);
    //set table
    model->setTable("USER");
    //select data
    model->select();
    //set model
    ui->database->setModel(model);
    //set column 5 's width to 200
    ui->database->setColumnWidth(model->fieldIndex("USER"), 150);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showConnection()
{
    user_count++;

    /* add socket object that join in */
    ui->objectBox->addItem(QString("%1").arg(user_server->socketList.last()));
    /* change connect number while connection is connecting */
    ui->num->setText(QString("%1").arg(user_count));
}

void Dialog::showDisconnection(int socketDescriptor)
{
    user_count--;

    /* remove disconnect socketdescriptor from list */
    user_server->socketList.removeAll(socketDescriptor);

    /* reload combobox */
    ui->objectBox->clear();

    for (int i = 0; i < user_server->socketList.size(); i++)
    {
         ui->objectBox->addItem(QString("%1").arg(user_server->socketList.at(i)));
    }

    //change connect number while connection is disconnecting
    ui->num->setText(QString("%1").arg(user_count));

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
        return ;
    }

    msg = QString::fromLocal8Bit(data);
    ui->msg->append(msg);
    //cut the recieve msg......................................
    QStringList list=msg.split("#");
    QString return_msg=list[0];
    bool ret = 0;
    if(list[0]=="regist"){
        ret = checkSignUp(list[1],list[2]);      //注册
        if(ret){
            return_msg+="#true";
            qDebug() << return_msg;
        }
        else{
            return_msg+="#false";
            qDebug() << return_msg;
        }
        emit sendData(return_msg.toLocal8Bit(), ui->objectBox->currentText().toInt());
    }
    else if(list[0]=="login"){  //登录
        ret = checkSignIn(list[1],list[2]);
        if(ret){
            return_msg+="#true";
            qDebug() << return_msg;
        }
        else{
            return_msg+="#false";
            qDebug() << return_msg;
        }
        emit sendData(return_msg.toLocal8Bit(), ui->objectBox->currentText().toInt());
    }
    else if(list[0]=="location"){  //获取单车信息
        ret = getBikeLocation();
        if(!ret){
            return_msg+="#false";
            qDebug() << return_msg;
            emit sendData(return_msg.toLocal8Bit(), ui->objectBox->currentText().toInt());
        }
    }
    else if(list[0]=="unlock"){
        ret = askBikeUnlock(list[1]);
        if(ret){
            return_msg+="#true";
            qDebug() << return_msg;
        }
        else{
            return_msg+="#false";
            qDebug() << return_msg;
        }
        emit sendData(return_msg.toLocal8Bit(), ui->objectBox->currentText().toInt());
    }
    else
        return;

    //......................................................................................

    peerAddr.insert(peerAddr.size(), ": ");
    stringToHtmlFilter(peerAddr);
    stringToHtml(peerAddr, QColor(255, 0, 0));

    msg.prepend(peerAddr);   
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

bool Dialog::checkSignUp(QString name, QString passward)
{
    sqlite_operation *mysql = new sqlite_operation();
    bool ret = mysql->signup(name,passward);
    if(ret){
        QSqlDatabase DB;
        DB = QSqlDatabase::addDatabase("QSQLITE");
        DB.setDatabaseName("../../BIKE.db");
        DB.open();
        QString str=QString("select count (*) from USER");
        QSqlQuery *query = new QSqlQuery;
        query->exec(str);
        qint32 user_total = 0;
        if(query->first())
        {
            user_total = query->value(0).toInt();
            qDebug()<< "user_total from database :" <<user_total;
        }
        DB.close();
        ui->user_total->setText(QString("%1").arg(user_total));
    }

    return ret;
}

int Dialog::getBikeLocation()
{
    QString return_msg = "&marker=";
    QSqlDatabase DB;
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    DB.open();
    QString str=QString("select BIKE_localtion from BIKE");
    QSqlQuery *query = new QSqlQuery;
    query->exec(str);
    QString local;
    while(query->next())
    {   
        local+= query->value(0).toString();
        local+="|";
    }
    if(!query->first())
        return_msg+="false";

    DB.close();
    return_msg+=local;
        qDebug() << return_msg;
    emit sendData(return_msg.toLocal8Bit(), ui->objectBox->currentText().toInt());
        return 1;
}

int Dialog::askBikeUnlock(QString IP)
{
    qDebug()<<IP;
    QString str;
    QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    if(!DB.open())
        qDebug() << "loguser:open database error";
    QSqlQuery *sql_query=new QSqlQuery;
    str  =QString("select * from BIKE where IP_Addr='%1' and STATUS='0'").arg(IP);
    sql_query->exec(str);
    sql_query->last();
    int record=sql_query->at()+1;

    if(record==0){
        DB.close();
        return false;
    }
    else{
        QTcpSocket link_bike;
        QString msg_ok;
        link_bike.connectToHost(IP,6688);
        link_bike.write("U");
        link_bike.waitForReadyRead(5000);
        msg_ok = link_bike.readAll();
        if(msg_ok=="true"){
            qDebug()<<"接受到返回值"<<msg_ok;;
            str = QString("update BIKE set STATUS='1' where IP_Addr='%1'").arg(IP);
            sql_query->exec(str);
            DB.close();
            qDebug()<<"3";
            return true;
        }
        else{
            DB.close();
            return false;
        }
    }
}
