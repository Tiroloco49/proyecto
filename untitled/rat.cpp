#include "rat.h"

rat::rat()
{
layer.load("rat.png");
queso=0;
}

void rat::mover(int y, int x, int yq, int xq, QImage **map, int tam){
    int swGiz=0,swGde=0,swGar=0,swGab=0,swQiz=0,swQde=0,swQar=0,swQab=0;
    int dir=0,diraux;
    srand(time(NULL));

    //ubicando el queso dentro del rango del raton
    if(xq<=xRat+10 && xq>=xRat-10 && yq<=yRat+10 && yq>=yRat-10){

        //IZQUIERDA
        if(xq>=xRat-10 && xq<xRat && yq<=yRat+10 && yq>=yRat-10){
            swQiz=1;
        }
        //DERECHA
        if(xq<=xRat+10 && xq>xRat && yq<=yRat+10 && yq>=yRat-10){
            swQde=1;
        }
        //ARRIBA
        if(yq>=yRat-10 && yq<yRat && xq<=xRat+10 && xq>=xRat-10){
            swQar=1;
        }
        //ABAJO
        if(yq<=yRat+10 && yq>yRat && xq<=xRat+10 && xq>=xRat-10){
            swQab=1;
        }



    }

//ubicando el gato dentro del rango del raton
    if(x<=xRat+3 && x>=xRat-3 && y<=yRat+3 && y>=yRat-3){

        //IZQUIERDA
        if(x>=xRat-3 && x<xRat && y<=yRat+3 && y>=yRat-3){
            swGiz=1;
        }
        //DERECHA
        if(x<=xRat+3 && x>xRat && y<=yRat+3 && y>=yRat-3){
            swGde=1;
        }
        //ARRIBA
        if(y>=yRat-3 && y<yRat && x<=xRat+3 && x>=xRat-3){
            swGar=1;
        }
        //ABAJO
        if(y<=yRat+3 && y>yRat && x<=xRat+10 && x>=xRat-3){
            swGab=1;
        }

    }


    //para el queso___________________________________________________________
    //si se consigue el queso, se indica la direccion en la que se movera
    if(swQiz && swQar)//esquina superior izquierda
        dir=8;
    else
    if(swQiz && swQab)//esquina inferior izquierda
        dir=6;
    else
    if(swQde && swQar)//esquina superior derecha
        dir=2;
    else
    if(swQde && swQab)//esquina inferior derecha
        dir=4;
    else
    if(swQab)//abajo
        dir=5;
    else
    if(swQar)//arriba
        dir=1;
    else
    if(swQiz)//izquierda
        dir=7;
    else
    if(swQde)//derecha
        dir=3;

    //para el gato_________________________________________________-
   // si se consige el gato se indica la direccion para escapar

    if(swGiz && swGar){//esquina superior izquierda
        dir=rand()%5+2;
        diraux=1;
    }else
    if(swGiz && swGab){//esquina inferior izquierda
        dir=rand()%4+1;
        diraux=4;
    }else
    if(swGde && swGar){//esquina superior derecha
        dir=rand()%5+4;
        diraux=2;
    }else
    if(swGde && swGab){//esquina inferior derecha
        dir=rand()%3+6;
        diraux=3;
    }else
    if(swGab){//abajo
        dir=rand()%3+1;
        diraux=6;
    }else
    if(swGar){//arriba
        dir=rand()%5+3;
        diraux=5;
    }else
    if(swGiz){//izquierda
        dir=rand()%5+1;
        diraux=7;
    }else
    if(swGde){//derecha
        dir=rand()%4+5;
        diraux=8;
    }
    if(!dir){

        dir=rand()%8+1;
    }


    //para limites____________________________________________________________
    //si es esta en los limites del mapa
    if(yRat==0 && xRat==0){//esquina superior izquierda
        if(diraux==8){//condicionales si esta entre el gato y la pared
            dir=5;
        }else
        if(diraux==3){

          dir=rand()%1;
           if(dir)
                dir=3;
            else
                dir=5;

        }else
        if(diraux==6){
            dir=3;
        }else
        dir=rand()%3+3;
    }else
    if(yRat==0 && xRat==tam-1){//esquina superior derecha
        if(diraux==7){//condicionales si esta entre el gato y la pared
            dir=5;
        }else
        if(diraux==4){

          dir=rand()%1;
           if(dir)
                dir=3;
            else
                dir=7;

        }else
        if(diraux==6){
            dir=7;
        }else
        dir=rand()%3+5;
    }else
    if(yRat==tam-1 && xRat==tam-1){//esquina inferior derecha
        if(diraux==5){//condicionales si esta entre el gato y la pared
            dir=7;
        }else
        if(diraux==1){

          dir=rand()%1;
           if(dir)
                dir=7;
            else
                dir=5;

        }else
        if(diraux==7){
            dir=5;
        }else
        dir=rand()%2+7;
    }else
    if(yRat==tam-1 && xRat==0){//esquina inferior izquierda
        if(diraux==8){//condicionales si esta entre el gato y la pared
            dir=5;
        }else
        if(diraux==2){

          dir=rand()%1;
           if(dir)
                dir=8;
            else
                dir=5;

        }else
        if(diraux==5){
            dir=8;
        }else
        dir=rand()%3+1;
    }else
        //CRASHEA SI SE ENCUENTRA ACORRALADO
    if(yRat==0){//arriba
        //falta poner las condiciones por si esta entre el gato y la pared
        dir=rand()%5+3;
    }else
    if(yRat==tam-1){//abajo
        //falta poner las condiciones por si esta entre el gato y la pared
        dir=rand()%1;
        if(dir==0)
            dir=rand()%3+1;
        else
            dir=rand()%2+7;
    }else
    if(xRat==0){//izquierda
        //falta poner las condiciones por si esta entre el gato y la pared
         dir=rand()%5+1;
    }else
    if(xRat==tam-1){//derecha
        //falta poner las condiciones por si esta entre el gato y la pared
         dir=rand()%4+5;
    }

    //switch para moverse

    switch(dir){

    case 1:
            yRat--;
        break;

    case 2:
        yRat--;
        xRat++;
        break;

    case 3:
        xRat++;
        break;

    case 4:
        yRat++;
        xRat++;
        break;

    case 5:
        yRat++;
        break;

    case 6:
        yRat++;
        xRat--;
        break;

    case 7:
        xRat--;
        break;

    case 8:
        yRat--;
        xRat--;
        break;

    }

    if(xRat==xq && yRat==yq){//si se come el queso

        queso=1;
    }



}
