#include "guiproducto.h"
#include "ui_guiproducto.h"
#include "head.h"
#include "QDebug"

//ventanas//

#include "guiprod_nuevo.h"

static QHash<QString,Producto> prod; //corregir

GuiProducto::GuiProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuiProducto)
{


    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    ui->comboMarca->setEnabled(false);
    ui->comboModelo->setEnabled(false);

    // creo la tabla con el archivo
    imprimirTodos();


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

//prodecimientos de manejo de tabla

void GuiProducto::imprimirTodos()
{
    ui->tableWidget->setRowCount(0);

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



}


void GuiProducto::imprimirPorMarca(QString marca)
{
    ui->tableWidget->setRowCount(0);

    ProductoArchivo archi;
    archi.cargarProductos(prod,"ProdHash");

    QHashIterator<QString,Producto> i(prod);
    while (i.hasNext()){
        i.next();
        if (i.value().getMarca() == marca){
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
    }



}


void GuiProducto::imprimirPorModelo(QString modelo)
{
    ui->tableWidget->setRowCount(0);

    ProductoArchivo archi;
    archi.cargarProductos(prod,"ProdHash");

    QHashIterator<QString,Producto> i(prod);
    while (i.hasNext()){
        i.next();
        if (i.value().getModelo() == modelo){
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
    }

}


void GuiProducto::imprimirPorBusqueda(QString bsq, QString mod, QString mar)
{
    ui->tableWidget->setRowCount(0);

    ProductoArchivo archi;
    archi.cargarProductos(prod,"ProdHash");

    QHashIterator<QString,Producto> i(prod);


    if ((mod != "") && (mod != "Seleccionar")){

        if ((mar == "") || (mar == "Todos")){



            while (i.hasNext()){
                i.next();

                if ( (i.value().getMarca() == mar) && (i.value().getNom().contains(bsq))) {
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
            }



        } else {

            if ((i.value().getModelo() == mod) && (i.value().getNom().contains(bsq))) {
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






        }


    } else {


        while (i.hasNext()){
            i.next();

            if (i.value().getNom().contains(bsq)) {
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
        }



    }

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

            //lo agrego al hash con el numero de producto como key y lo guardo en el archivo

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
        this->close();


    }

    void GuiProducto::on_comboMarca_currentTextChanged()
    {
        if(ui->radioButton->isChecked()) {

            ui->tableWidget->setRowCount(0);
            if (ui->comboMarca->currentText() == "Seleccionar"){

                ui->comboModelo->setCurrentIndex(1);
                ui->comboModelo->setEnabled(false);

                imprimirTodos();

            } else {

                ui->comboModelo->setEnabled(true);
                QHash<QString,QString> HAux;

                MMArchivo file2;
                file2.cargarMM(HAux, "MMHash");


                QList<QString> aux;
                aux = HAux.values(ui->comboMarca->currentText());
                ui->comboModelo->clear();


                ui->comboModelo->addItem("Todos");
                for (int i = 0; i < aux.size(); ++i){
                    ui->comboModelo->addItem(aux.at(i));
                }



            }
        }
    }

    void GuiProducto::on_eliminar_clicked()
    {
        prod.remove(ui->tableWidget->itemAt(ui->tableWidget->currentRow(),1)->text());
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
        ui->pushButton->setEnabled(true);

    }


    void GuiProducto::on_radioButton_clicked()
    {
        if(ui->radioButton->isChecked()){

            ui->comboMarca->setEnabled(true);
            ui->comboModelo->setEnabled(true);


        }

        if(ui->radioButton->isChecked() == false){

            ui->comboMarca->setEnabled(false);
            ui->comboModelo->setEnabled(false);
            ui->comboMarca->setCurrentText("Seleccionar");
            ui->comboModelo->setCurrentText("Todos");
            ui->tableWidget->setRowCount(0);

            imprimirTodos();


        }
    }


    void GuiProducto::on_comboModelo_currentTextChanged()
    {
        if(ui->radioButton->isChecked()) {


            if (ui->comboModelo->currentText() == "Todos"){

                imprimirPorMarca(ui->comboMarca->currentText());

            } else {

                //Agrego todos los productos con el modelo elegido a la tabla

                imprimirPorModelo(ui->comboModelo->currentText());
            }
        }
    }

    void GuiProducto::on_buscar_clicked()
    {
        if (ui->radioButton->isChecked()) {

            imprimirPorBusqueda(ui->busqueda->text(),ui->comboMarca->currentText(),ui->comboModelo->currentText());

        } else {

            imprimirPorBusqueda(ui->busqueda->text(),"","");
        }
    }

    void GuiProducto::on_pushButton_3_clicked()
    {
        ui->comboMarca->setEnabled(false);
        ui->comboModelo->setEnabled(false);
        ui->comboMarca->setCurrentText("Seleccionar");
        ui->comboModelo->setCurrentText("Todos");
        ui->tableWidget->setRowCount(0);
        ui->radioButton->setChecked(false);

        imprimirTodos();
    }
