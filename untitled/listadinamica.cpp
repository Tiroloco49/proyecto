#include "listadinamica.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void ListaDinamica::Insertar(int x, int y){
    Nodo *nuevo,*ultimo;

    nuevo = new Nodo;
    if(nuevo){
        nuevo->x=x;
        nuevo->y=y;
        if(!cabecera){//1
            cabecera=nuevo;
            //ya tienen el null por defecto
        }else{
            ultimo=cabecera;
            while(ultimo->sucesor!=NULL){
                ultimo=ultimo->sucesor;
            }
            nuevo->sucesor=NULL;
            ultimo->sucesor=nuevo;

        }   
    }else
        cout << "\nNo hay Memoria";    
}
