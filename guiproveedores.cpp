#include "guiproveedores.h"
#include "ui_guiproveedores.h"
#include "guiprov_nuevo.h"
#include "proveedores.h"
#include <QHash>
#include <QFile>
#include <QDataStream>

static QHash<QString,proveedores> listaProv; //Es mala practica declarar static al principio, hay que hacer una funcion//

guiproveedores::guiproveedores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiproveedores)
{
    ui->setupUi(this);
    QFile file("PHash");
    if (!file.open(QIODevice::ReadOnly))
        return;
    QDataStream in(&file);

    in >> listaProv;
    file.close();
    QHashIterator<QString,proveedores> i(listaProv);
    while (i.hasNext()){
        i.next();
        ui->listWidget->addItem(i.key());
    }


}

guiproveedores::~guiproveedores()
{
    delete ui;
}

void guiproveedores::on_Agregar_clicked()
{
   guiprov_nuevo guiPN ;
   guiPN.setModal(true);
   int res = guiPN.exec();
   if (res == QDialog::Accepted){
       ui->listWidget->addItem(guiPN.nombre());
       //guardo los datos en un objeto de la clase proveedores//

       proveedores prov(guiPN.nombre(),guiPN.tele1(),guiPN.tele2(),guiPN.mail(),guiPN.nrop(),guiPN.rsoc());
       listaProv.insert(guiPN.nombre(),prov);
   }
}


void guiproveedores::on_listWidget_itemClicked(QListWidgetItem *item)
//Muestra los datos del proveedor seleccionado//
{
    //proveedores a("",0,0,"",0,"");
    proveedores a;
    //a = listaProv.value(ui->listWidget->currentItem()->text());

    a = listaProv.value(item->text()); //es lo mismo que lo de arriba

    ui->nom->setText(a.verNom());
    ui->tel1->setText(QString::number(a.verTele()));
    ui->tel2->setText(QString::number(a.verTele2()));
    ui->mail->setText(a.verCorreo());
    ui->rzonsoc->setText(a.verRS());
    ui->nroprov->setText(QString::number(a.verNro()));
}




void guiproveedores::on_Eliminar_clicked()
{

}

void guiproveedores::on_guardar_clicked()
{
    QFile file("PHash");
    if (!file.open(QIODevice::WriteOnly))
        return;
    QDataStream out(&file);
    out << listaProv;
    file.close();
}

