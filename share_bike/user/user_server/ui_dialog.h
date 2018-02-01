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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QTextBrowser *msg;
    QTableView *database;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *sendMsg;
    QPushButton *sendBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *objectBox;
    QCheckBox *addrCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clearBtn;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *num;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *user_total;
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
        Dialog->setSizeGripEnabled(false);
        Dialog->setModal(false);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(13, 13, 761, 531));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        msg = new QTextBrowser(layoutWidget);
        msg->setObjectName(QStringLiteral("msg"));

        horizontalLayout_4->addWidget(msg);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        database = new QTableView(layoutWidget);
        database->setObjectName(QStringLiteral("database"));

        horizontalLayout_5->addWidget(database);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sendMsg = new QLineEdit(layoutWidget);
        sendMsg->setObjectName(QStringLiteral("sendMsg"));

        horizontalLayout_3->addWidget(sendMsg);

        sendBtn = new QPushButton(layoutWidget);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));

        horizontalLayout_3->addWidget(sendBtn);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        objectBox = new QComboBox(layoutWidget);
        objectBox->setObjectName(QStringLiteral("objectBox"));

        horizontalLayout_2->addWidget(objectBox);

        addrCheckBox = new QCheckBox(layoutWidget);
        addrCheckBox->setObjectName(QStringLiteral("addrCheckBox"));

        horizontalLayout_2->addWidget(addrCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        clearBtn = new QPushButton(layoutWidget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));

        horizontalLayout_2->addWidget(clearBtn);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        num = new QLabel(layoutWidget);
        num->setObjectName(QStringLiteral("num"));

        horizontalLayout->addWidget(num);

        horizontalSpacer = new QSpacerItem(13, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        user_total = new QLabel(layoutWidget);
        user_total->setObjectName(QStringLiteral("user_total"));

        horizontalLayout->addWidget(user_total);

        horizontalSpacer_3 = new QSpacerItem(13, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "USER\346\234\215\345\212\241\345\231\250", 0));
        sendMsg->setText(QString());
        sendBtn->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201", 0));
        label_2->setText(QApplication::translate("Dialog", "\345\217\221\351\200\201\345\257\271\350\261\241  \357\274\232", 0));
        addrCheckBox->setText(QApplication::translate("Dialog", "\344\270\215\346\230\276\347\244\272\345\256\242\346\210\267\347\253\257\345\234\260\345\235\200   ", 0));
        clearBtn->setText(QApplication::translate("Dialog", "\346\270\205\347\251\272\346\216\245\346\224\266", 0));
        label->setText(QApplication::translate("Dialog", "\345\275\223\345\211\215\347\224\250\346\210\267\350\277\236\346\216\245\346\225\260\357\274\232", 0));
        num->setText(QString());
        label_3->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\346\200\273\346\225\260:", 0));
        user_total->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
