//	CS315		FALL 2015
//	Dylan Jenkins		Homework3p1.cpp
//	Program is designed to accept two binary numbers input by the user.
//	It then places those into separate vectors and subtracts them. Displaying the result.
//	PROBLEM 1

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

vector<int> Subtraction(vector<int> &data1, vector<int> &data2)
{
	vector<int> Sub;
	int s = data1.size() - 1;
	int c = 0;

	Sub.insert(Sub.begin(), s + 1, 0);
	
	for (int k = 0; k <= s; k++)
	{
		if (((c + data1[k] + data2[k]) % 2) != 0)
		{
			Sub[k] = 1;
		}
		else
		{
			Sub[k] = 0;
		}

		if (c + data2[k] + Sub[k] >= 2)
		{
			c = 1;
		}
		else
			c = 0;
	}

	reverse(Sub.begin(), Sub.end());

	for (int j = 0; j < Sub.size(); j++)
	{
		if (Sub[j] == 0)
			Sub.erase(Sub.begin());
		else
			break;
	}

	return Sub;
}

int main()
{
	vector<int> Bin;		// Vector Bin will hold first binary input by user.
	vector<int> Bin2;		// Vector Bin2 will hold second binary input by user.
	vector<int> Bin3;		// Vector Bin3 will hold the vector returned from
							//		the addition of Bin2 and Single, after flipped.

	int input;				// Integer input is for user input of binary number.

	// Ask for user input of first binary number, one digit at a time.
	cout << "Enter binary number:\n";
	cin >> input;

	while (input == 1 || input == 0)
	{
		Bin.insert(Bin.begin(), input);
		cin >> input;
	}

	// Ask for user input of second binary number, one digit at a time.
	cout << "Enter 2nd binary number:\n";
	cin >> input;

	while (input == 1 || input == 0)
	{
		Bin2.insert(Bin2.begin(), input);
		cin >> input;
	}

	// Fills smaller vector to the size of the assumed larger vector.
	Bin2.insert(Bin2.end(), Bin.size() - Bin2.size(), 0);

	cout << "When subtracted:\n";
	Bin3 = Subtraction(Bin, Bin2);
	Display(Bin3);

	return 0;
}

