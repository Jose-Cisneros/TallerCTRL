#include "guiempleado_nuevo.h"
#include "ui_guiempleado_nuevo.h"
#include "taller.h"
#include "guiempleado.h"



guiempleado_nuevo::guiempleado_nuevo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiempleado_nuevo)
{
    ui->setupUi(this);

}

guiempleado_nuevo::~guiempleado_nuevo()
{
    delete ui;
}

void guiempleado_nuevo::on_buttonBox_rejected()
{
    reject();
}

void guiempleado_nuevo::on_buttonBox_accepted()
{

    accept();

}


QString guiempleado_nuevo::nombre()
{
    return ui->nombre->text();
}


QString guiempleado_nuevo::direccion()
{
    return ui->direccion->text();
}

int guiempleado_nuevo::telefono()
{
    return ui->telefono->text().toInt();
}

int guiempleado_nuevo::dni()
{
    return ui->dni->text().toInt();
}

int guiempleado_nuevo::saldo()
{
    return ui->saldo->value();
}
