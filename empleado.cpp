#include <empleado.h>

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

Empleado::verDoc()
{
    return dni;
}

QString Empleado::verNom()
{
    return nombre;
}

Empleado::verNroE()
{
    return nroDeEmpleado;
}

Empleado::verTele()
{
    return telefono;
}

QString Empleado::verApe()
{
    return apellido;
}

//fin ver
