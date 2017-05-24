#include "guiproveedores.h"
#include "ui_guiproveedores.h"
#include "guiprov_nuevo.h"
#include "proveedor.h"


//DBProveedor DBP;
QList<QString> listaProv;


guiproveedores::guiproveedores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiproveedores)
{


//    QList<QString> listProv = DBP.listarProveedores();

//    for (int i; i < listProv.size(); i++){

//        ui->listWidget->addItem(listProv[i]);
//    }


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

       Proveedor prov(guiPN.nrop(),guiPN.nombre(),guiPN.rsoc(),guiPN.mail(),guiPN.tele1(),guiPN.tele2());

//       DBP.agregar(prov);

   }
}


void guiproveedores::on_listWidget_itemClicked(QListWidgetItem *item)
//Muestra los datos del proveedor seleccionado//
{

//    Proveedor a;
//    a = listaProv.value(ui->listWidget->currentItem()->text());


//    ui->nom->setText(a.verNom());
//    ui->tel1->setText(QString::number(a.verTele()));
//    ui->tel2->setText(QString::number(a.verTele2()));
//    ui->mail->setText(a.verCorreo());
//    ui->rzonsoc->setText(a.verRS());
//    ui->nroprov->setText(QString::number(a.verNro()));

    ui->Eliminar->setEnabled(true);
    ui->Editar->setEnabled(true);

    QHash<QString,Producto> auxProd ;

    ProductoArchivo archi;
    archi.cargarProductos(auxProd,"ProdHash");


    ui->tableWidget->setRowCount(0);


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

}

void guiproveedores::on_guardar_clicked()
{

    this->close();
}

