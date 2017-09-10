// Program Name: ProgramAssignment6.cpp
// Author: Dylan Jenkins
// Date: May 3, 2011

#include <iostream>
#include <cstring>
using namespace std;

const int EMPLOYEES = 200;
const float TAX = 3.625;

void inputEmployeeInfo(string name[], float hours[], float payrate[], int & size)
{
	string sentinel = "zzz";
	string entry = "";

	int index = 0;
	while (size < EMPLOYEES)
	{
		cout << "Enter zzz to exit the loop. " << endl;
		cout << "Enter the name of the employee: ";
		getline(cin, entry);
		if (entry.compare(sentinel) == 0)
			break;

		name[index] = entry;
		cout << "Enter the hourly wage: ";
		cin >> payrate[index];

		if (payrate[index] <= 0)
		{
			cout << "The payrate cant be negative or a 0. " << endl;
			cout << "Please enter employee information." << endl << endl;
			cin.ignore();
			continue;
		}

		cout << "Enter the hours worked during previous week: ";
		cin >> hours[index];

		if (hours[index] <= 0)
		{
			cout << "The hours worked can be negative or 0." << endl;
			cout << "Please enter employee information." << endl << endl;
			cin.ignore();
			continue;
		}

		++index;

		cout << endl;
		cin.ignore();
	}

	size = index;
}

void computePay(float grosspay[], float netpay[], float hours[], float payrate[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (hours[i] <= 40)
			grosspay[i] = hours[i] * payrate[i];
		else
		{
			grosspay[i] = 40 * payrate[i];
			grosspay[i] += (hours[i] - 40) * (1.5f * payrate[i]);
		}

		netpay[i] = grosspay[i] * (100.00f - TAX) / 100.00f;
	}
}

void outputPayReport(string name[], float hours[], float payrate[], float grosspay[], float netpay[], int size)
{
	cout << "EMPLOYEE\tPAY\t\t\t\tGROSS" << endl;
	cout << "NAME\t\tRATE\t\tHOURS\t\tPAY\tNET PAY" << endl;

	for (int i = 0; i < size; ++i)
	{
		cout << name[i] << "\t" << payrate[i] << "\t\t" << hours[i] << "\t\t" << grosspay[i] << "\t" << netpa$
	}
}

int main()
{
	string name[EMPLOYEES];
	float hours[EMPLOYEES];
	float payrate[EMPLOYEES];
	float grosspay[EMPLOYEES];
	float netpay[EMPLOYEES];
	int size;

	inputEmployeeInfo(name, hours, payrate, size);

	computePay(grosspay, netpay, hours, payrate, size);

	cout << endl;
	outputPayReport(name, hours, payrate, grosspay, netpay, size);

	return 0;
}

