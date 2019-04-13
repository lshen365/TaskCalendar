#ifndef YEAR_HPP
#define YEAR_HPP

#include <iostream>

Class Year{
  public:
    Year(int num);
    int getYear();
    void addYear(int num);
    bool doesYearExist(int num);

  private:
    int year;

};
#endif
