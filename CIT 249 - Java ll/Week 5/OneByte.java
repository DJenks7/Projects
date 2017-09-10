//------------------------------------------------------------------------------
/*
    Class:  OneByte
    Author: C. Tucker
    Purpose:
    			Converts a decimal value in the range of 0-255
    			into a one binary byte

*/
//------------------------------------------------------------------------------

public class OneByte
{
	private int[] bits = new int[8];
    int value;

	public OneByte (int value)
	{
		this.value = value;
		convertToBinary();
	}

    private void convertToBinary()
    {   int rem, x = 0;

    	while (value != 0)
			{	rem = value%2;
				bits[x] = rem;
				value = value/2;
				x++;
			}
	}

    public int getValue()
    {	return value;   }

    public void setValue(int value)
    {   this.value = value;
        convertToBinary();}

	public String toString ()
	{ String byteString = "";
		for (int i=7; i >= 0; i--)
	        byteString += bits[i] ;
	    return byteString; }

}