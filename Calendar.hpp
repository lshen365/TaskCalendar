#ifndef CALENDAR_HPP
#define CALENDAR_HPP
#include "Day.Hpp"
#include "Month.hpp"
#include "Year.hpp"
#include <iostream>
using namespace std;

Class Calendar{
public:
  Calendar();
  void printMonth(int month);
  void printWeek();
private:
  Year years;
  Month months;
  Day days;


};
#endif
