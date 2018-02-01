/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sun Mar 30 16:35:16 2014
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDial>
#include <QFrame>
#include <QHeaderView>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

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
    QDial *dial;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLCDNumber *lcdDate_1;
    QLCDNumber *lcdTime_1;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(916, 542);
        QPalette palette;
        QBrush brush(QColor(0, 170, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        label0 = new QLabel(Widget);
        label0->setObjectName(QString::fromUtf8("label0"));
        label0->setGeometry(QRect(5, 7, 358, 268));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(199, 237, 204, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label0->setPalette(palette1);
        line = new QFrame(Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(365, 0, 4, 541));
        QPalette palette2;
        QBrush brush4(QColor(0, 0, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        line->setPalette(palette2);
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(4);
        line->setFrameShape(QFrame::VLine);
        line_2 = new QFrame(Widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 278, 731, 4));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        line_2->setPalette(palette3);
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(4);
        line_2->setFrameShape(QFrame::HLine);
        label1 = new QLabel(Widget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(372, 7, 355, 268));
        label2 = new QLabel(Widget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(7, 285, 355, 250));
        label3 = new QLabel(Widget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(372, 285, 355, 250));
        line_3 = new QFrame(Widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(730, 0, 4, 541));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        line_3->setPalette(palette4);
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(4);
        line_3->setFrameShape(QFrame::VLine);
        line_4 = new QFrame(Widget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 0, 4, 541));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        line_4->setPalette(palette5);
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(4);
        line_4->setFrameShape(QFrame::VLine);
        line_5 = new QFrame(Widget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(-1, 0, 731, 4));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        line_5->setPalette(palette6);
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(4);
        line_5->setFrameShape(QFrame::HLine);
        line_6 = new QFrame(Widget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(0, 538, 731, 4));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        line_6->setPalette(palette7);
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setLineWidth(4);
        line_6->setFrameShape(QFrame::HLine);
        dial = new QDial(Widget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(780, 210, 91, 91));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush);
        dial->setPalette(palette8);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(800, 470, 61, 16));
        QPalette palette9;
        QBrush brush5(QColor(0, 0, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        QBrush brush6(QColor(0, 170, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label_4->setPalette(palette9);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(780, 450, 101, 21));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label_3->setPalette(palette10);
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(780, 500, 111, 20));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label_5->setPalette(palette11);
        lcdDate_1 = new QLCDNumber(Widget);
        lcdDate_1->setObjectName(QString::fromUtf8("lcdDate_1"));
        lcdDate_1->setGeometry(QRect(760, 10, 141, 31));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Link, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Link, brush2);
        QBrush brush7(QColor(51, 153, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::Link, brush2);
        lcdDate_1->setPalette(palette12);
        lcdTime_1 = new QLCDNumber(Widget);
        lcdTime_1->setObjectName(QString::fromUtf8("lcdTime_1"));
        lcdTime_1->setGeometry(QRect(740, 60, 161, 51));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Link, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Link, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette13.setBrush(QPalette::Disabled, QPalette::Link, brush2);
        lcdTime_1->setPalette(palette13);
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
        dial->raise();
        label_4->raise();
        label_3->raise();
        label_5->raise();
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
