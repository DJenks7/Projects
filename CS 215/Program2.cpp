/*
Dylan Jenkins           12/3/2013
Program2.cc
This program is designed to display a current message and await
a command from the user (entering 'h') for help. Entering 'h'
will display the command menu.
'm' to enter a new message.
'c' to encrypt via the Caesar Cipher.
'C' to decrypt via the Caesar Cipher.
'v' to encrypt via the Vigenere Cipher.
'V' to decrypt via the Vigenere Cipher.
'h' to display help menu.
'q' to quit.
The general purpose of this program is to take a message entered
by the user and encrypt or decrypt the message.
*/
#include "stdafx.h"
#include <iostream>
#include <cstring>
#undef NULL

using namespace std;

const int NULL = 0;             // Constant of NULL or empty.
typedef char element;           // New typedef of characters.
const element SENTINEL = '\n';  // Sentinel value to exit loops is a new line.

								// Class listnode, contains an element called data and
								//      a listnode pointer called next.
class listnode {
public:
	element data;
	listnode * next;
};

// Class Llist, contains constructor and destructor,
//      two listnode pointers called head and tail, and methods
//      Action, Message, Duplicate, InsertTail, Clean, Help, Print,
//      Read, CaesarEncrypt, CaesarDecrypt, VigenereEncrypt, and
//      VigenereDecrypt.
class Llist {
public:
	Llist();
	~Llist();
	listnode * head;
	listnode * tail;
	void Action();                  // Holds loop to keep awaiting
									// input from user and menu displaying

	void Message();                 // Holds users Current Message and
									// asks for user input.

	void Duplicate(Llist & Source); // Duplicates the contents of Llist.

	void InsertTail(element thing); // Inserts a new tail into the list.
private:
	void Clean();           // Emptys the data in the list.

	void Help();            // Displays the menu.

	void Print();           // Prints the contents of Llist.

	void Read();            // Reads a new message to become
							// the Current Message.

	void CaesarEncrypt();   // Code to encrypt the Current Message
							// via the Caesar Encryption.

	void CaesarDecrypt();   // Code to decrypt the Current Message
							// via the Caesar Decryption.

	void VigenereEncrypt(); // Code to encrypt the Current Message
							// via the Vigenere Encryption.

	void VigenereDecrypt(); // Code to decrypt the Current Message
							// via the Vigenere Decryption.
};

int Read_int();         // Reads integer and validates entry.

element Read_element(); // Reads element and validates entry.

int main() {
	Llist A;        // Creates Llist object called A.

	A.Action();     // Calls Action method in Llist object A.
}

Llist::Llist() {
	//PRE: None.
	//POST: The N.O. is valid and empty.
	head = NULL;
}

Llist::~Llist() {
	//PRE: N.O. is valid.
	//POST: N.O. is still valid and is empty.
	//      Memory has been returned to heap.
	Clean();
}

void Llist::Action() {
	//PRE: N.O. is valid.
	//POST: The program has been run, the current message
	//      has been displayed at least once. The user has entered
	//      q to exit the program.
	element action;

	Message();              // Prints the Current Message before
							// awaiting user input.

	action = Read_element();

	// While user entry is not 'q'.
	while (action != 'q') {
		// User wants to enter a new Current Message.
		if (action == 'm') {
			Read();
			Message();
		}
		// User wants to Encrypt via Caesar Cipher.
		if (action == 'c') {
			cout << endl << "Caesar Cipher Encrypt." << endl;
			CaesarEncrypt();
			Message();
		}
		// User wants to Decrypt via Caesar Cipher.
		if (action == 'C') {
			cout << endl << "Caesar Cipher Decrypt." << endl;
			CaesarDecrypt();
			Message();
		}
		// User wants to Encrypt via Vigenere Cipher.
		if (action == 'v') {
			cout << endl << "Vignere Cipher Encrypt." << endl;
			VigenereEncrypt();
			Message();
		}
		// User wants to Decrypt via Vigenere Cipher.
		if (action == 'V') {
			cout << endl << "Vignere Cipher Decrypt." << endl;
			VigenereDecrypt();
			Message();
		}
		// User wants help (Menu displayed).
		if (action == 'h') {
			Help();
			Message();
		}
		action = Read_element();
	}
}

