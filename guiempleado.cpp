#include "guiempleado.h"
#include "ui_guiempleado.h"

//ventanas
#include "guiempleado_nuevo.h"


GUIEmpleado::GUIEmpleado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GUIEmpleado)
{
    ui->setupUi(this);

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
    QString nom;
    nom = guiEN.nombre();
    if (res == QDialog::Accepted){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(guiEN.nombre()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(QString::number(guiEN.telefono())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(guiEN.direccion()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3, new QTableWidgetItem(QString::number(guiEN.dni())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4, new QTableWidgetItem(QString::number(guiEN.saldo())));
    }
}
