//
// Created by Joanna on 29.05.2023.
//

#ifndef UNTITLED_KRUSKAL_H
#define UNTITLED_KRUSKAL_H

#include "../Graph/GraphList.h"
#include "../Graph/GraphMatrix.h"

class Kruskal {
public:
    static int forList(GraphList &g);
    static int forMatrix(GraphMatrix &g);

    int forMatrixAuto(GraphMatrix &g);

    int forListAuto(GraphList &g);
};


#endif //UNTITLED_KRUSKAL_H
