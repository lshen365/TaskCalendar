#include <iostream>
#include "Calendar.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Calendar run(50,4,21);
  cout<<"Days till due "<<run.dayTracker(5,1,1,1);
  //run.enqueue();
  // while(!run.isEmpty()){
  //   pQueue n = run.peek();
  //   cout<<n.finalPriority<<endl;
  //   run.dequeue();
  // }
//  cout<<run.peek().eventName;
  // run.printYear();
  // run.printMonth(11);
  //run.printWeek(4,18);

  return 0;
}
