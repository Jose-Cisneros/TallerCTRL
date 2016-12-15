#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "head.h"


class Producto
{
public:

    //Constructor default//
    Producto();

    QString getCategoria() const;
    void setCategoria(QString value);

    QString getDesc() const;
    void setDesc(QString value);

    int getDescuento() const;
    void setDescuento(int value);

    QString getMarca() const;
    void setMarca(const QString &value);

    QString getModelo() const;
    void setModelo(const QString &value);

    QString getNroPieza() const;
    void setNroPieza(QString value);

    QString getPorcentajeSumado() const;
    void setPorcentajeSumado(QString value);

    QString getProv() const;
    void setProv(const QString &value);

    QString getPrecioCompra() const;
    void setPrecioCompra(QString value);

    QString getPrecioLista() const;
    void setPrecioLista(QString value);

    QString getPrecioVta() const;
    void setPrecioVta(QString value);

    int getStock() const;
    void setStock(int value);

    QString getNom() const;
    void setNom(const QString &value);


    //OPERADOR >> PARA GUARDAR CLASE EN ARCHIVO//

    friend QDataStream &operator <<(QDataStream &out, const Producto &s)
        {
            out<< s.nroPieza << s.nom << s.marca << s.modelo << s.categoria << s.stock << s.precioCompra << s.precioLista << s.precioVta << s.descuento << s.Prov <<s.porcentajeSumado;
            return out;
        }
    //OPERADOR << PARA CARGAR ARCHIVO//

    friend QDataStream &operator >> (QDataStream &in, Producto &s)
        {
            in>> s.nroPieza >> s.nom >> s.marca >> s.modelo >> s.categoria >> s.stock >> s.precioCompra >> s.precioLista >> s.precioVta >> s.descuento >> s.Prov >> s.porcentajeSumado;
            return in;
        }


private:
    QString categoria;
    QString desc;
    int descuento;
    QString marca;
    QString modelo;
    QString nroPieza;
    QString porcentajeSumado;
    QString precioCompra;
    QString precioLista;
    QString precioVta;
    QString Prov;
    int stock;
    QString nom;

};


#endif // PRODUCTO_H
