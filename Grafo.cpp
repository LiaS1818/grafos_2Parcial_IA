#include "Grafo.h"

Grafo::Grafo() {
    primero = nullptr;
    tamano = 0;
}

bool Grafo::EstaVacio()
{
    return tamano == 0;
}

int Grafo::ObtenerTamano()
{
    return tamano;
}

Vertice* Grafo::ObtenerVertice(string nombre)
{
    Vertice* i = primero;

    while (i != NULL)
    {
        if (i->nombre == nombre)
            return i;

        i = i->sig;
    }

    return NULL;
}

void Grafo::InsertaVertice(string nombre)
{
    if (ObtenerVertice(nombre) == NULL)
    {
        Vertice* nuevo = new Vertice(nombre);

        if (EstaVacio())
            primero = nuevo;
        else
        {
            Vertice* i = primero;

            while (i->sig != NULL)
                i = i->sig;

            i->sig = nuevo;
        }

        tamano++;
    }
    else
        cout << "Ese vertice ya existe en el grafo" << endl;
}


void Grafo::InsertaArista(string ori, string dest, int precio)
{
    Vertice* verticeOrigen = ObtenerVertice(ori);
    Vertice* verticeDestino = ObtenerVertice(dest);
    if (verticeOrigen != NULL && verticeDestino != NULL) {
        Arista* nuevaArista = new Arista(verticeDestino, precio);
        nuevaArista->sig = verticeOrigen->ari;
        verticeOrigen->ari = nuevaArista;
    } else {
        cout << "Uno de los vértices no existe." << endl;
    }
}

void Grafo::Kruskal() {
    map<Vertice*, map<Vertice*, int>> matrizDeAdyacencia; // Matriz de adyacencia
    map<Vertice*, map<Vertice*, int>> solucion; // Mapa para la solución
    map<Vertice*, Vertice*> conectados; // Mapa de vértices conectados

    // Inicializa la matriz de adyacencia
    Vertice* vi = primero;
    while (vi != nullptr) {
        conectados[vi] = vi; // Cada vértice se conecta consigo mismo
        Vertice* vj = primero;
        while (vj != nullptr) {
            matrizDeAdyacencia[vi][vj] = 0; // Inicializa la matriz con ceros
            vj = vj->sig; // Siguiente vértice
        }
        Arista* aj = vi->ari; // Arista actual de vi
        while (aj != nullptr) {
            matrizDeAdyacencia[vi][aj->destino] = aj->peso; // Asigna el precio
            aj = aj->sig; // Siguiente arista
        }
        vi = vi->sig; // Siguiente vértice
    }

    Vertice* vA, * vB;
    int aristas = 0; // Comenzar con 0 aristas en la solución

    while (aristas < tamano - 1) { // Debe ser tamano - 1 para formar un MST
        int min = INT_MAX; // Inicializa min con un valor alto
    // Encuentra la arista con el precio mínimo
        for (map<Vertice*, map<Vertice*, int>>::iterator i = matrizDeAdyacencia.begin(); i != matrizDeAdyacencia.end(); i++) {
            for (map<Vertice*, int>::iterator j = i->second.begin(); j != i->second.end(); j++) {
                // Verifica que la arista no esté conectando vértices ya conectados
                if (j->second < min && j->second != 0 && conectados[i->first] != conectados[j->first]) {
                    min = j->second;
                    vA = i->first;
                    vB = j->first;
                }
            }
        }

        if (min != INT_MAX) { // Verifica si se encontró una arista válida
            solucion[vA][vB] = min; // Agrega la arista a la solución

            // Actualiza el mapa de conectados
            Vertice* vTemp = conectados[vB];
            conectados[vB] = conectados[vA];

            for (map<Vertice*, Vertice*>::iterator i = conectados.begin(); i != conectados.end(); i++) {
                if (i->second == vTemp)
                    i->second = conectados[vA];
            }

            aristas++; // Incrementa el contador de aristas
        }
    }

    // Imprime la solución
    cout << "Arbol de expansion minimo:" << endl;
    for (map<Vertice*, map<Vertice*, int>>::iterator i = solucion.begin(); i != solucion.end(); i++) {
        for (map<Vertice*, int>::iterator j = i->second.begin(); j != i->second.end(); j++) {
            cout << i->first->nombre << " --(" << j->second << ")--> " << j->first->nombre << endl;
        }
    }
}

void Grafo::Mostrar() {
    Vertice* i = primero;
    while (i != NULL) {
        cout << i->nombre << " -> ";

        Arista* aristaActual = i->ari; // Suponiendo que `ari` es el puntero a la lista de aristas
        while (aristaActual != NULL) {
            cout << aristaActual->destino->nombre << " --(" << aristaActual->peso << ")--> ";
            aristaActual = aristaActual->sig; // Mueve al siguiente en la lista de aristas
        }

        cout << "NULL" << endl; // Indica el final de la lista de aristas para este vértice
        i = i->sig; // Mueve al siguiente vértice
    }
}


