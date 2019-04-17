#include <iostream>
#include "Calendar.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Calendar run(50,4,17);
  run.enqueue("Birthday",4,18,15.5,5);
  // run.printYear();


  return 0;
}
