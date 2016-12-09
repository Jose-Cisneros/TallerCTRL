#include "guiprod_nuevo.h"
#include "ui_guiprod_nuevo.h"

//ventanas//
#include "guiprod_nuevo_marca.h"
#include "guiprod_nuevo_modelo.h"

//datos//
#include "marca.h"

#include<QtDebug>

static QHash<QString,Marca> marcas; //Corregir//


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
        Marca nueva;
        nueva.setNom(guiPM.nombre());
        QStringList n;
        nueva.setAutos(n);

        marcas.insert(guiPM.nombre(),nueva); //Agrego al diccionario

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
        Marca aux;
        aux = marcas.value(ui->listWidget->currentItem()->text());

        //marcas.value(ui->listWidget->currentItem()->text()).agregar(guiPMod.nom());


        //qDebug() << aux.autos.join("");
        //QStringList a = aux.getAutos();
        //qDebug() << ui->listWidget->currentItem()->text();
        //qDebug() << a.join("");

    }
}


void guiProd_nuevo::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->nuevo_2->setEnabled(true);
    ui->modificar_2->setEnabled(true);
    ui->eliminar_2->setEnabled(true);

    Marca aux;
    aux = marcas.value(item->text());
    QStringList a = aux.getAutos();

    qDebug() << a.join("");

    //Recorro lista y cargo los modelos en listWidget2//


    for (int i = 0; i < a.size(); ++i){
        qDebug() << a.at(i);
        ui->listWidget_2->addItem(a.at(i));
    }
}
