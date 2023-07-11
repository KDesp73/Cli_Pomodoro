#include "my_time.h"
#include "cli_kit.h"
#include <curses.h>

#ifdef _WIN32
    #include <conio.h>  
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#include <iterator>
#include <vector>
#include <string>

using namespace CliKit;

namespace Keys{
    const int ENTER = 0;
    const int UP = 1;
    const int DOWN = 2;
    const int LEFT = 3;
    const int RIGHT = 4;
};

Time Time::secondsToTime(int seconds){
    int hours, minutes;

    minutes = seconds / 60;
    hours = minutes / 60;

    seconds = seconds % 60;
    minutes = minutes % 60;

    return Time{hours, minutes, seconds};
}

int Time::timeToSeconds(Time time){
    int hours = time.hours;
    int minutes = time.minutes;
    int seconds = time.seconds;

    return seconds + (minutes * 60) + (hours * 60 * 60);
}

string Time::to_string(){
    string hours_str = (std::to_string(hours).size() == 1) ? "0" + std::to_string(hours) : std::to_string(hours);
    string minutes_str = (std::to_string(minutes).size() == 1) ? "0" + std::to_string(minutes) : std::to_string(minutes);
    string seconds_str = (std::to_string(seconds).size() == 1) ? "0" + std::to_string(seconds) : std::to_string(seconds);

    return hours_str + ":" + minutes_str + ":" + seconds_str;

}

void printTime(vector<int> digits, int selected){
    for(int i = 0; i < digits.size(); i++){
        string digit = (i == selected)
            ? Text::color("bg", 4) + std::to_string(digits.at(i)) + Text::normal
            : std::to_string(digits.at(i));
        
        cout << digit;
        if(i % 2 != 0 && i != digits.size()-1) cout << ":";
    }
}

int handleArrowKeys() {
#ifdef _WIN32
    switch (getchar()) {
        case 13:
            return ENTER;
        case '\x1b':    // Escape character
            getchar();  // Read '[' character
            switch (getchar()) {
                case 72:
                    return Keys::UP;
                case 80:
                    return Keys::DOWN;
                case 77:
                    return Keys::RIGHT;
                case 75:
                    return Keys::LEFT;
                default:
                    return -1;
            }
    }
#else
    switch (getchar()) {
        case '\n':
            return Keys::ENTER;
        case '\x1b':    // Escape character
            getchar();  // Read '[' character
            switch (getchar()) {
                case 'A':
                    return Keys::UP;
                case 'B':
                    return Keys::DOWN;
                case 'C':
                    return Keys::RIGHT;
                case 'D':
                    return Keys::LEFT;
                default:
                    return -1;
            }
    }
#endif
    return -1;
}

Time Time::guiTimeInput(){
    bool confirm = false;
    int selected = 0;
    
    std::vector<int> digits = {
        0, 0,
        0, 0,
        0, 0
    };
       

    Text::clearScreen();
    Text::disableInputBuffering();
    while(!confirm){
        printTime(digits, selected);
    
        switch(handleArrowKeys()){
            case Keys::UP:
                if(digits.at(selected) < 9)
                    digits.at(selected)++;
                break;
            case Keys::DOWN:
                if(digits.at(selected) > 0)
                    digits.at(selected)--;
                break;
            case Keys::LEFT:
                (selected == 0) ? selected = digits.size()-1 : selected--;
                break;
            case Keys::RIGHT:
                (selected == digits.size()-1) ? selected = 0 : selected++;
                break;
            case Keys::ENTER:
                confirm = true;
                break;
            default:
                break;
        }

        for(int i = 0; i < digits.size()+2; i++){
            cout << "\b";
        }
    }

    Text::enableInputBuffering();

    return Time{
        digits.at(0) * 10 + digits.at(1),
        digits.at(2) * 10 + digits.at(3),
        digits.at(4) * 10 + digits.at(5),
    };
}

