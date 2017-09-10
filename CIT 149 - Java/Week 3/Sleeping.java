// Author: Dylan Jenkins
// Program Name: Sleeping.java
// Date: 1/29/13
// Purpose: To take input of a persons name, birth year, and
// 	number of hours normally slept per night and determine
// 	the average total of hours slept throughout their life.

import java.util.Scanner;																		// Code to accept input from keyboard

public class Sleeping
{
	public static void main (String[] args)
	{
		Scanner scan = new Scanner (System.in);													// Code to accept input from keyboard

		String Name = " ";
		int BirthYear = 0;
		int Hours = 0;
		int Age = 0;
		int TotalHours = 0;																		// Declarations
		double TotalDays = 0.0f;
		double TotalYears = 0.0f;
		int Year = 2013;

		System.out.print ("Enter users name: ");												// Get users name
		Name = scan.nextLine();

		System.out.print ("Enter users birth year: ");											// Get users birth year
		BirthYear = scan.nextInt();

		System.out.print ("Enter number of hours slept each day: ");							// Get average number of hours slept a day
		Hours = scan.nextInt();

		System.out.println ("\nName: " + Name);
		System.out.println ("DoB: " + BirthYear);												// Prints users information back
		System.out.println ("Hours slept a day: " + Hours);

		Age = Year - BirthYear;
		TotalHours = (Hours * 365) * Age;														// Calculations for total number of hours, days, and years slept
		TotalDays = TotalHours / 24.0;
		TotalYears = TotalDays / 365.0;

		System.out.println ("\nYour age is: " + Age);
		System.out.println ("You have slept " + TotalHours + " hours in your life.");			// Output of calculation results
		System.out.println ("You have slept " + TotalDays + " days in your life.");
		System.out.println ("You have slept " + TotalYears + " year(s) in your life.\n");
	}
}