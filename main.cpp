#include "taller.h"
#include <QApplication>
#include <head.h>
#include "dbmanager.h"



int main(int argc, char *argv[])
{


    DBManager("taller.db");

    QApplication a(argc, argv);
    a.setStyle("fusion");
    Taller w;
    w.show();



    return a.exec();
}



