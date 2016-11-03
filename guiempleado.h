#ifndef GUIEMPLEADO_H
#define GUIEMPLEADO_H

#include <QDialog>

namespace Ui {
class GUIEmpleado;
}

class GUIEmpleado : public QDialog
{
    Q_OBJECT

public:
    explicit GUIEmpleado(QWidget *parent = 0);
    ~GUIEmpleado();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::GUIEmpleado *ui;
};

#endif // GUIEMPLEADO_H
