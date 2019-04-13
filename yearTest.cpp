#include "Year.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  Year test;
  test.addYear(2019);
  cout<<test.doesYearExist(2020);
  return 0;
}
