#include "guiprod_nuevo_marca.h"
#include "ui_guiprod_nuevo_marca.h"

guiprod_nuevo_marca::guiprod_nuevo_marca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiprod_nuevo_marca)
{
    ui->setupUi(this);
}

guiprod_nuevo_marca::~guiprod_nuevo_marca()
{
    delete ui;
}

void guiprod_nuevo_marca::on_buttonBox_accepted()
{
    accept();
}

void guiprod_nuevo_marca::on_buttonBox_rejected()
{
    reject();
}

QString guiprod_nuevo_marca::nombre()
{
    return ui->lineEdit->text();
}
