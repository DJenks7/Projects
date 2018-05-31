/* -------------------------------------------------------
CS 216			10/31/15
Programming Assignment 2
CS216_Program2.cpp
Dylan Jenkins
----------------------------------------------------------*/
#include "CS216_Program2.h"
using namespace std;

int main() {
	Llist A;				// Creates object Llist called A.
	A.Initalize();			// Calls the function in object A to read from a file
								//			and fill the linked list with text from the file.
	A.Action();				// Calls function in object A to perform the rest of the program.

	return 0;
}