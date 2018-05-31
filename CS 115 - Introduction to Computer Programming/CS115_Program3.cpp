//	Program Name: CS115_Program3.cpp
//	Author: Dylan Jenkins
//	Date: March 10, 2011

//	This program is designed to read the runners names and race times
//	and convert them into feet per second and meters per second.

/*	EDIT
	Updated: 5/14/2018
	Removed unnecessary include statement.
	
	Broken - Unsure if there was a sample file provided for runner names. If so, it has been lost.
				Comments implies it reads runner names and times from a file I am missing.
*/

#include <iostream>
#include <string>
using namespace std;

// Declare variables and functions.
const int Feet = 5280;  // 5280 feet in a mile.
int Minutes;
float Seconds, MT_PER_S, FT_PER_S, S;

void input(string&FirstName, string&LastName, int&Minutes, float&Seconds);
void computeFT_PER_S(string&FirstName);
void computeMT_PER_S(string&FirstName);
void Conclusion(string&FirstName, string&LastName);

int main(string&FirstName, string&LastName) {
	int End;

	void input(string&FirstName, string&LastName, int&Minutes, float&Seconds);

	computeFT_PER_S(FirstName);

	computeMT_PER_S(FirstName);

	Conclusion(FirstName, LastName);

	cin >> End;
	return 0;
}

void input(string&FirstName, string&LastName, int&Minutes, float&Seconds) {
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
void computeFT_PER_S(string&FirstName) {
	S = (60 * Minutes) + Seconds;

	FT_PER_S = Feet / S;

	cout << FirstName << "'s speed is " << FT_PER_S << "feet per second. ";
}

// compute meters per second.
void computeMT_PER_S(string&FirstName) {
	MT_PER_S = (3.281 * 5280) / S;

	cout << FirstName << "'s speed is " << MT_PER_S << "meters per second. ";
}

// concluding statement with meters and feet per second displayed.
void Conclusion(string&FirstName, string&LastName) {
	cout << FirstName << LastName << "'s speed is " << FT_PER_S <<
			" feet per second and " << MT_PER_S << " meters per second. ";
}
