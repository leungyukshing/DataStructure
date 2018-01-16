#ifndef TIMER_H
#define TIMER_H
#include <ctime>
class Timer {
public:
  Timer();
  double elapsed_time();
  void reset();
private:
  clock_t start_time;
};
#endif