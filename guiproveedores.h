#ifndef GUIPROVEEDORES_H
#define GUIPROVEEDORES_H

#include <QDialog>

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
    void on_pushButton_clicked();

private:
    Ui::guiproveedores *ui;
};

#endif // GUIPROVEEDORES_H
