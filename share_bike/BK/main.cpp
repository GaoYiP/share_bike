#include "dialog.h"
#include <QApplication>
#include "sqlite_operation.h"
#include "logindialog.h"
#include <QProcess>
#include <widget.h>
#include <QIcon>

int main(int argc, char *argv[])
{
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
