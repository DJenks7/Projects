/*
	Dylan Jenkins
	CS 215-J001     Fall 2013
	Program Assignment 1
	CS215_Program1.cpp

	This program is designed to create an array or list of a specific
	data type created called element.

	Displays a menu for the user to fill up the array with their own entry's
	using a SENTINEL value to stop, generate the array list with random
	numbers, perform one of three sorting methods on the list a Bubble
	Sort, an Insertion Sort, or a Selection Sort on the list, or two
	variations of searching methods a Linear or Binary Search. The last
	menu option is to exit.

	EDIT
	Updated: 5/15/2018
	Removed unnecessary include statement.
	Added simple error checking.
	Minor code cleanup.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int MLS = 50;				// due to change, constant size for the array.
typedef int element;			// new typedef to make altering data easier.
const element SENTINEL = -1;	// sentinel value to exit Read().

// Class Alist, contains, an array, a Read(), Print(), BubbleSort(), Swap(), and Read_element() methods.
class Alist {
private:
	element items[MLS];				// Array named items of element data type.
	int size;						// Integer to hold the size given by user.
	bool sorted;					// Boolean to decide if items array has been sorted.
	bool Filled;					// Boolean to decide if items array has been filled.
	void Swap(int Pos1, int Pos2);  // Swap method to go into items array and swap two elements.
	element Read_element();         // Used to validate user element entry.
public:
	void Read();														// Method to read elements by user entry.
	void GenerateRandomList(int ListSize, element low, element high);	// Generates random elements by user size, lower and upper bounds entry.
	void Print();														// Method to print the current list.
	void BubbleSort();													// Method for Bubble Sort.
	void InsertionSort();												// Method for Insertion Sort.
	void SelectionSort();												// Method for Selection Sort.
	void LinearSearch(element Target, bool & found, int & Pos);			// Method for Linear Search of current array list.
	void BinarySearch(element Target, bool & found, int & Pos);			// Method for Binary Search of current array list.
	void Action();														// Method for menu input loop and exit of program. Contains most input for the menu.
	void Menu();														// Display the menu and current list.
	void Initalize();													// Initalize the list at beginning.
	int Read_int();														// Validate user integer entry.
};

int main() {
	Alist B;		// Creates A list object called B.

	B.Initalize();
	B.Action();		// Starts program.
}

// Prints the array.
void Alist::Print() {
	// PRE: Native Object(N.O.-currently Alist) is valid.
	// POST: N.O. is unchanged & elements of N.O. have been displayed.
	for (int I = 0; I<size; I++)
		cout << items[I] << " ";
}

// Asks the user to fill the array with elements.
void Alist::Read() {
	// PRE: None.
	// POST: N.O. is valid using data entered by the user.
	element userVal;		// Element called userVal for user entry.

	cout << "Enter elements, use " << SENTINEL << " to stop.\n";
	size = 0;
	userVal = Read_element();

	// while the user has not entered the sentinel value and size is less than constant MLS, add element to array.
	while ((userVal != SENTINEL) && (size<MLS)) {
		items[size] = userVal;
		size++;

		if (size<MLS) {
			userVal = Read_element();
		}
	}

	cout << "Manual entry complete, " << size << " elements entered.\n\n";

	sorted = false;		// Boolean value to determine if the list has been sorted.
	Filled = true;		// Boolean value to determine if the list has been filled.
}

// Initalize the array list for beginning use.
void Alist::Initalize() {
	for (int i = 0; i<size; i++)
		items[i] = 0;
}

// Sorts the array into Ascending order.
void Alist::BubbleSort() {
	// PRE: N.O. Alist is valid.
	// POST: N.O. is still valid, except its elements have been placed in ascending order.
	int Acount = 0, Amove = 0;									// Actual count for number of comparisons and movements.
	int Tcount = (((size*size) / 2) - (size / 2));				// Theoretical comparisons count.
	int Tmove = (((3 * (size*size)) / 2) - ((3 * size) / 2));	// Theoretical movements count.

	cout << "Performing Bubble Sort...\n\n";

	for (int i = 0; i<size - 1; i++) {
		for (int j = 0; j<size - 1 - i; j++) {
			if (items[j]>items[j + 1]) {
				Swap(j, j + 1);
				Amove = Amove + 3;
				Acount++;
			}
			else {
				Acount++;
			}
		}
	}

	sorted = true;

	cout << "Theoretical sort statistics:\t" << Tcount << " element comparisons, " << Tmove << " element movements.\n";
	cout << "Actual sort statistics:\t\t" << Acount << " element comparisons, " << Amove << " element movements.\n\n";
	cout << "Finished Bubble Sort.\n\n";
}

// Sorts the array into Ascending order.
void Alist::InsertionSort() {
	// PRE: N.O. Alist is valid.
	// POST: N.O. is still valid, except its elements have been placed in ascending order.
	int j;														// Integer called j to hold a position.
	bool done;													// Boolean called done for the end of the list.
	int Acount = 0, Amove = 0;									// Actual count for number of comparisons and movements.
	int Tcount = (((size*size) / 2) - (size / 2));				// Theoretical comparisons count.
	int Tmove = (((3 * (size*size)) / 2) - ((3 * size) / 2));	// Theoretical movements count.

	cout << "Performing Insertion Sort...\n\n";

	for (int i = 1; i<size; i++) {
		j = i;
		done = false;

		while ((j >= 1) && (!done)) {
			if (items[j]<items[j - 1]) {
				Swap(j, j - 1);
				j--;
				Amove = Amove + 3;
				Acount++;
			}
			else {
				done = true;
				Acount++;
			}
		}
	}

	sorted = true;

	cout << "Theoretical sort statistics:\t" << Tcount << " element comparisons, " << Tmove << " element movements.\n";
	cout << "Actual sort statistics:\t\t" << Acount << " element comparisons, " << Amove << " element movements.\n\n";
	cout << "Finished Insertion Sort.\n\n";
}

// Sorts the array into Ascending order.
void Alist::SelectionSort() {
	// PRE: N.O. Alist is valid.
	// POST: N.O. is still valid, except its elements have been placed in ascending order.
	int maxPos;											// Integer to hold the max position.
	int Acount = 0, Amove = 0;							// Actual count for number of comparisons and movements.
	int Tcount = (((size*size) / 2) - (size / 2));		// Theoretical count for comparisons.
	int Tmove = 3 * (size - 1);							// Theoretical count for number of movements.

	cout << "Performing Selection Sort...\n\n";

	for (int i = size - 1; i>0; i--) {
		maxPos = 0;
		for (int j = 1; j <= i; j++) {
			if (items[j]>items[maxPos]) {
				maxPos = j;
				Acount++;
			}
			else {
				Acount++;
			}
		}

		Swap(maxPos, i);
		Amove = Amove + 3;
	}

	sorted = true;

	cout << "Theoretical sort statistics:\t" << Tcount << " element comparisons, " << Tmove << " element movements.\n";
	cout << "Actual sort statistics:\t\t" << Acount << " element comparisons, " << Amove << " element movements.\n\n";
	cout << "Finished Selection Sort.\n\n";
}

// Searches the array for a specific target.
void Alist::LinearSearch(element Target, bool & found, int & Pos) {
	// PRE: N.O. is valid, Target is a valid element.
	// POST: N.O. is unchanged and if Target exists on N.O. then found will be true and Pos will be at the
	//       Target's location in the N.O. otherwise (if Target doesnt exist), then found will be false and Pos is undefined.
	Pos = 0;
	found = false;          // Boolean value to determine if target was found during search.
	int Acount = 0;         // Integer for Actual comparison count.
	int Tcount = size;      // Theoretical comparison count.

	while ((!found) && (Pos<size))
		if (Target == items[Pos]) {
			found = true;
			Acount++;
		}
		else {
			Acount++;
			Pos++;
		}

		cout << endl << "Theoretical search statistics:\t" << Tcount << " element comparisons.\n";
		cout << "Actual search statistics:\t" << Acount << " element comparisons.\n";

		// If the Target element was found.
		if (found == true) {
			cout << endl << "Target (" << Target << ") " << "was FOUND at list position " << Pos + 1 << endl << endl;
		}
		else {
			cout << endl << "Target (" << Target << ") was " << "NOT FOUND.\n\n";
		}
}

// Searches the array for a specific target.
void Alist::BinarySearch(element Target, bool & found, int & Pos) {
	// PRE: N.O is valid, Target is a valid element.
	// POST: N.O. is unchanged and if Target exists on N.O. then found will be true and Pos will be at the
	//       Target's location in the N.O. otherwise (if Target doesnt exist), then found will be false and Pos is undefined.
	int low, high, mid;		// Integers low (lowest point possible), high (highest point possible), mid (middle point of list).
	found = false;          // Boolean value to determine if target was found during search.
	int Acount = 0;									// Actual count for comparisons.
	int Tcount = (2 * ((log((float) size)) / (log((float) 2))));	// Theoretical count.

	low = 0;
	high = size - 1;

	// If the list has been sorted and is KNOWN to be ordered.
	if (sorted == true) {
		while ((!found) && (low <= high)) {
			mid = (low + high) / 2;

			if (Target == items[mid]) {
				found = true;
				Pos = mid;
				Acount++;
			}
			else if (Target<items[mid]) {

				high = mid - 1;
				Acount++;
			}
			else {   // Target>items[mid]
				low = mid + 1;
				Acount++;
			}
		}

		cout << "\nTheoretical search statistics:\t" << Tcount << " element comparisons.\n";
		cout << "Actual search statistics:\t" << Acount << " element comparisons.\n";

		// If the Target element was found.
		if (found == true) {
			cout << "\nTarget (" << Target << ") " << "was FOUND at list position " << Pos + 1 << endl << endl;
		}
		else {	// If the element was not found.
			cout << "\nTarget (" << Target << ") was " << "NOT FOUND.\n\n";
		}
	}
	else {	// If the list has NOT been sorted and is NOT KNOWN to be ordered.
		cout << "Sorry, the list is not known to be ordered\n";
		cout << "Therefore Binary Search cannot be performed at this time, sort the list first.\n\n";
	}
}

// Swaps the two elements in the array.
void Alist::Swap(int Pos1, int Pos2) {
	// PRE: N.O. is valid & 0 <= Pos1 < size, 0 <= Pos2 < size
	// POST: N.O. is unchanged, except element in position Pos1 & Pos2 have been swapped in the array.

	element temp;		// Element called temp to hold element in items array list to be swapped.

	temp = items[Pos1];
	items[Pos1] = items[Pos2];
	items[Pos2] = temp;
}

// Generates random numbers for array list, bounds entered by user.
void Alist::GenerateRandomList(int ListSize, element low, element high) {
	// PRE: 0 <= ListSize <= 50, low <= high, & srand() has been called.
	// POST: N.O. is valid using data randomly generated elements between low and high.

	for (int i = 0; i < ListSize; i++) {
		items[i] = (rand() % (high - low + 1)) + low;
	}

	size = ListSize;

	cout << endl << "Finished Generation, " << ListSize << " elements entered between " << low << " to " << high << endl << endl;

	sorted = false;		// Boolean value to determine if the list has been sorted.
	Filled = true;		// Boolean value to determine if the list has been filled.
}

// Displays the menu for user input.
void Alist::Action() {
	// PRE: None.
	// POST: Menu has been displayed asking for user input..
	element search, Low, High;		// Elements for user input for Searching Methods.

	int action, pos, Size;			// Integers, action is for menu input, pos is for Search method to display
									// position of element search (input by user). Size is for random list generation.
	bool Found;                     // Boolean for if element search is found.

	Menu();
	action = Read_int();

	// While user has not input 8 as menu option choice.
	while (action != 8) {
		// Users menu input was list creation from user entry.
		if (action == 1) {
			Read();
			Menu();
			action = Read_int();
		}
		// Users menu input was random list generation.
		else if (action == 2) {

			srand(int(time(0)));    // Help generate random numbers.

			cout << "Enter list size (MAX size is 50): ";

			Size = Read_int();

			// Checks size entry. Max is 50.
			if (Size>MLS) {
				cout << "Size entered is too big, " << "try again.\n";
				Size = Read_int();
			}
			else {
				;
			}

			cout << "Enter lowest possible element: ";
			Low = Read_int();

			cout << "Enter highest possible element: ";
			High = Read_int();

			// Generate random list method.
			GenerateRandomList(Size, Low, High);
			Menu();
			action = Read_int();
		}
		// Users menu input was Bubble Sort.
		else if (action == 3) {
			BubbleSort();
			Menu();
			action = Read_int();
		}
		// Users menu input was Insertion Sort.
		else if (action == 4) {
			InsertionSort();
			Menu();
			action = Read_int();
		}
		// Users menu input was Selection Sort.
		else if (action == 5) {
			SelectionSort();
			Menu();
			action = Read_int();
		}
		// Users menu input was Linear Search.
		else if (action == 6) {
			cout << "Enter element to search for: ";
			search = Read_int();

			LinearSearch(search, Found, pos);
			Menu();
			action = Read_int();
		}
		// User menu input was Binary Search
		else if (action == 7) {
			cout << "Enter element to search for: ";
			search = Read_int();

			BinarySearch(search, Found, pos);
			Menu();
			action = Read_int();
		}
		else {
			;
		}
	}

	cout << endl << "GOODBYE\n";
}

// Menu method, displays the current lsit and menu.
void Alist::Menu() {
	// PRE: None.
	// POST: Menu and current list is displayed.

	cout << "Current List:";
	// If the list has not been filled or is empty.
	if (Filled == false || size == 0) {
		cout << " (Empty) ";
	}
	else {  // Otherwise print the list.
		cout << "( ";
		Print();
		cout << ")";
	}

	// If the list has been sorted.
	if (sorted == true) {
		cout << "(KNOWN to be ordered)\n\n";
	}
	else {	// Otherwise.
		cout << "(NOT KNOWN to be ordered)\n\n";
	}

	cout << "Actions:\n";
	cout << "1. Reset the current list from the keyboard.\n";
	cout << "2. Reset the current list using randomly generated elements.\n";
	cout << "3. Perform Bubble Sort on the current list.\n";
	cout << "4. Perform Insertion Sort on the current list.\n";
	cout << "5. Perform Selection Sort on the current list.\n";
	cout << "6. Perform Linear Search on the current list.\n";
	cout << "7. Perform Binary Search on the current list.\n";
	cout << "8. Quit the program.\n\n";
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
	while (!cin.good()) {
		cout << "Invalid integer, try again." << endl;
		cin.clear();
		cin.ignore(80, '\n');
	}

	return Val;     // Rreturn if input is an integer.
}