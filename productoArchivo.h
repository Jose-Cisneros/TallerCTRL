#ifndef PRODUCTOSAVE_H
#define PRODUCTOSAVE_H
#include "head.h"
#include "producto.h"

class ProductoArchivo
{
public:
    ProductoArchivo();


    void guardarProductos(QHash<QString,Producto> prod, QString archivo);
    void cargarProductos(QHash<QString,Producto> &prod, QString archivo);
};

#endif // PRODUCTOSAVE_H
