//****************************************************************************
//	Dylan Jenkins		4/26/13
//	Critters.java
//	Critter class to create critters for hierarchy critter program.
//****************************************************************************

import java.lang.*;


public class Critter
{
	protected String size;
	protected String domestic;
	protected String live;
	protected String back;

	//-------------------
	//	Constructor
	//-------------------

	public Critter (String SIZE, String DOMESTIC, String LIVE, String BACK)
	{
		size = SIZE;
		domestic = DOMESTIC;
		live = LIVE;
		back = BACK;
	}

	//---------------------
	//	Accessors
	//---------------------

	public String getSize()
	{
		return size;
	}

	public String getDomesticated()
	{
		return domestic;
	}

	public String getLive()
	{
		return live;
	}

	public String getBack()
	{
		return back;
	}

	//--------------------
	//	Mutators
	//--------------------

	public void setSize(String SIZE)
	{
		size = SIZE;
	}

	public void setDomesticated(String DOMESTIC)
	{
		domestic = DOMESTIC;
	}

	public void setLive(String LIVE)
	{
		live = LIVE;
	}

	public void setBACK(String BACK)
	{
		back = BACK;
	}

	//--------------------------
	//	toString method
	//--------------------------

	public String toString()
	{
		String Phrase;
		Phrase = size + "\n" + domestic + "\n" + live + "\n" + back;
		return Phrase;
	}

}