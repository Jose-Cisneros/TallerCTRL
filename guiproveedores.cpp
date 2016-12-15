#include "guiproveedores.h"
#include "ui_guiproveedores.h"
#include "guiprov_nuevo.h"
#include "proveedores.h"
#include <QHash>
#include <QFile>
#include <QDataStream>
#include <QDebug>

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
    ui->Eliminar->setEnabled(false);
    ui->Editar->setEnabled(false);

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

    proveedores a;
    //a = listaProv.value(ui->listWidget->currentItem()->text());

    a = listaProv.value(item->text()); //es lo mismo que lo de arriba

    ui->nom->setText(a.verNom());
    ui->tel1->setText(QString::number(a.verTele()));
    ui->tel2->setText(QString::number(a.verTele2()));
    ui->mail->setText(a.verCorreo());
    ui->rzonsoc->setText(a.verRS());
    ui->nroprov->setText(QString::number(a.verNro()));

    ui->Eliminar->setEnabled(true);
    ui->Editar->setEnabled(true);

    QFile file("ProdHash");
    if (!file.open(QIODevice::ReadOnly))
        return;

    QHash<QString,Producto> auxProd;

    QDataStream in(&file);

    in >> auxProd;
    file.close();
    ui->tableWidget->clear();


    QHashIterator<QString,Producto> i(auxProd);
    while (i.hasNext()){
        i.next();

        if(i.value().getProv()== item->text()){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(i.value().getNroPieza()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(i.value().getNom()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(i.value().getMarca()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3, new QTableWidgetItem(i.value().getModelo()));
        }
    }
}



void guiproveedores::on_Eliminar_clicked()
{
    listaProv.remove(ui->listWidget->currentItem()->text());
    qDeleteAll(ui->listWidget->selectedItems());
}

void guiproveedores::on_guardar_clicked()
{
    QFile file("PHash");
    if (!file.open(QIODevice::WriteOnly))
        return;
    QDataStream out(&file);
    out << listaProv;
    file.close();
    this->close();
}

