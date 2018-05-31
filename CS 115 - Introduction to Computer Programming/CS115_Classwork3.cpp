// Program Name: CS115_Classwork3.cpp
// Author: Dylan Jenkins
// Date: March 31, 2011
/*	EDIT
	Updated: 5/14/2018
	Removed unneccessary include statement.
	Altered counter so it is no longer case sensitive.
	Minor code cleanup.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char searchChar, option = 'Y';
	string sentence;
	int charCount, posCount;
	charCount = posCount = 0;

	cout << "Do you want to search a character (Y/N)?\n";
	cin >> option;
	cin.ignore();

	while (option == 'Y' || option == 'y')
	{
		cout << "Enter a sentence: ";
		getline(cin, sentence);
		cout << "Enter a character: ";
		cin.get(searchChar);

		while (posCount < sentence.length())
		{
			if (sentence.at(posCount) == toupper(searchChar) || 
					sentence.at(posCount) == tolower(searchChar))
				charCount++;
			posCount++;
		}

		cout << endl << "The character \'" << searchChar
			<< "\' appears " << charCount
			<< " times in the follwing sentence: " << endl
			<< endl << sentence << endl;

		cout << "Do you want to search again (Y/N)?\n";
		cin >> option;
		cin.ignore();
	}

	return 0;
}

