#ifndef GUIPRODUCTO_H
#define GUIPRODUCTO_H
#include "mmarchivo.h"

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

    void on_radioButton_clicked();

    void on_comboModelo_currentTextChanged();

    void on_buscar_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::GuiProducto *ui;
    void imprimirTodos();
    void imprimirPorMarca(QString marca);
    void imprimirPorModelo(QString modelo);
    void imprimirPorBusqueda(QString bsq, QString mod, QString mar);
};

#endif // GUIPRODUCTO_H
