#include <iostream>
#include "timer.h"
#include <thread>

int main() {
    Timer timer;
    timer.Log();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    timer.Log();

    timer.ResetTimer2Now();

    timer.Log();

    timer.Stop();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    timer.Log();
    return 0;
}
