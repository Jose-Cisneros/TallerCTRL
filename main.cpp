#include "taller.h"
#include <QApplication>
#include <head.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Taller w;
    w.show();

    return a.exec();
}
