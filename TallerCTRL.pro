#-------------------------------------------------
#
# Project created by QtCreator 2016-10-30T22:16:12
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TallerCTRL
TEMPLATE = app


SOURCES += main.cpp\
        taller.cpp \
    cliente.cpp \
    empleado.cpp \
    guiempleado.cpp \
    guiempleado_nuevo.cpp \
    guiproveedores.cpp \
    guiprov_nuevo.cpp \
    producto.cpp \
    guiproducto.cpp \
    guiprod_nuevo.cpp \
    marca.cpp \
    guiprod_nuevo_marca.cpp \
    guiprod_nuevo_modelo.cpp \
    empleadosave.cpp \
    productoArchivo.cpp \
    mmarchivo.cpp \
    proveedor.cpp \
    dbmanager.cpp \
    dbproveedor.cpp

HEADERS  += taller.h \
    cliente.h \
    empleado.h \
    head.h \
    guiempleado.h \
    guiempleado_nuevo.h \
    guiproveedores.h \
    guiprov_nuevo.h \
    producto.h \
    guiproducto.h \
    guiprod_nuevo.h \
    marca.h \
    guiprod_nuevo_marca.h \
    guiprod_nuevo_modelo.h \
    empleadosave.h \
    productoArchivo.h \
    mmarchivo.h \
    proveedor.h \
    dbmanager.h \
    dbproveedor.h

FORMS    += taller.ui \
    guiempleado.ui \
    guiempleado_nuevo.ui \
    guiproveedores.ui \
    guiprov_nuevo.ui \
    guiproducto.ui \
    guiprod_nuevo.ui \
    guiprod_nuevo_marca.ui \
    guiprod_nuevo_modelo.ui
