//
// Created by Joanna on 29.05.2023.
//

#include <vector>
#include <cmath>
#include "GraphMatrix.h"
#include "sstream"
#include "fstream"
#include "iostream"
#include "iomanip"

using namespace std;
//konstruktor
GraphMatrix::GraphMatrix(int v){
    vertices = v;
    edges = new int * [vertices];
    for(int i = 0; i < vertices; i++)
        edges[i] = new int[vertices];

    for(int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            edges[i][j] = 0;
        }
    }

}
//destruktor
GraphMatrix::~GraphMatrix() {
    if(vertices > 0) {
        for (int i = 0; i < vertices; i++) {
            delete[] edges[i];
            edges[i] = nullptr;
        }
        delete[] edges;
        edges = nullptr;
    }
}
void GraphMatrix::resize(int v)
{
    delete[] edges;
    edges = nullptr;

    vertices = v;
    edges = new int * [vertices];
    for(int i = 0; i < vertices; i++)
        edges[i] = new int[vertices];

    for(int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            edges[i][j] = 0;
        }
    }
}
void GraphMatrix::readGraphUndirected(string s) {
    ifstream inputFile;
    int n,numE, u,v,w, first, end;

    inputFile.open( s);

    if(inputFile.is_open()) {
        cout << "Plik sie otworzyl" << endl;

        inputFile >> numE >> n >> first >> end;
        resize(n);

        for (int e = 0; e < numE; e++) {
            inputFile >> u >> v >> w;
            edges[u][v] = w;
        }
        for (int i = 0; i < n; i++)
         for(int j=0; j<n; j++)
         {
             if(edges[i][j]!=0)
                 edges[j][i] = edges[i][j];
         }
        inputFile.close();
    }
    else cout << "\nPlik sie nie otworzyl!";
}

