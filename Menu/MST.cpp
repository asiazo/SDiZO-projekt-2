//
// Created by Joanna on 30.05.2023.
//

#include <iostream>
#include "MST.h"
#include "../Graph/GraphMatrix.h"
#include "../Graph/GraphList.h"
#include "../Algorithms/Prim.h"
#include "../Algorithms/Kruskal.h"
#include "../Time/Time.h"
#include "../Time/AutomaticTest.h"
#include <bits/stdc++.h>

using namespace std;

void MST::printMenu() {
    GraphMatrix graphMatrix(0);
    GraphList graphList(0);
    Time time;
    int x = -100,n,d;
    int choice = -100;
    while (choice != 0) {
        cout << endl;
        cout << "Projekt 2 Joanna Zoglowek 264452" << endl;
        cout << "Menu dla minimalnego drzewa rozpinajacego" << endl;
        cout << "1. Wygeneruj losowy" << endl;
        cout << "2. Generuj losowo graf i zapisz go do pliku" << endl;
        cout << "3. Wczytaj graf z pliku." << endl;
        cout << "4. Algorytm Prima dla macierzy" << endl;
        cout << "5. Algorytm Kruskala dla macierzy" << endl;
        cout << "6. Algorytm Prima dla listy" << endl;
        cout << "7. Algorytm Kruskala dla listy" << endl;
        cout << "8. Testuj automatycznie" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: " << endl;
        cin >> x;
        switch (x) {
            default: {
                cout << "Wybrales zly numer\n";
                break;
            }
            case 0: {
                //wyjscie
                return;
            }
            case 1: {

                cout << "\nWybierz liczbe wierzcholkow w grafie: ";
                cin >> n;
                cout << "\nWybierz gestosc grafu (w %): ";
                cin >> d;
                graphMatrix.resize(n);
                graphMatrix.generateUndirectedRandomGraph(n, d);
                graphMatrix.display();

                graphList.clearLists();
                graphList.adjList.resize(n);
                graphList.readGraphFromMatrix(graphMatrix);
                graphList.display();
                break;
            }
            case 2: {
                cout << "\nWybierz liczbe wierzcholkow w grafie: ";
                cin >> n;
                cout << "\nWybierz gestosc grafu (w %): ";
                cin >> d;
                graphMatrix.resize(n);
                graphMatrix.generateUndirectedRandomGraphToFile(n,d);

                graphList.clearLists();
                graphList.adjList.resize(n);
                graphList.readGraphFromMatrix(graphMatrix);
                cout<<"Zapisano do pliku!"<<"\n";
                break;
            }
            case 3: {
                string file;
                cout << "Z jakiego pliku chcesz wczytac dane:  ";
                cin >> file;
                graphMatrix.readGraphUndirected(file);
                graphMatrix.display();

                graphList.clearLists();
                graphList.adjList.resize(graphMatrix.vertices);
                graphList.readGraphFromMatrix(graphMatrix);
                graphList.display();
                break;
            }

            case 4: {
                graphMatrix.display();
                Prim prim;
                time.start();
                int cost = prim.forMatrix(graphMatrix);
                time.stop();
                cout << "Koszt: " << cost << endl;
                cout<<"Czas dzialania: "<<time.returnTime()<<endl;
                break;
            }
            case 5: {
                graphMatrix.display();
                Kruskal kruskal;
                time.start();
                int cost = kruskal.forMatrix(graphMatrix);
                time.stop();
                cout << "Koszt: " << cost << endl;
                cout<<"Czas dzialania: "<<time.returnTime()<<endl;
                break;
            }
            case 6: {
                int cost;
                Prim prim;
                graphList.display();
                time.start();
                cost = prim.forList(graphList);
                time.stop();
                cout << "Koszt: " << cost << endl;
                cout<<"Czas dzialania: "<<time.returnTime()<<endl;
                break;
            }

            case 7: {
                graphList.display();
                Kruskal kruskal;
                time.start();
                int cost = kruskal.forList(graphList);
                time.stop();
                cout << "Koszt: " << cost << endl;
                cout<<"Czas dzialania: "<<time.returnTime()<<endl;
                break;
            }
            case 8:
            {
                AutomaticTest automaticTest;
                automaticTest.testMst();

                break;
            }
        }
    }

};



