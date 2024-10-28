#ifndef ARISTA_H
#define ARISTA_H

#include <string>
using namespace std;

// Forward declaration of the Vertice class
class Vertice;

class Arista {
public:
    Vertice* destino; // Puntero al vértice de destino
    int peso;         // Peso de la arista
    Arista* sig;     // Puntero a la siguiente arista en la lista

    // Constructor
    Arista(Vertice* destino, int peso);
};

#endif // ARISTA_H
