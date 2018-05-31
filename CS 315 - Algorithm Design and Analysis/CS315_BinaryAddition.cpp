/*	CS 315	--	Homework 1
	Dylan Jenkins
	Program designed to accept two numbers in binary and simply add them together.
	The program will then display the results.	*/
#include <iostream>
#include <vector>
using namespace std;

int Carry;		// Integer used to hold and determine if there is a 1 to carry over.

int Read_Int();						// Function to validate user input is an integer.
void Display(vector<int> &NUM);		// Function to simply display the vector passed in.
vector<int> Addition(vector<int> &data1, vector<int> &data2);		// Function to do the binary addition and return the results.

int main() {
	vector<int> Bin, Bin2, Bin3;
	int input, size, dif, End;

	cout << "Enter 1st binary #, 1 digit at a time (use any other # to stop):\n";
	cin >> input;

	while (input == 1 || input == 0) {
		Bin.insert(Bin.begin(), input);
		input = Read_Int();
	}

	cout << "Enter 2nd binary #, 1 digit at a time (use any other # to stop):\n";
	cin >> input;

	while (input == 1 || input == 0) {
		Bin2.insert(Bin2.begin(), input);
		input = Read_Int();
	}

		// Insert any leading 0's
	Bin2.insert(Bin2.end(), Bin.size() - Bin2.size(), 0);

	cout << "\nBinary1:\t";
	Bin3 = Bin;
	reverse(Bin3.begin(), Bin3.end());
	Display(Bin3);
	cout << "Binary2:\t";
	Bin3 = Bin2;
	reverse(Bin3.begin(), Bin3.end());
	Display(Bin3);

	// Addition Function call.
	Bin3 = Addition(Bin, Bin2);

	// If there is a left over carry bit. It is placed at the front.
	if (Carry == 1) {
		Bin3.insert(Bin3.begin(), 1);
	}

	cout << "\t\t--------------------\n";
	cout << "Sum:\t\t";
	Display(Bin3);

	cin >> End;

	return 0;
}

// Displays the vector.
void Display(vector<int> &NUM) {
	for (int i = 0; i < NUM.size(); i++) {
		cout << NUM[i];
	}
	cout << endl;
}

// Vector Binary Addition Function.
vector<int> Addition(vector<int> &data1, vector<int> &data2) {
	vector<int> BinAdd;
	Carry = 0;
	int s = data1.size();

	// Loop to add the vectors and place the result in a new vector.
	for (int i = 0; i < s; i++) {
		bool used = false;

		// 0+0+0
		if (used == false) {
			if (data1[i] + data2[i] + Carry == 0) {
				BinAdd.insert(BinAdd.begin(), 0);
				Carry = 0;
				used = true;
			}
		}

		// 1+0+0, 0+1+0, 1+0+0
		if (used == false) {
			if (data1[i] + data2[i] + Carry == 1) {
				BinAdd.insert(BinAdd.begin(), 1);
				Carry = 0;
				used = true;
			}
		}

		// 1+1+0, 1+0+1, 0+1+1
		if (used == false) {
			if (data1[i] + data2[i] + Carry == 2) {
				BinAdd.insert(BinAdd.begin(), 0);
				Carry = 1;
				used = true;
			}
		}

		// 1+1+1
		if (used == false) {
			if (data1[i] + data2[i] + Carry > 2) {
				BinAdd.insert(BinAdd.begin(), 1);
				Carry = 1;
				used = true;
			}
		}
	}

	return BinAdd;
}

// Reads the input by the user and accepts if it is an integer.
int Read_Int() {
	int Val;

	cin >> Val;
	while (!cin.good()) {
		cout << "Invalid integer, try again.\n";
		cin.clear();
		cin.ignore(80, '\n');
	}

	return Val;
}