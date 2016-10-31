#include "taller.h"
#include "ui_taller.h"

//ventanas

#include "guiempleado.h"

Taller::Taller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Taller)
{
    ui->setupUi(this);
}

Taller::~Taller()
{
    delete ui;
}

void Taller::on_pushButton_clicked()
{

}

void Taller::on_pushButton_2_clicked()
{
    GUIEmpleado guiE; //creo el objeto
    guiE.setModal(true);
    guiE.exec();

}
