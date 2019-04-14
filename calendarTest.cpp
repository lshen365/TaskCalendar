#include <iostream>
#include "Calendar.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Calendar run(50,3);
  run.enqueue("Birthday",4,13,15.0,5);
  //run.printMonth(3);

  return 0;
}
