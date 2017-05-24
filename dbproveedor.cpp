#include "dbproveedor.h"

DBProveedor::DBProveedor()
{

}

void DBProveedor::agregar(Proveedor prov)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Proveedores VALUES (:nro,:nom,:rs,:mail,:tel1,:tel2) ");
    query.bindValue(":nro",prov.verNro() );
    query.bindValue(":nom",prov.verNom() );
    query.bindValue(":rs",prov.verRS() );
    query.bindValue(":mail",prov.verCorreo());
    query.bindValue(":tel1",prov.verTele());
    query.bindValue(":tel2",prov.verTele2());
    query.exec();




}

void DBProveedor::listarProveedores(QList<QString> &lp)
{

    QSqlQuery query;
    query.prepare("SELECT nom FROM Proveedores");
    if (query.exec()){

        while (query.next()){

            lp << query.value(0).toString();

        }

    } else {
        qDebug() << "No hay proveedores en la base de datos";
    }

}

Proveedor DBProveedor::datosProv(QString nom)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Proveedores WHERE nom = :nom");
    query.bindValue(":nom", nom);
    query.exec();
    query.first();

    Proveedor a(query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString(),
                query.value(4).toInt(),
                query.value(5).toInt());

    return a;


}
