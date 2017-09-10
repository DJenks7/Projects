//	CS315		FALL 2015
//	Dylan Jenkins		Homework3p2B.cpp
//	Program is designed to accept two binary numbers input by the user.
//	It then places those into separate vectors and divides them. Displaying the result.
//	PROBLEM 2B

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int carry;

// Display the Vector.
void Display(vector<int> &NUM)
{
	for (int i = 0; i < NUM.size(); i++)
	{
		cout << NUM[i] << " ";
	}
	cout << endl;
}


// Adds the two vectors together.
vector<int> Addition(vector<int> &data1, vector<int> &data2)
{
	vector<int> BinAdd;
	int s = data1.size();
	carry = 0;

	// Loop to add the vectors and place the result in a new vector.
	for (int i = 0; i < s; i++)
	{
		bool used = false;

		if (used == false)
		{
			if (data1[i] + data2[i] + carry == 0)
			{
				BinAdd.insert(BinAdd.begin() + i, 0);
				carry = 0;
				used = true;
			}
		}

		if (used == false)
		{
			if (data1[i] + data2[i] + carry == 1)
			{
				BinAdd.insert(BinAdd.begin() + i, 1);
				carry = 0;
				used = true;
			}
		}

		if (used == false)
		{
			if (data1[i] + data2[i] + carry == 2)
			{
				BinAdd.insert(BinAdd.begin() + i, 0);
				carry = 1;
				used = true;
			}
		}

		if (used == false)
		{
			if (data1[i] + data2[i] + carry > 2)
			{
				BinAdd.insert(BinAdd.begin() + i, 1);
				carry = 1;
				used = true;
			}
		}
	}
	return BinAdd;
}

int main()
{
	vector<int> Bin;		// Vector Bin will hold first binary input by user.
	vector<int> Bin2;		// Vector Bin2 will hold second binary input by user.
	vector<int> Single;		// Vector Single will hold a single 1 in the vector
							//		to be added to Bin2 after it is flipped.
	vector<int> Bin3;		// Vector Bin3 will hold the vector returned from
							//		the addition of Bin2 and Single, after flipped.
	vector<int> Quotient;

	int input, hold;		// Integer input is for user input of binary number.
	bool check = false;		// Checks to see if addition was used once, so it
							//	doesnt add multiple times in one loop.

							// Ask for user input of first binary number.
	cout << "Enter binary #, 1 digit at a time(use another # to stop):\n";
	cin >> input;

	while (input == 1 || input == 0)
	{
		Bin.push_back(input);
		cin >> input;
	}

	// Ask for user input of second binary number.
	cout << "Enter 2nd binary #, 1 digit at a time(use another # to stop):\n";
	cin >> input;

	while (input == 1 || input == 0)
	{
		Bin2.push_back(input);
		cin >> input;
	}

	// Inserts zeros to fill assumed smaller vector (Bin2) to set
	//		to the same size as the larger vector (Bin).
	Bin2.insert(Bin2.end(), Bin.size() - Bin2.size(), 0);

	// Flips the second vector in order to be added via Complement Method.
	for (int i = 0; i < Bin.size(); i++)
	{
		if (Bin2[i] == 1)
		{
			Bin2[i] = 0;
		}
		else
		{
			Bin2[i] = 1;
		}
	}

	// Inserts a single one and fills the rest of the vector
	//		zeros into vector Single in order to be added
	//		to the new flipped Bin2.
	Single.insert(Single.begin(), 1);
	Single.insert(Single.end(), (Bin.size() - Single.size()), 0);

	// Add 1 to the vector.
	Bin3 = Addition(Bin2, Single);

	Quotient.insert(Quotient.begin(), Bin3.size(), 0);

	// Take the new vector Bin3 and add it to vector Bin.
	//		In order to subtract via complement method continously
	//		until a remainder of zero is found.
	while (check == false)
	{
		Bin = Addition(Bin, Bin3);

		check = all_of(Bin.begin(), Bin.end(), [](int i) {return i == 0; });

		if (Bin <= Bin2)
		{
			check = true;
		}

	}

	if (carry == 1)
	{
		Quotient.insert(Quotient.begin(), 1);
	}

	cout << "The quotient is:\n";
	reverse(Quotient.begin(), Quotient.end());
	Display(Quotient);

	cout << "Remainder:\n";
	Display(Bin);

	return 0;
}
