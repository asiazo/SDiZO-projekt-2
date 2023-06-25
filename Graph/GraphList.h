//
// Created by Joanna on 29.05.2023.
//

#ifndef UNTITLED_GRAPHLIST_H
#define UNTITLED_GRAPHLIST_H
#include "vector"
#include <string>
#include "list"
#include "GraphMatrix.h"
//#include "GraphList.h"

using namespace std;

class GraphList {
public:
    int vertices; // liczba wierzchołków
    int maxw=100;
    //vector<pair<int, pair<int,int>>> edges; // Wektor przechowujący krawędzie, (waga krawedzi, wierzcholek poczatkowy, wierzcholek koncowy)

    vector<list<pair<int, int>>> adjList;  //lista zawiera: numer sasiadujacego wierzcholka, waga krawedzi do tego wierzcholka

    void display();

    GraphList(int v);
    ~GraphList();

    void randomGraphUndirected(int n, int d);
    void randomGraphDirected(int n, int d);
    void readGraphFromMatrix(GraphMatrix &graphMatrix);
    void clearLists();
};

#endif //UNTITLED_GRAPHLIST_H
