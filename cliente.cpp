#include<cliente.h>

Cliente::Cliente(QString nomb , QString ape, QString mail, int doc, int tele,int cui)

{
nombre = nomb;
apellido = ape;
correo = mail;
dni = doc;
nroTel = tele;
cuit = cui;

}

//ver

Cliente::verDni()
{
    return dni;
}

Cliente::verNro()
{
    return nroTel;

}
Cliente::verCuit()
{
return cuit;
}

QString Cliente::verApellido()
{
    return apellido;
}

QString Cliente::verNombre()
{
    return nombre;
}

QString Cliente::verCorreo()
{
    return correo;
}
