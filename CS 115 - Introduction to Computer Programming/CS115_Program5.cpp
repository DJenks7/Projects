//	Program Name: CS115_Program5.cpp
//	Date: April 13, 2011
//	Author: Dylan Jenkins

//	This program is designed to prompt a user for a number of people to include in a membership.
//	It will then present rates and ask the user to define each member and once through all members,
//	it will display the monthly subscription cost.

/*	EDIT
	Updated: 5/14/2018

	Removed unnecessary include statement.
	Added simple error checking.
	Minor code cleanup.
*/

#include <iostream>
using namespace std;

int Read_int();

int main() {
	char option;
	int subscription, members, rate;

	cout << "Are there more queries? (Y/N): ";
	cin >> option;

	while (option == 'Y' || option == 'y') {
		cout << "How many people included in membership?: ";
		members = Read_int();

		subscription = 0;

		while (0 < members, members--) {
			cout << "1. Adult rate is $40.00 per month.\n";
			cout << "2. Child rate is $20.00 per month.\n";
			cout << "3. Senior citizen rate is $30.00 per month.\n\n";
			cout << "Enter 1, 2, or 3.\n";
			cout << "What is the rate for the member?: ";
			rate = Read_int();

			while (rate < 0 || rate > 3) {
				cout << "Not an option, try again.\n";
				rate = Read_int();
			}

			if (rate == 1) {
				subscription = subscription + 40;
			}
			else if (rate == 2) {
				subscription = subscription + 20;
			}
			else if (rate == 3) {
				subscription = subscription + 30;
			}

			cout << "Cost of monthly subscription is $" << subscription << ".00.\n";
		}

		cout << "Are there more queries? (Y/N): ";
		cin >> option;
	}

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


