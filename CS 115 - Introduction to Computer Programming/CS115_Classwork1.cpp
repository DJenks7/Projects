// Program Name: CS115_Classwork1.cpp
// Name: Dylan Jenkins
// Date: February 24, 2011
// This is my in class function assignment.
/*	EDIT
	Updated: 5/15/2018
	Added simple error checking.
*/

#include <iostream>
using namespace std;

int number1, number2, multiple;

int Read_int();
void inputNumber1();
void inputNumber2();
void multiply();
void display();

int main()
{
	inputNumber1();
	inputNumber2();
	multiply();
	display();
	
	return 0;
}

void inputNumber1()
{
	cout << "Enter the first number: ";
	number1 = Read_int();;
	cout << "Your nuumber is " << number1 << endl;
}

void inputNumber2()
{
	cout << "Enter the second number: ";
	number2 = Read_int();;
	cout << "Your number is " << number2 << endl;
}

void multiply(int number1, int number2)
{
	multiple = number1 * number2;
	cout << "Your answer is " << multiple << endl;
}	

void display()
{
	cout << "The product of the two numbers you entered is " << multiple << endl;
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
