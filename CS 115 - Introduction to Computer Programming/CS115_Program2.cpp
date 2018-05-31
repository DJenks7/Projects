//	Name: CS115_Program2.cpp
//	Author: Dylan Jenkins
//	Date: Feburary 21, 2011

//	This program is designed to convert length
//	from centimeters and display it in yards, feet, and inches.

/*	EDIT
	Updated: 5/14/2018
	Removed unnecessary include statement.
	Added simple error checking.
*/

#include <iostream>
using namespace std;

const float CM_PER_IN = 2.54; // 2.54 cenitmeters in an inch
const int IN_PER_FT = 12;
const int IN_PER_YD = 36;

int Read_int();

int main() {
	int centimeters, yards, feet, inches, End;

	cout << "Enter length in centimeters: ";
	centimeters = Read_int();

	// Convert the length to inches.
	inches = centimeters / CM_PER_IN;

	//Display the length in inches.
	cout << "The length in inches is " << inches << endl;

	// Convert inches into feet.
	feet = inches % IN_PER_FT;
	cout << "The length in feet is " << feet << endl;

	// Convert inches to yards.
	yards = IN_PER_YD % inches;
	cout << "The length in yards is " << yards << endl;

	// Display overall results in yards, feet, inches.
	cout << "The length equals " << yards << " yards, " << feet << 
			" feet, " << inches << " inches " << endl;

	cin >> End;
	return 0;
}

// Reads the input by the user and accepts if it is an integer.
int Read_int() {
	int Val;        // Integer called Val to hold user input.

	cin >> Val;
	while (!cin.good()) {
		cout << "Invalid integer, try again.\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> Val;
	}
	return Val;     // Return if input is an integer.
}

