#ifndef RAT_H
#define RAT_H
#include "qimage.h"
#include <iostream>
#include <time.h>
using namespace std;

class rat
{
public:
    rat();
    void mover(int y, int x, int yq, int xq,QImage **map,int tam);
    int xRat,yRat;
    int queso;
    QImage layer;
};

#endif // RAT_H
