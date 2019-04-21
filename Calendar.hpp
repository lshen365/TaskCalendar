#ifndef CALENDAR_HPP
#define CALENDAR_HPP
#include "Day.Hpp"
#include "Month.hpp"
#include "Year.hpp"
#include <iostream>
using namespace std;

struct pQueue
{
  string eventName;
  int dueMonth;
  int dueDay;
  float timeDuration; //Estimated Average of how long the task will take
  int userPriority; //User determined priority
  float finalPriority; //Algorithm calculated priority that will be used when inserting
};

class Calendar{
  public:
    Calendar(int,int);
    Calendar(int size, int currMonth,int currDay);

    int daysTillDueDate(int dueMonth, int dueDay);

    Month getMonth();
    //Will add it to the queue based off of the priorities
    void enqueue();

    //Allocates room at the beginning of the queue
    void dequeue();

    void printYear(); //Print out the current year
    void printMonth(int month); //Print out a specific month
    void printWeek(int month, int day);//Prints a weekly basis of the important items

    //Fix the heap when we add something in
    void repairUpward(int);

    //Fix the heap when we dequeue something
    void repairDownward(int);

    //Returns the first node in the queue
    pQueue peek();

    float priorityCalculator(int,int,float,int);

    bool isEmpty();
    Day getDays();
    Year getYears();
  private:
    Year years;
    Month months;
    Day days;

    float finalPriority;
    pQueue* priorityQueue;
    int currentQueueSize;
    int maxQueueSize;


};
#endif
