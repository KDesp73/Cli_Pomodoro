#pragma once

#include <string>

using namespace std;

class Time {
public:
    int hours;
    int minutes;
    int seconds;

    Time() = default;

    string to_string();

    static int timeToSeconds(Time time);
    static Time secondsToTime(int seconds);   
    static Time guiTimeInput();
};
