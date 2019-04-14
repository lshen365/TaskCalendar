#ifndef MONTH_HPP
#define MONTH_HPP
#include <iostream>
using namespace std;

class Month{
public:
  Month();
  int getMonth();
  void printMonth();
  string getMonthName(int);
  void setCurrentMonth(int);

private:
  int currentMonth;
  int months[12];

};
#endif
