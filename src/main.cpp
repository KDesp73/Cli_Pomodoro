#include <iostream>
#include <thread>

#include "cli_kit.h"

#include "timer.h"

using namespace CliKit;
using namespace std;

void thread_task(Timer& timer){
    timer.start();
}

int main(int argc, char **argv){
    Timer timer;


    std::thread timer_thread(thread_task, ref(timer));
   

    timer_thread.join();


	return 0;
}
