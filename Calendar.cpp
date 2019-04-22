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
      // cout<<daysTillDue<<"Days till due"<<endl;
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
    daysTillDue+=dueDay-days.getCurrentDay();
  }

  return daysTillDue;
}

/*
Counts how many days there are until the due Date
*/
int Calendar::dayTracker(int dueMonth, int dueDay, int month, int day){
  int daysTillDue = 0;
  if(month!=dueMonth){

    //Checks case if it is due in like July but current month is April
    if(month<dueMonth){

      daysTillDue+=days.numberOfDays(month,years.getCurrentYear())-day;
      for(int i=1;i<dueMonth-month;i++){ //Adds up all the inbetween months
        daysTillDue+=days.numberOfDays(month+i,years.getCurrentYear());
      }
      daysTillDue+=dueDay;
    }
    //Checks for if current Month is April and due date is in January
    else if(month>dueMonth){
      daysTillDue+=days.numberOfDays(month,years.getCurrentYear())-day;
      for(int i=1;i<12-months.getCurrentMonth();i++){
        daysTillDue+=days.numberOfDays(month+i,years.getCurrentYear());
      }
      for(int i=1;i<=dueMonth;i++){
        daysTillDue+=days.numberOfDays(i,years.getCurrentYear()+1);
      }
      daysTillDue+=dueDay;
    }
  }else{
    daysTillDue+=dueDay-day;
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
int left(int i){
  return (2*i + 1);
}
int right(int i){
  return 2*i+2;
}
int parent(int i){
  return (i-1)/2;
}

void swap(pQueue *a, pQueue *b){
  pQueue temp = *a;
  *a = *b;
  *b = temp;
}

void Calendar::repairUpward(int index){
  int p = parent(index);
  int l = left(index);
  int r = right(index);
  int max = index;

  if(priorityQueue[p].finalPriority<priorityQueue[index].finalPriority){
    max = p;
  }

  if(max != index){
    swap(&priorityQueue[max],&priorityQueue[index]);
    repairUpward(index);
  }
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

      //Organizes it in the array
      int index = currentQueueSize-1;
      int p = parent(index);
      while(currentQueueSize!=0&&priorityQueue[p].finalPriority<priorityQueue[index].finalPriority){
        swap(&priorityQueue[index],&priorityQueue[p]);
        index = parent(index);
        repairUpward(index);
      }
    }
  }
}

void Calendar::repairDownward(int index){
  int l = left(index);
  int r = right(index);
  int loc = index;
  if(l<currentQueueSize&&priorityQueue[l].finalPriority>priorityQueue[loc].finalPriority){
    loc = l;
  }else if(r<currentQueueSize&&priorityQueue[r].finalPriority>priorityQueue[loc].finalPriority){
    loc = r;
  }

  if(loc!=index){
    swap(&priorityQueue[loc],&priorityQueue[index]);
    repairDownward(index);
  }
}

//Taking out the first element and reorganizing it
void Calendar::dequeue(){
  if(currentQueueSize<=0){
    cout<<"Heap empty"<<endl;
    return;
  }
  if(currentQueueSize==1){
    priorityQueue[0]=priorityQueue[1];
    currentQueueSize--;
    return;
  }

  pQueue max = priorityQueue[0];
  priorityQueue[0]=priorityQueue[currentQueueSize-1];
  currentQueueSize--;
  repairDownward(0);
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
string dayName(int i){
  if(i==0)
    return "Sunday";
  if(i==1)
    return "Monday";
  if(i==2)
    return "Tuesday";
  if(i==3)
    return "Wednesday";
  if(i==4)
    return "Thursday";
  if(i==5)
    return "Friday";
  if(i==6)
    return "Saturday";
}
void Calendar::printDay(int month, int day){
  bool freeDay=true;
  cout<<"                 ";
  printf("%02d/", month);
  printf("%02d/", day);
  cout<<years.getCurrentYear()<<endl;
  int dayNum=this->days.dayNumber(day, month, years.getCurrentYear());
  printf("%33s", "The current date is a ");
  cout<<dayName(dayNum)<<endl;
  for(int i=0;i<currentQueueSize;i++){
    //if the current date is before the due date
    if(compareDate(years.getCurrentYear(),years.getCurrentYear(),month,priorityQueue[i].dueMonth,day,priorityQueue[i].dueDay)){
      //As long as the final priority is positive
      if(priorityQueue[i].finalPriority>0){
        //Spending more than half an hour on the task
        if(priorityQueue[i].timeDuration/daysTillDueDate(priorityQueue[i].dueMonth, priorityQueue[i].dueDay)>=0.5){
          //The date you are viewing is before the current date
          if(!compareDate(years.getCurrentYear(),years.getCurrentYear(),month,months.getCurrentMonth(),day,days.getCurrentDay())){
            freeDay=false;
            string event=priorityQueue[i].eventName;
            printf("%-20.20s ", event.c_str()); //First 20 characters of the event string
            printf("%.1f hrs ",priorityQueue[i].timeDuration/dayTracker(priorityQueue[i].dueMonth, priorityQueue[i].dueDay,months.getCurrentMonth(),days.getCurrentDay()));
            printf("%3d day(s) till due!\n",dayTracker(priorityQueue[i].dueMonth, priorityQueue[i].dueDay,month,day));
          }
        }
      }
    }
  }
  if(freeDay)
    cout<<"     Nothing to do as of today! You're free!\n\n";
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
Month Calendar::getMonth(){
  return months;
}

bool Calendar::isEmpty(){
  if(currentQueueSize==0)
    return true;
  return false;
}
