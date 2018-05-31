//	Program Name: CS115_Program6.cpp
//	Author: Dylan Jenkins
//	Date: May 3, 2011

//	This program is designed to accept an employee name, an hourly wage, and the number of hours the employee has worked.
//	This process will loop until the user enters the sentinel value 'zzz' and will then display the employee name, wage,
//	hours, gross pay and net pay on screen.

/*	EDIT
	Updated: 5/14/2018
	Removed unnecessary include statement.
	Added simple error checking.
	Minor code cleanup.
*/

#include <iostream>
#include <string>
using namespace std;

const int EMPLOYEES = 200;
const float TAX = 3.625;

int Read_int();
void inputEmployeeInfo(string name[], float hours[], float payrate[], int & size);
void computePay(float grosspay[], float netpay[], float hours[], float payrate[], int size);
void outputPayReport(string name[], float hours[], float payrate[], float grosspay[], float netpay[], int size);

int main() {
	string name[EMPLOYEES];
	float hours[EMPLOYEES], payrate[EMPLOYEES], grosspay[EMPLOYEES], netpay[EMPLOYEES];
	int size, End;

	inputEmployeeInfo(name, hours, payrate, size);

	computePay(grosspay, netpay, hours, payrate, size);

	outputPayReport(name, hours, payrate, grosspay, netpay, size);

	cin >> End;
	return 0;
}

void inputEmployeeInfo(string name[], float hours[], float payrate[], int & size) {
	string sentinel = "zzz";
	string entry = "";
	int index = 0;

	while (size < EMPLOYEES) {
		cout << "Enter zzz to exit the loop.\n";
		cout << "Enter the name of the employee: ";
		getline(cin, entry);
		if (entry.compare(sentinel) == 0)
			break;

		name[index] = entry;
		cout << "Enter the hourly wage: ";
		payrate[index] = Read_int();

		if (payrate[index] <= 0) {
			cout << "The payrate cant be negative or a 0.\n";
			cout << "Please enter employee information.\n\n";
			cin.ignore();
			continue;
		}

		cout << "Enter the hours worked during previous week: ";
		hours[index] = Read_int();

		if (hours[index] <= 0) {
			cout << "The hours worked can be negative or 0.\n";
			cout << "Please enter employee information.\n\n";
			cin.ignore();
			continue;
		}

		++index;
		cout << endl;
		cin.ignore();
	}

	size = index;
}

void computePay(float grosspay[], float netpay[], float hours[], float payrate[], int size) {
	for (int i = 0; i < size; ++i) {
		if (hours[i] <= 40) {
			grosspay[i] = hours[i] * payrate[i];
		}
		else {
			grosspay[i] = 40 * payrate[i];
			grosspay[i] += (hours[i] - 40) * (1.5f * payrate[i]);
		}

		netpay[i] = grosspay[i] * (100.00f - TAX) / 100.00f;
	}
	cout << endl;
}

void outputPayReport(string name[], float hours[], float payrate[], float grosspay[], float netpay[], int size) {
	cout << "EMPLOYEE\tPAY\tHOURS\tGROSS PAY\tNET PAY\n";

	for (int i = 0; i < size; ++i) {
		cout << name[i] << "\t\t" << payrate[i] << "\t" << hours[i] << "\t" << grosspay[i] << "\t\t" << netpay[i] << endl;
	}
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

