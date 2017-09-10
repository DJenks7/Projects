// Author: Dylan Jenkins
// Date: 3/7/2013
// Program Name: BlackJack

import java.util.Scanner;

public class BlackJack
{
	public static void main (String[] args)
	{
		//----------------------------------------------
		// Declarations
		//----------------------------------------------

		int faceValue, suitValue, TotalValue1, TotalValue2;

		Scanner in = new Scanner (System.in);

		//-----------------------------------------------------------------------------------------
		// Instantiating objects using Card class. Check to see if duplicate, if so reset card.
		//-----------------------------------------------------------------------------------------

		Card Card1 = new Card();
		Card Card2 = new Card();
		Card Card3 = new Card();
		Card Card4 = new Card();

		if (Card1 == Card2);
			Card2.setCard();

		if (Card3 == Card4);
			Card4.setCard();

		//--------------------------------------------------------
		// Displaying card results and declare winner.
		//--------------------------------------------------------

		TotalValue1 = (Card1.getPoints() + Card2.getPoints());
		TotalValue2 = (Card3.getPoints() + Card4.getPoints());

		System.out.println("Player Cards: " + Card1 + " " + "\n\t\t" + Card2);
		System.out.println("Player Points: " + TotalValue1);

		System.out.println("\nDealer Cards: " + Card3 + " " + "\n\t\t" + Card4);
		System.out.println("Dealer Points: " + TotalValue2);

		if (TotalValue1 > TotalValue2)
			System.out.println("\nThe Player has won the round!");
		if (TotalValue1 < TotalValue2)
			System.out.println("\nThe Dealer has won the round!");
		if (TotalValue1 == TotalValue2)
			System.out.println("\nDRAW! Try Again.");

	}

}