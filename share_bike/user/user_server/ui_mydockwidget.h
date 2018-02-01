/********************************************************************************
** Form generated from reading UI file 'mydockwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDOCKWIDGET_H
#define UI_MYDOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myDockWidget
{
public:
    QWidget *dockWidgetContents;
    QLabel *label;

    void setupUi(QDockWidget *myDockWidget)
    {
        if (myDockWidget->objectName().isEmpty())
            myDockWidget->setObjectName(QStringLiteral("myDockWidget"));
        myDockWidget->setEnabled(true);
        myDockWidget->resize(400, 300);
        myDockWidget->setAcceptDrops(true);
        myDockWidget->setFloating(true);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 381, 271));
        label->setAutoFillBackground(false);
        label->setScaledContents(true);
        myDockWidget->setWidget(dockWidgetContents);

        retranslateUi(myDockWidget);

        QMetaObject::connectSlotsByName(myDockWidget);
    } // setupUi

    void retranslateUi(QDockWidget *myDockWidget)
    {
        myDockWidget->setWindowTitle(QApplication::translate("myDockWidget", "DockWidget", 0));
        label->setText(QApplication::translate("myDockWidget", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class myDockWidget: public Ui_myDockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDOCKWIDGET_H
