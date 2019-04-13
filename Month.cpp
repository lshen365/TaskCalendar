#include "Month.hpp"
#include <iostream>

using namespace std;

Month::Month(){
  for(int i=0;i<12;i++){
    months[i]=i;
  }
}

/*
Returns the names of the months correlating to each index of the array
*/
string Month::getMonthName(int i){
  switch(i+1){
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
