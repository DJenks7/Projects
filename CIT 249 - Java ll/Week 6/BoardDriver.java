//*****************************************************************************************
//	Dylan Jenkins		9/30/2013
//	BoardDriver.java
//	Driver to create two board objects, place items on, display and count the boards
//*****************************************************************************************

public class BoardDriver
{
	public static void main (String[] args)
	{
		//---------------------------------------------------
		//	Create board B1 of size 8, 8.
		//---------------------------------------------------
		Board B1 = new Board(8, 8);

		//---------------------------------------------------
		//	Load board B1 with tokens.
		//---------------------------------------------------
		B1.useLocation(0, 1);
		B1.useLocation(0, 2);
		B1.useLocation(0, 3);
		B1.useLocation(0, 6);

		B1.useLocation(1, 0);
		B1.useLocation(1, 2);
		B1.useLocation(1, 3);
		B1.useLocation(1, 4);
		B1.useLocation(1, 5);
		B1.useLocation(1, 6);

		B1.useLocation(3, 0);
		B1.useLocation(3, 6);

		B1.useLocation(4, 7);

		B1.useLocation(5, 2);
		B1.useLocation(5, 3);
		B1.useLocation(5, 6);
		B1.useLocation(5, 7);

		B1.useLocation(6, 1);
		B1.useLocation(6, 5);

		B1.useLocation(7, 0);
		B1.useLocation(7, 3);
		B1.useLocation(7, 6);

		//---------------------------------------------------
		//	Counts the tokens on the board.
		//---------------------------------------------------
		System.out.println("# of Tokens on Board: " + B1.countTokens(7));

		//---------------------------------------------------
		//	Prints the board.
		//---------------------------------------------------
		System.out.println(B1.toString());

		//---------------------------------------------------
		//	Attempts to place a token at invalid location.
		//---------------------------------------------------
		try
		{
			B1.useLocation(9, 11);
		}
		catch(IndexOutOfBoundsException exception)
		{
			System.out.println("Error, entry(" + exception + ") is out of bounds.");
			System.out.println();
		}

		System.out.println("---------------------------------------");
		System.out.println();

		//---------------------------------------------------
		//	Create board B1 of size 10, 10.
		//---------------------------------------------------
		Board B2 = new Board(10, 10);

		//---------------------------------------------------
		//	Load board B2 with tokens.
		//---------------------------------------------------
		B2.useLocation(0, 2);
		B2.useLocation(0, 3);
		B2.useLocation(0, 6);
		B2.useLocation(0, 8);
		B2.useLocation(0, 9);

		B2.useLocation(1, 2);
		B2.useLocation(1, 5);
		B2.useLocation(1, 7);
		B2.useLocation(1, 8);
		B2.useLocation(1, 9);

		B2.useLocation(2, 0);
		B2.useLocation(2, 1);
		B2.useLocation(2, 4);
		B2.useLocation(2, 6);

		B2.useLocation(3, 0);
		B2.useLocation(3, 4);
		B2.useLocation(3, 5);
		B2.useLocation(3, 6);

		B2.useLocation(4, 1);
		B2.useLocation(4, 4);
		B2.useLocation(4, 6);
		B2.useLocation(4, 8);
		B2.useLocation(4, 9);

		B2.useLocation(5, 0);
		B2.useLocation(5, 1);
		B2.useLocation(5, 2);
		B2.useLocation(5, 3);
		B2.useLocation(5, 7);

		B2.useLocation(6, 2);
		B2.useLocation(6, 5);
		B2.useLocation(6, 6);

		B2.useLocation(7, 0);
		B2.useLocation(7, 2);
		B2.useLocation(7, 4);
		B2.useLocation(7, 9);

		B2.useLocation(8, 0);
		B2.useLocation(8, 3);
		B2.useLocation(8, 5);
		B2.useLocation(8, 6);
		B2.useLocation(8, 9);

		B2.useLocation(9, 2);
		B2.useLocation(9, 5);
		B2.useLocation(9, 7);

		//---------------------------------------------------
		//	Prints the board.
		//---------------------------------------------------
		System.out.println("# of Tokens on Board: " + B2.countTokens(9));

		//---------------------------------------------------
		//	Prints the board.
		//---------------------------------------------------
		System.out.println(B2.toString());
	}

}