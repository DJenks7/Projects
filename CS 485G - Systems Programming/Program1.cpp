#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Command[25];
unsigned int N;

void Display();                                 // Funtion used to display the menu.
void Hexadecimal(unsigned int number);          // Function to convert the given unsigned number to Hexadecimal.
int Validate(int n);                            // Function used to validate users integer inputs n and m.


int main(int argc, char* argv[]) {

	unsigned int Quit, valid, valid2, num, Octal = 0;       // Unsigned integers used for validation, number storing from input or
															//                      to be displayed, and quitting the program.
	int i = 0, j = 0, check, rem, k;                        // Integers used for counters, checking user input, and conversions respectively.

															// Validates a file has been entered when program is called.
	if (argc != 2) {
		printf("usage: %s filename\n", argv[0]);
	}
	else {
		FILE *myFile = fopen(argv[1], "r");

		// If the file cannot be read.
		if (!myFile) {
			printf("\n--------------------------------\n");
			printf("Unable to open file!\n");
			printf("--------------------------------\n\n");
			return 1;
		}

		// Reads data from file and saves it in an array.
		unsigned int *buffer;

		fread((void *)&N, 4, 1, myFile);

		buffer = (unsigned int *)malloc(N * 4);

		fread(buffer, 4, N, myFile);

		// While the user has not entered q to exit.
		while (Quit != 0) {
			Display();
			Quit = strncmp(Command, "q", 1);

			// Checks to ensure valid input then prints element i (user input of n) in Decimal.
			check = sscanf(Command, "pd %d", &i);
			valid = Validate(i);

			if (valid == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "pd ", 3)) == 0) {
				if (check == 1) {
					printf("%d\n", buffer[i]);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}
			}

			// Check to ensure valid input then prints element i (user input of n) in Hexadecimal.
			check = sscanf(Command, "px %d", &i);
			valid = Validate(i);

			if (valid == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "px ", 3)) == 0) {
				if (check == 1) {
					num = buffer[i];
					Hexadecimal(num);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks to ensure valid input then prints element i (user input of n) in Octal.
			check = sscanf(Command, "po %d", &i);
			valid = Validate(i);

			if (valid == 1) {
				return 1;
			}

			// Conversion to Octal.
			if ((k = strncmp(Command, "po ", 3)) == 0) {
				if (check == 1) {
					num = buffer[i];
					Octal = 0;
					k = 1;

					if (num < 0) {
						num = ~num;
						num += 1;
					}

					while (num != 0) {
						rem = num % 8;
						num /= 8;
						Octal += rem * k;
						k *= 10;
					}
					printf("%u\n", Octal);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks and validates input then prints the first byte of element n in 2 Hexadecimal characters.
			check = sscanf(Command, "b0 %d", &i);
			valid = Validate(i);

			if (valid == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "b0 ", 3)) == 0) {
				if (check == 1) {
					valid2 = (buffer[i] >> (8 * 0)) & 0xff;
					Hexadecimal(valid2);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks and validates input then prints the second byte of element n in 2 Hexadecimal characters.
			check = sscanf(Command, "b1 %d", &i);
			valid = Validate(i);

			if (valid == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "b1 ", 3)) == 0) {
				if (check == 1) {
					valid2 = (buffer[i] >> (8 * 1)) & 0xff;
					Hexadecimal(valid2);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks and validates input then prints the third byte of element n in 2 Hexadecimal characters.
			check = sscanf(Command, "b2 %d", &i);
			valid = Validate(i);

			if (valid == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "b2 ", 3)) == 0) {
				if (check == 1) {
					valid2 = (buffer[i] >> (8 * 2)) & 0xff;
					Hexadecimal(valid2);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks and validates input then prints the fourth byte of element n in 2 Hexadecimal characters
			check = sscanf(Command, "b3 %d", &i);
			valid = Validate(i);

			if (valid == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "b3 ", 3)) == 0) {
				if (check == 1) {
					valid2 = (buffer[i] >> (8 * 3)) & 0xff;
					Hexadecimal(valid2);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks and validates input then prints in Hexadecimal the addition of elements
			// i and j (n and m from user input).
			check = sscanf(Command, "+ %d %d", &i, &j);
			valid = Validate(i);
			valid2 = Validate(j);

			if (valid == 1 || valid2 == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "+ ", 2)) == 0) {
				if (check == 2) {
					num = buffer[i] + buffer[j];
					Hexadecimal(num);
				}
				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks and validates input then prints in Hexadecimal the bitwise AND
			// of elements i and j (n and m from user input).
			check = sscanf(Command, "& %d %d", &i, &j);
			valid = Validate(i);
			valid2 = Validate(j);

			if (valid == 1 || valid2 == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "& ", 2)) == 0) {
				if (check == 2) {
					valid2 = buffer[i] & buffer[j];
					Hexadecimal(valid2);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks and validates input then prints in Hexadecimal the bitwise OR
			// of elements i and j (n and m from user input).
			check = sscanf(Command, "| %d %d", &i, &j);
			valid = Validate(i);
			valid2 = Validate(j);

			if (valid == 1 || valid2 == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "| ", 2)) == 0) {
				if (check == 2) {
					valid2 = buffer[i] | buffer[j];
					Hexadecimal(valid2);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks and validates input then prints in Hexadecimal the bitwise XOR
			// of elements i and j (n and m from user input).
			check = sscanf(Command, "^ %d %d", &i, &j);
			valid = Validate(i);
			valid2 = Validate(j);

			if (valid == 1 || valid2 == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "^ ", 2)) == 0) {
				if (check == 2) {
					valid2 = buffer[i] ^ buffer[j];
					Hexadecimal(valid2);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks and validates input then prints the result of right-shifting element n by m bits.
			check = sscanf(Command, "> %d %d", &i, &j);
			valid = Validate(i);
			valid = Validate(j);

			if (valid == 1 || valid2 == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "> ", 2)) == 0) {
				if (check == 2) {
					valid2 = i >> j;
					Hexadecimal(valid2);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}

			// Checks and validates input then prints result of left-shifting element n by m bits.
			check = sscanf(Command, "< %d %d", &i, &j);
			valid = Validate(i);
			valid = Validate(j);

			if (valid == 1 || valid2 == 1) {
				return 1;
			}

			if ((k = strncmp(Command, "< ", 2)) == 0) {
				if (check == 2) {
					valid2 = i << j;
					Hexadecimal(valid2);
				}

				if (check == 0) {
					printf("\n--------------------------------\n");
					printf("Error on input!\n");
					printf("--------------------------------\n\n");
					return 1;
				}

			}
		}
	}
	return 0;
}

