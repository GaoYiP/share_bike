#include "sqlite_operation.h"

sqlite_operation::sqlite_operation()
{
}

bool sqlite_operation::up_bike_status(QString IP)
{
    QSqlDatabase DB;
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    if(!DB.open()){
        qDebug() << "logBIKE:open database error";
        return false;
    }
    query=new QSqlQuery;
    QString str = QString("update BIKE set STATUS='1' where IP_Addr='%1'").arg(IP);
    query->exec(str);
    DB.close();
    return true;
}

int sqlite_operation::up_bike_mark(QString ip,QString mark)
{
    QSqlDatabase DB;
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("../../BIKE.db");
    if(DB.open())
        qDebug() << "signup:open database error";
    QString str = QString("select * from BIKE where IP='%1").arg(ip);
    query=new QSqlQuery;
    query->exec(str);
    query->last();
    int record=query->at()+1;
    if(record!=0){
        str = QString("update BIKE set BIKE_localtion='%1' where IP_Addr='%2'").arg(mark).arg(ip);
        query->exec(str);
        DB.close();
        return 0;
    }
    else{
        str = QString("insert into BIKE values('%1','%2','0')").arg(mark).arg(ip);
        query->exec(str);
        DB.close();
        return 1;
    }
}
