#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include <head.h>
#include <QDataStream>

class Proveedor
{

public:
    //ver//
    int verTele2()const;
    int verTele()const;
    int verNro() const;
    QString verNom() const;
    QString verCorreo() const;
    QString verRS() const;

    //modificar//
    void modiNom(QString a);
    void modiTel1(int a);
    void modiTel2(int a);
    void modiNro(int a);
    void modiMail(QString a);
    void modiRS(QString a);

    //constructores//

    Proveedor();
    Proveedor(int nroProv, QString nom,QString razonS, QString correo, int tele,int tele2);


    //OPERADOR << PARA GUARDAR CLASE EN ARCHIVO//

    friend QDataStream &operator <<(QDataStream &out, const Proveedor &s)
        {
            out<< s.nombre << s.email << s.nroDeProv << s.razonSocial << s.telefono << s.telefono2;
            return out;
        }
    //OPERADOR >> PARA CARGAR ARCHIVO//

    friend QDataStream &operator >> (QDataStream &in, Proveedor &s)
        {
            in>> s.nombre >> s.email >> s.nroDeProv >> s.razonSocial >> s.telefono >> s.telefono2;
            return in;
        }




private:
    int telefono;
    int nroDeProv;
    int telefono2;
    QString nombre;
    QString email;
    QString razonSocial;



};

#endif // PROVEEDORES_H
