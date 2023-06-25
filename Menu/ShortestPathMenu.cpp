//
// Created by Joanna on 30.05.2023.
//

#include "ShortestPathMenu.h"
#include "../Graph/GraphMatrix.h"
#include <iostream>
#include <bits/stdc++.h>
#include "../Algorithms/BellmanFord.h"
#include "../Algorithms/Dijkstra.h"
#include "../Time/AutomaticTest.h"
#include "../Time/Time.h"
using namespace std;

ShortestPathMenu::ShortestPathMenu() = default;

void ShortestPathMenu::printMenu() {
    GraphMatrix graphMatrix(0);
    GraphList graphList(0);
    //Wypisanie menu dla problemu najkrótszej ścieżki.
    Time time;
    int x=-100,n,d;
    int choice= -100;
    while (choice != 0) {
        cout << endl;
        cout << "Projekt 2 Joanna Zoglowek 264452" << endl;
        cout << "Menu dla problemu najkrotszej sciezki" << endl;
        cout << "1. Wygeneruj losowy graf" << endl;
        cout << "2. Generuj losowo graf i zapisz go do pliku" << endl;
        cout << "3. Wczytaj graf z pliku" << endl;
        cout << "4. Algorytm Dijkstry dla macierzy" << endl;
        cout << "5. Algorytm Bellmana-Forda dla macierzy" << endl;
        cout << "6. Algorytm Dijkstry dla listy" << endl;
        cout << "7. Algorytm Bellmana-Forda dla listy" << endl;
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
            case 1:
            {
                cout << "\nWybierz liczbe wierzcholkow w grafie: ";
                cin >> n;
                cout << "\nWybierz gestosc grafu (w %): ";
                cin >> d;
                graphMatrix.resize(n);
                graphMatrix.generateDirectedRandomGraph(n, d);
                graphMatrix.display();

                graphList.clearLists();
                graphList.adjList.resize(n);
                graphList.readGraphFromMatrix(graphMatrix);
                //graphList.randomGraphDirected(n,d);
                graphList.display();
                break;
            }
            case 2:
            {
                cout << "\nWybierz liczbe wierzcholkow w grafie: ";
                cin >> n;
                cout << "\nWybierz gestosc grafu (w %): ";
                cin >> d;
                graphMatrix.resize(n);
                graphMatrix.generateDirectedRandomGraphToFile(n,d);

                graphList.clearLists();
                graphList.adjList.resize(n);
                graphList.readGraphFromMatrix(graphMatrix);
                //graphList.randomGraphDirected(n,d);
                cout<<"Zapisano do pliku!"<<"\n";
                break;
            }
            case 3:
            {
                string file;
                cout << "Z jakiego pliku chcesz wczytac dane:  ";
                cin >> file;
                graphMatrix.readGraphDirected(file);
                graphMatrix.display();

                graphList.clearLists();
                graphList.adjList.resize(graphMatrix.vertices);
                graphList.readGraphFromMatrix(graphMatrix);
                graphList.display();
                break;
            }
            case 4:
            {
                int beg=0;
                graphMatrix.display();
                Dijkstra dijkstra;
                time.start();
                dijkstra.forMatrix(graphMatrix, beg);
                time.stop();
                cout<<"Czas dzialania: "<<time.returnTime()<<endl;
                break;
            }
            case 5:
            {
                graphMatrix.display();
                BellmanFord bellmanFord;
                time.start();
                bellmanFord.forMatrix(graphMatrix, 0, true);
                time.stop();
                cout<<"Czas dzialania: "<<time.returnTime()<<endl;
                break;
            }
            case 6:
            {
                int beg=0;
                Dijkstra dijkstra;
                graphList.display();
                time.start();
               // graphList.DijkstraforListTest(beg);
                dijkstra.forList(graphList, beg);
                time.stop();
                cout<<"Czas dzialania: "<<time.returnTime()<<endl;
                break;
            }
            case 7:
            {
                graphList.display();
                BellmanFord bellmanFord;
                time.start();
                bellmanFord.forList(graphList, 0, true);
                time.stop();
                cout<<"Czas dzialania: "<<time.returnTime()<<endl;
                break;
            }
            case 8:
            {
                AutomaticTest automaticTest;
                automaticTest.testP();
                break;
            }
        }
    }
}
