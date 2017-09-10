/* -------------------------------------------------------
CS 216                  11/3/15
Programming Assignment 3
Program3.cpp
Dylan Jenkins
----------------------------------------------------------*/

#include "Header.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Missing command line argument" << endl;
		cout << "Usage: " << argv[0] << " <input text filename>\n";
		return 1;
	}
	else {
		Llist A;

		A.Initalize(argv[1]);
		A.Action();
	}
	return 0;
}
