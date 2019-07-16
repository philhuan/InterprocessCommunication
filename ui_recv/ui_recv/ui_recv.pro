#-------------------------------------------------
#
# Project created by QtCreator 2019-06-30T20:47:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ui_recv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mythread.cpp \
    task.cpp \
    msgrecivetask.cpp \
    ShdMemSendTask.cpp \
    piperecievetask.cpp \
    SocketRecvTask.cpp \
    param.cpp

HEADERS  += mainwindow.h \
    mythread.h \
    task.h \
    msgrecivetask.h \
    head.h \
    ShdMemSendTask.h \
    piperecievetask.h \
    SocketRecvTask.h \
    param.h

FORMS    += mainwindow.ui





unix:!macx: LIBS += -L$$PWD/../../os/cmake-build-debug/ -los

INCLUDEPATH += $$PWD/../../os
DEPENDPATH += $$PWD/../../os

unix:!macx: PRE_TARGETDEPS += $$PWD/../../os/cmake-build-debug/libos.a
