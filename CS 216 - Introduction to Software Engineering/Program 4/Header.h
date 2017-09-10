/*------------------------------------------------------------------------------------------
CS 216	005		12/5/15
Program Assignment 4
Header.h

This program is designed to, when ran, display a menu for the user and await input.
The menu requires the user to input menu option 1 first in order to have the user input
an infix expression to build our tree. Once this has been done the user can input
any option. Inputting a 2 will display the tree with a prefix expression.
Inputting a 3 will display the tree with an infix expression and 4 does this
with a postfix expression. Inputting a 5 will evaluate the expression.

Dylan Jenkins
--------------------------------------------------------------------------------------------*/
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <stack>
using namespace std;

struct TreeNode {
public:
	TreeNode(string k) { key = k; left = right = NULL; }
	friend class ParseTree;
private:
	string key;				// String to hold the key value in the tree.
	TreeNode* left;			// TreeNode to hold the left subtree.
	TreeNode* right;		// TreeNode to hold the right subtree.
};

class ParseTree {
public:
	ParseTree();			// Constructor.
	~ParseTree();			// Destructor.

	void Menu();			// Function to display the menu.
	void Action();			// Function to perform the bulk of the program.
							//		To loop until the user inputs a 6.
	void CleanTree();		// Function to clean the tree, calls the other CleanTree function.

	void buildTree(string E);		// Function to build the tree from the string input by the user.

	TreeNode* build(vector<string> E, int left, int right);		// Function build calls buildTree to help build the tree.

private:
	TreeNode* root;					// TreeNode holds the root value of the current tree/subtree.
	vector<string> Expression;		// Vector to hold the original input from the user for reference.

	int Read_Int();					// Function to validate the integer menu input from user.

	int findPlusMinus(vector<string> E, int left, int right);
	int findMulDiv(vector<string> E, int left, int right);

	int eval(int num1, string oper, int num2);		// Function to help evaluate the expression.
	string postOrderTraversal(TreeNode* ptr);		// Function to create a string in Postfix form.
	bool isOperator(string e);						// Function to check if there is an operator.
	bool isDigit(string e);							// Function to check if there is a digit.
	void Calculate();								// Function to begin the calculate process.

	void CleanTree(TreeNode* temp);		// Function to clean the tree.
	void Print(vector<string> E);		// Function to print the current expression given from the user.
	bool Validate(vector<string> E);

	void Prefix(TreeNode* localRoot);	// Function to print the prefix expression.
	void Infix(TreeNode* localRoot);	// Function to print the infix expression.
	void Postfix(TreeNode* localRoot);	// Function to print the postfix expression.
};

// Constructor.
ParseTree::ParseTree() {
	root = NULL;
}

// Function used to clean the tree object.
void ParseTree::CleanTree(TreeNode* temp) {
	if (temp != NULL) {
		CleanTree(temp->left);
		CleanTree(temp->right);
		delete temp;
	}
}

// Function used to call the CleanTree function with a parameter of root. 
// Cannot call without first being in the object first.
void ParseTree::CleanTree() {
	CleanTree(root);
}

// Destructor.
ParseTree::~ParseTree() {
	CleanTree();
}

// Function to display the action menu.
void ParseTree::Menu() {
	cout << "****************************************************\n";
	cout << "SELECTIONS:\n";
	cout << "1. Read an expression.\n";
	cout << "2. Display the prefix expression.\n";
	cout << "3. Display the infix expression.\n";
	cout << "4. Display the postfix expression.\n";
	cout << "5. Evaluate the expression usng postfix notation.\n";
	cout << "6. Exit.\n";
	cout << "****************************************************\n";
	cout << "Select: ";
}

// Function to build the Tree.
void ParseTree::buildTree(string E) {
	// Converts string into a vector.
	stringstream ss(E);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> vstrings(begin, end);
	// End conversion.

	Expression = vstrings;

	root = build(vstrings, 0, vstrings.size() - 1);
}

