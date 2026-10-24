/** Author: Justin Madison 
  * Date: 09/18/2026
  * Intent: ChadaTechClocks.h is used to implement and format clock displays (12 and 24 HR) 
  */
#ifndef CHADATECHCLOCKS_H
#define CHADATECHCLOCKS_H

#include<string>
using namespace std;

// used to make modifications to the time.
void addOneHour();
void addOneMinute();
void addOneSecond();

// used for the formating display of the clocks. 
string convertToTwoDigit(int d);
string format24(int h, int m, int s);
string format12(int h, int m, int s);
void displayClocks();
void printClockMenu();

// runs the clock application.
void buildClock();
void clockApp();

#endif

