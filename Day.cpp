#include "Day.hpp"
#include <iostream>

using namespace std;

Day::Day(){

}

int numberOfDays (int month, int year){
  // January
    if (month == 0)
        return (31);
    // February
    if (month == 1)
    {
        // If the year is leap then February has 29 days
        if (year%400==0||(year%4==0&&year%100!=0)) 
            return (29);
        else
            return (28);
    }
    // March
    if (month == 2)
        return (31);
    // April
    if (month == 3)
        return (30);
    // May
    if (month == 4)
        return (31);
    // June
    if (month == 5)
        return (30);
    // July
    if (month == 6)
        return (31);
    // August
    if (month == 7)
        return (31);
    // September
    if (month == 8)
        return (30);
    // October
    if (month == 9)
        return (31);
    // November
    if (month == 10)
        return (30);
    // December
    if (month == 11)
        return (31);
}
