// Program Name: ProgramAssignment3.cpp
// Author: Dylan Jenkins
// Date: March 10, 2011

//      This program is designed to read the runners
//      names and race times and convert them into
//      feet per second and meters per second.

#include <iostream>
using namespace std;

// Declare variables and functions.
const int Feet = 5280;  // 5280 feet in a mile.
int Minutes;
float Seconds, MT_PER_S, FT_PER_S, S;

void input();

string computeFT_PER_S();

string computeMT_PER_S();

string conclusion();

int  main(string&FirstName, string&LastName)
{
	void input(string&FirstName, string&LastName, int&Minutes, float&Seconds);

	computeFT_PER_S(string&FirstName);

	computeMT_PER_S(string&FirstName);

	conclusion(string&FirstName, string&LastName);

	return 0;
}

void input(string&FirstName,
	string&LastName,
	int&Minutes,
	float&Seconds)
{
	cout << "Enter runners first name: ";
	cin >> FirstName;
	cout << "Enter runners last name: ";
	cin >> LastName;
	cout << "Enter Minutes: ";
	cin >> Minutes;
	cout << "Enter seconds: ";
	cin >> Seconds;
}

// compute feet per second.
string computeFT_PER_S(string&FirstName)
{
	S = (60 * Minutes) + Seconds;

	FT_PER_S = Feet / S;

	cout << FirstName << "'s speed is " << FT_PER_S
	<< "feet per second. ";
}

// compute meters per second.
string computeMT_PER_S(string&FirstName)
{
	MT_PER_S = (3.281 * 5280) / S;

	cout << FirstName << "'s speed is " << MT_PER_S << "meters per second. ";
}

// concluding statement with meters and feet per second displayed.
string Conclusion(string&FirstName, string&LastName)
{
	cout << FirstName << LastName << "'s speed is " << FT_PER_S <<
		" feet per second and " << MT_PER_S << " meters per second. ";
}
