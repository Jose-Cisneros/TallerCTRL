#include "guiprod_nuevo.h"
#include "ui_guiprod_nuevo.h"

//ventanas//
#include "guiprod_nuevo_marca.h"
#include "guiprod_nuevo_modelo.h"

//datos//
#include "marca.h"

#include <QFile>
#include <QDataStream>
#include <QtDebug>

static QHash<QString,QString> autos; //Corregir//

guiProd_nuevo::guiProd_nuevo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiProd_nuevo)
{
    ui->setupUi(this);
    ui->nuevo_2->setEnabled(false);
    ui->modificar_2->setEnabled(false);
    ui->eliminar_2->setEnabled(false);


    MMArchivo file;
    file.cargarMM(autos,"MMHash");

//    QFile file("MMHash");
//    if (!file.open(QIODevice::ReadOnly))
//        return;
//    QDataStream in(&file);
//    in >> autos;
//    file.close();


    //cargo las keys unicas a la lista aux
    QList<QString> aux = autos.uniqueKeys();

    //recorro la lista y agrego a listWidget_1
    for (int i = 0; i < aux.size(); ++i){
        ui->listWidget->addItem(aux.at(i));
    }


    QHash<QString,proveedores> pAux;
//    ProductoArchivo file;
//    file.cargarProducto(pAux,"PHash");

    QFile file2("PHash");
    if (!file2.open(QIODevice::ReadOnly))
        return;

    QDataStream in2(&file2);
    in2 >> pAux ;
    file2.close();



    //cargo las keys unicas a la lista aux2
    QList<QString> aux2 = pAux.uniqueKeys();


    //recorro la lista y agrego a comboProv
    for (int i = 0; i < aux2.size(); ++i){
        ui->comboProv->addItem(aux2.at(i));
    }

}

guiProd_nuevo::~guiProd_nuevo()
{
    delete ui;
}

//funciones para enviar los datos a la ventana de productos


QString guiProd_nuevo::nom()
{
    return ui->nombre->text();
}

QString guiProd_nuevo::nroPieza()
{
    return ui->num->text();
}

QString guiProd_nuevo::categoria()
{
    return ui->categoria->text();
}

QString guiProd_nuevo::preC()
{
    return ui->preC->text();
}

QString guiProd_nuevo::preV()
{
    return ui->preVta->text();
}

QString guiProd_nuevo::preL()
{
    return ui->preList->text();
}

QString guiProd_nuevo::prov()
{
    return ui->comboProv->currentText();
}

int guiProd_nuevo::descuento()
{
    return ui->descuento->text().toInt();
}

QString guiProd_nuevo::marca()
{
    return ui->listWidget->currentItem()->text();
}

QString guiProd_nuevo::modelo()
{
    return ui->listWidget_2->currentItem()->text();
}

int guiProd_nuevo::stock()
{
    return ui->stock->text().toInt();
}


//funciones para el manejo de datos en esta misma ventana



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

        MMArchivo fileS;
        fileS.guardarMM(autos,"MMHash");

//        QFile file("MMHash");
//        if (!file.open(QIODevice::WriteOnly))
//            return;
//        QDataStream out(&file);
//        out << autos;
//        file.close();
    }
}




void guiProd_nuevo::imprimirTodos()
{
    QList<QString> aux;
    aux = autos.values(ui->listWidget->currentItem()->text());
    ui->listWidget_2->clear();

    for (int i = 0; i < aux.size(); ++i){
        ui->listWidget_2->addItem(aux.at(i));
    }
}


void guiProd_nuevo::imprimirPorAno()
{
    QList<QString> aux;
    aux = autos.values(ui->listWidget->currentItem()->text());
    ui->listWidget_2->clear();
    //solo agrega los que coincidan con el año del spinbox
    for (int i = 0; i < aux.size(); ++i){
        if (aux.at(i).contains(ui->spinBox->text())){
        ui->listWidget_2->addItem(aux.at(i));
        }
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

    if (ui->radioButton->isChecked()){

            imprimirPorAno();

     } else {
            imprimirTodos();
     }
    }


void guiProd_nuevo::on_radioButton_clicked()
{
    if (ui->radioButton->isChecked()){
        imprimirPorAno();
    } else {
        imprimirTodos();
    }
}



void guiProd_nuevo::on_buttonBox_accepted()
{
    accept();
}



void guiProd_nuevo::on_buttonBox_rejected()
{
    reject();
}

void guiProd_nuevo::on_eliminar_clicked()
{
    autos.remove(ui->listWidget->currentItem()->text());
    qDeleteAll(ui->listWidget->selectedItems());
}


//ARREGLAR ELIMINAR MODELO


void guiProd_nuevo::on_eliminar_2_clicked(){}
//{
//    QHash<QString, QString> aux;
//    QHash<QString,QString>::iterator i = aux.find(ui->listWidget->currentItem()->text());

//       while ( {
//          if (i.value() == ui->listWidget_2->currentItem()->text() ) {
//             i = aux.erase(i);
//          } else {
//              int a= 0;
//              a++;
//              qDebug() << a;

//              ++i;
//          }
//      }
//    qDeleteAll(ui->listWidget_2->selectedItems());

//    //actualizo el archivo

//}
