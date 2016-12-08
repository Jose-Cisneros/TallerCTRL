#include "guiprov_nuevo.h"
#include "ui_guiprov_nuevo.h"
#include "head.h"


guiprov_nuevo::guiprov_nuevo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiprov_nuevo)
{
    ui->setupUi(this);
}

guiprov_nuevo::~guiprov_nuevo()
{
    delete ui;
}

//void guiprov_nuevo::on_buttonBox_accepted()
//{
////    //variables
////    QString nomb;
////    int nroprov;
////    QString rs;
////    int tel1;
////    int tel2;
////    QString mail;


////    nomb = ui->nombre->text();
////    nroprov = ui->num->text().toInt();
////    rs = ui->razon->text();
////    tel1 = ui->telefono1->text().toInt();
////    tel2 = ui->telefono2->text().toInt();
////    mail = ui->correo->text();

////    proveedores nuevo(nomb,tel1,tel2,mail,nroprov,rs);


//   QMessageBox::about(this,"Proveedor","Proveedor añadido correctamente");

//}


void guiprov_nuevo::on_buttonBox_rejected()
{
    reject();
}

void guiprov_nuevo::on_buttonBox_accepted()
{

    accept();

}



QString guiprov_nuevo::nombre()
{
    return ui->nombre->text();
}


int guiprov_nuevo::nrop()
{
    return ui->num->text().toInt();
}

int guiprov_nuevo::tele1()
{
    return ui->telefono1->text().toInt();
}

int guiprov_nuevo::tele2()
{
    return ui->telefono2->text().toInt();
}

QString guiprov_nuevo::rsoc()
{
    return ui->razon->text();
}

QString guiprov_nuevo::mail()
{
    return ui->correo->text();
}
