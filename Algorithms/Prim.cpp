//
// Created by Joanna on 29.05.2023.
//

#include "Prim.h"
#include <set>
#include <queue>
#include "Prim.h"
#include "iostream"
#include "fstream"

using namespace std;

int Prim::forMatrix(GraphMatrix &g) {
    ofstream outFile;
    vector<bool> inMST(g.vertices, false);
    outFile.open("PrimMatrix.txt");
    inMST[0] = true;

    int edge_count = 0, mincost = 0;
    //vector<int> minWeight(g.vertices, g.maxw);
    while (edge_count < g.vertices - 1) {
        int min = g.maxw, u = -1, v = -1;
        for (int i = 0; i < g.vertices; i++) {
            if (inMST[i]) {
                for (int j = 0; j < g.vertices; j++) {
                    if (!inMST[j] && g.edges[i][j] > 0 && g.edges[i][j] < min) {
                        min = g.edges[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            cout << "Krawedz " << edge_count << ":\n" << u << " - " << v << "\n| cost = " << min << "\n";
            outFile<<"Krawedz " << edge_count << ":\n" << u << " - " << v << "\n| cost = " << min << "\n";
            mincost += min;
            inMST[v] = true; // Dodajemy v do MST
            edge_count++;
        }
        else {
            break; // Przerwanie pętli, jeśli nie można znaleźć więcej krawędzi
        }
    }
    outFile.close();
    return mincost;

}

int Prim::forList(GraphList &g) {
    vector<bool> inMST(g.adjList.size(), false);
    ofstream outFile;
    outFile.open("PrimList.txt");
    inMST[0] = true;

    int edge_count = 0, mincost = 0, weight=0, x, min , u, v;


    while (edge_count < g.adjList.size() - 1) {
        min = g.maxw, u = -1, v = -1;
        for (int i = 0; i < g.adjList.size(); i++) {
            if (inMST[i]) {
                for (int j = 0; j < g.adjList[i].size(); j++) {
                    auto it = g.adjList[i].begin();
                    advance(it, j);
                    weight = it -> second;
                    x = it->first; // koniec krawedzi
                    if (!inMST[x] && weight < min) {
                        min = weight;
                        u = i;
                        v = x;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            cout << "Krawedz " << edge_count << ":\n" << u << " - " << v << "\n| cost = " << min << "\n";
            outFile<<"Krawedz " << edge_count << ":\n" << u << " - " << v << "\n| cost = " << min << "\n";
            mincost += min;
            inMST[v] = true; // Dodajemy v do MST
            edge_count++;
        }
        else {
            break; // Przerwanie pętli, jeśli nie można znaleźć więcej krawędzi
        }
    }
    outFile.close();
    return mincost;

}
int Prim::forMatrixAuto(GraphMatrix &g) {

    vector<bool> inMST(g.vertices, false);
    inMST[0] = true;

    int edge_count = 0, mincost = 0;
    while (edge_count < g.vertices - 1) {
        int min = g.maxw, u = -1, v = -1;
        for (int i = 0; i < g.vertices; i++) {
            if (inMST[i]) {
                for (int j = 0; j < g.vertices; j++) {
                    if (!inMST[j] && g.edges[i][j] > 0 && g.edges[i][j] < min) {
                        min = g.edges[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            mincost += min;
            inMST[v] = true; // Dodajemy v do MST
            edge_count++;
        }
    }
    return mincost;
}

int Prim::forListAuto(GraphList &g) {

    vector<bool> inMST(g.adjList.size(), false);
    inMST[0] = true;

    int edge_count = 0, mincost = 0, weight=0, x, min , u, v;

    while (edge_count < g.adjList.size() - 1) {
        min = g.maxw, u = -1, v = -1;
        for (int i = 0; i < g.adjList.size(); i++) {
            if (inMST[i]) {
                for (int j = 0; j < g.adjList[i].size(); j++) {
                    auto it = g.adjList[i].begin();
                    advance(it, j);
                    weight = it -> second;
                    x = it->first; // koniec krawedzi
                    if (!inMST[x] && weight < min) {
                        min = weight;
                        u = i;
                        v = x;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            mincost += min;
            inMST[v] = true; // Dodajemy v do MST
            edge_count++;
        }
    }
    return mincost;
}