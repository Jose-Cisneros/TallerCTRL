#include "guiprod_nuevo.h"
#include "ui_guiprod_nuevo.h"

//ventanas//
#include "guiprod_nuevo_marca.h"
#include "guiprod_nuevo_modelo.h"

//datos//
#include "marca.h"

#include <QFile>
#include <QDataStream>
#include<QtDebug>

static QHash<QString,QString> autos; //Corregir//

guiProd_nuevo::guiProd_nuevo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiProd_nuevo)
{
    ui->setupUi(this);
    ui->nuevo_2->setEnabled(false);
    ui->modificar_2->setEnabled(false);
    ui->eliminar_2->setEnabled(false);
    ui->spinBox->setEnabled(false);


    QFile file("MMHash");
    if (!file.open(QIODevice::ReadOnly))
        return;
    QDataStream in(&file);
    in >> autos;
    file.close();

    //cargo las keys unicas a la lista aux


    QList<QString> aux = autos.uniqueKeys();



    //recorro la lista y agrego a listWidget_1
    for (int i = 0; i < aux.size(); ++i){
        ui->listWidget->addItem(aux.at(i));
    }

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

        QString a = guiPMod.nom() + "_" + QString::number(guiPMod.ano());

        autos.insertMulti(ui->listWidget->currentItem()->text(),a);

        //Agrego key y value al archivo//

        QFile file("MMHash");
        if (!file.open(QIODevice::WriteOnly))
            return;
        QDataStream out(&file);
        out << autos;
        file.close();
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

    if (ui->radioButton->isChecked()=true){

            ui->listWidget_2->clear();
            //agregar para que solo agregue los que coincidan con el año del spinbox
            for (int i = 0; i < aux.size(); ++i){
                if (aux.at(i).contains(ui->spinBox->QString::number(text()))=true){
                ui->listWidget_2->addItem(aux.at(i));
                }
            }
    }

    ui->listWidget_2->clear();

    for (int i = 0; i < aux.size(); ++i){
        ui->listWidget_2->addItem(aux.at(i));
    }



}


