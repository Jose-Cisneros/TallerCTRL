#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "head.h"


class Producto
{
public:

    //Constructor default//
    Producto();

    int getCategoria() const;
    void setCategoria(int value);

    double getDesc() const;
    void setDesc(double value);

    double getDescuento() const;
    void setDescuento(double value);

    QString getMarca() const;
    void setMarca(const QString &value);

    QString getModelo() const;
    void setModelo(const QString &value);

    int getNroPieza() const;
    void setNroPieza(int value);

    double getPorcentajeSumado() const;
    void setPorcentajeSumado(double value);

    QString getProv() const;
    void setProv(const QString &value);

    double getPrecioCompra() const;
    void setPrecioCompra(double value);

    double getPrecioLista() const;
    void setPrecioLista(double value);

    double getPrecioVta() const;
    void setPrecioVta(double value);

    int getStock() const;
    void setStock(int value);

private:
    int categoria;
    double desc;
    double descuento;
    QString marca;
    QString modelo;
    int nroPieza;
    double porcentajeSumado;
    double precioCompra;
    double precioLista;
    double precioVta;
    QString Prov;
    int stock;

};


#endif // PRODUCTO_H
