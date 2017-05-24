#include "dbproveedor.h"

DBProveedor::DBProveedor()
{

}

void DBProveedor::agregar(Proveedor prov)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Proveedores VALUES :nro,:nom,:rs,:mail,:tel1,:tel2 ");
    query.bindValue(":nro",prov.verNro() );
    query.bindValue(":nom",prov.verNom() );
    query.bindValue(":rs",prov.verRS() );
    query.bindValue(":mail",prov.verCorreo());
    query.bindValue(":tel1",prov.verTele());
    query.bindValue(":tel2",prov.verTele2());


}

QList<QString> DBProveedor::listarProveedores()
{
    QList<QString> aux;

    QSqlQuery query;
    query.prepare("SELECT nom FROM Proveedores");
    if (query.exec()){

        while (query.next()){

            aux << query.value(0).toString();
        }

        return aux;
    } else {
        qDebug() << "No hay proveedores en la base de datos";
    }

}

Proveedor DBProveedor::datosProv(QString nom)
{

}
