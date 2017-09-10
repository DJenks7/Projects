/*      Dylan Jenkins
		CS 215-j001     Fall 2013
		Homework1.cpp
*/

#include<iostream>
#include<cmath>

using namespace std;


int get_Num(int & num);
int read_Int();
void check_Square(int & N);
void display_Flavor(int & num1, int & num2);

// Main function to declare first two integers and call other functions
int main()
{
	int Num1;       //Represents the Num used in methods
	int Num2;       //Represents the 2nd Num used in methods

	get_Num(Num1);
	get_Num(Num2);

	cout << endl;

	check_Square(Num1);
	check_Square(Num2);

	display_Flavor(Num1, Num2);
}

// get_Num function asks the user for a number between 2 and 5000
int get_Num(int & num)
{
	cout << "Enter a number between 2 and 5000: ";
	num = read_Int();

	while ((num<1) || (num>5000))
	{
		cout << "Invalid range, should be between 2-5000. "
			<< "Try Again." << endl;
		num = read_Int();
	}
	return num;
}

/* check_Square takes one number from user entered numbers and creates
a string holding the factors for the number and declares if it is square
free
*/
void check_Square(int & N)
{
	int fac = 0;

	cout << N << " has these factors (>1) that are square: ";

	for (int I = 2; I <= N; I++)
	{
		if (N%I == 0 && I == N && (sqrt(I)*sqrt(I)) == I)
		{
			cout << I << endl;
			fac++;
		}
		if (N%I == 0 && I != N && (sqrt(I)*sqrt(I)) == I)
		{
			cout << I << ", ";
			fac++;
		}
	}

	if (fac == 0)
	{
		cout << "(none)" << endl;
		cout << N << " is square-free." << endl;
	}
	else
	{
		cout << N << " is not square-free." << endl;
	}
	cout << endl;
}

/* display_Flavor takes the integers the user entered and determines if it
is sweet, sour, salty, or bitter and displays the ordered pair.
*/
void display_Flavor(int & num1, int & num2)
{
	cout << "Therefore, the ordered pair ("
		<< num1 << ", " << num2 << ") is";
	int fac1 = 0;
	int fac2 = 0;

	for (int int1 = 2; int1 <= num1; int1++)
	{
		if (num1%int1 == 0 && (sqrt(int1)*sqrt(int1)) == num1)
			fac1 += 1;
	}
	for (int int2 = 2; int2 <= num2; int2++)
	{
		if (num2%int2 == 0 && (sqrt(int2)*sqrt(int2)) == num2)
			fac2 += 1;
	}

	if (fac1 == 0 && fac2 == 0)
	{
		cout << " SWEET.";
	}

	if (fac1 == 0 && fac2 >= 1)
	{

		cout << " SOUR.";
	}

	if (fac1 >= 1 && fac2 >= 1)
	{
		cout << " BITTER.";
	}

	if (fac1 >= 1 && fac2 == 0)
	{
		cout << " SALTY.";
	}
	cout << endl;
}

// takes the number entered by the user and checks if it is in fact an integer
int read_Int()
{
	int val;

	cin >> val;

	while (!cin.good())
	{
		cout << "Invalid, should be an integer. Try Again." << endl;
		cin.clear();
		cin.ignore(80, '\n');
	}
	return val;
}

