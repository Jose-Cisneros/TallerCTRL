#ifndef DBPROVEEDOR_H
#define DBPROVEEDOR_H
#include "head.h"


class DBProveedor
{
public:
    DBProveedor();
    void agregar(Proveedor prov);
    QList<QString> listarProveedores();
    Proveedor datosProv(QString nom);


};

#endif // DBPROVEEDOR_H
