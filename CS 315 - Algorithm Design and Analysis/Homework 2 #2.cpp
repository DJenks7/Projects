/*	CS 315	--	Homework 2 #2
	Dylan Jenkins
	Program designed to accept a number and base form
	and convert it into binary.
*/

#include <iostream>
#include <vector>
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
			num is the number input by the user.
			base is the base input by the user.
			hold is simply a place holder for the digits during conversion.
	*/
	vector<int> Bin;
	vector<int> Bin2;
	int num, base, hold;

	// User input...
	cout << "Enter number to convert:\n";
	cin >> num;

	cout << "\nEnter base(2^k):\n";
	cin >> base;
	cout << endl;

	if (base <= 0 || base > 9)
	{
		cout << "Invalid Input." << endl;
	}
	else
	{
		base = pow(2, base);

		// Breaks down the TOTAL decimal number into digits and places it into the vector.
		while (num > 0)
		{
			hold = num % 10;
			Bin.push_back(hold);
			num = num / 10;
		}

		cout << "The number entered will be treated as:\n";
		Display(Bin);

		// Runs through the vector and converts each to binary.
		for (int i = 0; i < Bin.size(); i++)
		{
			num = Bin[i];
			hold = num;

			while (num > 0)
			{
				hold = num % 2;
				Bin2.push_back(hold);
				num = num / 2;
			}
		}

		// Reverse order to because the sequence is actually backwards.
		// Display the binary code before and after reverse.
		cout << "\nThe Conversion is:\n";
		Display(Bin2);
		cout << "\nFlipped to create the original number it becomes:\n";
		reverse(Bin2.begin(), Bin2.end());
		Display(Bin2);
	}
	return 0;
}

