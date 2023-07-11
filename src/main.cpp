#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "cli_kit.h"

#include "timer.h"
#include "my_time.h"
#include "menu.h"
#include "pomodoro.h"

using namespace CliKit;
using namespace std;

Time work_interval;
Time break_interval;

void thread_task(Timer& timer){
    timer.start();
}

string getTask(){
    string task;
    cout << "Task: ";
    getline(cin, task);

    return task;
}

void MenuOptions::homeOptions(int option){
    Pomodoro p;
    switch(option){
        case 0:
            p = {getTask(), Time::timeToSeconds(work_interval), Time::timeToSeconds(break_interval)};

            p.start();
            
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
    switch(option){
        case 0:
            work_interval = Time::guiTimeInput();
            break;
        case 1:
            break_interval = Time::guiTimeInput();
            break;
        case 2:
            PomodoroMenu::settingsMenu();
            break;
    }
    PomodoroMenu::settingsMenu();
}



void Pomodoro::start(){
    bool end = false;

    thread timer_thread(thread_task, ref(timer));
    while(!end){
        while(timer.time_passed <= timer.target_time){
            // Rendering
            cout << Text::red << "Task: " << Text::normal  << task << endl;
            cout << timer.to_string() << endl;

            //Refresh
            this_thread::sleep_for(chrono::seconds(1));
            Text::clearScreen();
        }   
        if(break_interval != 0){
            cout << "Break..." << endl;
            Pomodoro break_pomodoro{"Break", this->break_interval, 0};
            break_pomodoro.start();
            cout << "Break is over. Back to your task now!" << endl;
            timer_thread.join();
            reset();
            start();
        } else break;
    }

    timer_thread.join();
}



int main(int argc, char **argv){
    PomodoroMenu::homeMenu();

    return 0;
}
