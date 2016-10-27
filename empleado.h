#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <QObject>


class Empleado
{

public:

    Qint verDni();
    Qint verTel();
    Qint verNro();
    QString verDireccion();
    QString verNombre();
    QString verApellido();
    Empleado(QString nom, QString apellido,QString direccion, Qint dni, Qint telefono,Qint nroDeEmpleado);


private:
    Qint dni;
    Qint telefono;
    Qint nroDeEmpleado;
    QString direccion;
    QString nombre;
    QString apellido;

};

#endif // EMPLEADO_H