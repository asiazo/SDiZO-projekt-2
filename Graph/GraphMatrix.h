//
// Created by Joanna on 29.05.2023.
//

#ifndef UNTITLED_GRAPHMATRIX_H
#define UNTITLED_GRAPHMATRIX_H

#include <string>

using namespace std;


class GraphMatrix {
public:
    int min=1, maxw=100;
    int **edges; // // to powinno sie nazywac moze nodes
    int vertices; // liczba wierzchołków
    int d;
    // Konstruktor inicjalizujący graf na podstawie liczby wierzchołków.
    GraphMatrix(int v);

    //Odczytuje graf nieskierowany z pliku
    void readGraphUndirected(string s);

    //Odczytuje graf skierowany z pliku
    void readGraphDirected(string s);

    //Dodaje krawędź między wierzchołkami u i v o wadze w.
    void addEdge(int u, int v, int w);

    //Wyswietla graf w postaci macierzy sasiedztwa
    void display() const;

    // destruktor
     ~GraphMatrix();

    void generateUndirectedRandomGraph(int v, int density);
    void generateDirectedRandomGraph(int v, int density);

    void resize(int v);

    void generateDirectedRandomGraphToFile(int v, int density);

    void generateUndirectedRandomGraphToFile(int v, int density);
};


#endif //UNTITLED_GRAPHMATRIX_H
