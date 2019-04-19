#include "Day.hpp"
#include <iostream>

using namespace std;

Day::Day(){

}

//Function returns the index of the day of the day from day/month/year format
//Index 0= sunday 1= monday etc.

int Day::dayNumber(int day, int month, int year)
{

    static int arr[] = { 0, 3, 2, 5, 0, 3, 5, 1,4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 + year/400 + arr[month-1] + day) % 7;
}

int Day::numberOfDays (int month, int year){
  // January
    if (month == 1)
        return (31);
    // February
    if (month == 2)
    {
        // If the year is leap then February has 29 days
        if (year%400==0||(year%4==0&&year%100!=0))
            return (29);
        else
            return (28);
    }
    // March
    if (month == 3)
        return (31);
    // April
    if (month == 4)
        return (30);
    // May
    if (month == 5)
        return (31);
    // June
    if (month == 6)
        return (30);
    // July
    if (month == 7)
        return (31);
    // August
    if (month == 8)
        return (31);
    // September
    if (month == 9)
        return (30);
    // October
    if (month == 10)
        return (31);
    // November
    if (month == 11)
        return (30);
    // December
    if (month == 12)
        return (31);
}
int Day::getCurrentDay(){
  return day;
}
void Day::setCurrentDay(int d){
  day=d;
}
