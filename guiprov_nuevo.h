#ifndef GUIPROV_NUEVO_H
#define GUIPROV_NUEVO_H

#include <QDialog>

namespace Ui {
class guiprov_nuevo;
}

class guiprov_nuevo : public QDialog
{
    Q_OBJECT

public:
    explicit guiprov_nuevo(QWidget *parent = 0);
    ~guiprov_nuevo();

private:
    Ui::guiprov_nuevo *ui;
};

#endif // GUIPROV_NUEVO_H
