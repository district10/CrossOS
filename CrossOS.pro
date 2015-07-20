#-------------------------------------------------
#
# Project created by QtCreator 2015-07-10T15:06:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CrossOS
TEMPLATE = app


SOURCES += main.cpp\
    server.cpp \
    client.cpp \
    clientagent.cpp \
    serveragent.cpp \
    moderator.cpp

HEADERS  += \
    client.h \
    server.h \
    clientagent.h \
    serveragent.h \
    moderator.h

FORMS    += \
    clientagent.ui \
    serveragent.ui
