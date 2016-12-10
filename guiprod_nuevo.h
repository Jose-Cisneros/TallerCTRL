#ifndef GUIPROD_NUEVO_H
#define GUIPROD_NUEVO_H

#include <QDialog>
#include "head.h"

namespace Ui {
class guiProd_nuevo;
}

class guiProd_nuevo : public QDialog
{
    Q_OBJECT

public:
    explicit guiProd_nuevo(QWidget *parent = 0);
    ~guiProd_nuevo();


private slots:
    void on_nuevo_clicked();

    void on_nuevo_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemSelectionChanged();

private:
    Ui::guiProd_nuevo *ui;
};

#endif // GUIPROD_NUEVO_H
