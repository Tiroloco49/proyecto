#ifndef CAT_H
#define CAT_H
#include "qimage.h"
#include <iostream>
#include <time.h>
using namespace std;


class cat
{
public:
	//ya supe que hacer nojoda y ahora el mundo es mio
    cat();
    void mover(int y, int x,QImage **map,int tam);
    int xCat,yCat,raton;
    QImage layer;
};

#endif // CAT_H
