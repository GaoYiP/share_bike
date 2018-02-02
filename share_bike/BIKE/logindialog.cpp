#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    setFixedSize(400, 300);
    setWindowTitle(tr("login"));
    ui->pwdLineEdit->setFocus();
    ui->loginBtn->setDefault(true);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
//login
void LoginDialog::on_loginBtn_clicked()
{
//    qDebug()<< "(1)";
//    //sql checking..............

//    QSqlDatabase DB;
//    DB.addDatabase("QSQLITE");
//    qDebug()<< "(2)";
//    DB.setDatabaseName("../../BIKE.db");
//    if(!DB.open())
//        qDebug() << "open database error";
//    if (ui->pwdLineEdit->text().isEmpty()) {
//        QMessageBox::information(this, tr("please input password"),
//                                 tr("please input password"), QMessageBox::Ok);
//        ui->pwdLineEdit->setFocus();
//    } else {
//        QSqlQuery query;
//        query.exec("select pwd from password");
//        query.next();
//        if (query.value(0).toString() == ui->pwdLineEdit->text()) {
            QDialog::accept();
//        } else {
//            QMessageBox::warning(this, tr("error password"),
//                                 tr("please input password"), QMessageBox::Ok);
//            ui->pwdLineEdit->clear();
//            ui->pwdLineEdit->setFocus();
//        }

//    }
//    DB.close();

}

//quit
void LoginDialog::on_quitBtn_clicked()
{
    QDialog::reject();
}
