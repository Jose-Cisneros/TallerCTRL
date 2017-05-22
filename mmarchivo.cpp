#include "mmarchivo.h"


MMArchivo::MMArchivo()
{    
}

void MMArchivo::cargarMM(QHash<QString, QString> &autos, QString archivo)
{
    QFile file(archivo);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QDataStream in(&file);
    in >> autos;
    file.close();

}

void MMArchivo::guardarMM(QHash<QString, QString> &autos, QString archivo)
{
    QFile file(archivo);
    if (!file.open(QIODevice::WriteOnly))
        return;
    QDataStream out(&file);
    out << autos;
    file.close();
}
