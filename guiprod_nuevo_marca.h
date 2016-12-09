#ifndef GUIPROD_NUEVO_MARCA_H
#define GUIPROD_NUEVO_MARCA_H

#include <QDialog>

namespace Ui {
class guiprod_nuevo_marca;
}

class guiprod_nuevo_marca : public QDialog
{
    Q_OBJECT

public:
    explicit guiprod_nuevo_marca(QWidget *parent = 0);
    ~guiprod_nuevo_marca();
    QString nombre();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::guiprod_nuevo_marca *ui;
};

#endif // GUIPROD_NUEVO_MARCA_H
