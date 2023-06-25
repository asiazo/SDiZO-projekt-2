//
// Created by Joanna on 29.05.2023.
//

#include "Kruskal.h"
#include "Join.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "fstream"

using namespace std;

int Kruskal::forList(GraphList &g) {
    int mst = 0, weight;
    ofstream outFile;
    outFile.open("KruskalList.txt");

    auto ds = new Join(g.adjList.size(), false);

    int edge_count = 0;
    while (edge_count < g.adjList.size() - 1) {
        int min = INT_MAX, u = - 1, v = -1;
        for (int i = 0; i < g.adjList.size(); i++) {
            for (int j = 0; j < g.adjList[i].size(); j++) {
                // Znalezienie najmniejszej krawędzi spośród niepołączonych wierzchołków
                auto it = g.adjList[i].begin();
                advance(it, j);
                weight = it -> second;
                if ((ds->find(i) != ds->find(it->first)) && 0 < weight && weight < min) {
                    min = weight; //waga
                    u = i;
                    v = it->first;
                }
            }
        }

        ds->merge(u, v);
        cout << "Krawedz " << edge_count << ":\n" << u << " - " << v << "\n| cost = " << min <<"\n";
        outFile << "Krawedz " << edge_count << ":\n" << u << " - " << v << "\n| cost = " << min <<"\n";
        edge_count++;
        mst += min;
    }

    outFile.close();
    return mst;
}

int Kruskal::forMatrix(GraphMatrix &g) {
    int mst = 0;
    ofstream outFile;
    outFile.open("KruskalMatrix.txt");
    auto ds = new Join(g.vertices, false);

    int edge_count = 0;
    while (edge_count < g.vertices - 1) {
        int min = INT_MAX, u = - 1, v = -1;
        for (int i = 0; i < g.vertices; i++) {
            for (int j = 0; j < g.vertices; j++) {
                // Znalezienie najmniejszej krawędzi spośród niepołączonych wierzchołków
                if ((ds->find(i) != ds->find(j)) && 0 < g.edges[i][j] && g.edges[i][j] < min) {
                    min = g.edges[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        ds->merge(u, v);
        cout << "Krawedz " << edge_count << ":\n" << u << " - " << v << "\n| cost = " << min <<"\n";
        outFile << "Krawedz " << edge_count << ":\n" << u << " - " << v << "\n| cost = " << min <<"\n";
        edge_count++;
        mst += min;
    }
    outFile.close();
    return mst;

}
int Kruskal::forListAuto(GraphList &g) {
    int mst = 0, weight;

    auto ds = new Join(g.adjList.size(), false);

    int edge_count = 0;
    while (edge_count < g.adjList.size() - 1) {
        int min = INT_MAX, u = - 1, v = -1;
        for (int i = 0; i < g.adjList.size(); i++) {
            for (int j = 0; j < g.adjList[i].size(); j++) {
                // Znalezienie najmniejszej krawędzi spośród niepołączonych wierzchołków
                auto it = g.adjList[i].begin();
                advance(it, j);
                weight = it -> second;
                if ((ds->find(i) != ds->find(it->first)) && 0 < weight && weight < min) {
                    min = weight; //waga
                    u = i;
                    v = it->first;
                }
            }
        }

        ds->merge(u, v);
        edge_count++;
        mst += min;
    }

    return mst;
}

int Kruskal::forMatrixAuto(GraphMatrix &g) {
    int mst = 0;

    auto ds = new Join(g.vertices, false);

    int edge_count = 0;
    while (edge_count < g.vertices - 1) {
        int min = INT_MAX, u = - 1, v = -1;
        for (int i = 0; i < g.vertices; i++) {
            for (int j = 0; j < g.vertices; j++) {
                // Znalezienie najmniejszej krawędzi spośród niepołączonych wierzchołków
                if ((ds->find(i) != ds->find(j)) && 0 < g.edges[i][j] && g.edges[i][j] < min) {
                    min = g.edges[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        ds->merge(u, v);
        edge_count++;
        mst += min;
    }

    return mst;

}