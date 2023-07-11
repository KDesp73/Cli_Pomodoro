#pragma once

#include "my_time.h"

#include <string>

using namespace std;

class Timer {
public:
    int time_passed = 0;
    int target_time;
    bool paused = false;

    Timer() = default;
    
    Timer(int seconds){
        this->target_time = seconds;
    }

    Timer(int hours, int minutes, int seconds){
        this->target_time = Time::timeToSeconds(Time{hours, minutes, seconds});
    };

    void start();
    void pause();
    void proceed();
    void restart();
    void reset();
    string to_string();
};
