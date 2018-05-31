//	Program Name: CS115_Program4.cpp
//	Author: Dylan Jenkins
//	Date: April 4, 2011

//	This program is designed for the user to input a number
//	and then display the month corresponding to the number.

/*	EDIT
	Updated: 5/14/2018
	Removed unnecessary include statement.
	Added simple error checking.
	Minor code cleanup.
*/

#include <iostream>
using namespace std;

int Read_int();

int main()
{
	int number, End;

	cout << "Enter a number within the range of 1 to 12.\n";
	number = Read_int();

	while (number < 1 || number > 12) {
		cout << "Incorrect Input, Try Again.\n";
		number = Read_int();
	}

	if (number == 1)
		cout << "Janurary!\n";
	else if (number == 2)
		cout << "February!\n";
	else if (number == 3)
		cout << "March!\n";
	else if (number == 4)
		cout << "April!\n";
	else if (number == 5)
		cout << "May!\n";
	else if (number == 6)
		cout << "June!\n";
	else if (number == 7)
		cout << "July!\n";
	else if (number == 8)
		cout << "August!\n";
	else if (number == 9)
		cout << "September!\n";
	else if (number == 10)
		cout << "October!\n";
	else if (number == 11)
		cout << "November!\n";
	else if (number == 12)
		cout << "December!\n";

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
