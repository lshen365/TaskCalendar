#include "Calendar.hpp"
#include <iostream>

/**
Include saving tasks to .txt file for later reference
**/


using namespace std;

Calendar::Calendar(){

}
void Calendar::printMonth(int month){
  printf ("         Calendar - %d\n\n", year);
   int days;

   // Index of the day from 0 to 6
   int current = dayNumber (1, 1, year);

   // i --> Iterate through all the months
   // j --> Iterate through all the days of the
   //       month - i
   for (int i = 0; i < 12; i++)
   {
       days = numberOfDays (i, year);

       // Print the current month name
       printf("\n  ------------%s-------------\n",
              getMonthName (i).c_str());

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
