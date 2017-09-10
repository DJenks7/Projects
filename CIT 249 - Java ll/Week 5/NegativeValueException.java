//******************************************************************************************************************
//	Dylan Jenkins		9/23/13
//	NegativeValueException.java
//	Represents the exception class to display a message if the number entered is negative.
//******************************************************************************************************************

import java.util.Scanner;

public class NegativeValueException extends Exception
{
	//----------------------------------------------------------------------------------------------------------
	// Returns message created in Driver if number entered is negative.
	//----------------------------------------------------------------------------------------------------------
	NegativeValueException(String msg)
	{
		super(msg);
	}


}