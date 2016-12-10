#ifndef MARCA_H
#define MARCA_H
#include "head.h"


class Marca
{
public:
    Marca();
    QString nom;
    QStringList autos;



    void agregar(QString &nuevo);
    void eliminar(QString &car);


    QString getNom();
    void setNom(const QString &value);
    QStringList getAutos();
    void setAutos(const QStringList &value);
};

#endif // MARCA_H
