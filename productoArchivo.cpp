#include "productoArchivo.h"
#include "QDebug"
ProductoArchivo::ProductoArchivo()
{


}

void ProductoArchivo::guardarProductos(QHash<QString, Producto> prod, QString archivo)
{

    QFile file(archivo);
    if (!file.open(QIODevice::WriteOnly))
        return;
    QDataStream out(&file);
    out << prod;
    file.close();


}

void ProductoArchivo::cargarProductos(QHash<QString, Producto> &prod, QString archivo)
{

    QFile file(archivo);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QDataStream in(&file);

    in >> prod;
    file.close();

}
