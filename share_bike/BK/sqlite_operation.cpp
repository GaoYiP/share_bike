#include "sqlite_operation.h"

sqlite_operation::sqlite_operation()
{
}

void sqlite_operation::initsql()
{
    //sql checking..............
    QSqlDatabase DB;
    qDebug() << "opening BIKEdatabase......."<<endl;
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    if(!DB.open())
        qDebug() << "open database error";

    //BIKE base checking.........
    QSqlQuery sql_query;
    QString create_sql = "create table if not exists BIKE(BIKE_localtion varchar(30) NOT NULL, IP_Addr varchar(30) UNIQUE NOT NULL, STATUS bool)";
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug()<<"Table BIKE Create failed";
        qDebug()<<sql_query.lastError();
        DB.close();
        return ;
    }
    sql_query.exec("create table password(pwd varchar primary key)");
    sql_query.exec("insert into password values('123456')");
//    else
//    {
//        qDebug()<<"Table BIKE be created early";
//    }

    DB.close();
}

bool sqlite_operation::loguser(QString ip, QString STATUS)
{
    QSqlDatabase DB;

    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    if(!DB.open())
        qDebug() << "logBIKE:open database error";
    QString str=QString("select * from BIKE where IP_Addr='%1' and STATUS='%2'").arg(ip).arg(STATUS);
    query=new QSqlQuery;
    query->exec(str);
    query->last();
    int record=query->at()+1;
    if(record==0)
        return false;
    else if(record<0){
        qDebug() << "error...................................................................................";
        qDebug() << str;
        qDebug() << record;
        return false;
    }
    else{
        qint32 TIMEs;
        if(query->first())
        {
            TIMEs = (query->value(4).toInt())+1;
            //qDebug()<< "TIMEs from database :" << TIMEs;
        }
        str.clear();
        query->clear();
        str = QString("update BIKE set STATUS='1' where IP_Addr='%1'").arg(STATUS);
        query->exec(str);
        DB.close();
        return true;
    }
}

bool sqlite_operation::signup(QString ip,QString STATUS)
{
    QSqlDatabase DB;

    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    if(DB.open())
//        qDebug() << "signup:open database success";
//    else
        qDebug() << "signup:open database error";
    QString str = QString("select * from BIKE where IP='%1").arg(ip);
    query=new QSqlQuery;
    query->exec(str);
    query->last();
    int record=query->at()+1;
    if(record!=0){
        return false;
    }
    str=QString("insert into BIKE values('0,0','%1','%2')").arg(ip).arg(STATUS);
    bool ret=query->exec(str);
                 qDebug() << ret;
    DB.close();
    return ret;
}
