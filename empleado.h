#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <head.h>


class Empleado
{

public:

    int verDoc();
    int verTele();
    int verNroE();
    QString verDireccion();
    QString verNom();
    QString verApe();
    Empleado(QString nom, QString apellido,QString direccion, int dni, int telefono,int nroDeEmpleado);


private:
    int dni;
    int telefono;
    int nroDeEmpleado;
    QString direccion;
    QString nombre;
    QString apellido;

};

#endif // EMPLEADO_H
