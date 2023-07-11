#include "timer.h"
#include "my_time.h"

#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;


void Timer::start(){
    int delay = 1;
    delay *= CLOCKS_PER_SEC;

    while(true){
        clock_t now = clock();
    
        while(clock() - now < delay);
        
        if(!paused)
            time_passed++;
    }
}

void Timer::pause(){
    paused = true;
}

void Timer::proceed(){
    paused = false;
}

void Timer::restart(){
    reset();
    start();
}

void Timer::reset(){
    time_passed = 0;
}

string Timer::to_string(){
    Time time = Time::secondsToTime(time_passed);

    return time.to_string();
}

