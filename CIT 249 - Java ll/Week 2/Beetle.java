//**************************************************************************
//	Dylan Jenkins			9/3/2013
//	Beetle.java
//	Beetle child class, extends parent Bug
//**************************************************************************

import java.lang.*;
import java.util.Random;

public class Beetle extends Bug
{
	private String attribute;

	//****************************
	//	Constructor
	//****************************
	public Beetle (String bugName, String bugColor, String bugDirection, Location bugLocation, String bugHorn)
	{
		super (bugName, bugColor, bugDirection, bugLocation);

		attribute = bugHorn;
	}

	//****************************
	//	Accessors
	//****************************
	public String getName()
	{
		return name;
	}

	public String getColor()
	{
		return color;
	}

	public String getHorn()
	{
		return attribute;
	}

	public String getDirection()
	{
		return direction;
	}

	public Location getLocation()
	{
		return location;
	}

	//*****************************
	//	Mutators
	//*****************************
	public void setName(String bugName)
	{
		name = bugName;
	}

	public void setColor(String bugColor)
	{
		color = bugColor;
	}

	public void setAttribute(String bugHorn)
	{
		attribute = bugHorn;
	}

	public void setDirection(String bugDirection)
	{
		direction = bugDirection;
	}

	public void setLocation(Location bugLocation)
	{
		location = bugLocation;
	}

	//***************************
	//	toString Method
	//***************************
	public String toString()
	{
		return super.toString() + "\nAttribute: " + attribute;
	}

	//******************************************
	//	Abstract Methods
	//******************************************
	public Boolean canMove()
	{

		if (location.getColumn() < 4 && location.getColumn() >= 0)
		{
			bugMove = true;
		}
		else
		{
			bugMove = false;
		}
		return bugMove;
	}

	public void move()
	{
		Random gen = new Random();

		if (bugMove = true)
		{
			location.setLocation(location.getRow(), location.getColumn() + 1);
		}
		else
		{
			location.setLocation(gen.nextInt(5), gen.nextInt(5));
		}
	}



}