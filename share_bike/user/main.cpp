#include "dialog.h"
#include <QApplication>
#include "sqlite_operation.h"
#include "logindialog.h"
#include <QProcess>

int main(int argc, char *argv[])
{
    QProcess *p = new QProcess;
    p->start("C:/Users/yue/Desktop/share_bike/BK/bike_server/debug/sever_multithread.exe");
    QApplication a(argc, argv);
    sqlite_operation ms;
    Dialog w;
    ms.initsql();
    LoginDialog dlg;
    if (dlg.exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    } else {
        return 0;
    }

}
