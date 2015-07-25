#include "mainwindow.h"
#include <iostream>
#include "qwidget.h"
#include "leer_mapa.h"
#include "qobject.h"
#include "qtimer.h"
#include "qbitmap.h"
#include "qgridlayout.h"
#include "qlabel.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    int tam=0;

    
    leer_mapa *obj=new leer_mapa();
    tam=obj->cargarDat();

    QWidget *ventana=new QWidget;
    ventana->setWindowTitle("gato y el raton");

    QGridLayout *layout=new QGridLayout();
    
    //llenando el layout con los labels
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            layout->addWidget(obj->mat[i][j],i,j);
        }
    }

    ventana->setLayout(layout);
    ventana->show();

    obj->crono->start(100);

    return a.exec();
}
