/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QTextBrowser *msg;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QCheckBox *show_cam;
    QTableView *database;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *sendMsg;
    QPushButton *sendBtn;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *objectBox;
    QCheckBox *addrCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clearBtn;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *num;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *bike_total;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(785, 551);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/tray.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setSizeGripEnabled(false);
        Dialog->setModal(false);
        splitter = new QSplitter(Dialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(14, 15, 761, 521));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        msg = new QTextBrowser(layoutWidget);
        msg->setObjectName(QStringLiteral("msg"));

        horizontalLayout_4->addWidget(msg);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        show_cam = new QCheckBox(layoutWidget);
        show_cam->setObjectName(QStringLiteral("show_cam"));
        show_cam->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/none.ico"), QSize(), QIcon::Normal, QIcon::Off);
        show_cam->setIcon(icon1);
        show_cam->setCheckable(true);
        show_cam->setChecked(false);

        verticalLayout->addWidget(show_cam);


        horizontalLayout_5->addLayout(verticalLayout);

        database = new QTableView(layoutWidget);
        database->setObjectName(QStringLiteral("database"));

        horizontalLayout_5->addWidget(database);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sendMsg = new QLineEdit(layoutWidget1);
        sendMsg->setObjectName(QStringLiteral("sendMsg"));

        horizontalLayout_3->addWidget(sendMsg);

        sendBtn = new QPushButton(layoutWidget1);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));

        horizontalLayout_3->addWidget(sendBtn);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        objectBox = new QComboBox(layoutWidget2);
        objectBox->setObjectName(QStringLiteral("objectBox"));

        horizontalLayout_2->addWidget(objectBox);

        addrCheckBox = new QCheckBox(layoutWidget2);
        addrCheckBox->setObjectName(QStringLiteral("addrCheckBox"));

        horizontalLayout_2->addWidget(addrCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        clearBtn = new QPushButton(layoutWidget2);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));

        horizontalLayout_2->addWidget(clearBtn);

        splitter->addWidget(layoutWidget2);
        layoutWidget3 = new QWidget(splitter);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        num = new QLabel(layoutWidget3);
        num->setObjectName(QStringLiteral("num"));

        horizontalLayout->addWidget(num);

        horizontalSpacer = new QSpacerItem(13, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        bike_total = new QLabel(layoutWidget3);
        bike_total->setObjectName(QStringLiteral("bike_total"));

        horizontalLayout->addWidget(bike_total);

        horizontalSpacer_3 = new QSpacerItem(13, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        splitter->addWidget(layoutWidget3);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "BIKE\346\234\215\345\212\241\345\231\250", 0));
        pushButton->setText(QApplication::translate("Dialog", "\350\247\243\351\224\201", 0));
        pushButton_2->setText(QApplication::translate("Dialog", "\350\216\267\345\217\226\344\275\215\347\275\256", 0));
        pushButton_3->setText(QApplication::translate("Dialog", "\351\224\201\345\256\232", 0));
        show_cam->setText(QApplication::translate("Dialog", "\345\233\276\345\203\217", 0));
        sendMsg->setText(QString());
        sendBtn->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201", 0));
        label_2->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201\345\257\271\350\261\241  \357\274\232", 0));
        addrCheckBox->setText(QApplication::translate("Dialog", "\344\270\215\346\230\276\347\244\272\345\256\242\346\210\267\347\253\257\345\234\260\345\235\200   ", 0));
        clearBtn->setText(QApplication::translate("Dialog", "\346\270\205\347\251\272\346\216\245\346\224\266", 0));
        label->setText(QApplication::translate("Dialog", "\345\275\223\345\211\215\347\251\272\351\227\262\350\207\252\350\241\214\350\275\246\346\225\260\357\274\232", 0));
        num->setText(QString());
        label_3->setText(QApplication::translate("Dialog", "\350\207\252\350\241\214\350\275\246\346\200\273\346\225\260\346\200\273\346\225\260:", 0));
        bike_total->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
