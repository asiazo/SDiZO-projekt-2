//
// Created by Joanna on 29.05.2023.
//

#ifndef UNTITLED_TIME_H
#define UNTITLED_TIME_H

#include "iostream"
#include "chrono"
using namespace  std;
using namespace std::chrono;

class Time {
private:
    high_resolution_clock::time_point beginning;
    high_resolution_clock::time_point end;
public:

    high_resolution_clock::time_point startPoint;

    high_resolution_clock::time_point stopPoint;

    void start();
    void stop();
    long long returnTime();

};


#endif //UNTITLED_TIME_H
