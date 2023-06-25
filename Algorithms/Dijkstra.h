//
// Created by Joanna on 29.05.2023.
//

#ifndef UNTITLED_DIJKSTRA_H
#define UNTITLED_DIJKSTRA_H


#include "../Graph/GraphMatrix.h"
#include "../Graph/GraphList.h"

class Dijkstra {
public:
     void forList(GraphList &g, int beginning);
     void forMatrix(GraphMatrix &g, int beginning);
     void forMatrixAuto(GraphMatrix &g, int beginning);
     void forListAuto(GraphList &g, int beginning);
};


#endif //UNTITLED_DIJKSTRA_H
