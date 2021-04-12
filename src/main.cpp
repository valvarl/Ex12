// Copyright 2021 valvarl
#include "TimedDoor.h"
#include <iostream>
#include <ctime>

int main() {
    TimedDoor tDoor(5);
    time_t start = time(nullptr);
    time_t finish;
    try {
            tDoor.unlock();
    } catch(const char *message) {
        finish = time(nullptr);
        int delta = finish - start;
        std::cout << delta;
    }

  return 0;
}
