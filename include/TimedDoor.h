// Copyright 2021 GHA Test Team

#ifndef INCLUDE_TIMEDDOOR_H_
#define INCLUDE_TIMEDDOOR_H_

class DoorTimerAdapter;
class Timer;
class Door;
class TimedDoor;

class TimerClient {
 public:
  virtual void Timeout() = 0;
};

class Door {
 public:
  virtual void lock() = 0;
  virtual void unlock() = 0;
  virtual bool isDoorOpened() = 0;
};

class DoorTimerAdapter : public TimerClient {
 private:
  TimedDoor& door;
 public:
  explicit DoorTimerAdapter(TimedDoor&);
  void Timeout() override;
};

class TimedDoor : public Door {
 private:
  DoorTimerAdapter * adapter;
  int iTimeout;
  bool opened;
 public:
  explicit TimedDoor(int);
  bool isDoorOpened() override;
  void unlock() override;
  void lock() override;
  void DoorTimeOut();
  void throwState();
};

class Timer {
  TimerClient *client;
  void sleep(int);
 public:
  void tregister(int, TimerClient*);
};

#endif  // INCLUDE_TIMEDDOOR_H_
