//***********************************************
//	Dylan Jenkins		4/12/13
//	Histogram.java
//	Classes for voting procedures.
//***********************************************

public class Histogram
{
	//	DECLARATIONS

	private int minRange1, minRange2, minRange3;
	private int maxRange1, maxRange2, maxRange3;
	private int countInRange1, countInRange2, countInRange3;

	//	CONSTRUCTOR

	public Histogram(int FminRange, int FmaxRange, int SminRange,
						int SmaxRange, int TminRange, int TmaxRange)
	{
		minRange1 = FminRange;
		minRange2 = SminRange;
		minRange3 = TminRange;
		maxRange1 = FmaxRange;
		maxRange2 = SmaxRange;
		maxRange3 = TmaxRange;
		countInRange1 = 0;
		countInRange2 = 0;
		countInRange3 = 0;
	}

	//	ACCESSORS

	public int getMinRnage1()
	{
		return minRange1;
	}

	public int getMinRange2()
	{
		return minRange2;
	}

	public int getMinRange3()
	{
		return minRange3;
	}

	public int getMaxRange1()
	{
		return maxRange1;
	}

	public int getMaxRange2()
	{
		return maxRange2;
	}

	public int getMaxRange3()
	{
		return maxRange3;
	}

	public int getCountInRange1()
	{
		return countInRange1;
	}

	public int getCountInRange2()
	{
		return countInRange2;
	}

	public int getCountInRange3()
	{
		return countInRange3;
	}

	//	METHODS TO ADD TO COUNTER

	public void addToRange1()
	{
		countInRange1 = countInRange1 + 1;
	}

	public void addToRange2()
	{
		countInRange2 = countInRange2 + 1;
	}

	public void addToRange3()
	{
		countInRange3 = countInRange3 + 1;
	}

	//	TO STRING METHOD TO DISPLAY HISTOGRAM

	public String toString()
	{
		String Phrase;
		int count;
		String Asterisks1 = "", Asterisks2 = "", Asterisks3 = "";

		for (count = countInRange1; count != 0; count--)
		{
			Asterisks1 = Asterisks1 + "*";
		}

		for (count = countInRange2; count != 0; count--)
		{
			Asterisks2 = Asterisks2 + "*";
		}

		for (count = countInRange3; count != 0; count--)
		{
			Asterisks3 = Asterisks3 + "*";
		}

		Phrase = minRange1 + "-" + maxRange1 + ": " + Asterisks1 +
			"\n" + minRange2 + "-" + maxRange2 + ": " + Asterisks2 +
			"\n" + minRange3 + "-" + maxRange3 + ": " + Asterisks3;
		return Phrase;
	}

}
