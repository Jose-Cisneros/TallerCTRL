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
    guiempleado_nuevo guiEN; //creo el objeto
    guiEN.setModal(true);
    guiEN.exec();
}
