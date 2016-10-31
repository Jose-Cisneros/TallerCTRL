#include "taller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Taller w;
    w.show();

    return a.exec();
}
