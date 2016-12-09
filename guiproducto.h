#ifndef GUIPRODUCTO_H
#define GUIPRODUCTO_H

#include <QDialog>

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

private:
    Ui::GuiProducto *ui;
};

#endif // GUIPRODUCTO_H
