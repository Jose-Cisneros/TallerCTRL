#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <QObject>

class Empleado
{

public:

    int verDni();
    int verTel();
    int verNro();
    QString verDireccion();
    QString verNombre();
    QString verApellido();
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
