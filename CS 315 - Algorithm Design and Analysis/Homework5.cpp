/*
This program is designed to create an array or list of a specific
data type created called element.

Displays a menu for the user to fill up the array with their own entry's
using a SENTINEL value to stop, generate the array list with random
numbers, perform one of three sorting methods on the list a Quick
Sort, an Insertion Sort, or Merge Sort on the list.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>
using namespace std;

typedef int element;			// new typedef to make altering data easier.
const element SENTINEL = -1;	// sentinel value to exit Read().

class Alist {
private:
	vector<element> items;	// Array named items of element data type.
	int size;               // Integer to hold the size given by user.
	bool sorted;            // Boolean to decide if items array has been sorted.
	bool Filled;            // Boolean to decide if items array has been filled.
	void Swap(int Pos1, int Pos2);  // Swap method to go into items array and swap two elements.
	element Read_element();         // Used to validate user element entry.

	void Test1();  			// [n,n-1,...1]
	void Test2();			// [6,5,4..] 
public:
	void Read();    // Method to read elements by user entry.
	void GenerateRandomList(int ListSize, int low, int high);
	// Generates random elements by user size, lower and upper bounds entry.

	void Print();							// Method to print the current list.
	void QuickSort();						// Method for Quick Sort.       
	int QuickSort(int first, int last);		// Method for Quick Sort, return comparisons.
	void InsertionSort();					// Method for Insertion Sort.
	void MergeSort();						// Method for Merge Sort.        
	int MergeSort(int first, int last);		// Method for Merge Sort, return comparisons.
	void Action();							// Method for menu input loop and exit
											// of program. Contains most input for the menu.

	void Menu();		// Display the menu and current list.
	int Read_int();		// Validate user integer entry.
};

int main() {
	Alist B;        // Creates A list object called B.

	B.Action();     // Starts program.
}

// Prints the array.
void Alist::Print() {
	// PRE: Native Object(N.O.-currently Alist) is valid.
	// POST: N.O. is unchanged & elements of N.O. have
	//              been displayed.

	for (int I = 0; I<size; I++)
		cout << items[I] << " ";
}

// Asks the user to fill the array with elements.
void Alist::Read() {
	// PRE: None.
	// POST: N.O. is valid using data entered by the user.

	element userVal;		// Element called userVal for user entry.

	cout << "Enter elements, use " << SENTINEL << " to stop." << endl;
	size = 0;
	items.clear();
	userVal = Read_element();

	// while the user has not entered the sentinel value
	//  and size is less than constant MLS, add element to array.
	while (userVal != SENTINEL) {
		items.push_back(userVal);
		size++;
		userVal = Read_element();
	}

	cout << "Manual entry complete, " << size <<
		" elements entered." << endl << endl;

	sorted = false;		// Boolean value to determine if the list has been sorted.
	Filled = true;		// Boolean value to determine if the list has been filled.
}

void Alist::QuickSort() {
	// PRE: N.O. Alist is valid.
	// POST: N.O. is still valid, except its elements
	//              have been placed in ascending order.

	int Acount = 0;			// Actual count for number of comparisons.
	int Tcount = (int)(size * log(size));	// Theoretical comparisons count.

	cout << "Performing Quick Sort..." << endl << endl;

	Acount = QuickSort(0, size - 1);

	sorted = true;

	cout << "Theoretical sort statistics:\t" << Tcount << " element comparisons\n";
	cout << "Actual sort statistics:\t\t" << Acount << " element comparisons\n\n";
	cout << "Finished Quick Sort." << endl << endl;
}

// Sorts the subarray into Ascending order.
//  returns the number of comparisons
int Alist::QuickSort(int first, int last) {
	int len = (last - first + 1);
	if (len <= 1)
		return 0;
	int Acount = 0;
	int pivot = items[first + rand() % len];
	int i = first;
	int j = last;

	while (i < j) {
		Acount++;
		while (items[i] < pivot) {
			Acount++;
			i++;
		}
		Acount++;
		while (items[j] > pivot) {
			Acount++;
			j--;
		}

		if (i < j) {
			Swap(i, j);
			i++;
		}
	}

	if (i == first)
		i++;

	Acount += QuickSort(first, i - 1);
	Acount += QuickSort(i, last);

	return Acount;
}

// Sorts the array into Ascending order.
void Alist::InsertionSort() {
	// PRE: N.O. Alist is valid.
	// POST: N.O. is still valid, except its elements
	//              have been placed in ascending order.

	int j;											// Integer called j to hold a position.
	bool done;										// Boolean called done for the end of the list.
	int Acount = 0;									// Actual count for number of comparisons.
	int Tcount = (((size*size) / 2) - (size / 2));	// Theoretical comparisons count.

	cout << "Performing Insertion Sort..." << endl << endl;

	for (int i = 1; i<size; i++) {
		j = i;
		done = false;

		while ((j >= 1) && (!done))
			if (items[j]<items[j - 1]) {
				Swap(j, j - 1);
				j--;
				Acount++;
			}
			else {
				done = true;
				Acount++;
			}
	}
	sorted = true;

	cout << "Theoretical sort statistics:\t" << Tcount << " element comparisons\n";
	cout << "Actual sort statistics:\t\t" << Acount << " element comparisons\n\n";
	cout << "Finished Insertion Sort." << endl << endl;
}

// Sorts the array into Ascending order.
void Alist::MergeSort() {
	// PRE: N.O. Alist is valid.
	// POST: N.O. is still valid, except its elements
	//              have been placed in ascending order.

	int maxPos;							// Integer to hold the max position.
	int Acount = 0;						// Actual count for number of comparisons.
	int Tcount = (int)(size * log(size));	// Theoretical count for comparisons.

	cout << "Performing Merge Sort..." << endl << endl;

	Acount = MergeSort(0, size - 1);

	sorted = true;

	cout << "Theoretical sort statistics:\t" << Tcount << " element comparisons\n";
	cout << "Actual sort statistics:\t\t" << Acount << " element comparisons\n\n";
	cout << "Finished Merge Sort." << endl << endl;
}

// Sorts the subarray into Ascending order.
//  returns the number of comparisons
int Alist::MergeSort(int first, int last) {
	int Acount = 0;
	int len = last - first + 1;

	if (len <= 1)
		return 0;

	vector<int> temp;

	int mid = first + len / 2;
	Acount += MergeSort(first, mid - 1);
	Acount += MergeSort(mid, last);

	// merge
	int i1 = first;
	int i2 = mid;

	while (i1 < mid && i2 <= last) {
		Acount++;
		if (items[i1] < items[i2]) {
			temp.push_back(items[i1]);
			i1++;
		}
		else {
			temp.push_back(items[i2]);
			i2++;
		}
	}

	while (i1 < mid) {
		temp.push_back(items[i1]);
		i1++;
	}
	while (i2 <= last) {
		temp.push_back(items[i2]);
		i2++;
	}

	for (int i = 0; i < len; i++) {
		items[first + i] = temp[i];
	}

	return Acount;
}

// Swaps the two elements in the array.
void Alist::Swap(int Pos1, int Pos2) {
	// PRE: N.O. is valid & 0 <= Pos1 < size
	//                      0 <= Pos2 < size
	// POST: N.O. is unchanged, except element in position
	//              Pos1 & Pos2 have been swapped in the array.

	element temp;           // Element called temp to hold element
							// in items array list to be swapped.

	temp = items[Pos1];
	items[Pos1] = items[Pos2];
	items[Pos2] = temp;
}

// Generates random numbers for array list, bounds entered by user.
void Alist::GenerateRandomList(int ListSize, int low, int high) {
	// PRE: 0 <= ListSize <= 50     low <= high
	//      srand() has been called.
	// POST: N.O. is valid using data randomly generated
	//      elements between low and high.
	items.clear();

	for (int i = 0; i < ListSize; i++)
		items.push_back((rand() % (high - low + 1)) + low);

	size = ListSize;

	cout << endl << "Finished Generation, " << ListSize <<
		" elements entered between " << low << " to "
		<< high << endl << endl;

	sorted = false;         // Boolean value to determine if the list has been sorted.
	Filled = true;          // Boolean value to determine if the list has been filled.
}

// Displays the menu for user input.
void Alist::Action() {
	// PRE: None.
	// POST: Menu has been displayed asking for user input..

	int Low, High;			// Elements for user input for Searching Methods.
	int action, Size;       // Integer action is for menu input.
							// Size is for random list generation.

	bool Found;				// Boolean for if element search is found.

	Menu();
	action = Read_int();

	// While user has not input 8 as menu option choice.
	while (action != 8) {
		// Users menu input was list creation from user entry.
		if (action == 1) {
			system("CLS");
			Read();
			system("CLS");
			Menu();
			action = Read_int();
		}

		// Users menu input was random list generation.
		else if (action == 2) {

			srand(int(time(0)));    // Help generate random numbers.

			system("CLS");
			cout << "Enter list size: ";

			Size = Read_int();

			cout << "Enter lowest possible element: ";
			Low = Read_int();

			cout << "Enter highest possible element: ";
			High = Read_int();

			// Generate random list method.
			GenerateRandomList(Size, Low, High);
			system("CLS");
			Menu();
			action = Read_int();
		}

		// Users menu input was Quick Sort.
		else if (action == 3) {
			system("CLS");
			QuickSort();
			Menu();
			action = Read_int();
		}

		// Users menu input was Insertion Sort.
		else if (action == 4) {
			system("CLS");
			InsertionSort();
			Menu();
			action = Read_int();
		}

		// Users menu input was Merge Sort.
		else if (action == 5) {
			system("CLS");
			MergeSort();
			Menu();
			action = Read_int();
		}
		else if (action == 6) {
			system("CLS");
			Test1();
			Menu();
			action = Read_int();
		}
		else if (action == 7) {
			system("CLS");
			Test2();
			Menu();
			action = Read_int();
		}
		else {
			cout << "Wrong Command.\nTry Again.\n";
			cout << "Action: ";
			action = Read_int();
		}
	}

	cout << endl << "GOODBYE" << endl;
}

void Alist::Test1() {
	int sizes[] = { 100, 200, 400, 800, 1600, 3200, 6400 };
	for (int i = 0; i < 7; i++) {
		size = sizes[i];
		cout << "----------------- SIZE " << size << " ------------------" << endl;
		for (int j = 0; j < 3; j++) {
			items.clear();
			for (int k = 0; k < size; k++)
				items.push_back(size - k);

			if (j == 0)
				InsertionSort();
			else if (j == 1)
				QuickSort();
			else
				MergeSort();
		}
	}
}

void Alist::Test2() {
	int sizes[] = { 100, 200, 400, 800, 1600, 3200, 6400 };
	for (int i = 0; i < 7; i++) {
		size = sizes[i];
		cout << "----------------- SIZE " << size << " ------------------" << endl;
		for (int j = 0; j < 3; j++) {
			items.clear();
			int k;
			for (k = 0; k < 6; k++)
				items.push_back(6 - k);
			for (k = 6; k < size; k++)
				items.push_back(k + 1);
			Swap(size - 1, size - 3);

			if (j == 0)
				InsertionSort();
			else if (j == 1)
				QuickSort();
			else
				MergeSort();
		}
	}
}

// Menu method, displays the current lsit and menu.
void Alist::Menu() {
	// PRE: None.
	// POST: Menu and current list is displayed.

	cout << "Current List:";
	// If the list has not been filled or is empty.
	if (Filled == false || size == 0)
		cout << " (Empty) ";
	else {  // Otherwise print the list.
		cout << "( ";
		Print();
		cout << ")";
	}

	// If the list has been sorted.
	if (sorted == true)
		cout << "\n(KNOWN to be ordered)" << endl << endl;

	else    // Otherwise.
		cout << "\n(NOT KNOWN to be ordered)" << endl << endl;

	cout << "Actions:" << endl;
	cout << "1. Reset the current list from the keyboard." << endl;
	cout << "2. Reset the current list using randomly generated "
		<< "elements." << endl;
	cout << "3. Perform Quick Sort on the current list." << endl;
	cout << "4. Perform Insertion Sort on the current list." << endl;
	cout << "5. Perform Merge Sort on the current list." << endl;
	cout << "6. Run algorithms on [n,n-1..]." << endl;
	cout << "7. Run algorithms on [6,5,4...]." << endl;
	cout << "8. Quit the program." << endl << endl;
	cout << "Action: ";
}

// Reads the input by user and accepts if it is correct data type.
element Alist::Read_element() {
	element Val;    // Element called Val to hold user input.

	cin >> Val;
	while (!cin.good()) {
		cout << "Invalid element, try again." << endl;
		cin.clear();
		cin.ignore(80, '\n');
	}
	return Val;     // Return if input is an element.
}

// Reads the input by the user and accepts if it is an integer.
int Alist::Read_int() {
	int Val;        // Integer called Val to hold user input.

	cin >> Val;
	while (!cin.good() && Val < 0) {
		cout << "Invalid integer, try again." << endl;
		cin.clear();
		cin.ignore(80, '\n');
		cin >> Val;
	}
	return Val;     // Rreturn if input is an integer.
}