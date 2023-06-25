//
// Created by Joanna on 02.06.2023.
//
#include <iostream>
#include "MST.h"
#include "ShortestPathMenu.h"

using namespace std;

int main(){
    MST mst;
    ShortestPathMenu pathMenu;
    int n;
    cout << "Projekt 2 Joanna Zoglowek 264452" << endl;
    cout<<"Z jakiego menu chcesz skorzystac? Wybierz 1 dla problemu najkrotszej sciezki, 2 dla minimmalnego drzewa rozpinajacego"<<endl;
    cin>> n;
    if(n==1)
        pathMenu.printMenu();
    else
        mst.printMenu();

    return 0;
}
