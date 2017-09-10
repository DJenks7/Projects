// Program Name: Formatting and Strings
// Author: Dylan Jenkins
// Date: 2/7/2013
// Purpose: To produce a receipt for tickets purchased online.

import java.util.Scanner;
import java.util.Random;
import java.text.NumberFormat;
import java.text.DecimalFormat;

public class FormattingAndStrings
{

	public static void main (String[] args)
	{
		//Declarations.

			final double AdultTicket = 71.25;
			final double ChildTicket = 44.15;
			final double Fee = 16.50;
			String Date, FirstName, LastName, Event;
			String ConNum, Str1, Str2, Str3, Str4, Str5;
			int NumAdultTickets, NumChildTickets = 0;
			double Total = 0.00;

		// Input from user to get info.

		Scanner scan = new Scanner (System.in);

		System.out.print ("Enter your First Name: ");
		FirstName = scan.nextLine();

		System.out.print ("Enter your Last Name: ");
		LastName = scan.nextLine();

		System.out.print ("What event are you seeing?: ");
		Event = scan.nextLine();

		System.out.print ("How many adult tickets?: ");
		NumAdultTickets = scan.nextInt();

		System.out.print ("How many child tickets?: ");
		NumChildTickets = scan.nextInt();

		System.out.print ("Current Date? (mmddyyyy): ");
		Date = scan.next();

		// Calculations and Random Number Generator.

		Total = (NumAdultTickets * AdultTicket) + (NumChildTickets * ChildTicket);

		Random generator = new Random();
		int Num = generator.nextInt(100) + 10;

		// Formatting.

		DecimalFormat fmt1 = new DecimalFormat ("0.00");

		Str1 = LastName.substring (0, 3);
		Str2 = FirstName.substring (0, 2);

		ConNum = Str1 + Str2 + Num + "D" + Date;

		Str3 = Date.substring (0, 2);
		Str4 = Date.substring (2, 4);
		Str5 = Date.substring (4, 8);

		// Display Results.

		System.out.println ("\n====== The Grand Theatre ======");
		System.out.println ("\nConfirmation for " + FirstName + " " + LastName);
		System.out.println ("Purchased on " + Str3 + "-" + Str4 + "-" + Str5);
		System.out.println ("\nConfirmation Number: " + ConNum );
		System.out.println ("\nEvent:\t\t" + Event);
		System.out.println ("Adult Tickets:\t" + NumAdultTickets + " @ $" + fmt1.format(AdultTicket) + " Each");
		System.out.println ("Child Tickets:\t" + NumChildTickets + " @ $" + fmt1.format(ChildTicket) + " Each");
		System.out.println ("Processing Fee:\t$" + fmt1.format(Fee));
		System.out.println ("\nTOTAL:\t\t$" + fmt1.format(Total));
		System.out.println ("\nPlease arrive 30 minutes before curtain call.\n");

	}
}