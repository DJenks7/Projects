// Program Name: ProgramAssignment4.cpp
// Author: Dylan Jenkins
// Date: April 4, 2011
// This program is designed for the user to input a number
// and then display the month corresponding to the number.

#include <iostream>
using namespace std;

int number;

int main()
{
	cout << "Enter a number within the range of 1 to 12. ";
	cin >> number;

	if (number == 0)
		cout << "Incorrect Input, Try Again." << endl;
	else if (number > 12)
		cout << "Incorrect Input, Try Again." << endl;
	else if (number == 1)
		cout << "Janurary!" << endl;
	else if (number == 2)
		cout << "February!" << endl;
	else if (number == 3)
		cout << "March!" << endl;
	else if (number == 4)
		cout << "April!" << endl;
	else if (number == 5)
		cout << "May!" << endl;
	else if (number == 6)
		cout << "June!" << endl;
	else if (number == 7)
		cout << "July!" << endl;
	else if (number == 8)
		cout << "August!" << endl;
	else if (number == 9)
		cout << "September!" << endl;
	else if (number == 10)
		cout << "October!" << endl;
	else if (number == 11)
		cout << "November!" << endl;
	else if (number == 12)
		cout << "December!" << endl;

	return 0;
}
