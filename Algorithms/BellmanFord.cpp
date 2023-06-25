//
// Created by Joanna on 29.05.2023.
//

#include <vector>
#include <iostream>
#include <queue>
#include "BellmanFord.h"
#include "fstream"
using namespace std;
void BellmanFord::forList(GraphList &g, int source, bool print) {
    g.vertices = g.adjList.size();
    vector<int> distance(g.vertices, INT_MAX);
    vector<int> path(g.vertices, -1);
    distance[source] = 0;
    int v, weight;
    ofstream outFile;
    outFile.open("BellmanFordList.txt");

    bool test = true; //patrzymy czy beda zachodzic jeszcze zmiany w relaksacji

    // Relaksacja krawędzi n - 1 razy
    for (int i = 1; i < g.vertices; i++) {
        test = true;
        for (int u = 0; u < g.vertices; u++) {
            for (int b = 0; b < g.adjList[u].size(); b++) {
                auto it = g.adjList[u].begin();
                advance(it, b);
                weight = it->second;
                v = it->first;
                if (distance[u] + weight < distance[v] && distance[u] != INT_MAX) {
                    test = false;
                    distance[v] = distance[u] + weight;
                    path[v] = u;
                }
            }
        }
        if (test)
            break;
    }

    // Dodatkowa iteracja relaksacji
    bool negativeCycleDetected = false;
    for (int u = 0; u < g.vertices; u++) {
        for (int b = 0; b < g.adjList[u].size(); b++) {
            auto it = g.adjList[u].begin();
            advance(it, b);
            weight = it->second;
            v = it->first;
            if (distance[u] + weight < distance[v] && weight != 0) {
                // Wykryto ujemny cykl
                negativeCycleDetected = true;
                markUnreachableList(g, v);
            }
        }
    }
    for (int u = 0; u < g.vertices; u++) {
        for (int b = 0; b < g.adjList[u].size(); b++) {
            auto it = g.adjList[u].begin();
            advance(it, b);
            weight = it->second;
            v = it->first;
            if (distance[u] + weight < distance[v]) {
                test = false;
                distance[v] = distance[u] + weight;
                path[v] = u;
            }
        }
    }

    if (negativeCycleDetected) {
        cout << "Graf zawiera ujemny cykl!" << endl;
        return;
    }

    if (print) {
        cout << "Wierzcholek: \t Dystans od: " << endl;
        outFile << "Wierzcholek: \t Dystans od: " << endl;
        for (int i = 0; i < g.vertices; i++) {
            if (distance[i] != 0)
            {
                cout << "  " << i << " \t\t" << distance[i] << '\n';
                outFile << "  " << i << " \t\t" << distance[i] << '\n';
            }
            else
            {
                cout << "  " << i << " \t\t" << "-" << '\n';
                outFile << "  " << i << " \t\t" << "-" << '\n';
            }

        }

    }
    outFile.close();
}

