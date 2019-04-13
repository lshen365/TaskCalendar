#ifndef DAY_HPP
#define DAY_HPP

#include <iostream>

class Day{
public:
  Day();
  int getDay();
  int numberOfDays (int month, int year);
  int dayNumber(int,int,int);

private:
  int day;

};
#endif
