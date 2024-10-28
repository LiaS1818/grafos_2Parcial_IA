//
// Created by LiaSan on 19/10/2024.
//

#ifndef VERTICE_H
#define VERTICE_H
#include <iostream>

class Arista; //Declaración adelantada de la clase Arista para evitar errores de compilación
//ya que la clase Arista se declara después de la clase Vertice


class Vertice {
    std::string nombre;
    Vertice* sig;
    Arista* ari;

    friend class Grafo; // las friends classes son aquellas que pueden acceder a los atributos privados de la clase
    public:
        Vertice(std::string _nombre); //Constructor
};


#endif //VERTICE_H
