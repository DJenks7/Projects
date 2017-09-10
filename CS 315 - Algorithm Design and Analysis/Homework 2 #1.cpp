/*	CS 315	--	Homework 2 #1
	Dylan Jenkins
	Program designed to accept a binary number entered 1 digit at a time.
	Place this into a vector then convert it and display it.
*/

#include <iostream>
#include <vector>
using namespace std;

// p holds the place value used to convert.
int p = 1, TOTAL;

// Prints the vector.
void Display(vector<int> &NUM)
{
	for (int i = 0; i < NUM.size(); i++)
	{
		cout << NUM[i] << " ";
	}
	cout << endl;
}

int main()
{
	/* Vector Bin is used to hold the binary number and to display the results.
		num is used to place first user input into the vector to be converted.
		d simply holds the decimal converted value to be placed into the vector.
	*/
	vector<int> Bin;
	int num, d;

	cout << "Enter Binary number one digit at a time:\n";

	// Loop to fill the vector with user input.
	do
	{
		cin >> num;
		Bin.push_back(num);
	} while (num == 1 || num == 0);

	// Runs through the vector and converts Binary to Decimal.
	for (int i = 0; i < Bin.size(); i++)
	{
		if (Bin[i] == 1)
		{
			TOTAL += p;
		}
		p *= 2;
	}

	Bin.clear();

	// Breaks down the TOTAL decimal number into digits and places it into the vector.
	while (TOTAL > 0)
	{
		d = TOTAL % 10;
		Bin.push_back(d);
		TOTAL = TOTAL / 10;
	}

	// Reverse order to display the actual decimal number.
	cout << "\nThe Decimal Conversion is(reverse order):\n";
	Display(Bin);
	cout << "\nThe Decimal Conversion is:\n";
	reverse(Bin.begin(), Bin.end());
	Display(Bin);

	return 0;
}

