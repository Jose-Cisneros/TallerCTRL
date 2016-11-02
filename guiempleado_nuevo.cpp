#include "guiempleado_nuevo.h"
#include "ui_guiempleado_nuevo.h"
#include "taller.h"
#include "guiempleado.h"



guiempleado_nuevo::guiempleado_nuevo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiempleado_nuevo)
{
    ui->setupUi(this);

}

guiempleado_nuevo::~guiempleado_nuevo()
{
    delete ui;
}

void guiempleado_nuevo::on_buttonBox_rejected()
{
    this->close();
}

void guiempleado_nuevo::on_buttonBox_accepted()
{
    //variables
    //QString nom;
    //QString ape;
    //QString direcc;
    //int tel;
    //int doc;

    //int nroEmp;
    //nroEmp = 01;



    //nom = ui->nombre->text();
    //ape = ui->apellido->text();
    //direcc = ui->direccion->text();
    //tel = ui->telefono->text().toInt();
    //doc = ui->dni->text().toInt();

    //Empleado nuevo(nom,ape,direcc,doc,tel,nroEmp);



    /////////////////////FALTA AGREGAR A LA COLECCION//////////////

    QMessageBox::about(this,"empleado","Empleado añadido correctamente");
    this->close();




}
