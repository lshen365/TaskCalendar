#ifndef YEAR_HPP
#define YEAR_HPP
#include <vector>
#include <iostream>
using namespace std;
class Year{
  public:

    Year();
    int getCurrentYear();
    void addYear(int num);
    bool doesYearExist(int num);

  private:
    int currentYear;
    vector<int>years;

};
#endif
