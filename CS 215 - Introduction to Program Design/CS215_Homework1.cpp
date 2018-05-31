/*	Dylan Jenkins
	CS 215-j001     Fall 2013
	CS215_Homework1.cpp

	EDIT
	Updated: 5/15/2018
	Removed unnecessary include statement.
	Added simple error checking.
	Minor code cleanup.
*/
#include <iostream>
#include <cmath>

using namespace std;

int get_Num(int & num);
int Read_int();
void check_Square(int & N);
void display_Flavor(int & num1, int & num2);

// Main function to declare first two integers and call other functions
int main() {
	int Num1, Num2;
	int End;

	get_Num(Num1);
	get_Num(Num2);

	cout << endl;

	check_Square(Num1);
	check_Square(Num2);

	display_Flavor(Num1, Num2);

	cin >> End;
	return 0;
}

// get_Num function asks the user for a number between 2 and 5000
int get_Num(int & num) {
	cout << "Enter a number between 2 and 5000: ";
	num = Read_int();

	while ((num<1) || (num>5000)) {
		cout << "Invalid range, should be between 2-5000.\nTry Again.\n";
		num = Read_int();
	}

	return num;
}

// check_Square takes one number from user entered numbers and creates
// a string holding the factors for the number and declares if it is square free.
void check_Square(int & N) {
	int fac = 0;

	cout << N << " has these factors (>1) that are square: ";

	for (int I = 2; I <= N; I++) {
		if (N%I == 0 && I == N && (sqrt((float) I)*sqrt((float) I)) == I) {
			cout << I << endl;
			fac++;
		}
		if (N%I == 0 && I != N && (sqrt((float) I)*sqrt((float) I)) == I) {
			cout << I << ", ";
			fac++;
		}
	}

	if (fac == 0) {
		cout << "(none)\n";
		cout << N << " is square-free.\n";
	}
	else {
		cout << N << " is not square-free.\n";
	}

	cout << endl;
}

// display_Flavor takes the integers the user entered and determines if it
// is sweet, sour, salty, or bitter and displays the ordered pair.
void display_Flavor(int & num1, int & num2) {
	int fac1 = 0, fac2 = 0;
	int int1, int2;

	cout << "Therefore, the ordered pair (" << num1 << ", " << num2 << ") is ";

	for (int1 = 2; int1 <= num1; int1++) {
		if (num1 % int1 == 0 && (sqrt((float) int1)*sqrt((float) int1)) == num1)
			fac1 += 1;
	}
	for (int2 = 2; int2 <= num2; int2++) {
		if (num2 % int2 == 0 && (sqrt((float) int2)*sqrt((float) int2)) == num2)
			fac2 += 1;
	}

	if (fac1 == 0 && fac2 == 0) {
		cout << "SWEET.\n";
	}

	if (fac1 == 0 && fac2 >= 1) {

		cout << "SOUR.\n";
	}

	if (fac1 >= 1 && fac2 >= 1) {
		cout << "BITTER.\n";
	}

	if (fac1 >= 1 && fac2 == 0) {
		cout << "SALTY.\n";
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


