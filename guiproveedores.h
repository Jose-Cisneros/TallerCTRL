#ifndef GUIPROVEEDORES_H
#define GUIPROVEEDORES_H

#include <QDialog>
#include "head.h"
#include "productoArchivo.h"

namespace Ui {
class guiproveedores;
}

class guiproveedores : public QDialog
{
    Q_OBJECT

public:
    explicit guiproveedores(QWidget *parent = 0);
    ~guiproveedores();

private slots:


    void on_Agregar_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_Eliminar_clicked();


    void on_guardar_clicked();

private:
    Ui::guiproveedores *ui;
};

#endif // GUIPROVEEDORES_H
