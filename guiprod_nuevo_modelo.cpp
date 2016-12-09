#include "guiprod_nuevo_modelo.h"
#include "ui_guiprod_nuevo_modelo.h"

guiprod_nuevo_modelo::guiprod_nuevo_modelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiprod_nuevo_modelo)
{
    ui->setupUi(this);
}

guiprod_nuevo_modelo::~guiprod_nuevo_modelo()
{
    delete ui;
}

QString guiprod_nuevo_modelo::nom()
{
    return ui->lineEdit->text();
}

double guiprod_nuevo_modelo::ano()
{
    return ui->spinBox->text().toInt();
}

void guiprod_nuevo_modelo::on_buttonBox_accepted()
{
    accept();
}

void guiprod_nuevo_modelo::on_buttonBox_rejected()
{
    reject();
}
