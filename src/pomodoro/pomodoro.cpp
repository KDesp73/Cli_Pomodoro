#include "pomodoro.h"
#include "cli_kit.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace CliKit;
using namespace std;

void Pomodoro::reset(){
    timer.reset();
}
