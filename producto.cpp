#include "producto.h"

Producto::Producto()
{
}


int Producto::getCategoria() const
{
    return categoria;
}

void Producto::setCategoria(int value)
{
    categoria = value;
}

double Producto::getDesc() const
{
    return desc;
}

void Producto::setDesc(double value)
{
    desc = value;
}

double Producto::getDescuento() const
{
    return descuento;
}

void Producto::setDescuento(double value)
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

int Producto::getNroPieza() const
{
    return nroPieza;
}

void Producto::setNroPieza(int value)
{
    nroPieza = value;
}

double Producto::getPorcentajeSumado() const
{
    return porcentajeSumado;
}

void Producto::setPorcentajeSumado(double value)
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

double Producto::getPrecioCompra() const
{
    return precioCompra;
}

void Producto::setPrecioCompra(double value)
{
    precioCompra = value;
}

double Producto::getPrecioLista() const
{
    return precioLista;
}

void Producto::setPrecioLista(double value)
{
    precioLista = value;
}

double Producto::getPrecioVta() const
{
    return precioVta;
}

void Producto::setPrecioVta(double value)
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