void GraphMatrix::readGraphDirected(string s) {
    ifstream inputFile;
    int n,numE, u,v,w, first, end;

    inputFile.open(s);

    if(inputFile.is_open()) {
        cout<<"Plik sie otworzyl"<<endl;
        inputFile >> numE >> n >> first >> end;
        resize(n);

        for (int e = 0; e < numE; e++) {
            inputFile >> u >> v >> w;
            edges[u][v] = w;
        }

        inputFile.close();
    }
    else {
        cout<<"Nie udalo sie otworzyc pliku wejsciowego"<<endl;
        return;
    }
}
void GraphMatrix::generateUndirectedRandomGraph(int v, int density)
{
    vector<int> helper (v);  //numery wierzcholkow
    srand(time(NULL));
    int help2;

    //wypelnienie wektora rosnacymi liczbami
    for(int n=0; n<v; n++)
    {
        helper[n]=n;
    }

    //generowanie losowego minimalnego grafu spojnego
    for( int m =1; m<v*v; m++)
    {
        int help = (rand() % (v-2))+1;
        swap(helper[help], helper[help+1]);
    }
    //wypelnianie macierzy sasiedztwa minimalnym garfem spojnym
    for(int d = 0; d<v-1; d++)
    {
        edges[helper[d]][helper[d+1]] = rand() % (maxw-min) + 1 ;
        edges[helper[d+1]][helper[d]] = edges[helper[d]][helper[d+1]];
    }

    int max = (v*(v-1))/2;
    int perc = floor((density*v*(v-1))/200);
    int fill = perc - (v-1);
    double d = (double )fill*100/((double )max-(v-1));
    int s = ceil(d); //prawdopodobienstwo z jakim dostawiamy wage do trojkata macierzy

    if(perc > v-1)
    {
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<i; j++)
            {
                help2 = rand() % maxw+1;
                if (help2 <= s && fill>0 && edges[i][j] == 0)
                {
                    edges[i][j] = rand() % (maxw-min) + 1;
                    edges[j][i] = edges[i][j];
                    fill--;
                }
            }
        }
    }
}
void GraphMatrix::generateDirectedRandomGraph(int v, int density)
{
    ofstream output;
    vector<int> helper (v);  //numery wierzcholkow
    int help2, help3;

    srand(time(NULL));

    //wypelnienie wektora rosnacymi liczbami
    for(int n=0; n<v; n++)
    {
        helper[n]=n;
    }

    //generowanie losowego minimalnego grafu spojnego
    for( int m =1; m<2*v; m++)
    {
        int help = (rand() % (v-2))+1;
        swap(helper[help], helper[help+1]);
    }
    //wypelnianie macierzy sasiedztwa minimalnym garfem spojnym
    for(int d = 0; d<v-1; d++)
    {
        edges[helper[d]][helper[d+1]] = rand() % (maxw-min) + 1 ;
    }
    int max = (v*(v-1))/2;                           // maks możliwa ilosc polaczen w grafie skierowanym
    int perc = floor((density*v*(v-1))/200);  // liczba strzałek do wstawienia przy danym density
    int fill = perc - (v-1);                     // liczba strzałek do wstawienia przy danym density po odjeciy tych wstawionych dla dgafu spojnego skierowanego
    double d = (double )fill*100/((double )max-(v-1));
    int s = ceil(d); //prawdopodobienstwo z jakim dostawiamy wage do trojkata macierzy

    if(perc > v-1)
    {
        for(int i=0; i<v; i++)
        {
            for(int j=i+1; j<v; j++)
            {
                help2 = rand() % maxw + 1; // prawdopodobienstwo wstawienia wagi
                help3 = rand() % 2;        // prawdopodobienstwo 50% (gorny czy dolny trojkat macierzy)
                    if (help2 <= s && fill>0 && edges[i][j] == 0 && edges[j][i] == 0)
                    {
                        if (help3==1)
                        {
                            edges[i][j] = rand() % (maxw-min) + 1;
                            fill--;
                        }
                        else
                        {
                            edges[j][i] = rand() % (maxw-min) + 1;
                            fill--;
                        }
                    }
            }
        }
    }
}
void GraphMatrix::generateUndirectedRandomGraphToFile(int v, int density) {
    generateUndirectedRandomGraph(v, density);
    ofstream output;
    output.open("MST.txt");

    int countEdges = 0;

    for(int i =0; i<v; i++) //obliczanie liczby krawedzi w wygenerowanej macierzy grafu
    {
        for(int j=0;j<i; j++)
        {
            if(edges[i][j]!=0)
                countEdges++;
        }
    }
    if(output.is_open())
    {
        output<<countEdges<<" "<<v<<" "<<"0 0"<<endl; //naglowek pliku
        for(int i =0; i<v; i++) //petla zapisujaca poczatek, koniec krawedzi i jej wage
        {
            for(int j=0;j<i; j++)
            {
                if(edges[i][j]!=0)
                    output<<i<<" "<<j<<" "<<edges[i][j]<<endl;
            }
        }
    }

}
void GraphMatrix::generateDirectedRandomGraphToFile(int v, int density) {
    generateDirectedRandomGraph(v, density);
    ofstream output;
    output.open("path.txt");

    int countEdges = 0;

    for(int i =0; i<v; i++) //obliczanie liczby krawedzi w wygenerowanej macierzy grafu
    {
        for(int j=0;j<v; j++)
        {
            if(edges[i][j]!=0)
                countEdges++;
        }
    }
    if(output.is_open())
    {
        output<<countEdges<<" "<<v<<" "<<"0 0"<<endl; //naglowek pliku
        for(int i =0; i<v; i++) //petla zapisujaca poczatek, koniec krawedzi i jej wage
        {
            for(int j=0;j<v; j++)
            {
                if(edges[i][j]!=0)
                    output<<i<<" "<<j<<" "<<edges[i][j]<<endl;
            }
        }
    }

}

void GraphMatrix::display() const{
    // szerokość pola wyświetlania
    const int fieldWidth = 4;
    cout << "Graf jako macierz" <<"\n";

    // wyswietlanie naglowkow kolumn
    cout << setw(fieldWidth) << " " << " | ";
    for (int j = 0; j < vertices; j++) {
        cout << setw(fieldWidth) << j << " ";
    }
    cout << endl;

    // wyswietlanie linii separatora
    cout << setfill('-') << setw(fieldWidth + 1) << "" << "+" << setw((fieldWidth + 1) * vertices) << "" << setfill(' ') <<"\n";

    // wyswietlanie zawartosci tablicy
    for (int i = 0; i < vertices; i++) {
        cout << setw(fieldWidth) << i << " | ";
        for (int j = 0; j < vertices; j++) {
            cout << setw(fieldWidth) << edges[i][j] << " ";
        }
        cout << endl;
    }
}






