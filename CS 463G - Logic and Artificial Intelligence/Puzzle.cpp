/*--------------------------------------------------------------------------------------------------------------------------------------------
Dylan Jenkins					Puzzle.cpp
8/27/16							CS 463G
	INCOMPLETE
Atomic Chaos Puzzle. The objective is to, once reset, try to get all the six's into the tube that has six places.
Then all the 5's into the tube that has five places, and so on and so on until they are all in their respective tubes.
----------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include<stdlib.h>
#include<string>
#include<stack>
using namespace std;

// Tube structure to contain the data for the current puzzle state.
struct Tube {
	stack<int> Game_Tube;			// Stack to hold the contents of the tube.
	int size;						// Integer to hold the size of the tube.

	Tube* next;						// Tube pointer, points to the corresponding tube connected tube.

	Tube(int s, int v);				// Constructor for Tube struct.
	~Tube();						// Destructor for the Tube struct.
};



// Creates and array of Pipe object to contain the Atomic Chaos Puzzle.
// Where 0's are blank or open spaces. Objective being to get all 6's into the tube of size 6,
// 5 into the tube of size 5, and so on...
Tube *Pipe[12] = { new Tube(6, 6), new Tube(5, 5), new Tube(4, 4), new Tube(3, 3),
					new Tube(2, 2), new Tube(1, 1), new Tube(6, 0), new Tube(5, 0),
					new Tube(4, 0), new Tube(3, 0), new Tube(2, 0), new Tube(1, 0) };

int i = 5, j = 11;					// Integers to hold count data for turn functions.
bool G = true;						// bool value to represent Gravity.
string Command;						// String to hold the command to be entered by the user.

void Action();						// Function that prints valid commands, calls Print and awaits input Command.
void Clockwise();					// Function to turn the puzzle clockwise.
void Counter_Clockwise();			// Function to turn the puzzle counter clockwise.
void Flip(Tube *Flip_Pipe[]);						// Function to flip the puzzle and act as gravity shifting the balls accordingly.
void Reset(int x);					// Funtion to randomize/reset the puzzle.
void PrintAll();					// Function to print all puzzle tubes/pipes.
void Print(Tube *Print_Tube);		// Function to prints the Tube passed into Print as a parameter.
void Initialize();					// Function simply to initialize all Pipe objects.
bool Solved();						// INCOMPLETE: Function was intended to be used to check if a puzzle state is solved.
									//				Would have been used for the search for a solved state.

int main() {
	bool Quit = false;				// Bool value to determine when the user has requested to Quit.
	int moves;						// Integer to hold the number of moves for the Reset function.

	Initialize();

	cout << "Welcome to the Atomic Chaos Puzzle!\n";
	cout << "Objective: To get all the numbers back into their corresponding tube.\n";
	cout << "\t\tFinished state is displayed. Type 'r' or 'R' to reset and begin!\n\n";
	cout << "\tNOTE: 0's = Blank/Open spots.\n\n";
	cout << "Enter a command to perform an operation.\n";
	while (Quit == false) {
		Action();

		if (Command == "Cl" || Command == "cl" || Command == "CL" || Command == "cL") {
			cin.ignore(256, '\n');
			Clockwise();
		}
		else if (Command == "Cc" || Command == "cc" || Command == "CC" || Command == "cC") {
			cin.ignore(256, '\n');
			Counter_Clockwise();
		}
		else if (Command == "F" || Command == "f") {
			cin.ignore(256, '\n');
			Flip(Pipe);
		}
		else if (Command == "R" || Command == "r") {
			cin.ignore(256, '\n');
			cout << "Enter number between 10-20\n";
			cin >> moves;
			if (moves >= 10 && moves <= 20) {
				Reset(moves);
			}
			else {
				cout << "\n-------------------------------------------------";
				cout << "\nInvalid Number. Try again.\n";
				cout << "-------------------------------------------------\n\n";
			}
		}
		else if (Command == "Q" || Command == "q") {
			Quit = true;
		}
		else {
			cout << "\n-------------------------------------------------";
			cout << "\nInvalid Command. Try again.\n";
			cout << "-------------------------------------------------\n\n";
		}
	}
	return 0;
}

// Display valid commands, prints the current puzzle state, and awaits input.
void Action() {
	cout << "\nValid Commands:\nEnter 'F' to Flip the puzzle, 'Cl' for a Clockwise turn, 'Cc' for a Counter Clockwise turn,\n";
	cout << "\t'R' to reset, or 'Q' to Quit.\n\n";

	// Display Initial finished state and await command.
	PrintAll();

	cout << "\nCommand: ";
	cin >> Command;
}

// Randomizer/Reset to generate a random move x times.
void Reset(int x) {
	/*	INCORRECT METHOD
	for (int i = 0; i < x; i++) {
		int z = rand() % 3 + 1;

		if (z == 1) {
			Clockwise();
		}
		if (z == 2) {
			Flip();
		}
		if (z == 3) {
			Counter_Clockwise();
		}
	}
	*/
}

