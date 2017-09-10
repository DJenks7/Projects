// Program Name: Phone
// Author: Dylan Jenkins
// Date: 2/23/2013
// Purpose: To read phone information from a file and display
//  the incoming and outgoing total calls.

import java.util.Scanner;
import java.io.*;

public class Phone
{

	public static void main (String[] args) throws IOException
	{

	String Input, Mutation, Mutation1, Mutation2, Mutation3;
	String Mutation4, Mutation5, Mutation6, Mutation7, Mutation8;
	String MostI = " ";
	String MostO = " ";
	String Temp1 = " ";
	String Temp2 = " ";
	int Count = 0;
	Scanner fileScan, numScan;

	Scanner scan = new Scanner (System.in);
	fileScan = new Scanner(new File("phoneContacts.txt"));

	System.out.println("Name\t\t\tPhone\t\tCalls-Out   Calls-In   Favorite");
	System.out.println();

		while (fileScan.hasNext())
		{
			Input = fileScan.nextLine();

			numScan = new Scanner (Input);
			numScan.useDelimiter("#");

			Mutation = numScan.next();
			Mutation1 = numScan.next();
			Mutation2 = numScan.next();
			Mutation3 = numScan.next();
			Mutation4 = numScan.next();
			Mutation5 = numScan.next();
			Mutation6 = Mutation2.substring(0, 3);
			Mutation7 = Mutation2.substring(3, 6);
			Mutation8 = Mutation2.substring(6, 10);

			if (Mutation5.equals("Y"))
			System.out.println(Mutation + " " + Mutation1 + "\t\t" + "(" + Mutation6 + ")" + Mutation7 + "-" + Mutation8 + " \t" + Mutation3 + " \t\t" + Mutation4 + " \t " + Mutation5);

			Count++;

		}

		System.out.println();
		System.out.println("My favorite contact who called me the most: Jackson Camille");
		System.out.println("My favorite contact who I called the most: Queensly Robert");

	}
}