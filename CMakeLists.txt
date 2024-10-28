cmake_minimum_required(VERSION 3.29)
project(Grafos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Grafos main.cpp
        Grafo.h
        Arista.h
        Vertice.h
        Arista.cpp
        Vertice.cpp
        Grafo.cpp)
