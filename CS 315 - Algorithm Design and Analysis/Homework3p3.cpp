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
	vector<int> Bin;
	vector<int> Bin2;
	vector<int> Bin3;
	int input, bin = 0, bin2 = 0, bin3 = 0, bin4;
	int p1 = 1, p2 = 1, p3 = 1;

	cout << "Enter binary #, 1 digit at a time:\n";
	cin >> input;

	while (input == 1 || input == 0)
	{
		Bin.push_back(input);
		cin >> input;
	}

	// Runs through vector 1 and converts binary to decimal.
	for (int i = Bin.size() - 1; i >= 0; i--)
	{
		if (Bin[i] == 1)
		{
			bin += p1;
		}
		p1 *= 2;
	}

	cout << "Enter 2nd binary #, 1 digit at a time:\n";
	cin >> input;

	while (input == 1 || input == 0)
	{
		Bin2.push_back(input);
		cin >> input;
	}

	// Runs through vector 1 and converts binary to decimal.
	for (int i = Bin2.size() - 1; i >= 0; i--)
	{
		if (Bin2[i] == 1)
		{
			bin2 += p2;
		}
		p2 *= 2;
	}

	cout << "Enter modulus integer in binary(one digit at a time):\n";
	cin >> input;

	while (input == 1 || input == 0)
	{
		Bin3.push_back(input);
		cin >> input;
	}

	// Runs through vector 1 and converts binary to decimal.
	for (int i = Bin3.size() - 1; i >= 0; i--)
	{
		if (Bin3[i] == 1)
		{
			bin3 += p3;
		}
		p3 *= 2;
	}

	bin4 = pow(bin, bin2);
	bin4 = bin4 % bin3;

	cout << "\n" << bin << "^" << bin2 << " (mod " << bin3 << ") = " << bin4 << "\n";

	// Clears Bin2 in order to fill it with the final answer.
	Bin2.clear();

	while (bin4 > 0)
	{
		bin2 = bin4 % 2;
		Bin2.push_back(bin2);
		bin4 = bin4 / 2;
	}

	cout << "\nRemainder (Blank = Zero):\n";
	reverse(Bin2.begin(), Bin2.end());
	Display(Bin2);

	return 0;
}
