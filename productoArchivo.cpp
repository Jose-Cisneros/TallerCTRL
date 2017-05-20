#include "productoArchivo.h"

ProductoArchivo::ProductoArchivo()
{


}

void ProductoArchivo::guardarProducto(QHash<QString, Producto> &prod, QString archivo)
{

    QFile file(archivo);
    if (!file.open(QIODevice::WriteOnly))
        return;
    QDataStream out(&file);
    out << prod;


}

void ProductoArchivo::cargarProducto(QHash<QString, Producto> &prod, QString archivo)
{

    QFile file(archivo);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QDataStream in(&file);

    in >> prod;
    file.close();

}
