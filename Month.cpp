#include "Month.hpp"
#include <iostream>

using namespace std;

/*
Initializes the array so that each element represents a number of month;
Ex: i=1 is January
    i=2 is February
*/
Month::Month(){
  for(int i=0;i<12;i++){
    months[i]=i;
  }
}

void Month::setCurrentMonth(int m){
  currentMonth = m;
}

int Month::getMonth(){
  return currentMonth;
}

/*
Returns the names of the months correlating to each index of the array
*/
string Month::getMonthName(int i){
  switch(i){
    case 0:
      return "January";

    case 1:
      return "February";

    case 2:
      return "March";

    case 3:
      return "April";

    case 4:
      return "May";

    case 5:
      return "June";

    case 6:
      return "July";

    case 7:
      return "August";

    case 8:
      return "September";

    case 9:
      return "October";

    case 10:
      return "November";

    case 11:
      return "December";

    default:
      return "Month is not valid";

  }
}
void Month::printMonth(){
  cout<<"currentMonth"<<endl;

}
