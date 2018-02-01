/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label0;
    QFrame *line;
    QFrame *line_2;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QLCDNumber *lcdDate_1;
    QLCDNumber *lcdTime_1;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(916, 542);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/none.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        label0 = new QLabel(Widget);
        label0->setObjectName(QStringLiteral("label0"));
        label0->setGeometry(QRect(5, 7, 358, 268));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush1(QColor(199, 237, 204, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        label0->setPalette(palette);
        line = new QFrame(Widget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(365, 0, 4, 541));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        line->setPalette(palette1);
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(4);
        line->setFrameShape(QFrame::VLine);
        line_2 = new QFrame(Widget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 278, 731, 4));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        line_2->setPalette(palette2);
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(4);
        line_2->setFrameShape(QFrame::HLine);
        label1 = new QLabel(Widget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(372, 7, 355, 268));
        label2 = new QLabel(Widget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(7, 285, 355, 250));
        label3 = new QLabel(Widget);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(372, 285, 355, 250));
        line_3 = new QFrame(Widget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(730, 0, 4, 541));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        line_3->setPalette(palette3);
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(4);
        line_3->setFrameShape(QFrame::VLine);
        line_4 = new QFrame(Widget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 0, 4, 541));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        line_4->setPalette(palette4);
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(4);
        line_4->setFrameShape(QFrame::VLine);
        line_5 = new QFrame(Widget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(-1, 0, 731, 4));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        line_5->setPalette(palette5);
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(4);
        line_5->setFrameShape(QFrame::HLine);
        line_6 = new QFrame(Widget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(0, 538, 731, 4));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        line_6->setPalette(palette6);
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setLineWidth(4);
        line_6->setFrameShape(QFrame::HLine);
        lcdDate_1 = new QLCDNumber(Widget);
        lcdDate_1->setObjectName(QStringLiteral("lcdDate_1"));
        lcdDate_1->setGeometry(QRect(760, 10, 141, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette7.setBrush(QPalette::Active, QPalette::Link, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Link, brush);
        QBrush brush4(QColor(51, 153, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Link, brush);
        lcdDate_1->setPalette(palette7);
        lcdTime_1 = new QLCDNumber(Widget);
        lcdTime_1->setObjectName(QStringLiteral("lcdTime_1"));
        lcdTime_1->setGeometry(QRect(740, 60, 161, 51));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette8.setBrush(QPalette::Active, QPalette::Link, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Link, brush);
        lcdTime_1->setPalette(palette8);
        label0->raise();
        line->raise();
        label1->raise();
        label2->raise();
        label3->raise();
        line_3->raise();
        line_4->raise();
        line_2->raise();
        line_5->raise();
        line_6->raise();
        lcdDate_1->raise();
        lcdTime_1->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label0->setText(QApplication::translate("Widget", "TextLabel", 0));
        label1->setText(QApplication::translate("Widget", "TextLabel", 0));
        label2->setText(QApplication::translate("Widget", "TextLabel", 0));
        label3->setText(QApplication::translate("Widget", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
