#include "marca.h"

Marca::Marca()
{

}

void Marca::agregar(QString &nuevo)
{
    autos.prepend(nuevo);
}

void Marca::eliminar(QString &car)
{
    int c = autos.indexOf(car);
    autos.removeAt(c);
}

QStringList Marca::getAutos()
{
    return autos;
}

void Marca::setAutos(const QStringList &value)
{
    autos = value;
}

QString Marca::getNom()
{
    return nom;
}

void Marca::setNom(const QString &value)
{
    nom = value;
}
