#include <iostream>
#include<string>
#include "Calendar.hpp"

using namespace std;

void displayMenu(){
  cout<<"Welcome to Leon and Justin's Task Scheduling App"<<endl;
  cout<<"(1) View Calendar"<<endl;
  cout<<"(2) Add Event"<<endl;
  cout<<"(3) Remove Event"<<endl;
  cout<<"(4) Exit"<<endl;
}
bool validMonth(string s){ //Valid month checker
  if(s=="12"||s=="1"||s=="2"||s=="3"||s=="4"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9"||s=="10"||s=="11")
    return true;
  return false;
}
bool validDay(string s){ //Valid day checker
  if(s=="1"||s=="2"||s=="3"||s=="4"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9"||s=="10"||s=="11"||s=="12"||s=="13"||s=="14"||s=="15"||s=="16"||s=="17"||s=="17"||s=="18"||s=="19"||s=="20"||s=="21"||s=="22"||s=="23"||s=="24"||s=="25"||s=="26"||s=="27"||s=="28"||s=="29"||s=="30"||s=="31")
    return true;
  return false;
}
void viewCalendar(Calendar calendar){ //Option to view calendar
  string month, day, choice;
  cout<<"Would you like to view a (1) Weekly Calendar (2) Monthly Calendar or (3) Yearly Calendar?\n";
  getline(cin, choice);
  if(choice == "1" || choice == "2" || choice =="3"){
    if(choice == "1"){
      cout<<"What month would you like to view? (1 for Jan, 2 for Feb, etc...)\n";
      getline(cin, month);
      if(!validMonth(month)){
        cout<<"Sorry, please enter a valid month\n\n";
        viewCalendar(calendar);
      }
      cout<<"What day would you like to view?\n";
      getline(cin, day);
      if(!validDay(day)){
        cout<<"Sorry, please enter a valid day\n\n";
        viewCalendar(calendar);
      }
      if(calendar.getDays().numberOfDays(stoi(month),calendar.getYears().getCurrentYear())<stoi(day)){
        cout<<"Sorry, day is not valid for the month\n\n";
        viewCalendar(calendar);
      }
      calendar.printWeek(stoi(month),stoi(day));
    }else if(choice == "2"){
      cout<<"What month would you like to view? (1 for Jan, 2 for Feb, etc...)\n";
      getline(cin, choice);
      if(validMonth(choice)){
        calendar.printMonth(stoi(choice));
      }else{
        cout<<"Sorry, please enter a valid month\n\n";
        viewCalendar(calendar);
      }
    }else{
      calendar.printYear();
    }
  }else{
    cout<<"Please enter a valid choice\n";
    viewCalendar(calendar);
  }
}

void addEvent(Calendar &calendar){
  string event, dueMonth, dueDay, time, priority;
  cout<<"What event will be added?\n";
  getline(cin, event);
  cout<<"What month will this be due?\n";
  getline(cin, dueMonth);
  cout<<"What day will this be due?\n";
  getline(cin, dueDay);
  cout<<"What is the estimated amount of hours this task will take?\n";
  getline(cin, time);
  cout<<"What is your estimated priority for this event?\n";
  getline(cin, priority);
  calendar.enqueue(event, stoi(dueMonth), stoi(dueDay), stoi(time), stoi(priority));
  cout<<"Your task "<<event<<" has been successfully enqueued!\n\n";
}
int main(int argc, char const *argv[]) {
  Calendar calendar(50,4,17);
  string menu;
  while(menu!="4"){
    displayMenu();
    getline(cin, menu);
    if(menu=="1"){//View Calendar
      viewCalendar(calendar);
    }else if(menu=="2"){//Add Event
      addEvent(calendar);
    }else if(menu=="3"){//Remove Event

    }else if(menu=="4"){//Exit
      cout<<"Thank you for using our scheduler. Goodbye!\n";
    }else{
      cout<<"Invalid input. Please try again\n";
    }
  }
  return 0;
}
