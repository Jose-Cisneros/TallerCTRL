#ifndef TALLER_H
#define TALLER_H

#include <QMainWindow>

namespace Ui {
class Taller;
}

class Taller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Taller(QWidget *parent = 0);
    ~Taller();

private:
    Ui::Taller *ui;
};

#endif // TALLER_H
