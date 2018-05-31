/*	CS 315	--	Homework 2 #2
	Dylan Jenkins
	Program designed to accept a number in decimal and Base to convert the decimal to.
	The program will proceed to convert the number to the provided base.	*/
#include <iostream>
#include <vector>
using namespace std;

void Display(vector<int> &NUM);
int Read_int();

int main() {
	vector<int> Bin;							// Vector Bin holds the final sequence of numbers.
	int Num, Base, Result, Remainder, End;		// Num is the number input by the user. Base is the base input by the user.
												// Result holds the result of the division by the base. Remainder holds the remainder of the mod division.
	// User input...
	cout << "Enter number to convert:\n";
	Num = Read_int();

	cout << "\nEnter base (2^k) to convert to (2-9):\n";
	Base = Read_int();

	while (Base < 2 || Base > 9) {
		cout << "Invalid Input.\n";
		Base = Read_int();
	}

	do {
		Result = Num / Base;
		Remainder = Num % Base;
		Bin.push_back(Remainder);
		Num = Result;
	} while (Num > 0);

	// Display the conversion results.
	cout << "\nThe Conversion to base " << Base << " is:\n";
	reverse(Bin.begin(), Bin.end());
	Display(Bin);

	cin >> End;

	return 0;
}

// Prints the vector.
void Display(vector<int> &NUM) {
	for (int i = 0; i < NUM.size(); i++) {
		cout << NUM[i];
	}
	cout << endl;
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
