// Program Name: 10 Dollar Menu Items
// Date: 2/14/2013
// Author: Dylan Jekins
// Purpose: To display song lyrics from user input (1-10) to
// display the line input and down.

//Import Scanner utility for user input.

import java.util.Scanner;

public class TenDollarMenu
{

	public static void main (String[] args)
	{

		//Declarations

		int Line;
		String Mutation9, Mutation8, Mutation7, Mutation6, Mutation5, Mutation4, Mutation3, Mutation2, Mutation1;
		String Lyrics = "10 items on the dollar menu, 10 items to eat.\n" +
				"Order cheesy fries. Pass ‘em around. 9 items left to buy.\n" +
				"9 items on the dollar menu, 9 items to eat.\n" +
				"Order a happy meal, pass it around. 8 items left to buy.\n" +
				"8 items on the dollar menu, 8 items to eat.\n" +
				"Order a shake, pass it around. 7 items left to buy.\n" +
				"7 items on the dollar menu, 7 items to eat.\n" +
				"Order onion rings. Pass ‘em around. 6 items left to buy.\n" +
				"6 items on the dollar menu, 6 items to eat.\n" +
				"Order a salad, pass it around. 5 items left to buy.\n" +
				"5 items on the dollar menu, 5 items to eat.\n" +
				"Order a bacon burger, pass it around. 4 items left to buy.\n" +
				"4 items on the dollar menu, 4 items to eat.\n" +
				"Order a chili dog. Pass it around. 3 items left to buy.\n" +
				"3 items on the dollar menu, 3 items to eat.\n" +
				"Order sweet tea, pass it around. 2 items left to buy.\n" +
				"2 items on the dollar menu, 2 items to eat.\n" +
				"Order buffalo wings, pass ‘em around. 1 items left to buy.\n" +
				"1 item on the dollar menu, 1 item to eat.\n" +
				"Order a sundae, pass it around. Nothing left to buy.\n";

		Scanner scan = new Scanner (System.in);

		// Get user input (0-10).

		System.out.print ("Enter number of items left to buy (Between 0-10): ");
		Line = scan.nextInt();

		// Error checking of input.

		if (Line <= 0 || Line > 10)
		System.out.println ("\nError: Number Entered Outside Range. Try Again.\n");

		// switch statements with string mutation.

		switch (Line)
		{
			case 10:
			System.out.println ("\n" + Lyrics + "\n");
			break;
			case 9:
			Mutation9 = Lyrics.substring (104, 996);
			System.out.println ("\n" + Mutation9 + "\n");
			break;
			case 8:
			Mutation8 = Lyrics.substring (205, 996);
			System.out.println ("\n" + Mutation8 + "\n");
			break;
			case 7:
			Mutation7 = Lyrics.substring (301, 996);
			System.out.println ("\n" + Mutation7 + "\n");
			break;
			case 6:
			Mutation6 = Lyrics.substring (402, 996);
			System.out.println ("\n" + Mutation6 + "\n");
			break;
			case 5:
			Mutation5 = Lyrics.substring (498, 996);
			System.out.println ("\n" + Mutation5 + "\n");
			break;
			case 4:
			Mutation4 = Lyrics.substring (601 , 996);
			System.out.println ("\n" + Mutation4 + "\n");
			break;
			case 3:
			Mutation3 = Lyrics.substring (701, 996);
			System.out.println ("\n" + Mutation3 + "\n");
			break;
			case 2:
			Mutation2 = Lyrics.substring (799, 996);
			System.out.println ("\n" + Mutation2 + "\n");
			break;
			case 1:
			Mutation1 = Lyrics.substring (902, 996);
			System.out.println ("\n" + Mutation1 + "\n");
			break;

		}
	}
}