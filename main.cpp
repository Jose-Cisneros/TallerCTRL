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

//cout << "eee" "\n";
//cout << "eee" "\n";
//cout << "eee" "\n";
//Empleado jose("josecillo","calcalskc","asdasd",22323,2414,142421);
//Empleado chumpoa("JPPPP","PORDAL","ADSAD",40441200,33231330,1);
//Empleado warsaw("santiago","rudolf","47 N1395", 402453,2214463,123455);
//cout << jose.verNom() ;
//cout <<  "\n";
//cout << "ingresar nombre del empleado nuevo" "\n";
//cin << hola;


//return 0;


