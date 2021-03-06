/*	CS 315	--	Homework 2A
	Dylan Jenkins
	Program designed to accept a binary number entered 1 digit at a time.
	Place this into a vector then convert it and display it.	*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> Action();
void Display(vector<int> &NUM);
int Read_int();

int main() {
	// Vector Bin is used to hold the binary number and to display the results.
	vector<int> Bin;
	int End;

	cout << "Enter Binary number one digit at a time (Use another # to stop):\n";

	Bin = Action();

	// Reverse order to display the actual decimal number.
	cout << "\nThe Conversion to Decimal is:\n";
	reverse(Bin.begin(), Bin.end());
	Display(Bin);

	cin >> End;

	return 0;
}

// Fills the vector with user input then runs through the vector and converts Binary to Decimal and return the vector.
vector<int> Action() {
	vector<int> TempBin;				// p holds the place value used to convert.
	int num, d, TOTAL = 0, p = 1;		//	num is used to place first user input into the vector to be converted.
										//	d simply holds the decimal converted value to be placed into the vector.
	// Fills the vector with user input.
	do {
		num = Read_int();
		TempBin.push_back(num);
	} while (num == 1 || num == 0);

	// Converts Binary to Decimal.
	for (int i = 0; i < TempBin.size(); i++) {
		if (TempBin[i] == 1) {
			TOTAL += p;
		}
		p *= 2;
	}

	TempBin.clear();

	// Breaks down the TOTAL decimal number into digits and places it into the vector.
	while (TOTAL > 0) {
		d = TOTAL % 10;
		TempBin.push_back(d);
		TOTAL = TOTAL / 10;
	}

	return TempBin;
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

