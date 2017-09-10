//**********************************************************************
//	Dylan Jenkins
//	Bug.java			9/3/2013
//	Bug parent class, used in creation of bug subclasses
//**********************************************************************

import java.lang.*;
import java.util.Random;

abstract class Bug
{
	protected String name;
	protected String color;
	protected String direction;
	protected Location location;
	protected boolean bugMove;

	//****************************
	//	Constructor
	//****************************
	public Bug (String bugName, String bugColor, String bugDirection, Location bugLocation)
	{
		name = bugName;
		color = bugColor;
		direction = bugDirection;
		location = bugLocation;
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

	public void setDirection(String bugDirection)
	{
		direction = bugDirection;
	}

	public void setLocation(Location bugLocation)
	{
		location = bugLocation;
	}

	//*****************************
	//	Abstract Class
	//*****************************
	abstract class Move
	{
		public Boolean canMove()
		{
			return bugMove;
		}

		public void move()
		{
			Random gen = new Random();

			if (bugMove = true)
			{

			}
			else
			{

			}
		}
	}

	//*****************************
	//	toString Method
	//*****************************
	public String toString()
	{
		String Phrase;
		Phrase = name + "\n" + color + "\n" + direction + "\n" + location;
		return Phrase;
	}


}