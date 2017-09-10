// Program Name: ProgramAssignment5.cpp
// Date: April 13, 2011
// Author: Dylan Jenkins

#include <iostream>
using namespace std;

char option;
int subscription, members, rate;

int main()
{
	cout << "Are there more queries? (Y/N): ";
	cin >> option;
	if (option == 'Y', option == 'y')
	{
		cout << "How many people included in membership?: ";
		cin >> members;

		subscription == 0;
		while (0 < members, members--)
		{
			cout << "1. Adult rate is $40.00 per month." << endl;
			cout << "2. Child rate is $20.00 per month." << endl;
			cout << "3. Senior citizen rate is $30.00 per month." << endl;
			cout << "What is the rate for the member?: ";
			cin >> rate;

			if (rate == 1)
				subscription = subscription + 40;
			else if (rate == 2)
				subscription = subscription + 20;
			else if (rate == 3)
				subscription = subscription + 30;
			else if (rate < 0, rate > 3)
				cout << "Not an option, try again." << endl;

			cout << "Cost of monthly subscription is $" << subscription << ".00." << endl;
		}
	}

	if (option == 'N', option == 'n')
	{
		return 0;
	}

	return main();
}


