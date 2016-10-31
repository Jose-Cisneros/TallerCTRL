#ifndef GUIEMPLEADO_NUEVO_H
#define GUIEMPLEADO_NUEVO_H

#include <QDialog>

namespace Ui {
class guiempleado_nuevo;
}

class guiempleado_nuevo : public QDialog
{
    Q_OBJECT

public:
    explicit guiempleado_nuevo(QWidget *parent = 0);
    ~guiempleado_nuevo();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::guiempleado_nuevo *ui;
};

#endif // GUIEMPLEADO_NUEVO_H
