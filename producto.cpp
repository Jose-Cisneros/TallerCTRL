#include "producto.h"

Producto::Producto()
{
}


QString Producto::getCategoria() const
{
    return categoria;
}

void Producto::setCategoria(QString value)
{
    categoria = value;
}

QString Producto::getDesc() const
{
    return desc;
}

void Producto::setDesc(QString value)
{
    desc = value;
}

int Producto::getDescuento() const
{
    return descuento;
}

void Producto::setDescuento(int value)
{
    descuento = value;
}

QString Producto::getMarca() const
{
    return marca;
}

void Producto::setMarca(const QString &value)
{
    marca = value;
}

QString Producto::getModelo() const
{
    return modelo;
}

void Producto::setModelo(const QString &value)
{
    modelo = value;
}

QString Producto::getNroPieza() const
{
    return nroPieza;
}

void Producto::setNroPieza(QString value)
{
    nroPieza = value;
}

QString Producto::getPorcentajeSumado() const
{
    return porcentajeSumado;
}

void Producto::setPorcentajeSumado(QString value)
{
    porcentajeSumado = value;
}

QString Producto::getProv() const
{
    return Prov;
}

void Producto::setProv(const QString &value)
{
    Prov = value;
}

QString Producto::getPrecioCompra() const
{
    return precioCompra;
}

void Producto::setPrecioCompra(QString value)
{
    precioCompra = value;
}

QString Producto::getPrecioLista() const
{
    return precioLista;
}

void Producto::setPrecioLista(QString value)
{
    precioLista = value;
}

QString Producto::getPrecioVta() const
{
    return precioVta;
}

void Producto::setPrecioVta(QString value)
{
    precioVta = value;
}

int Producto::getStock() const
{
    return stock;
}

void Producto::setStock(int value)
{
    stock = value;
}

QString Producto::getNom() const
{
    return nom;
}

void Producto::setNom(const QString &value)
{
    nom = value;
}
