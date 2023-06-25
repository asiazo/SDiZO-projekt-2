//
// Created by Joanna on 29.05.2023.
//

#include "Join.h"

using namespace std;

Join::Join(int n, bool k) {
    this->n = n;
    parent = new int[n];
    rank = new int[n];
    if(k){
        for(int i = 0; i < n; i++){
            rank[i] = 10; // Wartość rank ustawiana na 10 dla każdego wierzchołka
            parent[i] = i; // Wierzchołek i jest początkowo swoim rodzicem
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            rank[i] = 0; // Wartość rank ustawiana na 0 dla każdego wierzchołka
            parent[i] = i; // Wierzchołek i jest początkowo swoim rodzicem
        }
    }
}

int Join::find(int u) {
    if(u != parent[u])
        u = find(parent[u]); // Rekurencyjne wywołanie find na rodzicu wierzchołka u
    return u;   // Zwraca korzeń zbioru, do którego należy wierzchołek u
}

void Join::merge(int x, int y) {
    x = find(x); // Znajdowanie korzenia zbioru, do którego należy wierzchołek x
    y = find(y); // Znajdowanie korzenia zbioru, do którego należy wierzchołek y

    if(rank[x] > rank[y]){
        parent[y] = x; // Dołączenie zbioru y do zbioru x poprzez ustawienie korzenia y jako rodzica korzenia x
    }
    else{
        parent[x] = y; // Dołączenie zbioru x do zbioru y poprzez ustawienie korzenia x jako rodzica korzenia y
    }

    if(rank[x] == rank[y]) y++; // Jeśli rangi (???) korzeni x i y są równe, zwiększ rangę korzenia y
}