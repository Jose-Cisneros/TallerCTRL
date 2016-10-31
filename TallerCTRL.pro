#-------------------------------------------------
#
# Project created by QtCreator 2016-10-30T22:16:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TallerCTRL
TEMPLATE = app


SOURCES += main.cpp\
        taller.cpp \
    cliente.cpp \
    empleado.cpp \
    guiempleado.cpp

HEADERS  += taller.h \
    cliente.h \
    empleado.h \
    head.h \
    guiempleado.h

FORMS    += taller.ui \
    guiempleado.ui
