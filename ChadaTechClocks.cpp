/** Author: Justin Madison 
  * Date: 09/18/2026
  * Intent: ChadaTechClocks.cpp is used to build the chada tech clocking applications. 
  */

#include "ChadaTechClocks.h"
#include <iostream>

using namespace std;

// created global variables to initialize the hours, minutes, and seconds.
int hours = 0;
int minutes = 0;
int seconds = 0;

// used to check if a digit is single and if so adds a 0 in front of the digit. Converted to a string for these changes.
string convertToTwoDigit(int d) {
	if (d >= 0 && d < 10) {
		return "0" + to_string(d);
	}
	return to_string(d);
}

// used to format and output the 12 hour clock numerical value.
string format12(int h, int m, int s) {
	string meridiem;
	meridiem = "AM";
	int HR = h;
	
	// checks for hour value to convert 24 clock to a 12 hour clock.
	if (h >= 12) {
		meridiem = "PM";
		if (h > 12) {
			HR = h - 12;
		}
	}
	if (HR == 0) {
		HR = 12;
	}
	return convertToTwoDigit(HR) + ":" + convertToTwoDigit(m) + ":" + convertToTwoDigit(s) + " " + meridiem;
}

// used to format and output the 24 hour clock numerical value.
string format24(int h, int m, int s) {
	return convertToTwoDigit(h) + ":" + convertToTwoDigit(m) + ":" + convertToTwoDigit(s);
}

// used to physically display the format dual clock system.
void displayClocks() {
	cout << endl;
	cout << "***************************   ***************************" << endl;
	cout << "*      12-Hour Clock      *   *      24-Hour Clock      *" << endl;
	cout << "*       " << format12(hours, minutes, seconds) << "       *   *        " << format24(hours, minutes, seconds) << "         *" << endl;
	cout << "***************************   ***************************" << endl;
	cout << endl;
}

// used to print and display the clock menu.
void printClockMenu() {
	cout << endl;
	cout << "**************************" << endl;
	cout << "* 1 - Add One Hour       *" << endl;
	cout << "* 2 - Add One Minute     *" << endl;
	cout << "* 3 - Add One Second     *" << endl;
	cout << "* 4 - Exit Program       *" << endl;
	cout << "**************************" << endl;
}

// Adds one hour and prevents the clock from exceeding expected range.
void addOneHour() {
	hours = (hours + 1) % 24;
}

// Adds 1 minute and checks minute quantity to verify it is less than 60, otherwise 1 hour is added to the clock.
void addOneMinute() {
	minutes += 1;
	if (minutes >= 60) {
		minutes = 0;
		addOneHour();
	}
}

// Adds 1 second and checks second quantity to verify it is less than 60, otherwise 1 minute is added to the clock.
void addOneSecond() {
	seconds += 1;
	if (seconds >= 60) {
		seconds = 0;
		addOneMinute();
	}
}

// Function used to build clock components based on user input.
void buildClock() {
	int tempVal;
	tempVal = 1;

	// Checks for correct hour digit input.
	while (tempVal == 1) {
		cout << "Enter total hours (24 hour format (0 - 23)): ";
		cin >> hours;
		if (hours >= 0 && hours <= 23) {
			tempVal = 0;
		}
		else {
			cout << "Invalid input. Please enter a number between 0 and 23." << endl;
		}
	}

	// Checks for correct minute digit input. 
	tempVal = 1;
	while (tempVal == 1) {
		cout << "Enter total minutes (0 - 59): ";
		cin >> minutes;
		if (minutes >= 0 && minutes < 60) {
			tempVal = 0;
		}
		else {
			cout << "Invalid input. Please enter a number between 0 and 59." << endl;
		}
	}

	// Checks for correct second digit input.
	tempVal = 1;
	while (tempVal == 1) {
		cout << "Enter total seconds (0 - 59): ";
		cin >> seconds;
		if (seconds >= 0 && seconds < 60) {
			tempVal = 0;
		}
		else {
			cout << "Invalid input. Please enter a number between 0 and 59." << endl;
		}
	}
	displayClocks();
}

// takes user input from the menu displau and runs the clock app. 
void clockApp() {
	int input;
	int tempVal;
	input = 0;
	tempVal = 1;

	while (tempVal == 1) {
		printClockMenu();
		cout << "Enter selection: ";
		cin >> input;
		if (input < 1 || input > 4) {
			cout << "Invalid input. Please enter a number between 1 and 4 (inclusive).";
			continue;
		}


		if (input == 1) {
			addOneHour();
			displayClocks();
		}

		
		else if (input == 2) {
			addOneMinute();
			displayClocks();
		}


		else if (input == 3) {
			addOneSecond();
			displayClocks();
		}


		else if (input == 4) {
			cout << "Exiting program...Bye!";
			tempVal = 0;
		}
	}

}


