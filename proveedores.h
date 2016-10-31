#ifndef PROVEEDORES_H
#define PROVEEDORES_H
#include <head.h>


class proveedores
{

public:

    int verTele2();
    int verTele();
    int verNro();
    QString verNom();
    QString verCorreo();
    QString verRS();

    proveedores(QString nom,int tele,int tele2,QString correo,int nroProv,QString razonS);


private:
    int telefono;
    int nroDeProv;
    int telefono2;
    QString nombre;
    QString email;
    QString razonSocial;



};

#endif // PROVEEDORES_H
