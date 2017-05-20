#ifndef GUIPRODUCTO_H
#define GUIPRODUCTO_H

#include <QDialog>
#include "productoArchivo.h"

namespace Ui {
class GuiProducto;
}

class GuiProducto : public QDialog
{
    Q_OBJECT

public:
    explicit GuiProducto(QWidget *parent = 0);
    ~GuiProducto();

private slots:
    void on_nuevo_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboMarca_currentTextChanged();

    void on_eliminar_clicked();

private:
    Ui::GuiProducto *ui;
};

#endif // GUIPRODUCTO_H
