// Copyright 2021 valvarl
#include "TimedDoor.h"
#include <iostream>
#include <ctime>

int main() {
    TimedDoor tDoor(5);
    try {
        tDoor.lock();
        tDoor.throwState();
    }
    catch(std::string message) {
        std::cout << message;
    }

  return 0;
}
