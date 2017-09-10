//**************************************************************************
//	Dylan Jenkins			9/3/2013
//	BugDriver.java
//	BugDriver creates the board for bugs to move across and creates bugs
//**************************************************************************

import java.util.Random;
import java.lang.*;

public class BugDriver
{
	public static void main (String[] args)
	{
		Random generator = new Random();

		int[][] Board = new int[5][5];

		int I1 = generator.nextInt(5);
		int I2 = generator.nextInt(5);
		int I3 = generator.nextInt(5);
		int I4 = generator.nextInt(5);
		int I5 = generator.nextInt(5);
		int I6 = generator.nextInt(5);

		Location loc = new Location(I1, I2);
		Location loc2 = new Location(I3, I4);
		Location loc3 = new Location(I5, I6);

		String S1 = "Beetle";
		String S2 = "Brown";
		String S3 = "North";
		String S4 = "West";
		String S5 = "South";
		String S7 = "Has Offensive Horns";
		String S8 = "Cocoon Evolution";
		String S9 = "Ability to fly";
		String S10 = "Caterpillar";
		String S11 = "Green";
		String S12 = "Moth";

		Beetle beetle = new Beetle(S1, S2, S3, loc, S7);
		Caterpillar caterpillar = new Caterpillar(S10, S11, S5, loc2, S8);
		Moth moth = new Moth(S12, S2, S4, loc3, S8, S9);

		//******************************************
		//	Load the bug locations into the array
		//******************************************
		Board[I1][I2] = 1;
		Board[I3][I4] = 1;
		Board[I5][I6] = 1;

		//
		//	Print the array
		//
		for (int row = 0; row < Board.length; row++)
		{
			for (int col = 0; col < Board.length; col++)
				System.out.print (Board[row][col] + "\t");
				System.out.println();
		}

		//******************************************
		//	Move bugs on board first time
		//******************************************
		if (beetle.canMove() == true)
		{
			Board[I1][I2] = 0;

			beetle.move();

			Location temp = new Location();

			temp = beetle.getLocation();

			I1 = temp.getRow();
			I2 = temp.getColumn();

			Board[I1][I2] = 1;
		}

		if (caterpillar.canMove() == true)
		{
			Board[I3][I4] = 0;

			caterpillar.move();

			Location temp = new Location();

			temp = caterpillar.getLocation();

			I3 = temp.getRow();
			I4 = temp.getColumn();

			Board[I3][I4] = 1;
		}

		if (moth.canMove() == true)
		{
			Board[I5][I6] = 0;

			caterpillar.move();

			Location temp = new Location();

			temp = caterpillar.getLocation();

			I5 = temp.getRow();
			I6 = temp.getColumn();

			Board[I5][I6] = 1;
		}

		//******************************************
		//	Print the array
		//******************************************
		System.out.println ("------------------------------------------------");
		for (int row = 0; row < Board.length; row++)
		{
			for (int col = 0; col < Board.length; col++)
				System.out.print (Board[row][col] + "\t");
			System.out.println();
		}

		//******************************************
		//	Move bugs on board a second time
		//******************************************
		if (beetle.canMove() == true)
		{
			Board[I1][I2] = 0;

			beetle.move();

			Location temp = new Location();

			temp = beetle.getLocation();

			I1 = temp.getRow();
			I2 = temp.getColumn();

			Board[I1][I2] = 1;
		}

		if (caterpillar.canMove() == true)
		{
			Board[I3][I4] = 0;

			caterpillar.move();

			Location temp = new Location();

			temp = caterpillar.getLocation();

			I3 = temp.getRow();
			I4 = temp.getColumn();

			Board[I3][I4] = 1;
		}

		if (moth.canMove() == true)
		{
			Board[I5][I6] = 0;

			caterpillar.move();

			Location temp = new Location();

			temp = caterpillar.getLocation();

			I5 = temp.getRow();
			I6 = temp.getColumn();

			Board[I5][I6] = 1;
		}

		//******************************************
		//	Print the array
		//******************************************
		System.out.println ("------------------------------------------------");
		for (int row = 0; row < Board.length; row++)
		{
			for (int col = 0; col < Board.length; col++)
				System.out.print (Board[row][col] + "\t");
			System.out.println();
		}

	}


}
