#ifndef PROVEEDORES_H
#define PROVEEDORES_H
#include <head.h>
#include <QDataStream>

class proveedores
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

    proveedores();
    proveedores(QString nom,int tele,int tele2,QString correo,int nroProv,QString razonS);


    //OPERADOR >> PARA GUARDAR CLASE EN ARCHIVO//

    friend QDataStream &operator <<(QDataStream &out, const proveedores &s)
        {
            out<< s.nombre << s.email << s.nroDeProv << s.razonSocial << s.telefono << s.telefono2;
            return out;
        }
    //OPERADOR << PARA CARGAR ARCHIVO//

    friend QDataStream &operator >> (QDataStream &in, proveedores &s)
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
