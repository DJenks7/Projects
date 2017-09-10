#include <iostream>
#include <vector>
using namespace std;

int carry = 0;

void Display(vector<int> &NUM)
{
	for (int i = 0; i < NUM.size(); i++)
	{
		cout << NUM[i] << " ";
	}
	cout << endl;
}

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
				BinAdd.insert(BinAdd.begin(), 0);
				carry = 0;
				used = true;
			}
		}

		if (used == false)
		{
			if (data1[i] + data2[i] + carry == 1)
			{
				BinAdd.insert(BinAdd.begin(), 1);
				carry = 0;
				used = true;
			}
		}

		if (used == false)
		{
			if (data1[i] + data2[i] + carry == 2)
			{
				BinAdd.insert(BinAdd.begin(), 0);
				carry = 1;
				used = true;
			}
		}

		if (used == false)
		{
			if (data1[i] + data2[i] + carry > 2)
			{
				BinAdd.insert(BinAdd.begin(), 1);
				carry = 1;
				used = true;
			}
		}
	}
	return BinAdd;
}

int main()
{
	vector<int> Bin;
	vector<int> Bin2;
	vector<int> Bin3;

	int input, size, dif;

	cout << "Enter binary #, 1 digit at a time(use another # to stop):\n";
	cin >> input;

	while (input == 1 || input == 0)
	{
		Bin.insert(Bin.begin(), input);
		cin >> input;
	}

	cout << "Enter 2nd binary #, 1 digit at a time(use another # to stop)\n";
	cin >> input;

	while (input == 1 || input == 0)
	{
		Bin2.insert(Bin2.begin(), input);
		cin >> input;
	}

	cout << "\nBin1:\n";
	Display(Bin);
	cout << "Bin2:\n";
	Display(Bin2);

	Bin2.insert(Bin2.end(), Bin.size() - Bin2.size(), 0);
	Bin3 = Addition(Bin, Bin2);

	if (carry == 1)
	{
		Bin3.insert(Bin3.begin(), 1);
	}

	cout << "\nRESULT\n";
	Display(Bin3);

	return 0;
}