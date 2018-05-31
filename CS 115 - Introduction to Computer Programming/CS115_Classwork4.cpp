// Program Name: CS115_Classwork4.cpp
// Author: Dylan Jenkins
// Date: March 31, 2011
/*	EDIT
	Updated: 5/14/2018
	Removed unnecessary include statement.
	Added simple error checking.
	Minor code cleanup.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Read_int();

int main()
{
	int randomNumber, number;
	int End;

	srand(time(0));

	cout << "Guess a number! (1-100)\n";
	number = Read_int();

	while (number < 1 || number > 100) {
		cout << "Whoops! Try again.\n";
		number = Read_int();
	}

	randomNumber = rand() % 100 + 1;

	cout << "The random number is! --> " << randomNumber << endl;

	if (randomNumber == number)
	{
		cout << "Good Guess!\n";
	}

	if (randomNumber != number)
	{
		cout << "Ouch, tough luck.\n";
	}

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


