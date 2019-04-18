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

int Month::getCurrentMonth(){
  return currentMonth;
}

/*
Returns the names of the months correlating to each index of the array
*/
string Month::getMonthName(int i){
  switch(i){
    case 1:
      return "January";

    case 2:
      return "February";

    case 3:
      return "March";

    case 4:
      return "April";

    case 5:
      return "May";

    case 6:
      return "June";

    case 7:
      return "July";

    case 8:
      return "August";

    case 9:
      return "September";

    case 10:
      return "October";

    case 11:
      return "November";

    case 12:
      return "December";

    default:
      return "Month is not valid";

  }
}
void Month::printMonth(){
  cout<<"currentMonth"<<endl;

}
