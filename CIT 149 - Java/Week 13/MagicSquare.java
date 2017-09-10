// ****************************************************************
// MagicSquare.java
//
// Dylan Jenkins	4/20/13
//
// Define a Square class with methods to create and read in
// info for a square matrix and to compute the sum of a row,
// a column, either diagonal, and whether it is magic.
//
// ****************************************************************

import java.util.Scanner;

public class MagicSquare
{

    int[][] Square;
    int Size;

    //--------------------------------------
    //create new square of given size
    //--------------------------------------
    public MagicSquare(int size)
    {
		Size = size;
		Square = new int [Size][Size];
    }


    //-----------------------------------------------
    //return the sum of the values in the given row
    //-----------------------------------------------
    public int sumRow(int row)
    {
		int Total = 0, col;

		for (col = 0; col < Size; col++)
		{
			Total = Total + Square[row][col];
		}
		return Total;
    }


    //-------------------------------------------------
    //return the sum of the values in the given column
    //-------------------------------------------------
    public int sumCol(int col)
    {
		int Total = 0, row;

		for (row = 0; row < Size; row++)
		{
			Total = Total + Square[row][col];
		}
		return Total;
    }

    //---------------------------------------------------
    //return the sum of the values in the main diagonal
    //---------------------------------------------------
    public int sumMainDiag()
    {
		int Total = 0, row, col;

		for (row = 0, col = 0; row < Size && col < Size; row++, col++)
		{
			Total = Total + Square[row][col];
		}
		return Total;
    }

    //---------------------------------------------------------------
    //return the sum of the values in the other ("reverse") diagonal
    //---------------------------------------------------------------
    public int sumOtherDiag()
    {
		int Total = 0, row, col;

		for (row = 0, col = Size - 1; row < Size && col >= 0; row++, col--)
		{
			Total = Total + Square[row][col];
		}
		return Total;
    }

    //-------------------------------------------------------------------
    //return true if the square is magic (all rows, cols, and diags have
    //same sum), false otherwise
    //-------------------------------------------------------------------
    public boolean magic()
    {
		int i, sum1, sum2;
		boolean state = false;

		sum1 = sumMainDiag();
		sum2 = sumOtherDiag();

		if (sum1 != sum2)
		{
			state = false;
		}
		else
		{
			for (i = 0; i < Size; i++)
			{
				sum2 = sumRow(i);

				if (sum1 != sum2)
					state = false;
				else
					state = true;
			}

			for (i = 0; i < Size; i++)
			{
				sum2 = sumCol(i);

				if (sum1 != sum2)
					state = false;
				else
					state = true;
			}
		}
		return state;
    }

    //----------------------------------------------------
    //read info into the square from a scanner object
    //----------------------------------------------------
    public void readSquare(Scanner scan)
    {
		int row, col;

		for (row = 0; row < Size; row++)
		{
			for (col = 0; col < Size; col++)
			{
				Square[row][col] = scan.nextInt();
			}
		}
    }

    //---------------------------------------------------
    //print the contents of the square, neatly formatted
    //---------------------------------------------------
    public String toString()
    {
		int i, x;
		String matrix = " ";

		for (i = 0; i < Size; i++)
		{
			matrix = matrix + "\n" + Square[i][0];

			for (x = 1; x < Size; x++)
			{
				matrix = matrix + "\t" + Square[i][x];
			}
		}
		return matrix;
    }

}






