#ifndef GUIPROD_NUEVO_H
#define GUIPROD_NUEVO_H

#include <QDialog>
#include "head.h"
#include "productoArchivo.h"
#include"mmarchivo.h"


namespace Ui {
class guiProd_nuevo;
}

class guiProd_nuevo : public QDialog
{
    Q_OBJECT

public:
    explicit guiProd_nuevo(QWidget *parent = 0);
    ~guiProd_nuevo();

    QString nom();
    QString nroPieza();
    QString categoria();
    QString preC();
    QString preV();
    QString preL();
    QString prov();
    int descuento();
    QString marca();
    QString modelo();
    int stock();

private slots:
    void on_nuevo_clicked();

    void on_nuevo_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void imprimirTodos();

    void imprimirPorAno();

    void on_radioButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_eliminar_clicked();

    void on_eliminar_2_clicked();

private:
    Ui::guiProd_nuevo *ui;
};

#endif // GUIPROD_NUEVO_H
