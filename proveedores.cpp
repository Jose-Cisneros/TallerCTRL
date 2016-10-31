#include "proveedores.h"

proveedores::Proveedores(QString nom,int tele,int tele2,QString correo,int nroProv,QString razonS)

{
razonSocial = razonS;
 nombre = nom;
telefono2 = tele2;
 telefono = telefono;
 nroDeProv = nroProv ;
 email = correo;

}

proveedores::verTele()
{
    return telefono;
}

proveedores::verNro()
{
    return nroDeProv;
}

QString proveedores::verNom()
{
    return nombre;
}

QString proveedores::verCorreo()
{
    return email;
}
QString proveedores::verRS()
{
    return razonSocial;
}

proveedores::verTele2()
{
    return telefono2;
}
