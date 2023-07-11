#include <curses.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#include "cli_kit.h"

#include "timer.h"
#include "my_time.h"
#include "menu.h"
#include "pomodoro.h"

using namespace CliKit;
using namespace std;

Time work_interval;
Time break_interval;
std::atomic<bool> stopFlag(false);

void thread_task(Timer& timer){
    while(!stopFlag)
        timer.start();
}

string getTask(){
    string task;
    cout << Text::red << "Task: " << Text::normal;
    getline(cin, task);

    return task;
}

char getCharacter() {
#ifdef _WIN32
    return _getch();
#else
    char buf = 0;
    struct termios old{};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
#endif
}

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

    bool end = false;

    Text::clearScreen();
    while(!end){
        //if(getCharacter() == 'e' || getCharacter() == 'E') return;

        while(timer.time_passed <= timer.target_time){
            //if(getCharacter() == 'e' || getCharacter() == 'E') return;    

            // Rendering
            cout << Text::red << "Task: " << Text::normal  << task << endl;
            cout << timer.to_string() << endl;
            Animations::loadingBar(this->timer.time_passed, this->timer.target_time);

            // Refresh
            this_thread::sleep_for(chrono::seconds(1));

            Text::clearScreen();
        }   
        if(break_interval != 0){
            cout << "\aBreak Time. Press " + Text::u_blue +"Enter" + Text::normal +  " to start your break";
            cin.get();
            
            Text::clearScreen();
            
            int break_seconds = 0;
            while(break_seconds <= this->break_interval){
                Time t = Time::secondsToTime(break_seconds);
                
                // Rendering
                cout << Text::red << "Break Time!" << Text::normal << endl; 
                cout << t.to_string() << endl;
                Animations::loadingBar(break_seconds, this->break_interval);

                // Refresh
                this_thread::sleep_for(chrono::seconds(1));

                break_seconds++; 

                Text::clearScreen();
            }
            
            cout << "\aBreak is over. Press " + Text::u_blue + "Enter" + Text::normal + " to continue with your task";
            cin.get();

            Text::clearScreen();
            reset();
        } else break;
    }
}



int main(int argc, char **argv){
    work_interval = {0, 0, 10};
    break_interval = {0, 0, 5};
    
    PomodoroMenu::homeMenu();


    int work_int = Time::timeToSeconds(work_interval);
    int break_int = Time::timeToSeconds(break_interval);
    Pomodoro p{getTask(), work_int, break_int};
    
    thread timer_thread(thread_task, ref(p.timer));
    p.start();

    timer_thread.join();
    return 0;
}
