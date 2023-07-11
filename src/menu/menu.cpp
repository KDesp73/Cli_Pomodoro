#include "menu.h"
#include "cli_kit.h"

#include <string>

using namespace CliKit;
using namespace std;


void MenuOptions::settingsOptions(int option){
    switch(option){
        case 0:
            PomodoroMenu::selectIntervalMenu();
            break;
        case 1:
            PomodoroMenu::homeMenu();
            break;
        default:
            break;
    }
}

void PomodoroMenu::homeMenu(){
    vector <string> options = {"Start", "Settings", "Exit"};
    CliKit::Menu::menu("Cli Pomodoro", 4, options, &MenuOptions::homeOptions);
}

void PomodoroMenu::settingsMenu(){
    vector <string> options = {"Set intervals", "Return"};
    CliKit::Menu::menu("Settings", 4, options, &MenuOptions::settingsOptions);
}

void PomodoroMenu::selectIntervalMenu(){
    vector<string> options = {"Work", "Break", "Return"};
    CliKit::Menu::menu("Set Intervals", 4, options, &MenuOptions::selectIntervalOptions);
}