// BUG: When changing direction. It moves two tubes..? Logic error I cannot seem to find...
// Rotates the puzzle clockwise.
void Clockwise() {
	int count = 1;				// Simple counter value. Counts 1-6.

	for (i, j, count; count < 6; count++, i--, j--) {
		if (i - 1 < 0) {
			i = 5;
		}
		if (j < 6) {
			j = 11;
		}
		Pipe[i - 1]->next = Pipe[j];
	}

	if (j < 6) {
		j = 11;
	}

	Pipe[5]->next = Pipe[j];
	Pipe[j]->next = Pipe[5];
}

// Rotates the puzzle counter clockwise.
void Counter_Clockwise() {
	int count = 1;				// Simple counter value. Counts 1-6.

	for (i, j, count; count < 6; count++, i++, j++) {
		if (i + 1 > 5) {
			i = 0;
		}
		if (j > 11) {
			j = 6;
		}
		Pipe[i + 1]->next = Pipe[j];
	}

	if (j > 11) {
		j = 6;
	}

	Pipe[0]->next = Pipe[j];
	Pipe[j]->next = Pipe[0];
}

// Flips the puzzle and moves the "balls" or numbers
// in the tube/pipe corresponding to the value of G.
void Flip(Tube *Flip_Pipe[]) {
	G = !G;
	int k, l = 0;
	int Pop[12];
	// CODE TO ACT AS GRAVITY AND MOVE BALLS ACCORDINGLY
	// UNFINISHED :(
	// Idea was to top() each Tube one at a time and if the element is a 0, then pop it out of the Tube.
	// Once this is finished pop out the balls in the respective Tubes and push them into the "empty" Tube Tube.size times.
	// If we run across a numbered ball in the Tube of 0's stop, obtain the size of the tube and save it in an integer and 
	// then push the numbered balls in until some integer is Tube.size.
	for (k = 1; k > Flip_Pipe[0]->size; k++) {
		if (Flip_Pipe[0]->Game_Tube.top() == 0) {
			Pop[l] = Flip_Pipe[0]->Game_Tube.pop();
			l++;
		}
	}

	// CHECK LEFT TUBE FOR NUMBERS, IF ZEROS DO NOTHING, POP NUMBERS OUT OF RIGHT TUBE, PUSH THE POPPED NUMBERS
	// BACK INTO RIGHT TUBE UNTIL SIZE, IF REMAINING NUMBERS EXIST, PUSH INTO LEFT TUBE.

	// EDIT TO TURNING FUNCTIONS... PULL BALLS FROM LEFT TUBE INTO RIGHT TUBE IF RIGHT TUBE IS NOT FULL.
}

// Prints all tubes/pipes.
void PrintAll() {
	cout << "--------------------------\n";
	Print(Pipe[0]->next);
	Print(Pipe[0]);
	cout << "\n";

	cout << "  ";
	Print(Pipe[1]->next);
	Print(Pipe[1]);
	cout << "\n";

	cout << "    ";
	Print(Pipe[2]->next);
	Print(Pipe[2]);
	cout << "\n";

	cout << "      ";
	Print(Pipe[3]->next);
	Print(Pipe[3]);
	cout << "\n";

	cout << "        ";
	Print(Pipe[4]->next);
	Print(Pipe[4]);
	cout << "\n";

	cout << "          ";
	Print(Pipe[5]->next);
	Print(Pipe[5]);
	cout << "\n";
	cout << "--------------------------\n";
}

// Prints a single tube/pipe.
void Print(Tube *Print_Tube) {
	stack<int> p;
	stack<int> dump = Print_Tube->Game_Tube;

	// Reverse's the stack printing process to print in the correct order.
	if (Print_Tube->size > 5) {
		for (int q = 0; q < Print_Tube->size; q++) {
			p.push(dump.top());
		}
		for (p; !p.empty(); p.pop()) {
			cout << p.top() << ' ';
		}
	}
	// Otherwise, prints the stack normally.
	else {
		for (dump; !dump.empty(); dump.pop())
			cout << dump.top() << ' ';
	}
}

// Initalizes pointers to their corresponding tube/pipe.
void Initialize() {
	Pipe[0]->next = Pipe[6];
	Pipe[1]->next = Pipe[7];
	Pipe[2]->next = Pipe[8];
	Pipe[3]->next = Pipe[9];
	Pipe[4]->next = Pipe[10];
	Pipe[5]->next = Pipe[11];

	Pipe[6]->next = Pipe[0];
	Pipe[7]->next = Pipe[1];
	Pipe[8]->next = Pipe[2];
	Pipe[9]->next = Pipe[3];
	Pipe[10]->next = Pipe[4];
	Pipe[11]->next = Pipe[5];
}

bool Solved()
{
	return false;
}

// Tube Constructor.
Tube::Tube(int s, int v) {
	size = s;

	for (int i = 1; i < s + 1; i++) {
		Game_Tube.push(v);
	}
	s--;
}

// Tube Destructor.
Tube::~Tube() {
	delete next;
}