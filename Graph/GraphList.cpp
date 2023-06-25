//
// Created by Joanna on 29.05.2023.
//

#include "GraphList.h"
#include "GraphMatrix.h"
#include <iostream>

using namespace std;

GraphList::GraphList(int v) {
    //this-> vertices = v;
    vertices = v;
    adjList.resize(vertices);
}
GraphList::~GraphList() {
    for(int i = 0; i<adjList.size(); i++)
    {
        adjList[i].clear();
    }
    adjList.clear();
}
void GraphList::clearLists()
{
    for(int i = 0; i<adjList.size(); i++)
    {
        adjList[i].clear();
    }
}
void GraphList::readGraphFromMatrix(GraphMatrix &graphMatrix)
{

    for(int i=0; i<graphMatrix.vertices; i++)
    {
        for(int j=0; j<graphMatrix.vertices; j++)
        {
            if (graphMatrix.edges[i][j] != 0)
            {
                adjList[i].emplace_back(j, graphMatrix.edges[i][j]);
            }
        }
    }
}

void GraphList::randomGraphUndirected(int n, int d)
{
    GraphMatrix graph (n);
    graph.generateUndirectedRandomGraph(n, d);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (graph.edges[i][j] != 0)
            {
                    adjList[i].emplace_back(j, graph.edges[i][j]);
            }
        }
    }
}
void GraphList::randomGraphDirected(int n, int d)
{
    GraphMatrix graph (n);
    graph.generateDirectedRandomGraph(n, d);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (graph.edges[i][j] != 0)
            {
                adjList[i].emplace_back(j, graph.edges[i][j]);
            }
        }
    }
}

// Wyświetl listy sąsiedztwa
void GraphList::display() {
    cout << "Graf jako lista:" << endl;
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Lista " << i << ": ";
        for (const auto& vertex : adjList[i]) {
            int dest = vertex.first;  //Wierzcholek docelowy
            int weight = vertex.second; //Waga krawedzi
            cout << "(" << dest << ", " << weight << ") ";
        }
        cout <<endl;
    }
}





