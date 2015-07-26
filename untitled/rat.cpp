#include "rat.h"

rat::rat()
{
layer.load("rat.png");
queso=0;
}

void rat::mover(int y, int x, int yq, int xq, QImage **map, int tam){
    int swGiz=0,swGde=0,swGar=0,swGab=0,swQiz=0,swQde=0,swQar=0,swQab=0;
    int dir=0,pared1=0,pared2=0,pared3=0,pared4=0,pared5=0,pared6=0,pared7=0,pared8=0;
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
//paredes######################################################################
 if(yRat!=tam-1 && xRat!=tam-1)
    if(map[yRat+1][xRat+1].colorCount()==1)
        pared4=1;
 if(yRat!=tam-1 && xRat!=0)
    if(map[yRat+1][xRat-1].colorCount()==1)
        pared6=1;
 if(yRat!=0)
    if(map[yRat+1][xRat].colorCount()==1)
        pared5=1;
 if(yRat!=0 && xRat!=tam-1)
    if(map[yRat-1][xRat+1].colorCount()==1)
        pared2=1;
 if(yRat!=0 && xRat!=0)
    if(map[yRat-1][xRat-1].colorCount()==1)
        pared8=1;
 if(yRat!=0)
    if(map[yRat-1][xRat].colorCount()==1)
        pared1=1;
if(xRat!=tam-1)
    if(map[yRat][xRat+1].colorCount()==1)
        pared3=1;
if(xRat!=0)
    if(map[yRat][xRat-1].colorCount()==1)
        pared7=1;

//para el rato#####################################################################
    if(swQiz && swQar){//esquina superior izquierda

        if(!pared8)
            dir=8;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared5)
            dir=5;

    }else
    if(swQiz && swQab){//esquina inferior izquierda
        if(!pared6)
            dir=6;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared5)
            dir=5;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared2)
            dir=2;
    }else
    if(swQde && swQar){//esquina superior derecha
        if(!pared2)
            dir=2;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared5)
            dir=5;
        else
        if(!pared6)
            dir=6;
    }else
    if(swQde && swQab){//esquina inferior derecha
        if(!pared4)
            dir=4;
        else
        if(!pared5)
            dir=5;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared8)
            dir=8;
    }else
    if(swQab){//abajo
        if(!pared5)
            dir=5;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared1)
            dir=1;
    }else
    if(swQar){//arriba
        if(!pared1)
            dir=1;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared5)
            dir=5;
    }else
    if(swQiz){//izquierda
        if(!pared7)
            dir=7;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared5)
            dir=5;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared3)
            dir=3;
    }else
    if(swQde){//derecha
        if(!pared3)
            dir=3;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared5)
            dir=5;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared7)
            dir=7;
    }

 //para el gato##################################################################
    if(swGiz && swGar){//esquina superior izquierda
                if(!pared4)
                    dir=4;
                else
                if(!pared5)
                    dir=5;
                else
                if(!pared3)
                    dir=3;
                else
                if(!pared6)
                    dir=6;
                else
                if(!pared2)
                    dir=2;
                else
                if(!pared7)
                    dir=7;
                else
                if(!pared1)
                    dir=1;
                else
                if(!pared8)
                    dir=8;
    }else
    if(swGiz && swGab){//esquina inferior izquierda
        if(!pared2)
            dir=2;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared5)
            dir=5;
        else
        if(!pared6)
            dir=6;
    }else
    if(swGde && swGar){//esquina superior derecha
        if(!pared6)
            dir=6;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared5)
            dir=5;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared2)
            dir=2;
    }else
    if(swGde && swGab){//esquina inferior derecha
        if(!pared8)
            dir=8;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared5)
            dir=5;
    }else
    if(swGab){//abajo
        if(!pared1)
            dir=1;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared5)
            dir=5;
    }else
    if(swGar){//arriba
        if(!pared5)
            dir=5;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared7)
            dir=7;
        else
        if(!pared3)
            dir=3;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared1)
            dir=1;
    }else
    if(swGiz){//izquierda
        if(!pared3)
            dir=3;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared5)
            dir=5;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared7)
            dir=7;
    }else
    if(swGde){//derecha
        if(!pared7)
            dir=7;
        else
        if(!pared8)
            dir=8;
        else
        if(!pared6)
            dir=6;
        else
        if(!pared1)
            dir=1;
        else
        if(!pared5)
            dir=5;
        else
        if(!pared2)
            dir=2;
        else
        if(!pared4)
            dir=4;
        else
        if(!pared3)
            dir=3;
    }

 //para limites gato y queso###################################################

    if(yRat==0 && xRat==0){//esquina superior izquierda

        if(pared3 && !pared4 && !pared5){//######################
            if(swGab && swGde)
                dir=5;
            else
            if(swGab && !swGde)
                dir=4;
            else
            if(!swGab && !swGde){
                if(xRat+1==xq && yRat+1==yq)
                    dir=4;
                else
                if(xRat==xq && yRat+1==yq)
                    dir=5;
                else
                dir=rand()%2+4;
            }

        }else
        if(!pared3 && pared4 && !pared5){//#########################
            if(!swGab && swGde)
                dir=5;
            else
            if(swGab && !swGde)
                dir=3;
            else
            if(!swGab && !swGde){
                if(xRat==xq && yRat+1==yq)
                    dir=5;
                else
                if(xRat+1==xq && yRat==yq)
                    dir=3;
                else{
                dir=rand()%2;
                if(dir)
                    dir=3;
                else
                    dir=5;
                }
            }

        }else
        if(!pared3 && !pared4 && pared5){//############################
            if(swGab && swGde)
                dir=3;
            else
            if(!swGab && swGde)
                dir=4;
            else
            if(!swGab && !swGde){
                if(xRat+1==xq && yRat+1==yq)
                    dir=4;
                else
                if(xRat+1==xq && yRat==yq)
                    dir=3;
                else{
                dir=rand()%2+3;
                }
            }
        }else
        if(pared3 && pared4 && !pared5){//##############################
            if(swGab)
                dir=0;
            else
            if(!swGab)
                dir=5;

        }else
        if(pared3 && !pared4 && pared5){//###############################
            if(swGab && swGde)
                dir=0;
            else
            if(!swGab && !swGde)
                dir=4;
        }else
        if(!pared3 && pared4 && pared5){//################################

            if(swGde)
                dir=0;
            else
            if(!swGde)
                dir=3;
        }else
        if(!pared3 && !pared4 && !pared5){//################################
            if(!swGab && swGde){
                if(xRat+1==xq && yRat+1==yq)
                    dir=4;
                else
                if(xRat==xq && yRat+1==yq)
                    dir=5;
                else
                dir=rand()%2+4;
            }else
            if(swGab && swGde){
                if(xRat==xq && yRat+1==yq)
                    dir=5;
                else
                if(xRat+1==xq && yRat==yq)
                    dir=3;
                else{
                dir=rand()%2;
                if(dir)
                    dir=3;
                else
                    dir=5;
                }

            }else
            if(swGab && !swGde){
                if(xRat+1==xq && yRat+1==yq)
                    dir=4;
                else
                if(xRat+1==xq && yRat==yq)
                    dir=3;
                else{
                dir=rand()%2+3;
                }

            }else
            if(!swGab && !swGde){
                if(xRat+1==xq && yRat+1==yq)
                    dir=4;
                else
                if(xRat+1==xq && yRat==yq)
                    dir=3;
                else
                if(xRat==xq && yRat+1==yq)
                    dir=5;
                else
                dir=rand()%3+3;
                }
         }
    }else

    if(yRat==0 && xRat==tam-1){//esquina superior derecha

        if(pared7 && !pared6 && !pared5){//######################
            if(swGab && swGiz)
                dir=5;
            else
            if(swGab && !swGiz)
                dir=6;
            else
            if(!swGab && !swGiz){
                if(xRat-1==xq && yRat+1==yq)
                    dir=6;
                else
                if(xRat==xq && yRat+1==yq)
                    dir=5;
                else
                dir=rand()%2+5;
            }

        }else
        if(!pared7 && pared6 && !pared5){//#########################
            if(!swGab && swGiz)
                dir=5;
            else
            if(swGab && !swGiz)
                dir=7;
            else
            if(!swGab && !swGiz){
                if(xRat==xq && yRat+1==yq)
                    dir=5;
                else
                if(xRat-1==xq && yRat==yq)
                    dir=7;
                else{
                dir=rand()%2;
                if(dir)
                    dir=7;
                else
                    dir=5;
                }
            }

        }else
        if(!pared7 && !pared6 && pared5){//############################
            if(swGab && swGiz)
                dir=7;
            else
            if(!swGab && swGiz)
                dir=6;
            else
            if(!swGab && !swGiz){
                if(xRat-1==xq && yRat+1==yq)
                    dir=6;
                else
                if(xRat-1==xq && yRat==yq)
                    dir=7;
                else{
                dir=rand()%2+6;
                }
            }
        }else
        if(pared7 && pared6 && !pared5){//##############################
            if(swGab)
                dir=0;
            else
            if(!swGab)
                dir=5;

        }else
        if(pared7 && !pared6 && pared5){//###############################
            if(swGab && swGiz)
                dir=0;
            else
            if(!swGab && !swGiz)
                dir=6;
        }else
        if(!pared7 && pared6 && pared5){//################################

            if(swGiz)
                dir=0;
            else
            if(!swGiz)
                dir=7;
        }else
        if(!pared7 && !pared6 && !pared5){//################################
            if(!swGab && swGiz){
                if(xRat-1==xq && yRat+1==yq)
                    dir=6;
                else
                if(xRat==xq && yRat+1==yq)
                    dir=5;
                else
                dir=rand()%2+5;
            }else
            if(swGab && swGiz){
                if(xRat==xq && yRat+1==yq)
                    dir=5;
                else
                if(xRat-1==xq && yRat==yq)
                    dir=7;
                else{
                dir=rand()%2;
                if(dir)
                    dir=7;
                else
                    dir=5;
                }

            }else
            if(swGab && !swGiz){
                if(xRat-1==xq && yRat+1==yq)
                    dir=6;
                else
                if(xRat-1==xq && yRat==yq)
                    dir=7;
                else{
                dir=rand()%2+6;
                }

            }else
            if(!swGab && !swGde){
                if(xRat-1==xq && yRat+1==yq)
                    dir=6;
                else
                if(xRat-1==xq && yRat==yq)
                    dir=7;
                else
                if(xRat==xq && yRat+1==yq)
                    dir=5;
                else
                dir=rand()%3+5;
                }
         }
    }else

    if(yRat==tam-1 && xRat==tam-1){//esquina inferior derecha

        if(pared7 && !pared8 && !pared1){//######################
            if(swGar && swGiz)
                dir=1;
            else
            if(swGar && !swGiz)
                dir=8;
            else
            if(!swGar && !swGiz){
                if(xRat-1==xq && yRat-1==yq)
                    dir=8;
                else
                if(xRat==xq && yRat-1==yq)
                    dir=1;
                else
                dir=rand()%2;
                if(!dir)
                    dir=8;
            }

        }else
        if(!pared7 && pared8 && !pared1){//#########################
            if(!swGar && swGiz)
                dir=1;
            else
            if(swGar && !swGiz)
                dir=7;
            else
            if(!swGar && !swGiz){
                if(xRat==xq && yRat-1==yq)
                    dir=1;
                else
                if(xRat-1==xq && yRat==yq)
                    dir=7;
                else{
                dir=rand()%2;
                if(dir)
                    dir=7;
                else
                    dir=1;
                }
            }

        }else
        if(!pared7 && !pared8 && pared1){//############################
            if(swGar && swGiz)
                dir=7;
            else
            if(!swGar && swGiz)
                dir=8;
            else
            if(!swGar && !swGiz){
                if(xRat-1==xq && yRat-1==yq)
                    dir=8;
                else
                if(xRat-1==xq && yRat==yq)
                    dir=7;
                else{
                dir=rand()%2+7;
                }
            }
        }else
        if(pared7 && pared8 && !pared1){//##############################
            if(swGar)
                dir=0;
            else
            if(!swGar)
                dir=1;

        }else
        if(pared7 && !pared8 && pared1){//###############################
            if(swGar && swGiz)
                dir=0;
            else
            if(!swGar && !swGiz)
                dir=8;
        }else
        if(!pared7 && pared8 && pared1){//################################

            if(swGiz)
                dir=0;
            else
            if(!swGiz)
                dir=7;
        }else
        if(!pared7 && !pared8 && !pared1){//################################
            if(!swGar && swGiz){
                if(xRat-1==xq && yRat-1==yq)
                    dir=8;
                else
                if(xRat==xq && yRat-1==yq)
                    dir=1;
                else
                dir=rand()%2+5;
            }else
            if(swGar && swGiz){
                if(xRat==xq && yRat-1==yq)
                    dir=1;
                else
                if(xRat-1==xq && yRat==yq)
                    dir=7;
                else{
                dir=rand()%2;
                if(dir)
                    dir=7;
                else
                    dir=1;
                }

            }else
            if(swGar && !swGiz){
                if(xRat-1==xq && yRat-1==yq)
                    dir=8;
                else
                if(xRat-1==xq && yRat==yq)
                    dir=7;
                else{
                dir=rand()%2+7;
                }

            }else
            if(!swGar && !swGde){
                if(xRat-1==xq && yRat-1==yq)
                    dir=8;
                else
                if(xRat-1==xq && yRat==yq)
                    dir=7;
                else
                if(xRat==xq && yRat-1==yq)
                    dir=1;
                else{
                dir=rand()%3+7;
                if(dir==9)
                    dir=1;
                }
             }
         }
    }else

    if(yRat==tam+1 && xRat==0){//esquina inferior izquierda

        if(pared3 && !pared2 && !pared1){//######################
            if(swGar && swGde)
                dir=1;
            else
            if(swGar && !swGde)
                dir=2;
            else
            if(!swGar && !swGde){
                if(xRat+1==xq && yRat-1==yq)
                    dir=2;
                else
                if(xRat==xq && yRat-1==yq)
                    dir=1;
                else
                dir=rand()%2+2;
            }

        }else
        if(!pared3 && pared2 && !pared1){//#########################
            if(!swGar && swGde)
                dir=1;
            else
            if(swGar && !swGde)
                dir=3;
            else
            if(!swGar && !swGde){
                if(xRat==xq && yRat-1==yq)
                    dir=1;
                else
                if(xRat+1==xq && yRat==yq)
                    dir=3;
                else{
                dir=rand()%2;
                if(dir)
                    dir=3;
                else
                    dir=1;
                }
            }

        }else
        if(!pared3 && !pared2 && pared1){//############################
            if(swGar && swGde)
                dir=3;
            else
            if(!swGar && swGde)
                dir=2;
            else
            if(!swGar && !swGde){
                if(xRat+1==xq && yRat-1==yq)
                    dir=2;
                else
                if(xRat+1==xq && yRat==yq)
                    dir=3;
                else{
                dir=rand()%2+2;
                }
            }
        }else
        if(pared3 && pared2 && !pared1){//##############################
            if(swGar)
                dir=0;
            else
            if(!swGab)
                dir=1;

        }else
        if(pared3 && !pared2 && pared1){//###############################
            if(swGar && swGde)
                dir=0;
            else
            if(!swGar && !swGde)
                dir=2;
        }else
        if(!pared3 && pared2 && pared1){//################################

            if(swGde)
                dir=0;
            else
            if(!swGde)
                dir=3;
        }else
        if(!pared3 && !pared2 && !pared1){//################################
            if(!swGar && swGde){
                if(xRat+1==xq && yRat-1==yq)
                    dir=2;
                else
                if(xRat==xq && yRat-1==yq)
                    dir=1;
                else
                dir=rand()%2+1;
            }else
            if(swGar && swGde){
                if(xRat==xq && yRat-1==yq)
                    dir=1;
                else
                if(xRat+1==xq && yRat==yq)
                    dir=3;
                else{
                dir=rand()%2;
                if(dir)
                    dir=3;
                else
                    dir=1;
                }

            }else
            if(swGar && !swGde){
                if(xRat+1==xq && yRat-1==yq)
                    dir=2;
                else
                if(xRat+1==xq && yRat==yq)
                    dir=3;
                else{
                dir=rand()%2+2;
                }

            }else
            if(!swGar && !swGde){
                if(xRat+1==xq && yRat-1==yq)
                    dir=2;
                else
                if(xRat+1==xq && yRat==yq)
                    dir=3;
                else
                if(xRat==xq && yRat-1==yq)
                    dir=1;
                else
                dir=rand()%3+1;
                }
         }
    }else

    if(yRat==0){//arriba

                if(swGiz && !swGde && !swGab && !swGar){//izquierda
                    dir=rand()%3+3;
                }else
                if(swGiz && !swGde && swGab && !swGar){//inferior izquierda
                    dir=rand()%2+3;
                }else
                if(!swGiz && !swGde && swGab && !swGar){//abajo
                    dir=rand()%2;
                    if(dir)
                        dir=3;
                    else
                        dir=7;
                }else
                if(!swGiz && swGde && swGab && !swGar){//inferior derecho
                    dir=rand()%2+6;
                }else
                if(!swGiz && swGde && !swGab && !swGar){//derecha
                    dir=rand()%3+5;
                }else

                    if(xRat-1==xq && yRat==yq){//condicionales si esta entre el queso y la pared
                        dir=7;
                    }else
                    if(xRat-1==xq && yRat+1==yq){
                        dir=6;
                    }else
                    if(xRat==xq && yRat+1==yq){
                        dir=5;
                    }else
                    if(xRat+1==xq && yRat+1==yq){
                        dir=4;
                    }else
                    if(xRat-1==xq && yRat==yq){
                        dir=3;
                    }else
                    dir=rand()%5+3;

    }else

    if(yRat==tam-1){//abajo


        if(swGiz && !swGde && !swGab && !swGar){//izquierda
            dir=rand()%3+1;
        }else
        if(swGiz && !swGde && !swGab && swGar){//superior izquierda
            dir=rand()%2+2;
        }else
        if(!swGiz && !swGde && !swGab && swGar){//arriba
            dir=rand()%2;
            if(dir)
                dir=3;
            else
                dir=7;
        }else
        if(!swGiz && swGde && !swGab && swGar){//superior derecho
            dir=rand()%2+7;
        }else
        if(!swGiz && swGde && !swGab && !swGar){//derecha
            dir=rand()%3+7;
            if(dir==9)
                dir=1;
        }else{
            if(xRat-1==xq && yRat==yq){//condicionales si esta entre el queso y la pared
                dir=7;
            }else
            if(xRat-1==xq && yRat-1==yq){
                dir=8;
            }else
            if(xRat==xq && yRat-1==yq){
                dir=1;
            }else
            if(xRat-1==xq && yRat-1==yq){
                dir=2;
            }else
            if(xRat-1==xq && yRat==yq){
                dir=3;
            }else
            dir=rand()%5+7;
            if(dir==9)
                dir=1;
            if(dir==10)
                dir=2;
            if(dir==11)
                dir=3;
        }

    }else

    if(xRat==0){//izquierda

        if(!swGiz && !swGde && !swGab && swGar){//arriba
                    dir=rand()%3+3;
                }else
                if(!swGiz && swGde && !swGab && swGar){//superior derecho
                    dir=rand()%2+4;
                }else
                if(!swGiz && swGde && !swGab && !swGar){//derecha
                    dir=rand()%2;
                    if(dir)
                        dir=1;
                    else
                        dir=5;
                }else
                if(!swGiz && swGde && swGab && !swGar){//inferior derecho
                    dir=rand()%2+1;
                }else
                if(!swGiz && !swGde && swGab && !swGar){//abajo
                    dir=rand()%3+1;
                }else
                    if(xRat+1==xq && yRat+1==yq){//condicionales si esta entre el queso y la pared
                        dir=4;
                    }else
                    if(xRat==xq && yRat+1==yq){
                        dir=5;
                    }else
                    if(xRat==xq && yRat-1==yq){
                        dir=1;
                    }else
                    if(xRat-1==xq && yRat-1==yq){
                        dir=2;
                    }else
                    if(xRat-1==xq && yRat==yq){
                        dir=3;
                    }else
                 dir=rand()%5+1;



    }else

    if(xRat==tam-1){//derecha


        if(!swGiz && !swGde && !swGab && swGar){//arriba
            dir=rand()%3+5;
        }else
        if(swGiz && !swGde && !swGab && swGar){//superior izquierdo
            dir=rand()%2+5;
        }else
        if(swGiz && !swGde && !swGab && !swGar){//izquierda
            dir=rand()%2;
            if(dir)
                dir=1;
            else
                dir=5;
        }else
        if(swGiz && !swGde && swGab && !swGar){//inferior izquierdo
            dir=rand()%2+8;
            if(dir==9)
                dir=1;
        }else
        if(!swGiz && !swGde && swGab && !swGar){//abajo
            dir=rand()%3+7;
            if(dir==9)
                dir=1;
        }else
            if(xRat-1==xq && yRat==yq){//condicionales si esta entre el queso y la pared
                dir=7;
            }else
            if(xRat-1==xq && yRat-1==yq){
                dir=8;
            }else
            if(xRat==xq && yRat-1==yq){
                dir=1;
            }else
            if(xRat==xq && yRat+1==yq){
                dir=5;
            }else
            if(xRat-1==xq && yRat+1==yq){
                dir=6;
            }else
         dir=rand()%5+5;
        if(dir==9)
            dir=1;



    }

    //switch para moverse
    cout<<"raton:"<<dir<<endl;
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

        //queso=1;
    }



}
