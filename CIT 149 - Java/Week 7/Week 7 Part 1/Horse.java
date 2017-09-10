// Program Name: Horse
// Author: Dylan Jenkins
// Date: 3/1/2013
// Purpose: To learn the mechanics of a driver class and creation of own class.

public class Horse
{

	private String name, sire, dam;
	private int weight;
	private int birthYear;
	private char gender;

	//------------------------------------------------------------------
	// Constructor - Requires 6 parameters.
	//------------------------------------------------------------------

	public Horse(String cname, int cweight, int cbirthYear, char cgender, String csire, String cdam)
	{
		name = cname;
		weight = cweight;
		birthYear = cbirthYear;
		gender = cgender;
		sire = csire;
		dam = cdam;
	}

	//--------------------------------------------
	// Constructor - Default.
	//--------------------------------------------

	public Horse()
	{

		name = "";
		weight = 0;
		birthYear = 0;
		gender = 0;
		sire = "";
		dam = "";
	}

	//------------------------------------------
	// Accessors.
	//------------------------------------------

	public String getName()
	{
		return name;
	}

	public int getWeight()
	{
		return weight;
	}

	public int getBirthYear()
	{
		return birthYear;
	}

	public char getGender()
	{
		return gender;
	}

	public String getSire()
	{
		return sire;
	}

	public String getDam()
	{
		return dam;
	}

	//---------------------------------------
	// Mutators.
	//---------------------------------------

	public void setName (String cname)
	{
		name = cname;
	}

	public void setWeight (int cweight)
	{
		weight = cweight;
	}

	public void setBirthYear (int cbirthYear)
	{
		birthYear = cbirthYear;
	}

	public void setGender (char cgender)
	{
		gender = cgender;
	}

	public void setSire (String csire)
	{
		sire = csire;
	}

	public void setDam (String cdam)
	{
		dam = cdam;
	}

	//-----------------------------------------------
	// Other methods.
	//-----------------------------------------------

	public String toString()
	{
		String Phrase;
		Phrase = "Horse Name: " + name + "\n" + "Horse Weight: " + weight + "\n" + "Birth Year: " + birthYear + "\n" + "Gender: " + gender + "\n" + "Sire: " + sire + "\n" + "Dam: " + dam;

		return Phrase;
	}

	public int calculateHorseAge()
	{
		return (2013 - birthYear);
	}
}