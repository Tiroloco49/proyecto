#ifndef LEER_MAPA_H
#define LEER_MAPA_H
#include <iostream>
#include "qimage.h"
#include "qlabel.h"
#include "qobject.h"
#include "malloc.h"
#include "qtimer.h"
#include "rat.h"
#include "cat.h"
#include "cheese.h"
#include "string.h"
#include "stdlib.h"
using namespace std;


class leer_mapa: public QObject
{
    Q_OBJECT
public:
        leer_mapa();
        int cargarDat();

        QImage **map;
        rat rata;
        cat gato;
        cheese queso;
        QTimer *crono;
        QLabel ***mat;
        int tam;
public slots:
             void mover();
};

#endif // LEER_MAPA_H
