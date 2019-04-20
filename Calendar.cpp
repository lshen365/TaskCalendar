#include "Calendar.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
/**
Include saving tasks to .txt file for later reference
**/


using namespace std;

/*
Creates a priorityQueue and sets it to the determined size
*/
Calendar::Calendar(int size, int currMonth,int currDay){
  priorityQueue = new pQueue[size];
  currentQueueSize = 0;
  maxQueueSize = size;
  months.setCurrentMonth(currMonth);
  days.setCurrentDay(currDay);
}



int Calendar::daysTillDueDate(int dueMonth, int dueDay){
  int daysTillDue = 0;
  if(months.getCurrentMonth()!=dueMonth){

    //Checks case if it is due in like July but current month is April
    if(months.getCurrentMonth()<dueMonth){
      daysTillDue+=days.numberOfDays(months.getCurrentMonth(),years.getCurrentYear())-days.getCurrentDay();
      for(int i=1;i<dueMonth-months.getCurrentMonth();i++){ //Adds up all the inbetween months
        daysTillDue+=days.numberOfDays(months.getCurrentMonth()+i,years.getCurrentYear());
      }
      daysTillDue+=dueDay;
      cout<<daysTillDue<<"Days till due"<<endl;
    }
    //Checks for if current Month is April and due date is in January
    else if(months.getCurrentMonth()>dueMonth){
      daysTillDue+=days.numberOfDays(months.getCurrentMonth(),years.getCurrentYear())-days.getCurrentDay();
      for(int i=1;i<12-months.getCurrentMonth();i++){
        daysTillDue+=days.numberOfDays(months.getCurrentMonth()+i,years.getCurrentYear());
      }
      for(int i=1;i<=dueMonth;i++){
        daysTillDue+=days.numberOfDays(i,years.getCurrentYear()+1);
      }
      daysTillDue+=dueDay;
    }
  }else{
    daysTillDue+=days.numberOfDays(months.getCurrentMonth(),years.getCurrentYear())-days.getCurrentDay();
  }

  return daysTillDue;
}

/*
This will calculate all the final priority value based off all the information given
and will return the float priority value. This will be calculated by adding up the
days left until the due date + userPriority + time timeDuration
*/
float Calendar::priorityCalculator(int dueMonth, int dueDay, float timeDuration, int userPriority){
  float total=0.0;
  int daysTillDue=daysTillDueDate(dueMonth,dueDay);
  total+=timeDuration+userPriority+1-daysTillDue;
  return total;

}

void swap(pQueue *a, pQueue *b){
  pQueue temp = *a;
  *a = *b;
  *b = temp;
}
/*
Adds the events that are important into the array
*/
void Calendar::enqueue(){



  ifstream myFile;
  myFile.open("test.txt");
  if(myFile.is_open()){
    string text;
    while(getline(myFile,text)){
      stringstream words(text);
      string holdWord;
      getline(words,holdWord,',');
      priorityQueue[currentQueueSize].eventName = holdWord;
      getline(words,holdWord,',');
      priorityQueue[currentQueueSize].dueMonth = stoi(holdWord);
      getline(words,holdWord,',');
      priorityQueue[currentQueueSize].dueDay = stoi(holdWord);
      getline(words,holdWord,',');
      priorityQueue[currentQueueSize].timeDuration = stoi(holdWord);
      getline(words,holdWord,',');
      priorityQueue[currentQueueSize].userPriority = stoi(holdWord);
      getline(words,holdWord,',');
      priorityQueue[currentQueueSize].finalPriority=stof(holdWord);
      currentQueueSize++;
      int index = currentQueueSize-1;
      // while(index!=0&&priorityQueue[index-1/2].finalPriority<= priorityQueue[index].finalPriority){
      //   swap(&priorityQueue[(index-1/2)],&priorityQueue[index]);
      // }
    }
  }


  // cout<<priorityQueue[index].finalPriority;


}

void Calendar::printMonth(int month){
  printf ("         Calendar - %d\n\n", years.getCurrentYear());
   int days;

   // Index of the day from 0 to 6
   int current = this->days.dayNumber (0, 0, years.getCurrentYear());

   days = this->days.numberOfDays (month, years.getCurrentYear());

   // Print the current month name
   printf("\n  ------------%s-------------\n",
          months.getMonthName(month).c_str());

   // Print the columns
   printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

   // Print appropriate spaces
   int k;
   for (k = 0; k < current; k++)
       printf("     ");
   for (int j = 1; j <= days; j++)
   {
       printf("%5d", j);

       if (++k > 6)
       {
           k = 0;
           printf("\n");
       }
   }
   if (k)
       printf("\n");
   current = k;
   return;
}

void Calendar::printYear(){
  printf ("         Calendar - %d\n\n", years.getCurrentYear());
   int days;

   // Index of the day from 0 to 6
   int current = this->days.dayNumber (1, 1, years.getCurrentYear());

   // i --> Iterate through all the months
   // j --> Iterate through all the days of the month - i
   for (int i = 1; i <= 12; i++)
   {
       days = this->days.numberOfDays (i, years.getCurrentYear());

       // Print the current month name
      printf("\n  ------------%s-------------\n", months.getMonthName(i).c_str());

       // Print the columns
       printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

       // Print appropriate spaces
       int k;
       for (k = 0; k < current; k++)
           printf("     ");
       for (int j = 1; j <= days; j++)
       {
           printf("%5d", j);

           if (++k > 6)
           {
               k = 0;
               printf("\n");
           }
       }
       if (k)
           printf("\n");
       current = k;
   }
   return;
}
//Compares two dates to see which one comes before
//True if date1 comes before date2 and false otherwise
bool compareDate(int year1, int year2, int month1, int month2, int day1, int day2) {
    if (year1 < year2)
        return true;
    if (year1 == year2 && month1 < month2)
        return true;
    if (year1 == year2 && month1 == month2 && day1 < day2)
        return true;
    return false;
}
void Calendar::printWeek(int month, int day){
  int current = this->days.dayNumber (1, 1, years.getCurrentYear());
  int days = this->days.numberOfDays (month, years.getCurrentYear());
  // printf("\n  ------------%s-------------\n", months.getMonthName(i).c_str());
  cout<<"            Week of "<<month<<"/"<<day<<"/"<<years.getCurrentYear()<<endl;
  printf("    Sun     Mon    Tue    Wed    Thu    Fri    Sat\n");

  for(int i=0;i<currentQueueSize;i++){
    if(compareDate(years.getCurrentYear(),years.getCurrentYear(),month,priorityQueue[i].dueMonth,day,priorityQueue[i].dueDay))
    {
      string event=priorityQueue[i].eventName;
      printf("%.7s\n", event.c_str()); //First 7 characters of the event string
    }
  }
}
pQueue Calendar::peek(){
  return priorityQueue[0];
}
Day Calendar::getDays(){
  return days;
}
Year Calendar::getYears(){
  return years;
}