void Llist::CaesarEncrypt() {
	//PRE: N.O. is valid.
	//POST: N.O.'s listnodes have been encrypted by the Key entered
	//      by the user. PlainText, Key, and CipherText have been displayed.
	//      Llist Cipher and OldText has been used and properly disposed of.
	int Key = 0;
	listnode * temp;
	Llist OldText;

	OldText.Duplicate(*this);

	temp = head;

	// Obtain Key.
	cout << "Enter Key (between 1-26): ";
	cin.ignore(80, '\n');
	Key = Read_int();

	// Check validation of Key.
	while ((Key <= 0) || (Key > 26)) {
		cout << "Invalid Key, try again." << endl;
		cout << "Enter Key: ";
		cin.ignore(80, '\n');
		Key = Read_int();
	}

	// While there is still data, encrypt via Key.
	while (temp != NULL) {
		int item = (temp->data);

		if (item >= 65 && item <= 90) {
			item += Key;

			if (item > 90)
				item -= 26;
		}

		if (item >= 97 && item <= 122) {
			item += Key;

			if (item > 122)
				item -= 26;
		}
		(temp->data) = item;

		temp = temp->next;
	}

	// Displays PlainText, Key, and CipherText.
	cout << endl << "Plain Text: ";
	OldText.Print();
	cout << endl << "Key: " << Key << endl;
	cout << "Cipher Text: ";
	Print();
	cout << endl << endl << "Caesar Encryption Complete." << endl;
}

void Llist::CaesarDecrypt() {
	//PRE: N.O. is valid.
	//POST: N.O.'s listnodes have been decrypted by the Key entered
	//      by the user. CipherText, Key, and PlainText have been displayed.
	//      Llist Cipher and OldText has been used and properly disposed of.
	int Key = 0;
	listnode * temp;
	Llist OldText;

	OldText.Duplicate(*this);

	temp = head;

	// Obtain Key.
	cout << "Enter Key: ";
	cin.ignore(80, '\n');
	Key = Read_int();

	// Checks validation of Key.
	while ((Key <= 0) || Key > 26) {
		cout << "Invalid Key, try again." << endl;
		cout << "Enter Key: ";
		cin.ignore(80, '\n');
		Key = Read_int();
	}

	// While there is still data, decrypt via Key.
	while (temp != NULL) {
		int item = (temp->data);

		if (item >= 65 && item <= 90) {
			item -= Key;

			if (item < 65)
				item += 26;
		}

		if (item >= 97 && item <= 122) {
			item -= Key;

			if (item < 97)
				item += 26;
		}
		(temp->data) = item;

		temp = temp->next;
	}

	// Displays CipherText, Key, and PlainText.
	cout << endl << "Cipher Text: ";
	OldText.Print();
	cout << endl << "Key: " << Key << endl;
	cout << "Plain Text: ";
	Print();
	cout << endl << endl << "Caesar Decryption Complete." << endl;
}

