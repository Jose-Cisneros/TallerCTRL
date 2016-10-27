#ifndef CLIENTE_H
#define CLIENTE_H
#include <head.h>

class Cliente
{
public:

    int verDni();
    int verTel();
    int verNro();
    QString verDireccion();
    QString verNombre();
    QString verApellido();
 //   Empleado(QString nom , QString apellido,QString direccion, int dni, int telefono,int nroDeEmpleado);


private:
    int dni;
    int cuit;
    int nroDeEmpleado;
    QString correo;
    QString nombre;
    QString apellido;

};

#endif // CLIENTE_H
