#include <iostream>
#include "YEAR.HPP"
#include <vector>
using namespace std;


Year::Year(int year){
  addYear(year);
  currentYear=year;
}

void Year::addYear(int num){
  if(doesYearExist(num)){
    cout<<"Sorry this year already exists. No need to add it again."<<endl;
    return;
  }
  years.push_back(num);
}

/**
Traverse through the entire vector size and see if the years match
This will return a true if the year is inside the years vector.
**/
bool Year::doesYearExist(int num){
  for(int i=0;i<years.size();i++){
    if(years.at(i)==num)
      return true;
  }
  return false;
}