// Function to help build the tree.
TreeNode* ParseTree::build(vector<string> E, int left, int right) {
	if (left == right) {
		return (new TreeNode(E[left]));
	}
	TreeNode *T;
	int loc = findPlusMinus(E, left, right);
	if (loc != -1) {
		if (E[loc] == "+")
			T = new TreeNode("+");
		else
			T = new TreeNode("-");

		T->left = build(E, left, loc - 1);
		T->right = build(E, loc + 1, right);
		return T;
	}
	loc = findMulDiv(E, left, right);
	if (loc != -1) {
		if (E[loc] == "*")
			T = new TreeNode("*");
		else
			T = new TreeNode("/");

		T->left = build(E, left, loc - 1);
		T->right = build(E, loc + 1, right);
		return T;
	}
	return build(E, left + 1, right - 1);
}

int ParseTree::findPlusMinus(vector<string> E, int left, int right) {
	int parenCnt = 0, loc = right;

	while (loc >= left) {
		if (E[loc] == ")")
			parenCnt++;
		else
			if (E[loc] == "(")
				parenCnt--;
			else
				if (E[loc] == "+" || E[loc] == "-")
					if (parenCnt == 0)      return loc;

		loc--;
	}
	return -1;
}

int ParseTree::findMulDiv(vector<string> E, int left, int right) {
	int parenCnt = 0, loc = right;

	while (loc >= left) {
		if (E[loc] == ")")
			parenCnt++;
		else
			if (E[loc] == "(")
				parenCnt--;
			else
				if (E[loc] == "*" || E[loc] == "/")
					if (parenCnt == 0)      return loc;

		loc--;
	}
	return -1;
}

// Function to run the Prefix expression.
void ParseTree::Prefix(TreeNode* localRoot) {
	if (localRoot != NULL) {
		cout << localRoot->key;
		cout << " ";
		Prefix(localRoot->left);
		Prefix(localRoot->right);
	}
}

// Function to run the Infix expression.
void ParseTree::Infix(TreeNode* localRoot) {
	if (localRoot != NULL) {
		Infix(localRoot->left);
		cout << localRoot->key;
		cout << " ";
		Infix(localRoot->right);
	}
}

// Function to run the Postfix expression.
void ParseTree::Postfix(TreeNode* localRoot) {
	if (localRoot != NULL) {
		Postfix(localRoot->left);
		Postfix(localRoot->right);
		cout << localRoot->key;
		cout << " ";
	}
}

// Function to act as the control and run the bulk of the program.
//              After the main funcation calls it from Program4.cpp.
void ParseTree::Action() {
	int Input;
	bool Empty = true;
	bool Valid = false;
	string Exp;

	Input = Read_Int();

	// While the user has not input 6 to exit.
	while (Input != 6) {
		// User wants to read an expression.
		if (Input == 1) {
			cout << "\nEnter an infix expression:\n";
			cin.ignore(1, '\n');
			getline(cin, Exp);

			// Converts string into a vector.
			stringstream ss(Exp);
			istream_iterator<string> begin(ss);
			istream_iterator<string> end;
			vector<string> V(begin, end);
			// End conversion.

			Valid = Validate(V);

			if (Valid == true) {
				buildTree(Exp);
			}
			else {
				cout << "Invalid Expression!\n";
			}

			Empty = false;
		}
		// If the user has first created an expression.
		if (Empty == false) {
			// User wants to see the Prefix expression.
			if (Input == 2) {
				cout << "\nExpression from user input: ";
				Print(Expression);
				cout << "\nPrefix Expression: ";
				Prefix(root);
				cout << "\n";
			}
			// User wants to see the Infix expression.
			else if (Input == 3) {
				cout << "\nExpression from user input: ";
				Print(Expression);
				cout << "\nInfix Expression: ";
				Infix(root);
				cout << "\n";
			}
			// User wants to see the Postfix expression.
			else if (Input == 4) {
				cout << "\nExpression from user input: ";
				Print(Expression);
				cout << "\nPostfix Expression: ";
				Postfix(root);
				cout << "\n";
			}
			// User wants to evaluate the expression using Postfix.
			else if (Input == 5) {
				Calculate();
			}
			else if (Input > 6 || Input <= 0) {
				cout << "Input out of range.\n";
			}
		}
		else {
			cout << "Expression from user input is empty!\n";
		}
		cout << endl;
		Menu();
		Input = Read_Int();
	}


}

