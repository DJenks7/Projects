/*---------------------------------------------------------------------------
CS 216	005		12/5/15
Program Assignment 4
Program4.cpp

Dylan Jenkins
-----------------------------------------------------------------------------*/
#include "Header.h"
using namespace std;

int main() {
	ParseTree A;	// Creates an object from ParseTree called A.

	A.Menu();		// Calls the function to display the menu the first time.
	A.Action();		// Calls the function to handle the rest of the program.

	return 0;
}