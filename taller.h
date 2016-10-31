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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Taller *ui;
};

#endif // TALLER_H
