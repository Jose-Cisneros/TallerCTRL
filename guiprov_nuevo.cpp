#include "guiprov_nuevo.h"
#include "ui_guiprov_nuevo.h"

guiprov_nuevo::guiprov_nuevo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guiprov_nuevo)
{
    ui->setupUi(this);
}

guiprov_nuevo::~guiprov_nuevo()
{
    delete ui;
}
