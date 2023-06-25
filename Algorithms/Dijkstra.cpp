//
// Created by Joanna on 29.05.2023.
//

#include "Dijkstra.h"
#include "iostream"
#include "../Graph/GraphList.h"
#include "../Graph/GraphMatrix.h"
#include <queue>
#include <set>
#include "fstream"

using namespace std;

void Dijkstra::forList(GraphList &g, int beginning) {
    g.vertices = g.adjList.size();
    //dystans do kazdego wierzcholka
    vector<int> distance(g.vertices, INT_MAX);
    //czy odwiedzono dany wierzcholek
    vector<bool> visited(g.vertices, false);
    vector<int> path(g.vertices, -1);
    int weight,v;
    ofstream outFile;
    outFile.open("DijkstraList.txt");

    distance[beginning] = 0;

    for (int count = 0; count < g.vertices; count++) {
        int minDistance = INT_MAX; // krawędz o najmniejszej wadze do danego wierzchołka
        int minVertex = -1; // nr wierzchołka poprzednika

        for (int u = 0; u < g.vertices; u++) {
            if (!visited[u] && distance[u] < minDistance) {
                minDistance = distance[u];
                minVertex = u;
            }
        }
        visited[minVertex] = true;

        for (int b = 0; b < g.adjList[minVertex].size(); b++) { //b - indeks na liscie elementow dla wierzcholka o indeksie minVertex
            auto it = g.adjList[minVertex].begin();
            advance(it, b);
            weight = it -> second;
            v = it->first;
            if (!visited[v] && distance[minVertex] + weight < distance[v] && distance[minVertex] != INT_MAX) {
                distance[v] = distance[minVertex] + weight;
                path[v] = minVertex;
            }
        }

    }

    cout << "Wierzcholek: \t Dystans od: " << "\n";
    outFile << "Wierzcholek: \t Dystans od: " << "\n";
    for(int i = 0; i < g.vertices; i++){
        if(distance[i] != 0)
        {
            cout << "  " << i << " \t\t" << distance[i] << "\n";
            outFile << "  " << i << " \t\t" << distance[i] << "\n";
        }
        else
        {
            cout << "  " << i << " \t\t" << "-" << "\n";
            outFile << "  " << i << " \t\t" << "-" << "\n";
        }
    }
    outFile.close();
}

void Dijkstra::forMatrix(GraphMatrix &g, int beginning) {
    vector<int> distance(g.vertices, INT_MAX);
    vector<bool> visited(g.vertices, false);
    vector<int> path(g.vertices, -1);
    ofstream outFile;
    outFile.open("DijkstraMatrix.txt");

    distance[beginning] = 0;

    for (int count = 0; count < g.vertices; count++) {
        int minDistance = INT_MAX; // krawędz o najmniejszej wadze do danego wierzchołka
        int minVertex = -1; // nr wierzchołka poprzednika

        for (int u = 0; u < g.vertices; u++) {
            if (!visited[u] && distance[u] < minDistance) {
                minDistance = distance[u];
                minVertex = u;
            }
        }
        visited[minVertex] = true;

        for (int v = 0; v < g.vertices; v++) {

            if (!visited[v] && g.edges[minVertex][v] != 0 && distance[minVertex] + g.edges[minVertex][v] < distance[v] && distance[minVertex] != INT_MAX) {
                distance[v] = distance[minVertex] + g.edges[minVertex][v];
                path[v] = minVertex;
            }
        }

    }
    cout << "Wierzcholek: \t Dystans od: " << "\n";
    outFile << "Wierzcholek: \t Dystans od: " << "\n";
    for(int i = 0; i < g.vertices; i++){
        if(distance[i] != 0)
        {
            cout << "  " << i << " \t\t" << distance[i] << "\n";
            outFile << "  " << i << " \t\t" << distance[i] << "\n";
        }
        else
        {
            cout << "  " << i << " \t\t" << "-" << "\n";
            outFile << "  " << i << " \t\t" << "-" << "\n";
        }
    }
    outFile.close();
}
void Dijkstra::forListAuto(GraphList &g, int beginning) {
    //dystans do kazdego wierzcholka
    vector<int> distance(g.vertices, INT_MAX);
    //czy odwiedzono dany wierzcholek
    vector<bool> visited(g.vertices, false);
    vector<int> path(g.vertices, -1);
    int weight,v;

    distance[beginning] = 0;

    for (int count = 0; count < g.vertices; count++) {
        int minDistance = INT_MAX; // krawędz o najmniejszej wadze do danego wierzchołka
        int minVertex = -1; // nr wierzchołka poprzednika

        for (int u = 0; u < g.vertices; u++) {
            if (!visited[u] && distance[u] < minDistance) {
                minDistance = distance[u];
                minVertex = u;
            }
        }
        visited[minVertex] = true;

        for (int b = 0; b < g.adjList[minVertex].size(); b++) { //b - indeks na liscie elementow dla wierzcholka o indeksie minVertex
            auto it = g.adjList[minVertex].begin();
            advance(it, b);
            weight = it -> second;
            v = it->first;
            if (!visited[v] && distance[minVertex] + weight < distance[v] && distance[minVertex] != INT_MAX) {
                distance[v] = distance[minVertex] + weight;
                path[v] = minVertex;
            }
        }

    }
}

void Dijkstra::forMatrixAuto(GraphMatrix &g, int beginning) {
    vector<int> distance(g.vertices, INT_MAX);
    vector<bool> visited(g.vertices, false);
    vector<int> path(g.vertices, -1);

    distance[beginning] = 0;

    for (int count = 0; count < g.vertices; count++) {
        int minDistance = INT_MAX; // krawędz o najmniejszej wadze do danego wierzchołka
        int minVertex = -1; // nr wierzchołka poprzednika

        for (int u = 0; u < g.vertices; u++) {
            if (!visited[u] && distance[u] < minDistance) {
                minDistance = distance[u];
                minVertex = u;
            }
        }
        visited[minVertex] = true;

        for (int v = 0; v < g.vertices; v++) {

            if (!visited[v] && g.edges[minVertex][v] != 0 && distance[minVertex] + g.edges[minVertex][v] < distance[v] && distance[minVertex] != INT_MAX) {
                distance[v] = distance[minVertex] + g.edges[minVertex][v];
                path[v] = minVertex;
            }
        }

    }
}