void BellmanFord::forMatrix(GraphMatrix &g, int source, bool print) {
    vector<int> distance(g.vertices, INT_MAX);
    vector<int> path(g.vertices, -1);
    distance[source] = 0;
    ofstream outFile;
    outFile.open("BellmanFordMatrix.txt");

    bool test = true; //patrzymy czy beda zachodzic jeszcze zmiany w relaksacji

    // Relaksacja krawędzi n - 1 razy
    for (int i = 1; i < g.vertices; i++) {
        test = true;
        for (int u = 0; u < g.vertices; u++) {
            for (int v = 0; v < g.vertices; v++) {
                if (g.edges[u][v] != 0 && distance[u] + g.edges[u][v] < distance[v] && distance[u] != INT_MAX) {
                    test = false;
                    distance[v] = distance[u] + g.edges[u][v];
                    path[v] = u;
                }
            }
        }
        if (test) {
            break;
        }
    }

    // Dodatkowa iteracja relaksacji
    bool negativeCycleDetected = false;
    for (int u = 0; u < g.vertices; ++u) {
        for (int v = 0; v < g.vertices; ++v) {
            if (g.edges[u][v] != 0 && distance[u] + g.edges[u][v] < distance[v]) {
                // Wykryto ujemny cykl
                negativeCycleDetected = true;
                markUnreachable(g, v);
            }
        }
    }
    for (int u = 0; u < g.vertices; u++) {
        for (int v = 0; v < g.vertices; v++) {
            if (g.edges[u][v] != 0 && distance[u] + g.edges[u][v] < distance[v]) {
                test = false;
                distance[v] = distance[u] + g.edges[u][v];
                path[v] = u;
            }

        }
    }

    if (negativeCycleDetected) {
        cout << "Graf zawiera ujemny cykl!" << endl;
        return;
    }

    if (print) {
        cout << "Wierzcholek: \t Dystans od: " << endl;
        outFile << "Wierzcholek: \t Dystans od: " << endl;
        for (int i = 0; i < g.vertices; i++) {
            if (distance[i] != 0) {
                cout << "  " << i << " \t\t" << distance[i] << '\n';
                outFile << "  " << i << " \t\t" << distance[i] << '\n';
            } else {
                cout << "  " << i << " \t\t" << "-" << '\n';
                outFile << "  " << i << " \t\t" << "-" << '\n';
            }

        }
        outFile.close();
    }
}

    void BellmanFord::markUnreachable(GraphMatrix &g, int v) {
        vector<bool> visited(g.vertices, false);
        queue<int> q;
        q.push(v);
        visited[v] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < g.vertices; i++) {
                if (g.edges[u][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    // Ustaw odległość na wartość ujemną
                    g.edges[u][i] = -1 * g.edges[u][i];
                }
            }
        }
    }

    void BellmanFord::markUnreachableList(GraphList &g, int v) {
        vector<bool> visited(g.vertices, false);
        queue<int> q;
        q.push(v);
        visited[v] = true;
        int weight, t;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < g.adjList[u].size(); ++i) {
                auto it = g.adjList[u].begin();
                advance(it, i);
                weight = it -> second;
                t = it->first;
                if (weight!= 0 && !visited[t]) {
                    visited[t] = true;
                    q.push(t);
                    // Ustaw odległość na wartość ujemną
                    weight = -1*weight;
                }
            }
        }
    }
    void BellmanFord::forListAuto(GraphList &g, int source, bool print) {
        vector<int> distance(g.vertices, INT_MAX);
        vector<int> path(g.vertices, -1);
        distance[source] = 0;
        int v, weight;

        bool test = true; //patrzymy czy beda zachodzic jeszcze zmiany w relaksacji

        // Relaksacja krawędzi n - 1 razy
        for (int i = 1; i < g.vertices; i++) {
            test = true;
            for (int u = 0; u < g.vertices; u++) {
                for (const auto &edge: g.adjList[u]) {
                    v = edge.first;
                    weight = edge.second;

                    if (distance[u] + weight < distance[v] && distance[u] != INT_MAX) {
                        test = false;
                        distance[v] = distance[u] + weight;
                        path[v] = u;
                    }
                }
            }
            if (test)
                break;
        }

        // Dodatkowa iteracja relaksacji
        bool negativeCycleDetected = false;
        for (int u = 0; u < g.vertices; u++) {
            for (int b = 0; b < g.adjList[u].size(); b++) {
                auto it = g.adjList[u].begin();
                advance(it, b);
                weight = it->second;
                v = it->first;
                if (distance[u] + weight < distance[v]) {
                    // Wykryto ujemny cykl
                    negativeCycleDetected = true;
                    markUnreachableList(g, v);
                }
            }
        }
        for (int u = 0; u < g.vertices; u++) {
            for (int b = 0; b < g.adjList[u].size(); b++) {
                auto it = g.adjList[u].begin();
                advance(it, b);
                weight = it->second;
                v = it->first;
                if (distance[u] + weight < distance[v]) {
                    test = false;
                    distance[v] = distance[u] + weight;
                    path[v] = u;
                }
            }
        }

        if (negativeCycleDetected) {
            cout << "Graf zawiera ujemny cykl!" << endl;
            return;
        }
    }

    void BellmanFord::forMatrixAuto(GraphMatrix &g, int source, bool print) {
        vector<int> distance(g.vertices, INT_MAX);
        vector<int> path(g.vertices, -1);
        distance[source] = 0;

        bool test = true; //patrzymy czy beda zachodzic jeszcze zmiany w relaksacji

        // Relaksacja krawędzi n - 1 razy
        for (int i = 1; i < g.vertices; i++) {
            test = true;
            for (int u = 0; u < g.vertices; u++) {
                for (int v = 0; v < g.vertices; v++) {
                    if (g.edges[u][v] != 0 && distance[u] + g.edges[u][v] < distance[v] && distance[u] != INT_MAX) {
                        test = false;
                        distance[v] = distance[u] + g.edges[u][v];
                        path[v] = u;
                    }
                }
            }
            if (test) {
                break;
            }
        }

        // Dodatkowa iteracja relaksacji
        bool negativeCycleDetected = false;
        for (int u = 0; u < g.vertices; ++u) {
            for (int v = 0; v < g.vertices; ++v) {
                if (g.edges[u][v] != 0 && distance[u] + g.edges[u][v] < distance[v]) {
                    // Wykryto ujemny cykl
                    negativeCycleDetected = true;
                    markUnreachable(g, v);
                }
            }
        }
        for (int u = 0; u < g.vertices; u++) {
            for (int v = 0; v < g.vertices; v++) {
                if (g.edges[u][v] != 0 && distance[u] + g.edges[u][v] < distance[v]) {
                    test = false;
                    distance[v] = distance[u] + g.edges[u][v];
                    path[v] = u;
                }

            }
        }

        if (negativeCycleDetected) {
            cout << "Graf zawiera ujemny cykl!" << endl;
            return;
        }
    }