// Prints a menu for the user with valid commands then it waits for input from the user.
void Display() {
	printf("\nn and m represent non-negative decimal integers.\n\n");
	printf("pd n \tprint element n in decimal (supress leading zeros)\n");
	printf("px n \tprint element n in hex\n");
	printf("po n \tprint element in otcatl (supress leading zeros)\n");
	printf("b0 n \tprint the lowest order (first) byte of element n in 2 hex characters\n");
	printf("b1 n \tprint the second byte of element n in 2 hex characters\n");
	printf("b2 n \tprint the third byte of element n in 2 hex characters\n");
	printf("b3 n \tprint the fourth byte of element n in 2 hex characters\n");
	printf("+ n m \tprint the sum of elements n and m, ignoring overflow\n");
	printf("& n m \tprint the bitwise and of elements n and m\n");
	printf("| n m \tprint the bitwise or of elements n and m\n");
	printf("^ n m \tprint the bitwise xor of elements n and m\n");
	printf("> n m \tprint the result of right-shifting element n by m bits\n");
	printf("< n m \tprint the result of left-shifting element n by m bits\n");
	printf("q \tquit; do not print anything\n\n");
	printf("Command: ");
	fgets(Command, 25, stdin);
}

// Validates that n is a valid element in the buffer array.
int Validate(int n) {
	if (n > N + 1) {
		printf("\n--------------------------------\n");
		printf("Error on input!\n");
		printf("--------------------------------\n\n");
		return 1;
	}
	else {
		return 0;
	}
}

// Function used to convert the number if it is negative and print the number in hexadecimal,
// otherwise it simply converts the number into hexaecimal and displays.
void Hexadecimal(unsigned int number) {
	long int rem[50], k = 0, length = 0;            // Integers for number conversion.

	if (number < 0) {
		number = ~number;
		number += 1;
	}

	while (number > 0) {
		rem[k] = number % 16;
		number /= 16;
		k++;
		length++;
	}

	for (k = length - 1; k >= 0; k--) {
		switch (rem[k]) {
		case 10:
			printf("a");
			break;
		case 11:
			printf("b");
			break;
		case 12:
			printf("c");
			break;
		case 13:
			printf("d");
			break;
		case 14:
			printf("e");
			break;
		case 15:
			printf("f");
			break;
		default:
			printf("%ld", rem[k]);
			break;
		}
	}
	printf("\n");
}
