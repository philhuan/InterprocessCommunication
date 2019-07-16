#-------------------------------------------------
#
# Project created by QtCreator 2019-06-29T17:21:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    task.cpp \
    msgsendtask.cpp \
    shdmemsendtask.cpp \
    PipeSendTask.cpp \
    SocketSendTask.cpp \
    param.cpp

HEADERS  += mainwindow.h \
    head.h \
    task.h \
    msgsendtask.h \
    shdmemsendtask.h \
    PipeSendTask.h \
    SocketSendTask.h \
    param.h

FORMS    += mainwindow.ui





unix:!macx: LIBS += -L$$PWD/../../os/cmake-build-debug/ -los

INCLUDEPATH += $$PWD/../../os
DEPENDPATH += $$PWD/../../os

unix:!macx: PRE_TARGETDEPS += $$PWD/../../os/cmake-build-debug/libos.a
