#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{
public:

    Qint verDni();
    Qint verTel();
    Qint verNro();
    QString verDireccion();
    QString verNombre();
    QString verApellido();
    Empleado(QString nom, QString apellido,QString direccion, int dni, int telefono,int nroDeEmpleado);


private:
    Qint dni;
    Qint cuit;
    Qint nroDeEmpleado;
    QString correo;
    QString nombre;
    QString apellido;

};

#endif // CLIENTE_H
