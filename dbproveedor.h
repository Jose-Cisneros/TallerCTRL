#ifndef DBPROVEEDOR_H
#define DBPROVEEDOR_H
#include "head.h"


class DBProveedor
{
public:
    DBProveedor();
    void agregar(Proveedor prov);
    void listarProveedores(QList<QString> &lp);
    Proveedor datosProv(QString nom);


};

#endif // DBPROVEEDOR_H
