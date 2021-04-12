// Copyright 2021 valvarl

#include <TimedDoor.h>
#include <thread>

DoorTimerAdapter::DoorTimerAdapter(TimedDoor & timedDoor) : door(timedDoor) {}

void DoorTimerAdapter::Timeout() {
    door.DoorTimeOut();
}

TimedDoor::TimedDoor(int timeout) : iTimeout(timeout), opened(false) {
    adapter = new DoorTimerAdapter(*this);
}

bool TimedDoor::isDoorOpened() {
    return opened;
}

void TimedDoor::unlock() {
    opened = true;
    Timer timer{};
    timer.tregister(iTimeout, adapter);
}

void TimedDoor::lock() {
    opened = false;
}

void TimedDoor::DoorTimeOut() {
    if (opened) {
        throw std::string{"close the door!"};
        adapter->Timeout();
    }
}

void TimedDoor::throwState() {
    throw(opened ? std::string{"the door is opened!"} :
    std::string{"the door is closed!"});
}


void Timer::sleep(int delay) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay * 1000));
    client->Timeout();
}

void Timer::tregister(int delay, TimerClient * _client) {
    client = _client;
    sleep(delay);
}
