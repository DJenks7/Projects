//****************************************************************************
//	Dylan Jenkins		4/26/13
//	Bird.java
//	Bird class to create critters for hierarchy critter program.
//****************************************************************************

public class Bird extends Critter
{
	private String Species;
	private String Prey;
	private String Fly;
	private String Legs;
	private String Eyes;
	private String Head;

	//----------------------------
	//	Constructor
	//----------------------------

	public Bird (String SIZE, String DOMESTIC, String LIVE, String BACK,
			String SPECIES, String PREY, String FLY, String LEGS, String EYES,
			String HEAD)
	{
		super(SIZE, DOMESTIC, LIVE, BACK);

		Species = SPECIES;
		Prey = PREY;
		Fly = FLY;
		Legs = LEGS;
		Eyes = EYES;
		Head = HEAD;
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

	public void setFly(String FLY)
	{
		Fly = FLY;
	}

	public void setLegs(String LEGS)
	{
		Legs = LEGS;
	}

	public void setEyes(String EYES)
	{
		Eyes = EYES;
	}

	public void setHead(String HEAD)
	{
		Head = HEAD;
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

	public String getFly()
	{
		return Fly;
	}

	public String getLegs()
	{
		return Legs;
	}

	public String getEyes()
	{
		return Eyes;
	}

	public String getHead()
	{
		return Head;
	}

	//------------------------
	//	toString method
	//------------------------

	public String toString()
	{
		String Phrase;
		Phrase = "Species: " + Species + "\nPrey: " + Prey + "\n\nCommon Characteristics:\n" + size + "\n"
				+ domestic + "\n" + live + "\n" + back + "\n\nUnique Characteristics:\n"
				+ Fly + "\n" + Legs + "\n" + Eyes + "\n" + Head;
		return Phrase;
	}

}