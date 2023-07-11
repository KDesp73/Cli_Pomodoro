#pragma once

#include <string>
#include <vector>

using namespace std;

class Time {
public:
    int hours;
    int minutes;
    int seconds;

    Time() = default;

    string to_string();

    static int timeToSeconds(Time time);
    static vector<int> timeToDigits(Time time);
    static Time secondsToTime(int seconds);   
    static Time guiTimeInput(vector<int> digits = {0,0,0,0,0,0});
};
