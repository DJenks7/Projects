//	CS315		FALL 2015
//	Dylan Jenkins		Homework3p2A.cpp
//	Program is designed to accept two binary numbers input by the user. It then places
//	those into separate vectors and multiplies them together. Displaying the product.
//	PROBLEM 2 PART A

#include <iostream>
#include <vector>
using namespace std;

void Display(vector<int> &NUM);
vector<int> Addition(vector<int> &data1, vector<int> &data2);
vector<int> Multiply(vector<int> &data1, vector<int> &data2);

int carry = 0;

int main() {
	vector<int> Bin;		// Bin will hold the first binary # entered by user.
	vector<int> Bin2;		// Bin2 will hold the second binary # entered by the user.
	vector<int> BinTotal;	// BinTotal will hold the total vector once multiplied together.

	int input, hold;		// Input will hold the user input to be placed into the corresponding vector.

	// Ask user for input of first binary number.
	cout << "Enter binary #, 1 digit at a time(use any other # to stop):\n";
	cin >> input;

	while (input == 1 || input == 0) {
		Bin.insert(Bin.begin(), input);
		cin >> input;
	}

	// Ask user for the input of the second binary number.
	cout << "Enter 2nd binary #, 1 digit at a time(use any other # to stop):\n";
	cin >> input;

	while (input == 1 || input == 0) {
		Bin2.insert(Bin2.begin(), input);
		cin >> input;
	}

	if (Bin.size() > Bin2.size()) {
		Bin2.insert(Bin2.begin(), Bin.size() - Bin2.size(), 0);
	}
	else if(Bin.size() < Bin2.size()) {
		Bin.insert(Bin.begin(), Bin2.size() - Bin.size(), 0);
	}

	Display(Bin);
	Display(Bin2);

	// Initialize BinTotal to be the product of Bin and Bin2.
	BinTotal = Multiply(Bin, Bin2);

	// Display results.
	cout << "\nMultiplied Together:\n";
	Display(BinTotal);

	return 0;
}

// Prints the vector.
void Display(vector<int> &NUM) {
	for (int i = 0; i < NUM.size(); i++) {
		cout << NUM[i] << " ";
	}
	cout << endl;
}

vector<int> Addition(vector<int> &data1, vector<int> &data2) {
	vector<int> BinAdd;
	int s = data1.size();
	carry = 0;

	// Loop to add the vectors and place the result in a new vector.
	for (int i = 0; i < s; i++) {
		bool used = false;

		if (used == false) {
			if (data1[i] + data2[i] + carry == 0) {
				BinAdd.insert(BinAdd.begin(), 0);
				carry = 0;
				used = true;
			}
		}

		if (used == false) {
			if (data1[i] + data2[i] + carry == 1) {
				BinAdd.insert(BinAdd.begin(), 1);
				carry = 0;
				used = true;
			}
		}

		if (used == false) {
			if (data1[i] + data2[i] + carry == 2) {
				BinAdd.insert(BinAdd.begin(), 0);
				carry = 1;
				used = true;
			}
		}

		if (used == false) {
			if (data1[i] + data2[i] + carry > 2) {
				BinAdd.insert(BinAdd.begin(), 1);
				carry = 1;
				used = true;
			}
		}
	}
	return BinAdd;
}

vector<int> Multiply(vector<int> &data1, vector<int> &data2)
{
	vector<int> z;
	z.insert(z.begin(), data1.size() + data2.size(), 0);

	for (int i = data2.size() - 1; i >= 0; i--) {
		z[i] = 2 * z[i];

		if (data2[i] = 1) {
			z[i] = z[i] + data1[i];
		}
	}
	return z;
}

/*
// Multiplies the two vectors.
vector<int> Multiply(vector<int> &data1, vector<int> &data2)
{
	vector<int> Bin3;
	vector<int> Bin4;

	// Loop to clear Bin3 if it is filled. Inserts additional zero(s) after each run through
	// in order to multiply. Then multiplies the first digit of the second binary number by the
	// whole vector of the first binary number and repeats for each digit in the second vector.
	for (int i = 0; i < data2.size(); i++)
	{
		Bin3.clear();
		Bin3.insert(Bin3.begin(), i, 0);

		for (int j = 0; j < data1.size(); j++)
		{
			int insert = data1[j] * data2[i];
			Bin3.push_back(insert);
		}

		// Checks to see if Bin3 is larger than Bin4, if so fills Bin4 with
		// additional zeros in order to add correctly.
		if (Bin3.size() > Bin4.size())
		{
			for (int k = 0; k <= Bin3.size() - Bin4.size(); k++)
			{
				Bin4.push_back(0);
			}
		}

		// Adds the previous Bin4 and Bin3 to obtain the total value.
		Bin4 = Addition(Bin4, Bin3);

	}
	return Bin4;
}
*/