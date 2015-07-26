#include <cstdlib>
#include <iostream>
#include "Pila.h"

using namespace std;

Pila::Pila(){
}

void Pila::Insertar(int x, int y){
    Nodo *nuevo;
    nuevo = new Nodo;
    if(nuevo){
        nuevo->x=x;
        nuevo->y=y;
        nuevo->predecesor=tope;
        tope=nuevo;
    }else
        cout << "\nNo hay Memoria";
}

int Pila::Eliminar(){

    if(tope){
        Nodo *elimina;
        elimina=tope;
        tope=tope->predecesor;
        delete(elimina);
        return 1;
    }else
        cout << "\nPila Vacia";

    return 0;
}
