#ifndef SQLITE_OPERATION_H
#define SQLITE_OPERATION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class sqlite_operation:public QObject
{
    Q_OBJECT
public:
    explicit sqlite_operation();  
    bool up_bike_status(QString IP);
    int up_bike_mark(QString IP,QString mark);
private:
    QSqlQuery *query;
};

#endif // SQLITE_OPERATION_H
