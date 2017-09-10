//************************************************************************
//	Location.java
//
//  A class used to represent a location in a matrix, such as an array or grid
//************************************************************************


public class Location
{

	//***********************************************************************************
	//  Instance variables
	//***********************************************************************************

	private int row;
	private int column;

	//***********************************************************************************
	//  Constructors
	//
	//  Default constructor sets location to position 0,0
	//***********************************************************************************

	public Location (int row, int column)
	{	row = row;
		column = column;
	}

    public Location ()
    {   row = 0;
        column = 0;
	}
	//***********************************************************************************
	//  Accessors
	//***********************************************************************************

	public int getRow()
		{
			return row;
		}

	public int getColumn()
		{
			return column;
		}


	//***********************************************************************************
	//  Mutators
	//***********************************************************************************

	public void setRow(int row)
		{
			row = row;
		}

	public void setColumn(int column)
		{
			column = column;
		}

 	public void setLocation(int row, int column)
		{
			row = row;
			column = column;
		}

	//***********************************************************************************
	//  Additional Methods
	//***********************************************************************************

 	public String toString()
	{
		return ("Location: " + row + ", " + column);
	}


}

