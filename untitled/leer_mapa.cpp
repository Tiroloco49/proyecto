#include "leer_mapa.h"

leer_mapa::leer_mapa()
{
crono=new QTimer(this);
connect(crono,SIGNAL(timeout()),this,SLOT(mover()));
}

int leer_mapa::cargarDat(){

    FILE *fp;
    char aux[100],*aux2;
    int aux3;

    fp=fopen("data.txt","r");
    if(fp){

        fgets(aux,100,fp);
        tam=atoi(aux);

		//primer nivel de memoria
        mat=new QLabel **[tam];
        map=new QImage *[tam];
        
		//segunndo nivel de memoria
        for (int i = 0; i < tam; i++) {
            mat[i]=new QLabel*[tam];
            map[i]=new QImage[tam];
        }

		//tercer nivel de memoria
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                mat[i][j]=new QLabel();
            }
        }


	//cargando los datos
        fgets(aux,100,fp);
        aux2=strtok(aux,",");
        gato.yCat=atoi(aux2);
        aux2=strtok(NULL,"\n");
        gato.xCat=atoi(aux2);

        fgets(aux,100,fp);
        aux2=strtok(aux,",");
        rata.yRat=atoi(aux2);
        aux2=strtok(NULL,"\n");
        rata.xRat=atoi(aux2);

        fgets(aux,100,fp);
        aux2=strtok(aux,",");
        queso.yCheese=atoi(aux2);
        aux2=strtok(NULL,"\n");
        queso.xCheese=atoi(aux2);

        //llenando la matriz con el mapa
        for (int i=0; i<tam; i++){

            for (int j=0; j<tam+1; j++){

                aux3=fgetc(fp);

                if(aux3==48){
                   map[i][j].load("2.png");
                   map[i][j].setColorCount(2);
                   mat[i][j]->setPixmap(QPixmap::fromImage(map[i][j]));

                }else if(aux3==49){
                    map[i][j].load("1.png");
                    map[i][j].setColorCount(1);
                    mat[i][j]->setPixmap(QPixmap::fromImage(map[i][j]));

                }


            }
        }

        //ubicando los personajes
       mat[rata.yRat][rata.xRat]->setPixmap(QPixmap::fromImage(rata.layer));
       mat[gato.yCat][gato.xCat]->setPixmap(QPixmap::fromImage(gato.layer));
       mat[queso.yCheese][queso.xCheese]->setPixmap(QPixmap::fromImage(queso.layer));


    }

    return tam;
}

void leer_mapa::mover(){

    //restablecer el cuadro blanco donde estaba el gato y el raton
    mat[rata.yRat][rata.xRat]->setPixmap(QPixmap::fromImage(map[rata.yRat][rata.xRat]));
    mat[gato.yCat][gato.xCat]->setPixmap(QPixmap::fromImage(map[gato.yCat][gato.xCat]));

    rata.mover(gato.yCat,gato.xCat,queso.yCheese,queso.xCheese,map,tam);
    if(rata.queso)
        crono->stop();

    gato.mover(rata.yRat,rata.xRat,map,tam);

    if(gato.raton)
        crono->stop();

    //ubicar la imagen en la nueva posicion
    mat[queso.yCheese][queso.xCheese]->setPixmap(QPixmap::fromImage(queso.layer));
    mat[rata.yRat][rata.xRat]->setPixmap(QPixmap::fromImage(rata.layer));
    mat[gato.yCat][gato.xCat]->setPixmap(QPixmap::fromImage(gato.layer));

}
