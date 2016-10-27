QT += core
QT -= gui

CONFIG += c++11

TARGET = TallerCTRL
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    empleado.cpp \
    cliente.cpp

HEADERS += \
    head.h \
    empleado.h \
    cliente.h
