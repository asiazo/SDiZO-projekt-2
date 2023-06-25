//
// Created by Joanna on 29.05.2023.
//

#ifndef UNTITLED_BELLMANFORD_H
#define UNTITLED_BELLMANFORD_H

#include <vector>
#include <limits>
#include "../Graph/GraphList.h"
#include "../Graph/GraphMatrix.h"
#include "list"

using namespace std;

    class BellmanFord {
    public:
        void forList(GraphList &g, int source, bool print);
        void forMatrix(GraphMatrix &g, int source, bool print);
        void markUnreachable(GraphMatrix &g, int v);
        void markUnreachableList(GraphList &g, int v);
        void forMatrixAuto(GraphMatrix &g, int source, bool print);
        void forListAuto(GraphList &g, int source, bool print);
    };


#endif //UNTITLED_BELLMANFORD_H
