
//****************************************************************************
//	Dylan Jenkins		4/26/13
//	Frog.java
//	Frog class to create critters for hierarchy critter program.
//****************************************************************************

public class Frog extends Critter
{
	private String Species;
	private String Prey;
	private String Swim;
	private String Tongue;
	private String Jump;

	//----------------------------
	//	Constructor
	//----------------------------

	public Frog (String SIZE, String DOMESTIC, String LIVE, String BACK,
			String SPECIES, String PREY, String SWIM, String TONGUE, String JUMP)
	{
		super(SIZE, DOMESTIC, LIVE, BACK);

		Species = SPECIES;
		Prey = PREY;
		Swim = SWIM;
		Tongue = TONGUE;
		Jump = JUMP;
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

	public void setSwim(String SWIM)
	{
		Swim = SWIM;
	}

	public void setTongue(String TONGUE)
	{
		Tongue = TONGUE;
	}

	public void setJump(String JUMP)
	{
		Jump = JUMP;
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

	public String getSwim()
	{
		return Swim;
	}

	public String getTongue()
	{
		return Tongue;
	}

	public String getJump()
	{
		return Jump;
	}

	//------------------------
	//	toString method
	//------------------------

	public String toString()
	{
		String Phrase;
		Phrase = "Species: " + Species + "\nPrey: " + Prey + "\n\nCommon Characteristics:\n" + size + "\n"
				+ domestic + "\n" + live + "\n" + back + "\n\nUnique Characteristics:\n" + Swim
				+ "\n" + Tongue + "\n" + Jump;
		return Phrase;
	}

}