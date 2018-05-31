/*---------------------------------------------------------------------------
CS 216	005		12/5/15
Program Assignment 4
CS216_Program4.cpp

Dylan Jenkins
-----------------------------------------------------------------------------*/
#include "CS216_Program4.h"
using namespace std;

int main() {
	ParseTree A;	// Creates an object from ParseTree called A.

	A.Menu();		// Calls the function to display the menu the first time.
	A.Action();		// Calls the function to handle the rest of the program.

	return 0;
}