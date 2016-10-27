#include "empleado.h"

Empleado::Empleado(QString nomb, QString apell,QString direc, int nrodni, int tel, int nroEmp) //constructor
{
nombre = nomb;
apellido = apell;
direccion = direc;
dni = nrodni;
telefono = tel;
nroDeEmpleado = nroEmp;
}

//ver

QString Empleado::verDireccion()
{
       return direccion;
}

Empleado::verDni()
{
    return dni;
}

QString Empleado::verNombre()
{
    return nombre;
}

Empleado::verNro()
{
    return nroDeEmpleado;
}

Empleado::verTel()
{
    return telefono;
}

QString Empleado::verApellido()
{
    return apellido;
}

//fin ver
