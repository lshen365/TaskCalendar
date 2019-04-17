#ifndef DAY_HPP
#define DAY_HPP

#include <iostream>

class Day{
public:
  Day();
  int getCurrentDay();
  int numberOfDays (int month, int year);
  int dayNumber(int,int,int);
  void setCurrentDay(int);

private:
  int day;

};
#endif
