#include "pomodoro.h"
#include "cli_kit.h"
#include "utils.h"

#include <iostream>
#include <ctime>
#include <thread>

using namespace CliKit;
using namespace std;

void Pomodoro::reset(){
    timer.reset();
}

void Pomodoro::start(){
    int delay = 1;
    delay *= CLOCKS_PER_SEC;

    int loading_bar_length = 25;

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
            Animations::loadingBar(timer.time_passed, this->work_interval, loading_bar_length);

            // Refresh
            clock_t start_time = clock();
            while((clock() - start_time) / CLOCKS_PER_SEC < 1);
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
                Animations::loadingBar(break_seconds, this->break_interval, loading_bar_length);

                // Refresh
                clock_t start_time = clock();
                while((clock() - start_time) / CLOCKS_PER_SEC < 1);
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
