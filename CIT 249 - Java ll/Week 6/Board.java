//*****************************************************************************************
//	Dylan Jenkins		9/30/2013
//	Board.java
//	Board object, creates array of size Row_Size and Column_Size, has methods for
//  counting the tokens on the board, checking if a space is occupied and placing a token.
//*****************************************************************************************

public class Board
{
	private int[][] Layout;
	private int Row_Size;
	private int Column_Size;

	//---------------------------------------------------
	//	Constructor to create board array.
	//---------------------------------------------------
	public Board (int rSize, int cSize)
	{
		int i, x;
		Row_Size = rSize;
		Column_Size = cSize;
		Layout = new int [Row_Size][Column_Size];

		for(i=0;i<Row_Size;i++)
		{
			for(x=0;x<Column_Size;x++)
			{
				Layout[i][x] = 0;
			}
		}

	}

	//---------------------------------------------------
	//	Checks to see if space on array is a 1.
	//---------------------------------------------------
	public boolean isOccupied(int r, int c)
	{
		if(Layout[r][c] == 1)
			return true;
		else
			return false;
	}

	//---------------------------------------------------
	//	Place's a token on the board at this location.
	//---------------------------------------------------
	public void useLocation(int r, int c)
	{
		Layout[r][c] = 1;
	}

	//---------------------------------------------------
	//	Prints the array.
	//---------------------------------------------------
	public String toString()
	{
		int i, x;
		String phrase = "";

		for(i=0;i<Row_Size;i++)
		{
			phrase = phrase + "\n" + Layout[i][0];

			for(x=1;x<Column_Size;x++)
			{
				phrase = phrase + "   " + Layout[i][x];
			}
		}
		phrase = phrase + "\n";
		return phrase;
	}

	//---------------------------------------------------
	//	Recursively counts the tokens on the board.
	//---------------------------------------------------
	public int countTokens(int row)
	{
		int result = 0;

		for(int x=0;x<Column_Size;x++)
		{
			if(row<0)
				return result;
			else
				if(Layout[row][x]==1)
					result += 1;
		}
		return result + countTokens(row-1);
	}


}