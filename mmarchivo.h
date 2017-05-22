#ifndef MMARCHIVO_H
#define MMARCHIVO_H
#include "head.h"


class MMArchivo
{
public:
    MMArchivo();
    void cargarMM(QHash<QString,QString> &autos, QString archivo);
    void guardarMM(QHash<QString,QString> &autos, QString archivo);
};

#endif // MMARCHIVO_H
