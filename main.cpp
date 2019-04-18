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
bool isdigit(string s){ //Valid month checker
  if(s=="12"||s=="1"||s=="2"||s=="3"||s=="4"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9"||s=="10"||s=="11")
    return true;
  return false;
}


int main(int argc, char const *argv[]) {
  Calendar calendar(50,4,17);
  string input="0";
  while(1){
    cout<<"What is the current month? (1 for Jan, 2 for Feb, etc...)\n";
    getline(cin,input);
    if(isdigit(input)){
      break;
    }else{
      cout<<"Sorry not a valid month try again\n";
    }
  }
  calendar.printMonth(stoi(input));
  string menu;
  while(menu!="4"){
    displayMenu();
    getline(cin, menu);
    if(menu=="1"){//View Calendar
      calendar.printYear();
    }else if(menu=="2"){//Add Event

    }else if(menu=="3"){//Remove Event

    }else if(menu=="4"){//Exit
      cout<<"Thank you for using our scheduler. Goodbye!\n";
    }else{
      cout<<"Invalid input. Please try again\n";
    }
  }
  return 0;
}
