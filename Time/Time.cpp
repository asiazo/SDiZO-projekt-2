//
// Created by Joanna on 29.05.2023.
//

#include "Time.h"
#include <chrono>
#include <iostream>

using namespace  std;
using namespace std::chrono;


void Time::start() {
    startPoint = high_resolution_clock::now();
}

void Time::stop() {
    stopPoint = high_resolution_clock::now();
}

    long long Time::returnTime() {
        return duration_cast<microseconds>(Time::stopPoint - Time::startPoint).count();
    }