void Llist::Clean() {
	//PRE: N.O. is valid.
	//POST: N.O. is still valid and is empty.
	//      Memory has been returned to heap.
	listnode * temp;

	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

void Llist::Duplicate(Llist & Source) {
	//PRE: N.O. and Source are valid.
	//POST: N.O. Llist's original listnodes have been
	//      cleaned, and N.O. Llist is now a listnode
	//      by listnode copy of the Source Llist.
	//      Source Llist is unchanged.
	listnode * temp;

	Clean();
	temp = Source.head;
	while (temp != NULL) {
		InsertTail(temp->data);
		temp = temp->next;
	}
}

void Llist::Help() {
	//PRE: None.
	//POST: Help menu has been displayed.

	cout << endl << "Valid commands are:" << endl;
	cout << "m      enter a new current message from the keyboard." << endl;
	cout << "c      encrypt the current message using the Caesar Cipher."
		<< endl;
	cout << "C      decrypt the current message using the Caesar Cipher."
		<< endl;
	cout << "v      encrypt the current message using the Vigenere Cipher."
		<< endl;
	cout << "V      decrypt the current message using the Vignere Cipher."
		<< endl;
	cout << "h      show this help menu." << endl;
	cout << "q      quit the program." << endl;
}

void Llist::InsertTail(element thing) {
	//PRE: N.O. and thing are valid.
	//POST: N.O. is unchanged except it has 1 new listnode
	//      at tail end, containing element thing.
	listnode * temp;

	temp = new listnode;
	temp->data = thing;
	temp->next = NULL;

	if (head == NULL)
		head = temp;
	else
		tail->next = temp;

	tail = temp;
}

void Llist::Message() {
	//PRE: None.
	//POST: Current message has been displayed.
	//              Waiting on user input.
	cout << endl << "Current Message: \"";
	Print();
	cout << "\"." << endl << endl;
	cout << "Command (h for help): ";
}

void Llist::Print() {
	//PRE: N.O. Llist is valid.
	//POST: N.O. is unchanged and its elements have been displayed.
	listnode * temp;
	temp = head;

	while (temp != NULL) {
		cout << temp->data;
		temp = temp->next;
	}
}

void Llist::Read() {
	//PRE: N.O. Llist is valid.
	//POST: N.O. is still valid, using data entered by the user
	//              and elements will be in order entered.
	element User_Val;
	listnode * temp;

	Clean();
	cout << endl << "Use Enter/Return button to submit." << endl;
	cout << "Enter text: ";
	cin.ignore(80, '\n');

	User_Val = Read_element();

	// While user entry is not a new line (Enter Key).
	while (User_Val != SENTINEL) {
		temp = new listnode;
		temp->data = User_Val;
		temp->next = NULL;
		if (head == NULL)
			head = temp;
		else
			tail->next = temp;

		tail = temp;
		User_Val = Read_element();
	}
	cout << endl << "Message Accepted." << endl;
}

void Llist::VigenereEncrypt() {
	//PRE: N.O. is valid.
	//POST: N.O.'s listnodes have been encrypted by the Key entered
	//      by the user. PlainText, Key, and CipherText have been displayed.
	//      Llist Cipher and OldText has been used and properly disposed of.
	int Key = 0;
	listnode * temp;
	listnode * temp2;

	Llist Cipher;
	Llist OldText;

	OldText.Duplicate(*this);

	cout << endl << "Enter Key..." << endl;
	Cipher.Read();

	temp = head;
	temp2 = Cipher.head;

	while (temp != NULL) {
		int item = (temp->data);
		int item2 = (temp2->data);

		while (item2 == NULL) {
			temp2 = temp2->next;

			item2 = temp2->data;
		}

		if (item2 == 97 || item2 == 65) {
			Key = 1;
		}
		if (item2 == 98 || item2 == 66) {
			Key = 2;
		}
		if (item2 == 99 || item2 == 67) {
			Key = 3;
		}
		if (item2 == 100 || item2 == 68) {
			Key = 4;
		}
		if (item2 == 101 || item2 == 69) {
			Key = 5;
		}
		if (item2 == 102 || item2 == 70) {
			Key = 6;
		}
		if (item2 == 103 || item2 == 71) {
			Key = 7;
		}
		if (item2 == 104 || item2 == 72) {
			Key = 8;
		}
		if (item2 == 105 || item2 == 73) {
			Key = 9;
		}
		if (item2 == 106 || item2 == 74) {
			Key = 10;
		}
		if (item2 == 107 || item2 == 75) {
			Key = 11;
		}
		if (item2 == 108 || item2 == 76) {
			Key = 12;
		}
		if (item2 == 109 || item2 == 77) {
			Key = 13;
		}
		if (item2 == 110 || item2 == 78) {
			Key = 14;
		}
		if (item2 == 111 || item2 == 79) {
			Key = 15;
		}
		if (item2 == 112 || item2 == 80) {
			Key = 16;
		}
		if (item2 == 113 || item2 == 81) {
			Key = 17;
		}
		if (item2 == 114 || item2 == 82) {
			Key = 18;
		}
		if (item2 == 115 || item2 == 83) {
			Key = 19;
		}
		if (item2 == 116 || item2 == 84) {
			Key = 20;
		}
		if (item2 == 117 || item2 == 85) {
			Key = 21;
		}
		if (item2 == 118 || item2 == 86) {
			Key = 22;
		}
		if (item2 == 119 || item2 == 87) {
			Key = 23;
		}
		if (item2 == 120 || item2 == 88) {
			Key = 24;
		}
		if (item2 == 121 || item2 == 89) {
			Key = 25;
		}
		if (item2 == 122 || item2 == 90) {
			Key = 26;
		}

		if (Key != 0) {
			if (item >= 65 && item <= 90) {
				item += Key;

				if (item > 90)
					item -= 26;

				(temp->data) = item;
			}

			if (item >= 97 && item <= 122) {
				item += Key;

				if (item > 122)
					item -= 26;

				(temp->data) = item;
			}
		}
		temp = temp->next;
	}
	// Displays PlainText, Key, and CipherText.
	cout << endl << "Plain Text: ";
	OldText.Print();
	cout << endl << "Key: ";
	Cipher.Print();
	cout << endl << "Cipher Text: ";
	Print();
	cout << endl << endl << "Vigenere Encryption Complete." << endl;
}

void Llist::VigenereDecrypt() {
	//PRE: N.O. is valid.
	//POST: N.O.'s listnodes have been decrypted by the Key entered
	//      by the user. CipherText, Key, and PlainText have been displayed.
	//      Llist Cipher and OldText has been used and properly disposed of.
	int Key = 0;
	listnode * temp;
	listnode * temp2;

	Llist Cipher;
	Llist OldText;

	OldText.Duplicate(*this);

	temp = head;

	cout << "Enter Key..." << endl;
	Cipher.Read();

	temp2 = Cipher.head;

	while (temp != NULL) {
		int item = (temp->data);
		int item2 = (temp2->data);

		while (item2 == NULL) {
			temp2 = temp2->next;

			item2 = temp2->data;
		}

		if (item2 == 97 || item2 == 65) {
			Key = 1;
		}
		if (item2 == 98 || item2 == 66) {
			Key = 2;
		}
		if (item2 == 99 || item2 == 67) {
			Key = 3;
		}
		if (item2 == 100 || item2 == 68) {
			Key = 4;
		}
		if (item2 == 101 || item2 == 69) {
			Key = 5;
		}
		if (item2 == 102 || item2 == 70) {
			Key = 6;
		}
		if (item2 == 103 || item2 == 71) {
			Key = 7;
		}
		if (item2 == 104 || item2 == 72) {
			Key = 8;
		}
		if (item2 == 105 || item2 == 73) {
			Key = 9;
		}
		if (item2 == 106 || item2 == 74) {
			Key = 10;
		}
		if (item2 == 107 || item2 == 75) {
			Key = 11;
		}
		if (item2 == 108 || item2 == 76) {
			Key = 12;
		}
		if (item2 == 109 || item2 == 77) {
			Key = 13;
		}
		if (item2 == 110 || item2 == 78) {
			Key = 14;
		}
		if (item2 == 111 || item2 == 79) {
			Key = 15;
		}
		if (item2 == 112 || item2 == 80) {
			Key = 16;
		}
		if (item2 == 113 || item2 == 81) {
			Key = 17;
		}
		if (item2 == 114 || item2 == 82) {
			Key = 18;
		}
		if (item2 == 115 || item2 == 83) {
			Key = 19;
		}
		if (item2 == 116 || item2 == 84) {
			Key = 20;
		}
		if (item2 == 117 || item2 == 85) {
			Key = 21;
		}
		if (item2 == 118 || item2 == 86) {
			Key = 22;
		}
		if (item2 == 119 || item2 == 87) {
			Key = 23;
		}
		if (item2 == 120 || item2 == 88) {
			Key = 24;
		}
		if (item2 == 121 || item2 == 89) {
			Key = 25;
		}
		if (item2 == 122 || item2 == 90) {
			Key = 26;
		}

		if (Key != 0) {
			if (item >= 65 && item <= 90) {
				item -= Key;

				if (item < 65)
					item += 26;

				(temp->data) = item;
			}

			if (item >= 97 && item <= 122) {
				item -= Key;

				if (item < 97)
					item += 26;

				(temp->data) = item;
			}
		}
		temp = temp->next;
	}
	// Displays PlainText, Key, and CipherText.
	cout << endl << "Plain Text: ";
	OldText.Print();
	cout << endl << "Key: ";
	Cipher.Print();
	cout << endl << "Cipher Text: ";
	Print();
	cout << endl << endl << "Vigenere Decryption Complete." << endl;
}

int Read_int() {
	int Val;

	cin >> Val;
	while (!cin.good()) {
		cout << "Invalid integer, try again." << endl;
		cin.clear();
		cin.ignore(80, '\n');
		cin >> Val;
	}
	return Val;
}

element Read_element() {
	element Val;

	Val = cin.get();
	return Val;
}


