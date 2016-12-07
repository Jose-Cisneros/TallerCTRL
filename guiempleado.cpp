#include "guiempleado.h"
#include "ui_guiempleado.h"
#include "taller.h"
#include <QFile>
#include <QTextStream>

//ventanas
#include "guiempleado_nuevo.h"


GUIEmpleado::GUIEmpleado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GUIEmpleado)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    //CARGA Y CREACION DE TABLA A PARTIR DE EMPLEADOS.TXT//
    QFile file("empleados.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);
        while (!in.atEnd()){
            QString line = in.readLine();
            agregarATabla(line);
        }
        file.close();
    //FIN CARGA//
}

GUIEmpleado::~GUIEmpleado()
{
    delete ui;
}

void GUIEmpleado::on_pushButton_4_clicked()
{
    (this)->close();
}

//nuevo
void GUIEmpleado::on_pushButton_clicked()
{
    int res;
    guiempleado_nuevo guiEN(this); //creo el objeto
    guiEN.setWindowTitle("Nuevo empleado");
    guiEN.setModal(true);
    res = guiEN.exec();
    if (res == QDialog::Accepted){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(guiEN.nombre()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(QString::number(guiEN.telefono())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(guiEN.direccion()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3, new QTableWidgetItem(QString::number(guiEN.dni())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4, new QTableWidgetItem(QString::number(guiEN.saldo())));
    }
}

void GUIEmpleado::on_pushButton_3_clicked()
{
        //abro el archivo//

        QFile file("empleados.txt");
        if (!file.open(QIODevice::Append | QIODevice::Text))
            return;

        //Elimino archivo anterior//
        file.remove();

        //vuelvo a abrir el archivo//

        if (!file.open(QIODevice::Append | QIODevice::Text))
            return;
         QTextStream out(&file);
         int i ;
        for( i= 0; i <= ui->tableWidget->rowCount()-1;i++){


            out << ui->tableWidget->item(i,0)->text() << "-" << ui->tableWidget->item(i,1)->text() << "-" << ui->tableWidget->item(i,2)->text() << "-" << ui->tableWidget->item(i,3)->text() << "-" << ui->tableWidget->item(i,4)->text() << "\n";
             }

        file.close();
        this->close();
}


void GUIEmpleado::agregarATabla(QString line){

    QStringList A = line.split("-");
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(A[0]));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(A[1]));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(A[2]));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3, new QTableWidgetItem(A[3]));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4, new QTableWidgetItem(A[4]));

}
