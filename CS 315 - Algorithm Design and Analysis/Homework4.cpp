/*---------------------------------------------------------------------------------------
Dylan Jenkins           Homework5.cpp
11/5/15         HOMEWORK 5
CS 315

This program is designed to generate random binary numbers with n-digits,
compute modular exponentation and test for primality.
-----------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

// This function will simply return a randomly generated boolean value.
bool RandomBool() {
	return rand() % 2 == 0 ? false : true;
}

// This function generates a random binary sequence of n bits
// with the Least Significant Bit (Bin[0]) and the Most Significant Bit (Bin[Last] = 1)
// 1 representing True and 0 representing False.
void Random_Binary(bool BinaryNum[], int n) {
	BinaryNum[0] = true;
	BinaryNum[n - 1] = true;

	for (int i = 1; i < n - 1; i++) {
		BinaryNum[i] = RandomBool();
	}
}

// This function takes Bin and stores the binary equivalent in reverse order.
// Causing Bin[0] is the Least Significant Bit and Bin[Last] is the Most Significant Bit.
void Decimal_Binary(int Dec, bool Bin[]) {
	int Rem;
	int i = 0;

	do {
		Rem = Dec % 2;
		Rem == 0 ? Bin[i] = false : Bin[i] = true;
		Dec = Dec / 2;
		i++;
	} while (Dec > 0);
}

// This function takes the vector of decimal digits of an integer z
// and returns the vector of decimal digits of 2z.
void MultiplyTwo(int dNum[], int d) {
	int k;

	for (int i = 0; i < d; i++) {
		dNum[i] = dNum[i] * 2;
	}

	for (int i = 0; i < d - 1; i++) {
		if (dNum[i] > 9) {
			dNum[i] = dNum[i] - 10;
			dNum[i + 1] ++;
		}
	}
}

// This function converts the Bin numbers array to an array of decimals.
void Binary_Decimal(bool bNum[], int n, int dNum[], int d) {
	bool Flag = true;
	int k;

	for (int i = 0; i < d; i++) {
		dNum[i] = 0;
	}

	for (int i = n - 1; i >= 0; i--) {
		MultiplyTwo(dNum, d);
		if (bNum[i]) {
			if (Flag) dNum[0] = 1;
			else {
				dNum[0] = dNum[0] + 1;
				if (dNum[0] == 10) {
					dNum[0] = 0;

					for (k = 1; k < d; k++) {
						if (dNum[k] == 9)
							dNum[k] = 0;
						else
							break;
					}
					dNum[k]++;
				}
			}
			Flag = false;
		}
	}
}

// This function simply displays the boolean array as a binary number of n bits.
void Print(bool BinValue[], int n) {
	for (int i = 0; i < n; i++)
		BinValue[i] == false ? cout << "0 " : cout << "1 ";
}

int Most_Significant_Bit(bool Vector[], int Length) {
	for (int i = Length - 1; i >= 0; i--)
		if (Vector[i])
			return i;
	return 0;
}

// This function will return true if A is greater than or equal to B.
bool Compare(bool A[], int Size1, bool B[], int Size2) {
	int MSB1 = Most_Significant_Bit(A, Size1);
	int MSB2 = Most_Significant_Bit(B, Size2);

	if (MSB1 > MSB2)
		return true;
	if (MSB1 < MSB2)
		return false;

	for (int i = MSB1 - 1; i >= 0; i--) {
		if (A[i] != B[i])
			if (A[i])
				return true;
			else
				return false;
	}
	// Will reach this point if A equals B.
	return true;
}

// This function finds predecessor of BinValue and stores it in Y.
void Predecessor(bool BinValue[], bool Y[], int n) {
	int j = 1;;

	if (BinValue[0]) {
		Y[0] = false;
	}
	else {
		Y[0] = true;
		while (!BinValue[j]) {
			Y[j] = true;
			j++;
		}
		Y[j] = false;
	}

	for (int i = j; i < n; i++) {
		Y[i] = BinValue[i];
	}
}

// This function is used to increment BinValue by 1.
void Successor(bool BinValue[], int n) {
	if (!BinValue[0]) {
		BinValue[0] = true;
		return;
	}

	int i;
	for (i = 1; BinValue[i] != false; i++) {
		BinValue[i] = false;
	}
	BinValue[i] = true;
}

// This function is used to square a binary number, by shifting it one bit to the right.
void ShiftRight(bool BinValue[], int Size) {
	for (int i = Size - 1; i > 0; i--) {
		BinValue[i] = BinValue[i - 1];
	}
	BinValue[0] = false;
}

// This function does modular multiplication (Result = (X * Y) MOD N)
// Size stores the number of bits.
void ModularMultiply(bool X[], bool Y[], bool N[], int Size, bool Results[]) {
	bool Temp[2 * Size];

	for (int i = 0; i < 2 * Size; i++) {
		Temp[i] = false;
	}

	// Multiplyting Temp = X * Y
	// By using the iterative multiplication algorithm.
	bool Carry = false;
	bool Carry2 = false;
	bool Bit;

	for (int i = Size - 1; i >= 0; i--) {

		ShiftRight(Temp, 2 * Size);
		if (Y[i]) {
			// adding temp and x
			for (int j = 0; j < 2 * Size; j++) {
				if (j < Size) Bit = X[j];
				else Bit = false;

				Carry2 = (Temp[j] && Bit) || (Temp[j] && Carry) || (Carry && Bit);
				Temp[j] = (Temp[j] != Bit);
				Temp[j] = (Temp[j] != Carry);
				Carry = Carry2;
			}
		}
	}
	bool BorrowFlag = false;
	bool Rem[Size + 1];

	for (int l = 0; l <= Size; l++) {
		Rem[l] = false;
	}

	for (int i = 2 * Size - 1; i >= 0; i--) {
		ShiftRight(Rem, Size + 1);
		// Result = Results + 1
		if (Temp[i]) {
			Successor(Rem, Size + 1);
		}
		// If the result is greater than or equal to N.
		//      Subtract N from our current Result value.
		if (Compare(Rem, Size + 1, N, Size)) {
			int j;

			for (int k = 0; k < Size; k++) {
				if (Rem[k] == false && N[k] == true) BorrowFlag = true;
				Rem[k] = (Rem[k] != N[k]);

				// For cases 0 through 1.
				if (BorrowFlag) {
					Rem[k] = true;
					for (j = k + 1; Rem[j] != true; j++) {
						Rem[j] = true;
					}
					Rem[j] = false;
				}
				BorrowFlag = false;
			}
		}
	}
	// Results stores (X * Y) MOD N
	for (int i = 0; i < Size; i++) {
		Results[i] = Rem[i];
	}
}

// This function finds the modular exponent Results (Results = X^(y) MOD N)
// Size being the number of bits and being initalized to 1.
void ModularExponent(bool X[], bool Y[], bool N[], int Size, bool Results[]) {
	Results[0] = true;

	int i = Size - 1;
	do {
		ModularMultiply(Results, Results, N, Size, Results);
		if (Y[i]) {
			ModularMultiply(Results, X, N, Size, Results);
		}
		i--;
	} while (i >= 0);
}

// This function checks to see if the number BinValue
// is a prime number or not by testing it via Fermat's
// Little Theorem on the number a. n being the number of
// bits in BinValue.
bool Is_Prime(int a, bool BinValue[], int n) {
	bool Bin[n];
	bool Results[n];

	for (int i = 0; i < n; i++) {
		Bin[i] = false;
		Results[i] = false;
	}

	Decimal_Binary(a, Bin);

	// Determines (BinValue - 1) in binary
	bool Y[n];
	Predecessor(BinValue, Y, n);

	// This finds (a^(Bin-1)) mod Bin.
	ModularExponent(Bin, Y, BinValue, n, Results);

	// This checks to see if the result is 1 and return the
	// corresponding procedure to check if the result is equal to 1.
	if (Results[0] == false)
		return false;

	for (int i = 1; i < n; i++)
		if (Results[i])
			return false;

	return true;
}

int main() {
	clock_t begin = clock();
	srand(time(NULL));

	int n = 16;     // DUE TO ALTER -- NUMBER OF BITS

	bool BinValue[n];
	bool Prime = true;
	bool PrimeFlag;
	int Primes = 0;
	int TruePrimes = 0;
	int L = 0;
	long Decimal = 0;
	int Loops = 0;

	// Randomly checks 100 numbers as desired.
	do {
		Loops++;
		// Generates random binary numbers.
		Random_Binary(BinValue, n);

		// If the number satisfies Fermat's Test for (a = 3).
		if (Is_Prime(3, BinValue, n)) {
			Primes++;
		}
	} while (Primes < 1);
	cout << "---------------------------------------\n";
	cout << "\nIterations: " << Loops;
	cout << "\nPrimes Found: " << Primes;
	cout << "\n\nPrime Number(In Binary):\n";
	Print(BinValue, n);
	cout << "\n\nConverted to Decimal: ";

	int Digits = (n*log10(2)) + 1;
	int Dec[Digits];

	Binary_Decimal(BinValue, n, Dec, Digits);

	for (int i = 0; i < Digits; i++) {
		cout << Dec[i];
	}

	clock_t end = clock();
	double Time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "\n\tTime Taken: " << Time << "\n\n";
	cout << "---------------------------------------\n";

	return 0;
}
