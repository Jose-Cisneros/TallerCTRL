#ifndef GUIPROD_NUEVO_MODELO_H
#define GUIPROD_NUEVO_MODELO_H

#include <QDialog>

namespace Ui {
class guiprod_nuevo_modelo;
}

class guiprod_nuevo_modelo : public QDialog
{
    Q_OBJECT

public:
    explicit guiprod_nuevo_modelo(QWidget *parent = 0);
    ~guiprod_nuevo_modelo();
    QString nom();
    double ano();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::guiprod_nuevo_modelo *ui;
};

#endif // GUIPROD_NUEVO_MODELO_H
