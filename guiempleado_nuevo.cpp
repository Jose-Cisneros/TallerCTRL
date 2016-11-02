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
    reject();
}

void guiempleado_nuevo::on_buttonBox_accepted()
{
    //variables
//    QString nom;
//    QString direcc;
//    int tel;
//    int doc;
//    double sal;

//    //int nroEmp;
//    //nroEmp = 01;


//    direcc = ui->direccion->text();
//    tel = ui->telefono->text().toInt();
//    doc = ui->dni->text().toInt();
//    sal = ui->saldo->value();
//Empleado nuevo(nom,ape,direcc,doc,tel,nroEmp);





//    QMessageBox::about(this,"empleado","Empleado añadido correctamente");
//    this->close();

    accept();


}


QString guiempleado_nuevo::nombre()
{
    return ui->nombre->text();
}


QString guiempleado_nuevo::direccion()
{
    return ui->direccion->text();
}

int guiempleado_nuevo::telefono()
{
    return ui->telefono->text().toInt();
}

int guiempleado_nuevo::dni()
{
    return ui->dni->text().toInt();
}

int guiempleado_nuevo::saldo()
{
    return ui->saldo->value();
}
