#include "taller.h"
#include "ui_taller.h"



//ventanas

#include "guiempleado.h"
#include "guiproveedores.h"
#include "guiproducto.h"


Taller::Taller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Taller)
{
    ui->setupUi(this);

}

Taller::~Taller()
{
    delete ui;

}

void Taller::on_pushButton_clicked()
{
    guiproveedores  guiP;
    guiP.setModal(true);
    guiP.exec();
}

void Taller::on_pushButton_2_clicked()
{

    GUIEmpleado guiE; //creo el objeto
    guiE.setModal(true);
    guiE.exec();

}

void Taller::on_productos_clicked()
{
    GuiProducto guiP; //creo el objeto
    guiP.setModal(true);
    guiP.exec();
}
