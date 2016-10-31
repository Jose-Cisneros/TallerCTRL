#include "taller.h"
#include <QApplication>
#include <head.h>

#include <QTextStream>

QString hola;

QTextStream cout(stdout);


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Taller w;
    w.show();



    return a.exec();
}