// Function to check if the expression entered is valid.
//		Before the tree is created.
bool ParseTree::Validate(vector<string> E) {
	bool valid = false;
	int Count = 0;
	string O[] = { "+", "-", "*", "/" };

	if (E[E.size() - 1] == "+" || E[E.size() - 1] == "-" || E[E.size() - 1] == "*" || E[E.size() - 1] == "/") {
		valid = false;
	}
	else if (E[0] == "+" || E[0] == "-" || E[0] == "*" || E[0] == "/") {
		valid = false;
	}
	else {
		for (int i = 0; i < E.size(); i++) {
			if (E[i] == "+" || E[i] == "-" || E[i] == "*" || E[i] == "/") {
				for (int j = 0; j < 3; j++) {
					if (E[i + 1] == O[j]) {
						valid = false;
						Count = 100;
						break;
					}
				}
			}
			if (E[i] == "(")
				Count++;
			if (E[i] == ")")
				Count--;
		}

		if (Count == 0) {
			valid = true;
		}
	}
	return valid;
}

// Function to print the original expression for reference.
void ParseTree::Print(vector<string> E) {
	for (int i = 0; i < E.size(); i++) {
		cout << E[i] << " ";
	}
}

// Function to check if there is a digit.
bool ParseTree::isDigit(string e) {
	for (int i = 0; i < e.size(); i++)
	{
		if (e[i] >= '0' && e[i] <= '9')
		{

		}
		else
			return false;
	}
	return true;
}

// Function to check if there is an operator.
bool ParseTree::isOperator(string e) {
	if (e.size() == 1)
	{
		if (e[0] == '+' || e[0] == '-' || e[0] == '*' || e[0] == '/')
			return true;
	}

	return false;
}

// Function to help evaluate the expression.
int ParseTree::eval(int num1, string oper, int num2) {
	if (oper == "+")
	{
		return num1 + num2;
	}
	else if (oper == "-")
	{
		return num1 - num2;
	}
	else if (oper == "*")
	{
		return num1 * num2;
	}
	else if (oper == "/")
	{
		return num1 / num2;
	}
}

// Function to create a string in Postfix form.
string ParseTree::postOrderTraversal(TreeNode* ptr)
{
	string ret;
	if (ptr != NULL)
	{
		ret += postOrderTraversal(ptr->left);
		ret += postOrderTraversal(ptr->right);
		ret += ptr->key + " ";
	}
	return ret;
}

// Function to begin the calculate process.
void ParseTree::Calculate() {
	string postExpr = postOrderTraversal(root);
	stack<int> operand;
	stringstream ss(postExpr);

	string data;
	cout << "\nExpression from user input: ";
	Print(Expression);

	while (ss >> data)
	{
		if (isDigit(data))
		{
			operand.push(atoi(data.c_str()));
		}
		else if (isOperator(data))
		{
			if (operand.size() >= 2)
			{
				int num2 = operand.top();
				operand.pop();
				int num1 = operand.top();
				operand.pop();
				operand.push(eval(num1, data, num2));
			}
			else
			{
				cout << "Invalid Post Fix Expression.\n";
				return;
			}
		}
	}

	if (operand.size() == 1)
		cout << "\n\nEvaluation of Expression: " << operand.top();
	else
		cout << "Invalid Post Fix Expression.\n";

	cout << endl;
}

// Reads the input by the user and accepts if it is an integer.
int ParseTree::Read_Int() {
	int Val;

	cin >> Val;
	while (!cin.good()) {
		cout << "Invalid integer, try again." << endl;
		cin.clear();
		cin.ignore(80, '\n');
	}
	return Val;
}