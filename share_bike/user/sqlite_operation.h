#ifndef SQLITE_OPERATION_H
#define SQLITE_OPERATION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class sqlite_operation : public QObject
{
    Q_OBJECT
public:
    explicit sqlite_operation();  
    void initsql();
    bool loguser(QString name,QString passward);
    bool signup(QString name,QString passward);

private:
    QSqlQuery *query;
};

#endif // SQLITE_OPERATION_H
