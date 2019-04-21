#include <iostream>
#include <string>
#include "Calendar.hpp"
#include <fstream>
#include <sstream>
using namespace std;

void displayMenu(){
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

void viewDay(Calendar &calendar, int month, int day){
  string choice;
  cout<<"Would you like to view (1) Tomorrow (2) Yesterday or (3) Exit\n";
  getline(cin, choice);
  if(choice=="1"||choice=="2"||choice=="3"){
    if(choice=="1"){ //Tomorrow
      if(day+1>calendar.getDays().numberOfDays(month,calendar.getYears().getCurrentYear())){ //New Month
        if(month==12){ //New Year
          calendar.printDay(1,1);
          viewDay(calendar, 1, 1);
          calendar.getDays().setCurrentDay(1);
          calendar.getMonth().setCurrentMonth(1);
        }else{
          // calendar.days.setCurrentDay(calendar.days.getCurrentDay()+1);
          calendar.printDay(month+1,1);
          viewDay(calendar, month+1,1);
          calendar.getDays().setCurrentDay(1);
          calendar.getMonth().setCurrentMonth(month+1);
        }
      }else{
        calendar.printDay(month,day+1);
        viewDay(calendar, month, day+1);
        calendar.getDays().setCurrentDay(day+1);
        calendar.getMonth().setCurrentMonth(month);
      }
    }else if(choice=="2"){//Yesterday
      if(day-1<1){
        if(month==1){//New Year
          calendar.printDay(1,1);
          viewDay(calendar, 1, 1);
          calendar.getDays().setCurrentDay(1);
          calendar.getMonth().setCurrentMonth(1);
        }else{
          int dayTemp=calendar.getDays().numberOfDays(month-1,calendar.getYears().getCurrentYear());
          calendar.printDay(month-1,dayTemp);
          viewDay(calendar, month-1,dayTemp);
          calendar.getDays().setCurrentDay(dayTemp);
          calendar.getMonth().setCurrentMonth(month-1);
        }
      }else{
        calendar.printDay(month,day-1);
        viewDay(calendar, month, day-1);
        calendar.getDays().setCurrentDay(day-1);
        calendar.getMonth().setCurrentMonth(month);
      }
    }else{
      cout<<"Back to main menu...\n\n";
    }
  }else{
    cout<<"Not a valid input, try again\n";
    viewDay(calendar, month, day);
  }
}
void viewCalendar(Calendar &calendar){ //Option to view calendar
  string month, day, choice;
  cout<<"Would you like to view a (1) Daily Calendar (2) Monthly Calendar or (3) Yearly Calendar?\n";
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
      calendar.printDay(stoi(month),stoi(day));
      viewDay(calendar, stoi(month), stoi(day));
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

bool isValidDay(int month, int num){
  Day temp;
  int numDays = temp.numberOfDays(month,2019);
  if(num>0&&num<=numDays)
    return true;
  return false;
}

bool isValidMonth(int num){
  if(num>=1&&num<=12)
    return true;
  return false;
}
void addEvent(Calendar &calendar){
  string event, dueMonth, dueDay, time, priority;

  cout<<"What event will be added?\n";
  getline(cin, event);

  cout<<"What month will this be due?\n";
  getline(cin, dueMonth);
  while(!isValidMonth(stoi(dueMonth))){
    cout<<"Please enter a valid month \n"<<endl;
    getline(cin,dueMonth);
  }

  cout<<"What day will this be due?\n";
  getline(cin, dueDay);
  while(!isValidDay(stoi(dueMonth),stoi(dueDay))){
    cout<<"Please enter a valid day \n"<<endl;
    getline(cin,dueDay);
  }

  cout<<"What is the estimated amount of hours this task will take?\n";
  getline(cin, time);

  cout<<"What is your estimated priority for this event (0-10)?\n";
  getline(cin, priority);
  while(stoi(priority)<0||stoi(priority)>10){
    cout<<"Please enter a valid number"<<endl;
    getline(cin,priority);
  }

//  calendar.enqueue(event, stoi(dueMonth), stoi(dueDay), stoi(time), stoi(priority));
//  cout<<"Your task "<<event<<" has been successfully enqueued!\n\n";
  float finalPriorityValue = calendar.priorityCalculator(stoi(dueMonth),stoi(dueDay),stof(time),stoi(priority));
  //Add to textfile
  ofstream outfile;
  outfile.open("test.txt", ios_base::app); //Appends to the end of file
  outfile << event << "," << dueMonth << "," << dueDay << "," << time << "," <<priority << "," <<to_string(finalPriorityValue)<<endl;
  outfile.close();
}

void removeEvent(){
  cout<<"Which event would you like to remove? Please select a number \n"<<endl;
  ifstream testFile;
  testFile.open("test.txt",ios_base::app);
  ofstream tempFile("temp.txt");
  string storeString; //Holds the event they want to remove
  string choice; //Holds the string they should remove
  int total = 0; //Total number of strings there are
  string line;

  while(getline(testFile,line)){
    if(!line.empty()){
      cout<<"Run"<<endl;
      stringstream words(line);
      string holdWord;
      string holdMonth;
      string holdDay;
      getline(words,holdWord,',');
      getline(words,holdMonth,',');
      getline(words,holdDay,',');
      cout<<"("<<total<<") "<<holdWord<<"Due Date: "<<holdMonth<<"/"<<holdDay<<endl;
      total++;
    }

  }
  getline(cin,choice);
  while(stoi(choice)<1||stoi(choice)>total-1){
    cout<<"Please enter a valid response\n"<<endl;
    getline(cin,choice);
  }
  testFile.clear();
  testFile.seekg(0,ios::beg);

//  tempFile.open("temp.txt", ios_base::app);
  for(int i=0;i<total;i++){
    if(i!=stoi(choice)){
      string temp;
      getline(testFile,temp);
      tempFile<<temp<<endl;
    }else{
      string temp;
      getline(testFile,temp);
    }
  }
  testFile.close();
  tempFile.close();
  remove("test.txt");
  rename("temp.txt","test.txt");

  cout<<endl;

}

int main(int argc, char const *argv[]) {
  //Prompts first 2 questions asking for day / month
  cout<<endl;
  cout<<"Welcome to Leon and Justin's Task Scheduling App \n"<<endl;
  string holdMonth;
  string holdDay;
  cout<<"What month is today? \n"<<endl;
  getline(cin,holdMonth);
  while(!isValidMonth(stoi(holdMonth))){
    cout<<"Please enter a valid month \n"<<endl;
    getline(cin,holdMonth);
  }
  cout<<endl;
  cout<<"What day is today? \n"<<endl;
  getline(cin,holdDay);
  cout<<endl;
  while(!isValidDay(stoi(holdMonth),stoi(holdDay))){
    cout<<"Please enter a valid day \n"<<endl;
    getline(cin,holdDay);
  }

  Calendar calendar(50,stoi(holdMonth),stoi(holdDay));
  string menu;
  while(menu!="4"){
    displayMenu();
    calendar.enqueue();
    getline(cin, menu);
    if(menu=="1"){//View Calendar
      viewCalendar(calendar);
    }else if(menu=="2"){//Add Event
      addEvent(calendar);
    }else if(menu=="3"){//Remove Event
      removeEvent();
    }else if(menu=="4"){//Exit
      cout<<"Thank you for using our scheduler. Goodbye!\n";
    }else{
      cout<<"Invalid input. Please try again\n";
    }
  }
  return 0;
}
