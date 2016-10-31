#include "guiproveedores.h"
#include "ui_guiproveedores.h"
#include "guiprov_nuevo.h"

guiproveedores::guiproveedores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiproveedores)
{
    ui->setupUi(this);
}

guiproveedores::~guiproveedores()
{
    delete ui;
}

void guiproveedores::on_pushButton_clicked()
{
   guiprov_nuevo guiPN ;
   guiPN.setModal(true);
   guiPN.exec();
}
