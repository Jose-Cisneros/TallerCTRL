#include "proveedor.h"
#include "head.h"

//Constructor  default (Para el QHash)//
Proveedor::Proveedor()
{
}

Proveedor::Proveedor(int nroProv,QString nom,QString razonS,QString correo,int tele,int tele2)
{
    razonSocial = razonS;
    nombre = nom;
    telefono2 = tele2;
    telefono = tele;
    nroDeProv = nroProv ;
    email = correo;
}


int Proveedor::verTele()const
{
    return telefono;
}

int Proveedor::verNro() const
{
    return nroDeProv;
}

QString Proveedor::verNom()const
{
    return nombre;
}

QString Proveedor::verCorreo()const
{
    return email;
}
QString Proveedor::verRS()const
{
    return razonSocial;
}

int Proveedor::verTele2()const
{
    return telefono2;
}

void Proveedor::modiNom(QString a)
{
   nombre=a;
}

void Proveedor::modiTel1(int a)
{
    telefono=a;
}

void Proveedor::modiTel2(int a)
{
    telefono2=a;
}
void Proveedor::modiNro(int a)
{
    nroDeProv=a;
}

void Proveedor::modiMail(QString a)
{
    email=a;
}

void Proveedor::modiRS(QString a)
{
    razonSocial=a;
}
