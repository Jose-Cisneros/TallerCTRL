#include "guiproducto.h"
#include "ui_guiproducto.h"
#include "head.h"

//ventanas//

#include "guiprod_nuevo.h"

static QHash<QString,Producto> prod; //corregir

GuiProducto::GuiProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuiProducto)
{


    ui->setupUi(this);
    ui->pushButton->setEnabled(false);

    // creo la tabla con el archivo

    ProductoArchivo archi;
    archi.cargarProductos(prod,"ProdHash");

    QHashIterator<QString,Producto> i(prod);
    while (i.hasNext()){
        i.next();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(i.value().getNroPieza()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(i.value().getNom()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(i.value().getMarca()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3, new QTableWidgetItem(i.value().getModelo()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4, new QTableWidgetItem(i.value().getCategoria()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5, new QTableWidgetItem(QString::number(i.value().getStock())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6, new QTableWidgetItem(i.value().getPrecioCompra()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7, new QTableWidgetItem(i.value().getPrecioLista()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,8, new QTableWidgetItem(i.value().getPrecioVta()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,9, new QTableWidgetItem(QString::number(i.value().getDescuento())));
    }

  //cargo modelos y marcas
    QHash<QString,QString> HAux;

    MMArchivo file2;
    file2.cargarMM(HAux,"MMHash");

    //cargo las keys unicas a la lista aux2
    QList<QString> aux2 = HAux.uniqueKeys();


    //recorro la lista y agrego a comboProv
    for (int i = 0; i < aux2.size(); ++i){
        ui->comboMarca->addItem(aux2.at(i));
    }

}

GuiProducto::~GuiProducto()
{
    delete ui;
}

void GuiProducto::on_nuevo_clicked()
{
    int res;
    guiProd_nuevo guiPN(this); //creo el objeto
    guiPN.setWindowTitle("Nuevo Producto");
    guiPN.setModal(true);
    res = guiPN.exec();
    if (res == QDialog::Accepted){


        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(guiPN.nroPieza()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(guiPN.nom()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(guiPN.marca()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3, new QTableWidgetItem(guiPN.modelo()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4, new QTableWidgetItem(guiPN.categoria()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5, new QTableWidgetItem(QString::number(guiPN.stock())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6, new QTableWidgetItem(guiPN.preC()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7, new QTableWidgetItem(guiPN.preL()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,8, new QTableWidgetItem(guiPN.preV()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,9, new QTableWidgetItem(QString::number(guiPN.descuento())));

        //creo el objeto aux de clase Producto y lo inicializo
        Producto aux;
        aux.setNroPieza(guiPN.nroPieza());
        aux.setNom(guiPN.nom());
        aux.setMarca(guiPN.marca());
        aux.setModelo(guiPN.modelo());
        aux.setCategoria(guiPN.categoria());
        aux.setStock(guiPN.stock());
        aux.setPrecioCompra(guiPN.preC());
        aux.setPrecioLista(guiPN.preL());
        aux.setPrecioVta(guiPN.preV());
        aux.setDescuento(guiPN.descuento());
        aux.setProv(guiPN.prov());

        //lo agrego al hash con el numero de producto como key

        prod.insert(guiPN.nroPieza(),aux);

        ui->pushButton->setEnabled(true);

    }
}

void GuiProducto::on_pushButton_2_clicked()
{
    this->close();
}

void GuiProducto::on_pushButton_clicked()
{

    ProductoArchivo archi;
    archi.guardarProductos(prod,"ProdHash");

}

void GuiProducto::on_comboMarca_currentTextChanged()
{
    QHash<QString,QString> HAux;

    MMArchivo file2;
    file2.cargarMM(HAux, "MMHash");


    QList<QString> aux;
    aux = HAux.values(ui->comboMarca->currentText());
    ui->comboModelo->clear();

    for (int i = 0; i < aux.size(); ++i){
        ui->comboModelo->addItem(aux.at(i));
    }
}

void GuiProducto::on_eliminar_clicked()
{
        prod.remove(ui->tableWidget->itemAt(ui->tableWidget->currentRow(),1)->text());
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
        ui->pushButton->setEnabled(true);

}
