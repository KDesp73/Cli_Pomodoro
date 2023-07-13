#include <curses.h>
#include <iostream>
#include <string>
#include <chrono>
#include <atomic>
#include <vector>
#include <thread>

#ifdef _WIN32
    #include <conio.h>
    #include <Windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#include "cli_kit.h"

#include "timer.h"
#include "my_time.h"
#include "menu.h"
#include "pomodoro.h"
#include "utils.h"

using namespace CliKit;
using namespace std;

Time work_interval;
Time break_interval;


void MenuOptions::homeOptions(int option){
    switch(option){
        case 0:
            return;            
            break;
        case 1:
            PomodoroMenu::settingsMenu();
            break;
        case 2:
            cout << "Press Enter to exit...";
            cin.get();
            exit(0);
        default:
            break;
    }
}

void MenuOptions::selectIntervalOptions(int option){
    vector<int> work_digits = Time::timeToDigits(work_interval);
    vector<int> break_digits = Time::timeToDigits(break_interval);
    switch(option){
        case 0:
            work_interval = Time::guiTimeInput(work_digits);
            break;
        case 1:
            break_interval = Time::guiTimeInput(break_digits);
            break;
        case 2:
            PomodoroMenu::settingsMenu();
            break;
    } 
    PomodoroMenu::settingsMenu();
}



void Pomodoro::start(){
    int delay = 1;
    delay *= CLOCKS_PER_SEC;

    string side_space = "  ";
    string sound_path = Utils::getProjectPath() + "/assets/alert.ogg";
    sound_path = Utils::removeSubstring(sound_path, "/build");
    bool end = false;

    Text::hideCursor();
    Text::clearScreen();
    while(!end){
        while(this->timer.time_passed <= this->work_interval){
            Time t = Time::secondsToTime(timer.time_passed);

            // Rendering
            cout << endl << side_space << Text::red << "Task: " << Text::normal  << task << endl;
            cout << side_space << t.to_string() << endl;
            cout << side_space;
            Animations::loadingBar(timer.time_passed, this->work_interval, 40);

            // Refresh
            this_thread::sleep_for(chrono::seconds(1));
            timer.time_passed++;
            Text::clearScreen();
        }   
        if(break_interval != 0){
            Sound::playSound(sound_path);
            cout << endl << side_space << "Break Time. Press " + Text::u_blue +"Enter" + Text::normal +  " to start your break";
            cin.get();
            
            Text::clearScreen();
            
            int break_seconds = 0;
            while(break_seconds <= this->break_interval){
                Time t = Time::secondsToTime(break_seconds);
                
                // Rendering
                cout << endl << side_space << Text::red << "Break Time!" << Text::normal << endl; 
                cout << side_space << t.to_string() << endl;
                cout << side_space;
                Animations::loadingBar(break_seconds, this->break_interval, 40);

                // Refresh
                this_thread::sleep_for(chrono::seconds(1));
                break_seconds++; 
                Text::clearScreen();
            }
            Sound::playSound(sound_path);
            cout << endl << side_space << "Break is over. Press " + Text::u_blue + "Enter" + Text::normal + " to continue with your task";
            cin.get();

            Text::clearScreen();
            reset();
        } else break;
    }
}



int main(int argc, char **argv){
    work_interval = {0, 25, 0};
    break_interval = {0, 5, 0};
    
    PomodoroMenu::homeMenu();


    Pomodoro p{Utils::getTask(), work_interval, break_interval};
    
    p.start();

    Text::showCursor();

    return 0;
}
