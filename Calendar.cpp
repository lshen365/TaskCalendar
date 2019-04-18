#include "Calendar.hpp"
#include <iostream>

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
/*
Adds the events that are important into the array
*/
void Calendar::enqueue(string event,int dueMonth, int dueDay, float timeDuration,int priority){
  int index = currentQueueSize;
  currentQueueSize++;

  priorityQueue[index].eventName = event;
  priorityQueue[index].dueMonth = dueMonth;
  priorityQueue[index].dueDay = dueDay;
  priorityQueue[index].timeDuration = timeDuration;
  priorityQueue[index].userPriority = priority;
  priorityQueue[index].finalPriority = priorityCalculator(dueMonth,dueDay,timeDuration,priority);
  cout<<priorityQueue[index].finalPriority;
  //add to text file
}

void Calendar::printMonth(int month){
  printf ("         Calendar - %d\n\n", years.getCurrentYear());
   int days;

   // Index of the day from 0 to 6
   int current = this->days.dayNumber (1, 1, years.getCurrentYear());

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
   // j --> Iterate through all the days of the
   //       month - i
   for (int i = 1; i <= 12; i++)
   {
       days = this->days.numberOfDays (i, years.getCurrentYear());

       // Print the current month name
       printf("\n  ------------%s-------------\n",
              months.getMonthName(i).c_str());

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

pQueue Calendar::peek(){
  return priorityQueue[0];
}
