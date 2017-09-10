//******************************************************************************************************************
//	Dylan Jenkins		9/23/13
//	Driver.java
//	This is the driver to create a OneByte object and use Exception to catch the two
//	errors that can occur being a negative number or if the number entered is out of bounds.
//******************************************************************************************************************

import java.util.Scanner;

public class Driver
{
	public static void main (String[] args) throws NegativeValueException
	{
		Scanner scan = new Scanner(System.in);
		int number;

		//----------------------------------------------------------------------------------------------------------
		// Asking user for a number between 0-255
		//----------------------------------------------------------------------------------------------------------
		System.out.print("Enter a number between 0 and 255: ");
		number = scan.nextInt();

		//----------------------------------------------------------------------------------------------------------
		// Checks the number entered and displays error if it is out of bounds.
		//----------------------------------------------------------------------------------------------------------
		try
		{
			OneByte one = new OneByte(number);
			System.out.println("Converted to Binary: " + one.toString());
		}
		catch(IndexOutOfBoundsException exception)
		{
			System.out.println("Error, number entered out of bounds. " + number);
			System.out.println("Try Again.");
		}

		//----------------------------------------------------------------------------------------------------------
		// Creates a new class Exception to check if the number entered is negative and display error if so.
		//----------------------------------------------------------------------------------------------------------
		NegativeValueException NEG = new NegativeValueException("\n\n" + "Error, Number entered is negative and is out of bounds. \n Try Again.");

		if(number<0)
			throw NEG;
	}


}