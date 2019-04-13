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


int main(int argc, char const *argv[]) {
  Calendar calendar;
  string input="";
  while(input!="4"){
    displayMenu();
    if(input=="1"){//View Calendar

    }else if(input=="2"){//Add Event

    }else if(input=="3"){//Remove Event

    }else{//Exit

    }
  }
  getline(cin,input);
  return 0;
}
