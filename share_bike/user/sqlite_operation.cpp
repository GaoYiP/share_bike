#include "sqlite_operation.h"

sqlite_operation::sqlite_operation()
{
}

void sqlite_operation::initsql()
{
    //sql checking..............
    QSqlDatabase DB;
    qDebug() << "opening USERdatabase......."<<endl;
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    if(!DB.open())
        qDebug() << "open database error";

    //USER base checking.........
    QSqlQuery sql_query;
    QString create_sql = "create table if not exists USER(user_name varchar(30) UNIQUE NOT NULL, user_passwd int NOT NULL, IP_Addr varchar(30), FEE float, TIMEs int, online_s bool)";
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug()<<"Table USER Create failed";
        qDebug()<<sql_query.lastError();
        DB.close();
        return ;
    }
    sql_query.exec("create table password(pwd varchar primary key)");
    sql_query.exec("insert into password values('123456')");

    DB.close();
}

bool sqlite_operation::loguser(QString name, QString passward)
{
    QSqlDatabase DB;

    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    if(!DB.open())
        qDebug() << "loguser:open database error";
    QString str=QString("select * from USER where user_name='%1' and user_passwd='%2'").arg(name).arg(passward);
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
        qint32 TIMEs=0;
        if(query->first())
        {
            TIMEs = (query->value(4).toInt())+1;
            //qDebug()<< "TIMEs from database :" << TIMEs;
        }
        str.clear();
        query->clear();
        str = QString("update USER set TIMEs='%2' where user_name='%1'").arg(name).arg(TIMEs);
        query->exec(str);
        query->clear();
        str = QString("update USER set online_s='1' where user_name='%1'").arg(name);
        query->exec(str);
        DB.close();
        return true;
    }
}

bool sqlite_operation::signup(QString name,QString passward)
{
    QSqlDatabase DB;

    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    if(DB.open())
//        qDebug() << "signup:open database success";
//    else
        qDebug() << "signup:open database error";
    QString str = QString("select * from USER where user_name='%1").arg(name);
    query=new QSqlQuery;
    query->exec(str);
    query->last();
    int record=query->at()+1;
    if(record!=0){
        return false;
    }
    str=QString("insert into USER values('%1','%2','0','1','0','0');").arg(name).arg(passward);
    bool ret=query->exec(str);
                 qDebug() << ret;
    DB.close();
    return ret;
}
