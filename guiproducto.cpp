#include "guiproducto.h"
#include "ui_guiproducto.h"

//ventanas//
#include "guiprod_nuevo.h"

GuiProducto::GuiProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuiProducto)
{
    ui->setupUi(this);
}

GuiProducto::~GuiProducto()
{
    delete ui;
}

void GuiProducto::on_nuevo_clicked()
{
    int res;
    guiProd_nuevo guiPN(this); //creo el objeto
    guiPN.setWindowTitle("Nuevo Producto");
    guiPN.setModal(true);
    res = guiPN.exec();
    if (res == QDialog::Accepted){}
}
