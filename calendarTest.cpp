#include <iostream>
#include "Calendar.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Calendar run(50,4,18);
  run.enqueue("Birthday",4,13,15.0,5);
  run.enqueue("test",4,13,15.0,5);
  // run.printYear();
  // run.printMonth(11);
  run.printWeek(4,18);

  return 0;
}
