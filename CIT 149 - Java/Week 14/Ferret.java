//****************************************************************************
//	Dylan Jenkins		4/26/13
//	Ferret.java
//	Ferret class to create critters for hierarchy critter program.
//****************************************************************************

public class Ferret extends Critter
{
	private String Species;
	private String Prey;
	private String Length;
	private String Use;
	private String Odor;
	private String Fun;

	//----------------------------
	//	Constructor
	//----------------------------

	public Ferret (String SIZE, String DOMESTIC, String LIVE, String BACK,
			String SPECIES, String PREY, String LENGTH, String USE, String ODOR,
			String FUN)
	{
		super(SIZE, DOMESTIC, LIVE, BACK);

		Species = SPECIES;
		Prey = PREY;
		Length = LENGTH;
		Use = USE;
		Odor = ODOR;
		Fun = FUN;
	}

	//----------------------
	//	Mutators
	//----------------------

	public void setSpecies(String SPECIES)
	{
		Species = SPECIES;
	}

	public void setPrey(String PREY)
	{
		Prey = PREY;
	}

	public void setLength(String LENGTH)
	{
		Length = LENGTH;
	}

	public void setUse(String USE)
	{
		Use = USE;
	}

	public void setOdor(String ODOR)
	{
		Odor = ODOR;
	}

	public void setFun(String FUN)
	{
		Fun = FUN;
	}

	//------------------------
	//	Accessors
	//------------------------

	public String getSpecies()
	{
		return Species;
	}

	public String getPrey()
	{
		return Prey;
	}

	public String getLength()
	{
		return Length;
	}

	public String getUse()
	{
		return Use;
	}

	public String getOdor()
	{
		return Odor;
	}

	public String getFun()
	{
		return Fun;
	}

	//----------------------------
	//	toString method
	//----------------------------

	public String toString()
	{
		String Phrase;
		Phrase = "Species: " + Species + "\nPrey: " + Prey + "\n\nCommon Characteristics:\n" + size + "\n"
				+ domestic + "\n" + live + "\n" + back + "\n\nUnique Characteristics:\n" + Length
				+ "\n" + Use + "\n" + Odor + "\n" + Fun;
		return Phrase;
	}

}