#include "guiprod_nuevo.h"
#include "ui_guiprod_nuevo.h"

//ventanas//
#include "guiprod_nuevo_marca.h"
#include "guiprod_nuevo_modelo.h"

//datos//
#include "marca.h"

#include<QtDebug>

//static QHash<QString,Marca> marcas; //Corregir//
static QHash<QString,QString> autos;

guiProd_nuevo::guiProd_nuevo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiProd_nuevo)
{
    ui->setupUi(this);
    ui->nuevo_2->setEnabled(false);
    ui->modificar_2->setEnabled(false);
    ui->eliminar_2->setEnabled(false);
}

guiProd_nuevo::~guiProd_nuevo()
{
    delete ui;
}

void guiProd_nuevo::on_nuevo_clicked()
{
    int res;
    guiprod_nuevo_marca guiPM(this); //creo el objeto
    guiPM.setWindowTitle("Nueva Marca");
    guiPM.setModal(true);
    res = guiPM.exec();
    if ((res == QDialog::Accepted) && ( guiPM.nombre()!= ""))
    {
        ui->listWidget->addItem(guiPM.nombre());
        //Marca nueva;
        //nueva.setNom(guiPM.nombre());


       // marcas.insert(guiPM.nombre(),nueva); //Agrego al diccionario

        //autos.insert(guiPM.nombre(), );

    }
}

void guiProd_nuevo::on_nuevo_2_clicked()
{



    int res;
    guiprod_nuevo_modelo guiPMod(this); //creo el objeto
    guiPMod.setWindowTitle("Nuevo Modelo");
    guiPMod.setModal(true);
    res = guiPMod.exec();

    if ((res == QDialog::Accepted) && ( guiPMod.nom()!= "")){

        //aux.agregar(guiPMod.nom());
//        QStringList aux;
//        aux = autos.value(ui->listWidget->currentItem()->text());


//        aux

        //marcas.value(ui->listWidget->currentItem()->text()).agregar(guiPMod.nom());


        //qDebug() << aux.autos.join("");
        //QStringList a = aux.getAutos();
        //qDebug() << ui->listWidget->currentItem()->text();
        //qDebug() << a.join("");

        autos.insertMulti(ui->listWidget->currentItem()->text(),guiPMod.nom());

    }
}


void guiProd_nuevo::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->nuevo_2->setEnabled(true);
    ui->modificar_2->setEnabled(true);
    ui->eliminar_2->setEnabled(true);


    //Recorro lista y cargo los modelos en listWidget2//
    QList<QString> aux;
    aux = autos.values(item->text());


    ui->listWidget_2->clear();

    for (int i = 0; i < aux.size(); ++i){
        ui->listWidget_2->addItem(aux.at(i));
    }

}
