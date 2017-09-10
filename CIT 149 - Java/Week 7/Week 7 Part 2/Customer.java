//--------------------------------------------------------------------------------
//  Customer class for an mechanic shop to repair automobiles
//--------------------------------------------------------------------------------

import java.text.DecimalFormat;

public class Customer
{
	private String name;
	private float parts;
	private float labor;
	private DecimalFormat fmt = new DecimalFormat ("$#,##0.##");
	//--------------------------------------------------------------------------------
	//  Constructor - requires 3 parameters: name, cost of parts, and cost of labor
	//--------------------------------------------------------------------------------

	public Customer(String cname, float cparts, float clabor)
	{
		name = cname;
		parts = cparts;
		labor = clabor;

	}

	//--------------------------------------------------------------------------------
	//  Constructor - Default:
	//--------------------------------------------------------------------------------

	public Customer()
	{
		name = "";
		parts = 0.0F;
		labor = 0.0F;

	}

	//--------------------------------------------------------------------------------
	//  Accessors
	//--------------------------------------------------------------------------------
	public String getName()
	{
		return name;
	}

	public float getParts()
	{
		return parts;
	}

	public float getLabor()
	{
		return labor;
	}


	//--------------------------------------------------------------------------------
	//  Mutators
	//--------------------------------------------------------------------------------

	public void setName(String cname)
	{
		name = cname;
	}


	public void setParts(float cparts)
	{
		parts = cparts;
	}

	public void setLabor(float clabor)
	{
		labor = clabor;
	}



	//--------------------------------------------------------------------------------
	//  Other methods
	//--------------------------------------------------------------------------------
	public float calcTotal()
	{
		return (parts + labor);
	}


	public String toString()
	{
		String phrase;
		phrase = "Work for " + name + ": Parts: " + fmt.format(parts) + " Labor: " + fmt.format(labor);

		return phrase;
	}


}

