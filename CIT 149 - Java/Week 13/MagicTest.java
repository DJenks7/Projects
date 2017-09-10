// ****************************************************************
// MagicTest.java
//
// Dylan Jenkins	4/20/13
//
// Uses the Square class to read in square data and tell if
// each square is magic.
//
// ****************************************************************

import java.util.Scanner;
import java.io.*;

public class MagicTest
{
    public static void main(String[] args) throws IOException
    {

	Scanner scan = new Scanner (new File("magic.Data"));  // Will read from a file rather than keyboard

	int count = 1;                 //count which square we're on
	int size = scan.nextInt();     //size of next square


		//Expecting -1 at bottom of input file
		while (size != -1)
		{
		int i;
		// Create a new Square of the given size
			MagicSquare square = new MagicSquare(size);

		// Call the read method to read the values of the square from the data file
		// Scanner objects can be passed as arguments
		// i.e. you can pass scan to a method
			square.readSquare(scan);

		System.out.println("\n******** Square " + count + " ********");
		// Call the print method to print the square
			System.out.print(square.toString() + "\n\n");

		// Calculate and print the sums of its rows
		for (i = 0; i < size; i++)
		{
			System.out.println("Sum of Row " + i + " = " + square.sumRow(i));
		}

		// Calculate and print the sums of its columns
		for (i = 0; i < size; i++)
		{
			System.out.println("Sum of Column " + i + " = " + square.sumCol(i));
		}

		// Calculate and print the sum of the main diagonal
			System.out.println("Sum of Main Diagonal = " + square.sumMainDiag());

		// Calculate and print the sum of the other diagonal
			System.out.println("Sum of Other Diagonal = " + square.sumOtherDiag());

		// Determine and print whether it is a magic square
			if(square.magic() == true)
				System.out.println("It is a Magic Square!");
			else
				System.out.println("Not a Magic Square.");

		//get size of next square
		size = scan.nextInt();
		count++;
	    }
	}

}


