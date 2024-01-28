#include <atomic>
#include <chrono>
#include <ctime>
#include <curses.h>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <signal.h>

#ifdef _WIN32
#include <Windows.h>
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#include "cli_kit.h"

#include "menu.h"
#include "my_time.h"
#include "pomodoro.h"
#include "timer.h"
#include "utils.h"

using namespace CliKit;
using namespace std;

Time work_interval;
Time break_interval;

void MenuOptions::homeOptions(int option) {
    Pomodoro p;
    switch (option) {
        case 0:
            p = {Utils::getTask(), work_interval, break_interval};
            p.start();
            Text::showCursor();
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

void MenuOptions::selectIntervalOptions(int option) {
    vector<int> work_digits = Time::timeToDigits(work_interval);
    vector<int> break_digits = Time::timeToDigits(break_interval);
    switch (option) {
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
    PomodoroMenu::selectIntervalMenu();
}

void siginthandler(int args){
    Text::clearScreen();
    Text::enableInputBuffering();
    Text::showCursor();
    exit(0);
}

int main(int argc, char **argv) {
    work_interval = {0, 25, 0};
    break_interval = {0, 5, 0};


	signal(SIGINT, siginthandler);
    PomodoroMenu::homeMenu();

    return 0;
}
