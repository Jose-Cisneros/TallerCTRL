#ifndef CLIENTE_H
#define CLIENTE_H
#include <head.h>
class Cliente
{
public:

    int verDni();
    int verTel();
    int verNro();
    int verCuit();
    QString verCorreo();
    QString verNombre();
    QString verApellido();
    Cliente(QString nomb , QString ape,QString mail, int doc, int tele,int cui);

private:
    int dni;
    int cuit;
    int nroTel;
    QString correo;
    QString nombre;
    QString apellido;

};

#endif // CLIENTE_H
