#ifndef PILA_H
#define PILA_H
#include "nodo.h"

class Pila
{
public:
    // Public Declarations
    Pila();
    void Insertar(int x, int y);
    int Eliminar();
    Nodo *tope;
};

#endif // PILA_H
