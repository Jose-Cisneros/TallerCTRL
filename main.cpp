#include "taller.h"
#include <QApplication>
#include <head.h>

#include <QTextStream>




int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setStyle("fusion");
    Taller w;
    w.show();



    return a.exec();
}



