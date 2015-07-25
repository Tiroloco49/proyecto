#include "cat.h"

cat::cat()
{
layer.load("cat.png");
raton=0;
}

void cat::mover(int y, int x, QImage **map, int tam){
    int swRiz=0,swRde=0,swRar=0,swRab=0,dir=0;
     srand(time(NULL));
//ubicando el raton dentro del rango del gato

    if(x<=xCat+2 && x>=xCat-2 && y<=yCat+2 && y>=yCat-2){
        //IZQUIERDA
        if(x>=xCat-2 && x<xCat && y<=yCat+2 && y>=yCat-2){
            swRiz=1;
        }
        //DERECHA
        if(x<=xCat+2 && x>xCat && y<=yCat+2 && y>=yCat-2){
            swRde=1;
        }
        //ARRIBA
        if(y>=yCat-2 && y<yCat && x<=xCat+2 && x>=xCat-2){
            swRar=1;
        }
        //ABAJO
        if(y<=yCat+2 && y>yCat && x<=xCat+2 && x>=xCat-2){
            swRab=1;
        }

    }

    //para el raton___________________________________________________________

//si se consigue el raton, se prosigue a indicar direccion del movimiento
    if(swRiz && swRar){//esquina superior izquierda
        if((xCat-1==x && yCat-1==y) || (xCat-2==x && yCat-2==y)){
            dir=rand()%2;
          if(dir)
              dir;
           else
              dir=4;
        }
        if(xCat-1==x && yCat-2==y)
           dir=1;
        if(xCat-2==x && yCat-1==y){
           dir=4;
        }
    }else
    if(swRiz && swRab){//esquina inferior izquierda

        if((xCat-1==x && yCat+1==y) || (xCat-2==x && yCat+2==y)){
            dir=rand()%2;
          if(dir)
              dir=2;
           else
              dir=4;
        }
        if(xCat-1==x && yCat+2==y)
           dir=2;
        if(xCat-2==x && yCat+1==y){
           dir=4;
        }


    }else
    if(swRde && swRar){//esquina superior derecha


        if((xCat+1==x && yCat-1==y) || (xCat+2==x && yCat-2==y)){
            dir=rand()%2;
          if(dir)
              dir=1;
           else
              dir=3;
        }
        if(xCat+1==x && yCat-2==y)
           dir=1;
        if(xCat+2==x && yCat-1==y)
           dir=3;

    }else
    if(swRde && swRab){//esquina inferior derecha

        if((xCat+1==x && yCat+1==y) || (xCat+2==x && yCat+2==y)){
            dir=rand()%2;
          if(dir)
              dir=2;
           else
              dir=3;
        }
        if(xCat+1==x && yCat+2==y)
           dir=2;
        if(xCat+2==x && yCat+1==y)
           dir=3;
    }else
    if(swRab){//abajo
        dir=2;
    }else
    if(swRar){//arriba
        dir=1;
    }else
    if(swRde){//derecha
        dir=3;
    }else
    if(swRiz){//izquierda
        dir=3;
    }


   //para los limites______________________________________________________________

//se pasa a indicar la direccion del movimiento si esta en los limites del mapa
    if(yCat==0 && xCat==0){

        if(swRde && !swRab)//si el raton esta a la derecha
            dir=3;
        else
            if(!swRde && swRab)//si el raton esta abajo
                dir=2;
        else{//si esta diagonal

            dir=rand()%2;
            if(dir)
                dir=3;
            else
                dir=2;
            }
    }else
    if(yCat==0 && xCat==tam-1){

    if(swRiz && !swRab)//si el raton esta a la izquierda
            dir=4;
    else
       if(!swRiz && swRab)//si el raton esta abajo
                dir=2;
    else{//si esta diagonal

        dir=rand()%2;
        if(dir)
            dir=4;
        else
            dir=2;
    }
    }else
    if(yCat==tam-1 && xCat==tam-1){
   if(swRiz && !swRar)//si el raton esta a la izquierda
         dir=4;
   else
     if(!swRiz && swRar)//si el raton esta arriba
         dir=1;
   else{//si esta diagonal

        dir=rand()%2;
        if(dir)
            dir=4;
        else
            dir=1;
    }

    }else
    if(yCat==tam-1 && xCat==0){

    if(swRde && !swRar)//si el raton esta a la derecha
         dir=3;
   else
     if(!swRde && swRar)//si el raton esta arriba
          dir=1;
   else{//si esta diagonal

        dir=rand()%2;
        if(dir)
            dir=1;
        else
            dir=3;
       }

    }else
    if(yCat==0){

        if(swRde && !swRab && !swRiz){//si el raton esta a la derecha
            dir=3;
        }else
        if(!swRde && swRab && !swRiz){//si el raton esta abajo
           dir=2;
        }else
        if(!swRde && !swRab && swRiz){//si el raton esta a la izquierda
            dir=4;
        }else
        dir=rand()%2+3;

    }else
    if(yCat==tam-1){

        if(swRde && !swRar && !swRiz){//si el raton esta a la derecha
            dir=3;
        }else
        if(!swRde && swRar && !swRiz){//si el raton esta arriba
           dir=1;
        }else
        if(!swRde && !swRar && swRiz){//si el raton esta a la izquierda
            dir=4;
        }else
        dir=rand()%3+1;
        if(dir==2)
            dir=4;
    }else
    if(xCat==0){
        if(swRde && !swRab && !swRar){//si el raton esta a la derecha
            dir=3;
        }else
        if(!swRde && swRab && !swRar){//si el raton esta abajo
           dir=2;
        }else
        if(!swRde && !swRab && swRar){//si el raton esta arriba
            dir=1;
        }else
         dir=rand()%3+1;
    }else
    if(xCat==tam-1){
        if(swRiz && !swRab && !swRar){//si el raton esta a la izquierda
            dir=4;
        }else
        if(!swRiz && swRab && !swRar){//si el raton esta abajo
           dir=2;
        }else
        if(!swRiz && !swRab && swRar){//si el raton esta arriba
            dir=1;
        }else
         dir=rand()%3+1;
        if(dir==3)
            dir=4;
    }

    //si el raton no es encontrado y la direcion es 0
    if(!dir){//______________________________________________________________

        dir=rand()%4+1;
    }


    //switch para moverse
    switch(dir){

    case 1:
        yCat--;
        break;

    case 2:
        yCat++;
        break;

    case 3:
        xCat++;
        break;

    case 4:
        xCat--;
        break;


    }
    if(xCat==x && yCat==y){//si el gato mato al raton

        raton=1;
    }
}
