//
// Created by Joanna on 29.05.2023.
//

#ifndef UNTITLED_PRIM_H
#define UNTITLED_PRIM_H

#include "../Graph/GraphList.h"
#include "../Graph/GraphMatrix.h"

using namespace std;
class Prim {

    static bool isValidEdge(int u, int v, vector<bool> inMST);
    public:
         int forList(GraphList &g);
         int forMatrix(GraphMatrix &g);

    int forMatrixAuto(GraphMatrix &g);

    int forListAuto(GraphList &g);

    void deleteForMatrix(GraphMatrix &g);
};


#endif //UNTITLED_PRIM_H
