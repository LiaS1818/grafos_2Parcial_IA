//
// Created by LiaSan on 19/10/2024.
//

#pragma once //Evita que el compilador incluya dos veces el archivo
#include "Vertice.h"
#include "Arista.h"
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_set> //Para evitar repetidos en la lista de adyacencia

using namespace std;

class Grafo {
    Vertice* primero; //Primer vértice
    int tamano; //Número de vértices

public:
    Grafo(); //Constructor
    bool EstaVacio();

    int ObtenerTamano();

    Vertice *ObtenerVertice(string nombre);

    void InsertaVertice(string nombre);

    void InsertaArista(string ori, string dest, int precio);

    void Kruskal(); // Genera el árbol de expansión mínima
    void Mostrar();
};