//	Dylan Jenkins
//	CS463					12/2/2016
//	Markov.cpp
//	Program designed to use value iteration and find optimal policy with no dicount and horizon 7.
//	

#include <cmath>
#include <limits>
#include <iostream>
#include <iomanip>
using namespace std;

static const int map[6][6] = {
	0,  0, 0,  0,  0,  0,
	0,  0, 0, 10, -1,  0,
	-1, -1, 0,  0, -1,  0,
	100, -1, 0,  0, -1, 20,
	0, -1, 5,  0, -1,  0,
	0,  0, 0,  0,  0,  0
};

static float values_current[6][6] = {
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 10, -1, 0,
	-1, -1, 0, 0, -1, 0,
	100, -1, 0, 0, -1, 20,
	0, -1, 5, 0, -1, 0,
	0, 0, 0, 0, 0, 0
};

static float values_previous[6][6] = {
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 10, -1, 0,
	-1, -1, 0, 0, -1, 0,
	100, -1, 0, 0, -1, 20,
	0, -1, 5, 0, -1, 0,
	0, 0, 0, 0, 0, 0
};

static const float success_prob = 0.7f;
static const float opposite_prob = 0.2f;
static const float stay_prob = 0.7f;
static const float discount = .95f;

bool equal(float current[6][6], float previous[6][6]) {
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j)
			if (abs(current[i][j] - previous[i][j]) > numeric_limits<float>::epsilon())
				return false;

	return true;
}

float left(int i, int j) {
	float result = 0.f;

	if (j != 0 && values_previous[i][j - 1] != -1)
		result += success_prob * values_previous[i][j - 1];

	if (j != 5 && values_previous[i][j + 1] != -1)
		result += opposite_prob * values_previous[i][j + 1];

	return result;
}

float right(int i, int j) {
	float result = 0.f;

	if (j != 5 && values_previous[i][j + 1] != -1)
		result += success_prob * values_previous[i][j + 1];

	if (j != 0 && values_previous[i][j - 1] != -1)
		result += opposite_prob * values_previous[i][j - 1];

	return result;
}

float up(int i, int j) {
	float result = 0.f;

	if (i != 0 && values_previous[i - 1][j] != -1)
		result += success_prob * values_previous[i - 1][j];

	if (i != 5 && values_previous[i + 1][j] != -1)
		result += opposite_prob * values_previous[i + 1][j];

	return result;
}

float down(int i, int j) {
	float result = 0.f;

	if (i != 5 && values_previous[i + 1][j] != -1)
		result += success_prob * values_previous[i + 1][j];

	if (i != 0 && values_previous[i - 1][j] != -1)
		result += opposite_prob * values_previous[i - 1][j];

	return result;
}

void assign(float current[6][6], float previous[6][6]) {
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j)
			previous[i][j] = current[i][j];
}

void valueIteration7() {
	for (int n = 0; n < 7; ++n) {
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (map[i][j] != 0)
					continue;

				register float l = left(i, j);
				register float max = l;
				register float r = right(i, j);
				if (r > max)
					max = r;

				register float u = up(i, j);
				if (u > max)
					max = u;

				register float d = down(i, j);
				if (d > max)
					max = d;

				values_current[i][j] = max;
			}
		}

		if (equal(values_current, values_previous))
			break;

		assign(values_current, values_previous);
	}

	cout << "Final values for horizon 7 and no discount:" << endl;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j)
			cout << setw(8) << setprecision(3) << values_current[i][j] << " ";
		cout << endl;
	}
}

void valueIterationInfinity() {
	while (true) {
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (map[i][j] != 0)
					continue;

				register float l = left(i, j);
				register float max = l;
				register float r = right(i, j);
				if (r > max)
					max = r;

				register float u = up(i, j);
				if (u > max)
					max = u;

				register float d = down(i, j);
				if (d > max)
					max = d;

				values_current[i][j] = discount * max;
			}
		}

		if (equal(values_current, values_previous))
			break;

		assign(values_current, values_previous);
	}

	cout << "Final values for infinte horizon and 0.95 discount:" << endl;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j)
			cout << setw(8) << setprecision(3) << values_current[i][j] << " ";
		cout << endl;
	}
}

int main() {
	char Quit;

	valueIteration7();
	cout << endl;
	valueIterationInfinity();

	cout << "\nEnter any key to exit.\n";
	cin >> Quit;
	return 0;
}