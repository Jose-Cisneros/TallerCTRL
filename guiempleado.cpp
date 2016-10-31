#include "guiempleado.h"
#include "ui_guiempleado.h"

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
