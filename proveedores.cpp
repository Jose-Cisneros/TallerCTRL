#include "proveedores.h"
#include "head.h"

//Constructor  default (Para el QHash)//
proveedores::proveedores()
{
}

proveedores::proveedores(QString nom,int tele,int tele2,QString correo,int nroProv,QString razonS)

{
    razonSocial = razonS;
    nombre = nom;
    telefono2 = tele2;
    telefono = tele;
    nroDeProv = nroProv ;
    email = correo;

}


int proveedores::verTele()const
{
    return telefono;
}

int proveedores::verNro() const
{
    return nroDeProv;
}

QString proveedores::verNom()const
{
    return nombre;
}

QString proveedores::verCorreo()const
{
    return email;
}
QString proveedores::verRS()const
{
    return razonSocial;
}

int proveedores::verTele2()const
{
    return telefono2;
}

void proveedores::modiNom(QString a)
{
   nombre=a;
}

void proveedores::modiTel1(int a)
{
    telefono=a;
}

void proveedores::modiTel2(int a)
{
    telefono2=a;
}
void proveedores::modiNro(int a)
{
    nroDeProv=a;
}

void proveedores::modiMail(QString a)
{
    email=a;
}

void proveedores::modiRS(QString a)
{
    razonSocial=a;
}
