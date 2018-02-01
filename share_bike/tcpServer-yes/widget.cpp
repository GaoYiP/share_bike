#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/../icon/none.ico"));
    trayIcon->setToolTip(tr("视频监控"));

    QString titlec=tr("视频监控");
    QString textc=tr("视频监控正在运行...");
    trayIcon->setVisible(true);
    trayIcon->showMessage(titlec,textc,QSystemTrayIcon::Information,5000);

    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,SLOT(trayiconActivated(QSystemTrayIcon::ActivationReason)));
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

    ui->setupUi(this);

    screenNo[0] = 0;
    screenNo[1] = 0;
    screenNo[2] = 0;
    screenNo[3] = 0;

    this->ui->label0->setScaledContents(true);
    this->ui->label1->setScaledContents(true);
    this->ui->label2->setScaledContents(true);
    this->ui->label3->setScaledContents(true);

    ui->lcdDate_1->setStyleSheet("color:rgb(0, 120, 230); background:transparent;");
    ui->lcdTime_1->setStyleSheet("color:rgb(0, 120, 230); background:transparent;");

    ui->lcdDate_1->setDigitCount(10);
    ui->lcdTime_1->setDigitCount(8);
    QTime t;
    QString Time=t.currentTime().toString("hh:mm:ss");
    ui->lcdTime_1->display(Time);

    QTimer *t1=new QTimer;
    connect(t1,SIGNAL(timeout()),SLOT(showTime()));
    t1->start(1000);

    QDateTime dateTime;
    QString Date=dateTime.currentDateTime().toString("yyyy-MM-dd");
    ui->lcdDate_1->display(Date);

    setStyleSheet("background-color:black");
    ui->label_3->setStyleSheet("background-color:rgb(204, 204, 204)");
    ui->label_4->setStyleSheet("background-color:rgb(204, 204, 204)");
    ui->label_5->setStyleSheet("background-color:rgb(204, 204, 204)");
    this->ui->dial->setStyleSheet ("background-color:blue");

    tcpServer.listen(QHostAddress::Any, 6666);

    connect(&tcpServer, SIGNAL(newConnection()),this, SLOT(acceptConnection()));
}


Widget::~Widget()
{
    delete ui;
}

void Widget::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->x() < (this->width ()/2) && e->y() < (this->height ()/2))
    {
        labelWidth = this->ui->label0->width ();
        labelHeight = this->ui->label0->height ();
        labelX = this->ui->label0->x ();
        labelY = this->ui->label0->y ();
        this->ui->label0->raise();
        this->ui->label0->setGeometry(4, 4, 726, 536);
    }
    if(e->x() > (this->width ()/2) && e->y() < (this->height ()/2))
    {
        labelWidth = this->ui->label1->width ();
        labelHeight = this->ui->label1->height ();
        labelX = this->ui->label1->x ();
        labelY = this->ui->label1->y ();
        this->ui->label1->raise();
        this->ui->label1->setGeometry(4, 4, 726, 536);
    }
    if(e->x() < (this->width ()/2) && e->y() > (this->height ()/2))
    {
        labelWidth = this->ui->label2->width ();
        labelHeight = this->ui->label2->height ();
        labelX = this->ui->label2->x ();
        labelY = this->ui->label2->y ();
        this->ui->label2->raise();
        this->ui->label2->setGeometry(4, 4, 726, 536);
    }
    if(e->x() > (this->width ()/2) && e->y() > (this->height ()/2))
    {
        labelWidth = this->ui->label3->width ();
        labelHeight = this->ui->label3->height ();
        labelX = this->ui->label3->x ();
        labelY = this->ui->label3->y ();
        this->ui->label3->raise();
        this->ui->label3->setGeometry(4, 4, 726, 536);
    }
}


void Widget::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
        case Qt::Key_Escape:
            this->ui->label0->setGeometry(labelX, labelY, labelWidth, labelHeight);
            this->ui->label1->setGeometry(labelX, labelY, labelWidth, labelHeight);
            this->ui->label2->setGeometry(labelX, labelY, labelWidth, labelHeight);
            this->ui->label3->setGeometry(labelX, labelY, labelWidth, labelHeight);
        break;
    }
}

void Widget::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    MyThread *thread = new MyThread(tcpServerConnection,this);
    qDebug()<<"new connect";
    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));    
    connect(thread,SIGNAL(bytesArrived(QByteArray)),this,SLOT(showImg(QByteArray)));
    thread->run ();

}

void Widget::showImg(QByteArray data)
{
    qDebug()<<"showImg---"<<data.size();
    QPixmap pix;
    pix.loadFromData(data,"jpeg");
    ui->label0->setPixmap(pix);
}

void Widget::showTime()
{
    QTime t;
    QString Time=t.currentTime().toString("hh:mm:ss");
    ui->lcdTime_1->display(Time);
}    

void Widget::closeEvent(QCloseEvent *e)
{
    e->ignore();
    this->hide();
    if(flag==false)
    {
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(QIcon(":/../icon/none.ico"));
        trayIcon->setToolTip(tr("视频监控"));

        QString titlec=tr("视频监控");
        QString textc=tr("视频监控正在运行...");
        trayIcon->setVisible(true);
        trayIcon->showMessage(titlec,textc,QSystemTrayIcon::Information,5000);

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
