#ifndef YEAR_HPP
#define YEAR_HPP
#include <vector>
#include <iostream>
class Year{
  public:

    Year(int);
    int getCurrentYear();
    void addYear(int num);
    bool doesYearExist(int num);

  private:
    int currentYear;
    vector<int>years;

};
#endif
