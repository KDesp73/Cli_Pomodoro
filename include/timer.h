#pragma once

struct Time {
    int hours;
    int minutes;
    int seconds;
};

class Timer {
public:
    int total_time = 0;
    int target_time;

    Timer() = default;
    
    Timer(int seconds){
        this->target_time = seconds;
    }

    Timer(int hours, int minutes, int seconds){
        this->target_time = timeToSeconds(Time{hours, minutes, seconds});
    };

    void start();
    void pause();
    void restart();
    void reset();
    void refresh();

private:
    static int timeToSeconds(Time time);
    static Time secondsToTime(int seconds);   
};
