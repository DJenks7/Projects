//**************************************************************************
//	Dylan Jenkins			9/3/2013
//	Caterpillar.java
//	Caterpillar child class, extends parent Bug
//**************************************************************************

import java.lang.*;
import java.util.Random;

public class Caterpillar extends Bug
{
	protected String cocoon;

	//****************************
	//	Constructor
	//****************************
	public Caterpillar (String bugName, String bugColor, String bugDirection, Location bugLocation, String bugCocoon)
	{
		super(bugName, bugColor, bugDirection, bugLocation);

		cocoon = bugCocoon;
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

	public String getCocoon()
	{
		return cocoon;
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

	public void setCocoon(String bugCocoon)
	{
		cocoon = bugCocoon;
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
		return super.toString() + "\nCocoon: " + cocoon;
	}

	//******************************************
	//	Abstract Methods
	//******************************************
	public Boolean canMove()
	{

		if (location.getColumn() < 5 && location.getColumn() > 0)
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
			location.setLocation(location.getRow(), location.getColumn() - 1);
		}
		else
		{
			location.setLocation(gen.nextInt(5), gen.nextInt(5));
		}
	}


}