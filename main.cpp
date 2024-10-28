#include <iostream>

#include "Grafo.h"

int main() {
    Grafo* grafo = new Grafo();
    grafo->InsertaVertice("A");
    grafo->InsertaVertice("B");
    grafo->InsertaVertice("C");
    grafo->InsertaVertice("D");
    grafo->InsertaVertice("E");
    grafo->InsertaVertice("F");
    grafo->InsertaVertice("G");

    grafo->InsertaArista("A", "B", 7);
    grafo->InsertaArista("A", "D", 5);
    grafo->InsertaArista("B", "C", 8);
    grafo->InsertaArista("B", "D", 9);
    grafo->InsertaArista("B", "E", 7);
    grafo->InsertaArista("C", "E", 5);
    grafo->InsertaArista("D", "F", 6);
    grafo->InsertaArista("E", "F", 8);
    grafo->InsertaArista("E", "G", 9);
    grafo->InsertaArista("F", "G", 11);

    // Ahora llama a Kruskal
    grafo->Mostrar();

    grafo->Kruskal();


    /*grafo->InsertaVertice("A");
    grafo->InsertaVertice("B");
    grafo->InsertaVertice("C");
    grafo->InsertaVertice("D");
    grafo->InsertaVertice("E");
    grafo->InsertaVertice("F");
    grafo->InsertaVertice("G");
    grafo->InsertaArista("A", "A", 13);
    grafo->InsertaArista("A", "D", 8);
    grafo->InsertaArista("B", "B", 52);
    grafo->InsertaArista("B", "C", 17);
    grafo->InsertaArista("B", "D", 83);
    grafo->InsertaArista("B", "F", 97);
    grafo->InsertaArista("B", "G", 60);
    grafo->InsertaArista("C", "A", 4);
    grafo->InsertaArista("D", "B", 97);
    grafo->InsertaArista("D", "C", 37);
    grafo->InsertaArista("D", "D", 22);
    grafo->InsertaArista("D", "E", 41);
    grafo->InsertaArista("D", "G", 64);
    grafo->InsertaArista("E", "B", 8);
    grafo->InsertaArista("E", "E", 45);
    grafo->InsertaArista("E", "F", 92);
    grafo->InsertaArista("F", "A", 12);
    grafo->InsertaArista("F", "B", 8);
    grafo->InsertaArista("F", "E", 42);
    grafo->InsertaArista("G", "D", 17);*/


}
