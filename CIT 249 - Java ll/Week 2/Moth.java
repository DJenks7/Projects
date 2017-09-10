//**************************************************************************
//	Dylan Jenkins			9/3/2013
//	Moth.java
//	Moth child class, extends parent Caterpillar
//**************************************************************************

import java.util.Random;

public class Moth extends Caterpillar
{
	private String fly;

	//*********************
	//	Constructor
	//*********************
	public Moth (String bugName, String bugColor, String bugDirection, Location bugLocation, String bugCocoon, String bugFlight)
	{
		super(bugName, bugColor, bugDirection, bugLocation, bugCocoon);

		fly = bugFlight;
	}

	//********************
	//	Accessors
	//********************
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

	public String getFly()
	{
		return fly;
	}

	public String getDirection()
	{
		return direction;
	}

	public Location getLocation()
	{
		return location;
	}

	//********************
	//	Mutators
	//********************
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

	public void setFly(String bugFlight)
	{
		fly = bugFlight;
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
		return super.toString() + "\nFlight: " + fly;
	}

	//******************************************
	//	Abstract Methods
	//******************************************
	public Boolean canMove()
	{

		if (location.getRow() < 5 && location.getRow() >= 1)
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
			location.setLocation(location.getRow() - 1, location.getColumn());
		}
		else
		{
			location.setLocation(gen.nextInt(5), gen.nextInt(5));
		}
	}



}