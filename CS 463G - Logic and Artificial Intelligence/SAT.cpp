/* -------------------------------------------------------
CS 463                  9/23/16
Programming Assignment 3
SAT.cpp
Dylan Jenkins
----------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Missing command line argument" << endl;
		cout << "Correct Usage: " << argv[0] << " <filename>\n";
		return 1;
	}
	else {
		ifstream ReadFile;
		ReadFile.open("easy/1.cnf");	// argv[1]

		string line;
		int Var, Clause;
		int value, i, j;

		// If the file was opened...
		if (ReadFile.is_open()) {
			ReadFile >> line;

			// If the first line begins with character p, read the next three lines into the corresponding variables.
			if (line == "p") {
				ReadFile >> line;
				ReadFile >> Var;
				ReadFile >> Clause;
			}

			// Vector of Integer Vectors F to hold values for clauses.
			vector<vector<int>> F(Clause, vector<int>(4));

			// Fills Vectors with data from file.
			for (i = 0; i < Clause; i++) {
				for (j = 0; j <= 3; j++) {
					if (!ReadFile.eof()) {
						ReadFile >> value;
						F[i][j] = value;
					}
				}
			}

			ReadFile.close();

			//*************************************
			//	CALL ALGORITHMS
			//	HOPEFULLY....
			//	Vectors of Integer Vectors --> Data Structure
			//*************************************

			// Testing to print, ensuring data has been read...
			for (i = 0; i < Clause; i++) {
				for (j = 0; j <= 3; j++) {
					cout << F[i][j] << " ";
				}
				cout << endl;
			}
		}

		cin >> line;		// FOR TESTING PURPOSES - To pause before exiting.
//	}
	return 0;
}