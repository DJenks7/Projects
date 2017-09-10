/*	CS 315	--	Homework 2 #3
	Dylan Jenkins
	Program designed to accept two numbers and a desired base form
	and add the two vectors together displaying the sum.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
	/* Variables - Vector Bin holds the final sequence of numbers.
			Integer num is the number input by the user.
			Integer base is the base input by the user.
			Integer hold is simply a place holder for the digits during conversion.
	*/
	vector<int> Bin, Bin2, Bin3;
	int num, NUM, base, hold;

	// User input...
	cout << "Enter 1st number:\n";
	cin >> num;

	cout << "Enter 2nd number:\n";
	cin >> NUM;

	cout << "Enter base to be converted from(8 being octal):\n";
	cin >> base;

	if (base <= 0 || base > 9)
	{
		cout << "Invalid Input." << endl;
	}
	else
	{
		// Breaks down the numbers and places them into seperate vectors.
		while (num > 0)
		{
			hold = num % 10;
			Bin.push_back(hold);
			num = num / 10;
		}

		while (NUM > 0)
		{
			hold = NUM % 10;
			Bin2.push_back(hold);
			NUM = NUM / 10;
		}

		// Integer variables to hold the values.
		int carry = 0, size, Total;

		// Check to see which vector is larger and sets variable size to the
		// largest size of the two vectors available. For the loops.
		if (Bin.capacity() < Bin2.capacity())
		{
			size = Bin2.capacity();
		}
		else
		{
			size = Bin.capacity();
		}

		// Loop to add the two vectors together in the base form submitted.
		for (int i = 0; i < size; i++)
		{
			Total = carry + Bin[i] + Bin2[i];
			if (Total > base)
			{
				Total -= base;
				carry = 1;
			}
			else
			{
				Total -= base;
				carry = 0;
			}
			Bin3.push_back(Total);
		}

		// If the last loop has a 1 to carry, place it in the vector.
		if (carry = 1)
		{
			Bin3.push_back(carry);
		}

		// Displays the old vectors and the sum of the two vectors.
		cout << "\nFirst Sequence:\n";
		Display(Bin);

		cout << "\nSecond Sequence:\n";
		Display(Bin2);

		cout << "\nWhen added together...\n";
		Display(Bin3);
	}
	return 0;
}

