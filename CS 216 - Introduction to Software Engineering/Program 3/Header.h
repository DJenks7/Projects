/* ------------------------------------------------------------------------------------------------------------
CS 216                  11/3/15
Programming Assignment 3
Header.h
This program is designed to read text from a file and create a linked list containing the text each node
contains a line of text. The user can then edit it as desired. Deleting, Adding, and Printing the linked list.
Dylan Jenkins
---------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct listnode {
	string text;                    // String used to hold the line of text in each
									//              section of the linked list.
	listnode* next;                 // Pointer used to point to the next link in the list.
};

class Llist {
private:
	int Size;                               // Integer Size, to hold the number of lines in the editor.
	char* Name;
	char Read_char();                       // Function to check for input validation.
	string Copy(int Line);                  // Function used to copy a line.
	int Length();                           // Function used to count the number of lines in the editor.
	void InsertTail(string thing);          // Function to insert a new line of text at the end
											//              of the linked list.
	void InsertAt(int Num, string Line);    // Function to insert a new line of text where ever specified.
	void Delete(int num);                   // Function to delete specific line given by the user.
	void Print();                           // Function to print the entire linked list.
	void Help();                            // Function to display the help menu.
	void Clean();                           // Function to delete the current linked list.
	void Save(const char* fileName);        // Function used to save the current text to a file.
	void Clear();                           // Function used to clear the user's screen.
	void DisplayBottomHelp();               // Function to display help menu on the bottom of user screen.
public:
	Llist();                                // Constructor.
	~Llist();                               // Destructor.

	listnode* head;                         // Pointer used to point the the head of the list.
	listnode* tail;                         // Pointer used to point to the end of the list.
	void Initalize(char* fileName);
	void Action();
};

// Constructor.
Llist::Llist() {
	head = NULL;
}

// Destructor.
Llist::~Llist() {
	Clean();
}

void Llist::Clear() {
	printf("\033[%d;%dH", 1, 1);
	int lines = atoi(getenv("LINES"));
	int columns = atoi(getenv("COLUMNS"));
	if (system("CLS"))
		system("clear");
	for (int n = 1; n < lines; n++)
		cout << "\n";
}

void Llist::DisplayBottomHelp() {
	printf("\033[%d;%dH", 1, 1);
	int lines = atoi(getenv("LINES"));
	int columns = atoi(getenv("COLUMNS"));

	if (system("CLS"))
		system("clear");
	for (int n = 1; n < lines - 4; n++)
		cout << "\n";
	for (int n = 1; n < columns; n++)
		cout << "-";

	cout << "\n";
	cout << " I <linenum>: insert a line;\t D <linenum>: delete a line;\n";
	cout << " C <linenum>: copy a line to clipboard;\t P <linenum>: paste a line from clipboard;\n";
	cout << " L : list all lines;\t H : print help;\t E : to exit";
	printf("\033[%d;%dH", 1, 1);
}

// Performs the rest of the program. Awating user input and
//              performs the tasks input by the user. Editing the text as desired.
void Llist::Action() {
	char input;
	int LineNum;
	string Line, NEWstring;
	string cpy;

	Help();

	cout << "> ";
	input = Read_char();

	while (input != 'E') {
		LineNum = 0;
		// User wants to input text at a specific line.
		if (input == 'I' || input == 'i') {
			char Test = cin.get();

			if (Test == '\n') {
				cout << "> ";
				getline(cin, Line);
				InsertTail(Line);
			}
			else {
				if (Test == ' ') {
					cin >> LineNum;

					if (LineNum <= 0) {
						cout << "> Invalid Line Number.\n";
						cin.ignore(256, '\n');
					}
					else {
						cin.ignore(1);
						cout << "> ";
						getline(cin, Line);

						if (LineNum == Size + 1) {
							InsertTail(Line);
						}
						else {
							if (Line != "") {
								InsertAt(LineNum, Line);
							}
						}
					}
				}
				else {
					cout << "> Invalid Command.\n";
				}
			}
			Size = Length();
		}

		// User wants to delete the desired line of text.
		else if (input == 'D' || input == 'd') {
			char Test = cin.get();

			if (Test == '\n') {
				cout << "> Invalid Command.\n";
			}
			else {
				if (Test == ' ') {
					cin >> LineNum;

					if (LineNum > Size || LineNum <= 0) {
						cout << "> Invalid Line Number.\n";
						cin.ignore(256, '\n');
					}
					else {
						Delete(LineNum);
					}
				}
				else {
					cout << "> Invalid Command.\n";
				}
			}

			Size = Length();
		}

		// User wants to copy a line.
		else if (input == 'C' || input == 'c') {
			char Test = cin.get();

			if (Test == '\n') {
				cout << "> Invalid Command.\n";
			}
			else {
				if (Test == ' ') {
					cin >> LineNum;

					if (LineNum > Size || LineNum <= 0) {
						cout << "> Invalid Line Number.\n";
						cin.ignore(256, '\n');
					}
					else {
						cpy = Copy(LineNum);
					}
				}
				else {
					cout << "> Invalid Command.\n";
				}
			}

			Size = Length();
		}

		// User wants to paste a line.
		else if (input == 'P' || input == 'p') {
			char Test = cin.get();

			if (Test == '\n') {
				cout << "> Invalid Command.\n";
			}
			else {
				if (Test == ' ') {
					cin >> LineNum;

					if (cpy == "") {
						cout << "> Cannot paste when nothing has been copied.\n";
						cin.ignore(256, '\n');
					}
					else {
						if (LineNum <= 0) {
							cout << "> Invalid Line Number.\n";
							cin.ignore(256, '\n');
						}
						else {
							if (LineNum == Size + 1) {
								InsertTail(cpy);
							}
							else {
								InsertAt(LineNum, cpy);
							}
						}
					}
				}
				else {
					cout << "> Invalid Command.\n";
				}
			}
			Size = Length();
		}

		// User wants to print the text on screen.
		else if (input == 'L' || input == 'l') {
			if (cin.get() != '\n') {
				cout << "> Invalid Entry.\n";
				cin.ignore(256, '\n');
			}
			else {
				Clear();
				DisplayBottomHelp();
				Print();
			}
		}

		// User wants the help menu displayed.
		else if (input == 'H' || input == 'h') {
			if (cin.get() != '\n') {
				cout << "> Invalid Entry.\n";
				cin.ignore(256, '\n');
			}
			else {
				Help();
			}
		}

		else {
			cout << "> Invalid Command.\n";
			cin.ignore(256, '\n');
		}
		cout << "> ";
		input = Read_char();
	}

	if (system("CLS")) system("clear");
	printf("\033[%d;%dH", 1, 1);
	Save("Output.txt");
	cout << "\nThank you for using! GOODBYE!\n";
}

// Reads text from a file and creates a linked list.
void Llist::Initalize(char* fileName) {
	string line;
	ifstream myfile(fileName);

	listnode* temp;

	if (!myfile.eof()) {
		while (getline(myfile, line)) {
			temp = new listnode;
			temp->text = line;
			temp->next = NULL;
			if (head == NULL) {
				head = temp;
			}
			else
				tail->next = temp;

			tail = temp;
		}
	}
	else cout << "Unable to open file.\n";

	Size = Length();
}

// Deletes all the current text in the linked list.
void Llist::Clean() {
	listnode* temp;

	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

// Prints the help menu display.
void Llist::Help() {
	int lines = atoi(getenv("LINES"));
	int columns = atoi(getenv("COLUMNS"));

	if (system("CLS"))
		system("clear");

	printf("\033[%d;%dH", lines - 14, 1);
	cout << "---------------------------------------------------------------------------------------------\n";
	cout << "Welcome to the text editor!\n";
	cout << "\tTo insert text at the end of the file, type 'I' and then the\n";
	cout << "\t\ttext to be inserted.\n";
	cout << "\tTo insert text at a certain line number, type 'I', a space,\n";
	cout << "\t\tand the desired line number then followed by the text.\n";
	cout << "\tTo copy a line to clipboard, type 'C' followed by a space\n";
	cout << "\t\tand the line number.\n";
	cout << "\tTo paste a line, type 'P' followed by a space and the line number.\n";
	cout << "\tTo delete a line, type 'D'.\n";
	cout << "\tTo print all the lines, type 'L'.\n";
	cout << "\tTo exit, type 'E'.\n";
	cout << "\tTo display this menu again, type 'H'.\n";
	cout << "---------------------------------------------------------------------------------------------\n";
	printf("\033[%d;%dH", 1, 1);
}

// Prints the current text in the linked list.
void Llist::Print() {
	listnode* temp = head;
	int i = 1;

	while (temp != NULL) {

		cout << i << "> " << temp->text << endl;
		temp = temp->next;
		i++;
	}
}

// Copies text from a desired valid line.
string Llist::Copy(int Line) {
	string cText;
	listnode* temp = head;

	for (int i = 1; i < Line; i++) {
		temp = temp->next;
	}

	cText = temp->text;

	return cText;
}

// Inserts another line of text at the end of the linked list.
void Llist::InsertTail(string thing) {
	listnode* temp;

	temp = new listnode;
	temp->text = thing;
	temp->next = NULL;

	if (head == NULL)
		head = temp;
	else
		tail->next = temp;

	tail = temp;
}

// Insert a new line of text at desired line in the linked list.
void Llist::InsertAt(int Num, string Line) {
	listnode* NEWtext = new listnode;
	listnode* curr = new listnode;
	listnode* prev = new listnode;

	int tempPos = 1;

	NEWtext->text = Line;
	curr = head;

	if (head != NULL) {
		while (curr->next != NULL && tempPos != Num) {
			prev = curr;
			curr = curr->next;
			tempPos++;
		}
		if (Num == 1) {
			NEWtext->next = head;
			head = NEWtext;
		}
		if (curr->next == NULL && Num == tempPos + 1) {
			InsertTail(Line);
		}
		if (curr->next == NULL && Num > tempPos) {
			while (Num > tempPos + 1) {
				InsertTail("");
				tempPos++;
			}
			InsertTail(Line);
		}
		else {
			prev->next = NEWtext;
			NEWtext->next = curr;
		}
	}
}

// Delete desired line of text at the desired line in the linked list.
void Llist::Delete(int num) {
	listnode* temp = head;
	listnode *D = new listnode;

	if (num == 1) {
		head = head->next;
		delete temp;
	}
	else {
		for (int i = 0; i < num - 1; i++) {
			D = temp;
			temp = temp->next;
		}
		D->next = temp->next;
	}

}

// Determines the number of lines in the text.
int Llist::Length() {
	listnode* curr = new listnode;
	int count = 1;

	curr = head;

	while (curr->next != NULL) {
		curr = curr->next;
		count++;
	}
	return count;
}

// Saves the current edited text list to an output file.
void Llist::Save(const char* fileName)
{
	fstream fout;
	listnode* temp = head;
	fout.open(fileName, ios::out);
	if (temp != NULL)
	{
		while (temp != NULL)
		{
			// Output each line to file.
			fout << temp->text << endl;
			temp = temp->next;
		}
	}
	fout.close();
}

// Character input data validation.
char Llist::Read_char() {
	char Val;

	cin >> Val;
	while (!cin.good()) {
		cout << "> Invalid entry, try again.\n";
		cin.clear();
		cin.ignore(256, '\n');
		cout << "> ";
		cin >> Val;
	}
	return Val;
}
