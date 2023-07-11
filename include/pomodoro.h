#pragma once

#include "timer.h"
#include "my_time.h"

#include <string>

using namespace std;

class Pomodoro {
public:
    int work_interval;
    int break_interval;
    string task;
    Timer timer;

    Pomodoro() = default;
    Pomodoro(string task, int work_interval = Time::timeToSeconds(Time{0, 25, 0}), int break_interval = Time::timeToSeconds(Time{0, 5, 0})){
        this->task = task;
        this->work_interval = work_interval;
        this->break_interval = break_interval;
        
        this->timer = {work_interval};
    }

    void start();
    void reset();
};


