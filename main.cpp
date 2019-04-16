#include <iostream>
#include "Calendar.hpp"

using namespace std;

void displayMenu(){
  cout<<"Welcome to Leon and Justin's Task Scheduling App"<<endl;
  cout<<"(1) View Calendar"<<endl;
  cout<<"(2) Add Event"<<endl;
  cout<<"(3) Remove Event"<<endl;
  cout<<"(4) Exit"<<endl;
}
bool isdigit(string s){
  if(s=="0"||s=="1"||s=="2"||s=="3"||s=="4"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9"||s=="10"||s=="11")
    return true;
  return false;
}


int main(int argc, char const *argv[]) {
  Calendar calendar(50,3);
  string input="0";
  while(1){
    cout<<"What is the current month? (0 for Jan, 1 for Feb, etc...)\n";
    getline(cin,input);
    if(isdigit(input)){
      break;
    }else{
      cout<<"Sorry not a valid month try again\n";
    }
  }
  calendar.printMonth(stoi(input));

  while(input!="4"){
    displayMenu();
    getline(cin, input);
    if(input=="1"){//View Calendar
      calendar.printYear();
    }else if(input=="2"){//Add Event

    }else if(input=="3"){//Remove Event

    }else if(input=="4"){//Exit
      cout<<"Thank you for using our scheduler. Goodbye!\n";
    }else{
      cout<<"Invalid input. Please try again\n";
    }
  }
  return 0;
}
