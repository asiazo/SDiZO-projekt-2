//
// Created by Joanna on 29.05.2023.
//

#ifndef UNTITLED_JOIN_H
#define UNTITLED_JOIN_H


class Join {
public:
    int *parent, *rank;
    int n;

    Join(int n, bool k);

    int find(int u);
    void merge(int x, int y);

};


#endif //UNTITLED_JOIN_H
