#-------------------------------------------------
#
# Project created by QtCreator 2016-03-07T20:38:29
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sever_multithread
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    serverthread.cpp \
    server.cpp \
    mysocket.cpp \
    sqlite_operation.cpp \
    logindialog.cpp \
    mythread.cpp \
    widget.cpp

HEADERS  += dialog.h \
    serverthread.h \
    server.h \
    mysocket.h \
    sqlite_operation.h \
    logindialog.h \
    mythread.h \
    widget.h

FORMS    += dialog.ui \
    logindialog.ui \
    widget.ui

RESOURCES += \
    tubiao.qrc

DISTFILES += \
    README.md
