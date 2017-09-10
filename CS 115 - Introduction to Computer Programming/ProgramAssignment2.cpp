// Name: ProgramAssignment.cpp
// Author: Dylan Jenkins
// Date: Feburary 21, 2011
//
/* This program is designed to convert length
from centimeters and display it in yards, feet,
and inches.
*/

#include <iostream>
using namespace std;

const float CM_PER_IN = 2.54; // 2.54 cenitmeters in an inch
const int IN_PER_FT = 12;
const int IN_PER_YD = 36;
int centimeters, yards, feet, inches;

int main()
{
	cout << "Enter the length in centimeters: ";
	cin >> centimeters;

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

	return 0;
}

