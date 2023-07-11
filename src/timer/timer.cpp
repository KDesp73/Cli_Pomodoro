#include "timer.h"

#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;


void Timer::start(){
    int delay = 1;
    delay *= CLOCKS_PER_SEC;

    while(true){
        clock_t now = clock();
    
        while(clock() - now < delay);

        total_time++;
    }
}

void Timer::pause(){

}

void Timer::restart(){
    reset();
    start();
}

void Timer::reset(){
    total_time = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
}

void Timer::refresh(){

}

Time Timer::secondsToTime(int seconds){
   int hours, minutes;

   minutes = seconds / 60;
   hours = minutes / 60;
   seconds = seconds % 60;

   return Time{hours, minutes, seconds};
}

int Timer::timeToSeconds(Time time){
    int hours = time.hours;
    int minutes = time.minutes;
    int seconds = time.seconds;

    return seconds + (minutes * 60) + (hours * 60 * 60);
}
