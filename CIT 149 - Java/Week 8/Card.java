// Author: Dylan Jenkins
// Date: 3/7/2013
// Program Name: Card

import java.util.Random;

public class Card
{
	private int face, faceValue;
	private int suit, suitValue;
	private int points;
	private String Phrase, sValue, fValue;
	Random generator = new Random();

	//-------------------------------
	// Constructors - Default.
	//-------------------------------

	public Card()
	{
		setCard();
	}

	//----------------------------------
	// Constructors - 2 parameters.
	//----------------------------------

	public Card(int faceValue, int suitValue)
	{
		face = faceValue;
		suit = suitValue;
	}

	//----------------------------------
	// Accessors.
	//----------------------------------

	public int getFace()
	{
		return face;
	}

	public int getSuit()
	{
		return suit;
	}

	//-------------------------------------
	// Mutators.
	//-------------------------------------

	public void setFace(int face)
	{
		face = faceValue;
	}

	public void setSuit(int suit)
	{
		suit = suitValue;
	}

	//-------------------------------------
	// Other Methods.
	//-------------------------------------

	public int setCard()
	{
		suit = generator.nextInt(4) + 1;
		face = generator.nextInt(13) + 1;
		return face;
	}

	public int getPoints()
	{
		switch (face)
		{
			case 1:
				points = 11;
				break;
			case 2:
				points = 2;
				break;
			case 3:
				points = 3;
				break;
			case 4:
				points = 4;
				break;
			case 5:
				points = 5;
				break;
			case 6:
				points = 6;
				break;
			case 7:
				points = 7;
				break;
			case 8:
				points = 8;
				break;
			case 9:
				points = 9;
				break;
			default:
				points = 10;
				break;
		}
		return points;
	}

	public String toString()
	{
		String phrase;
		switch (face)
		{
			case 1:
				fValue = "Ace";
				break;
			case 2:
				fValue = "2";
				break;
			case 3:
				fValue = "3";
				break;
			case 4:
				fValue = "4";
				break;
			case 5:
				fValue = "5";
				break;
			case 6:
				fValue = "6";
				break;
			case 7:
				fValue = "7";
				break;
			case 8:
				fValue = "8";
				break;
			case 9:
				fValue = "9";
				break;
			case 10:
				fValue = "10";
				break;
			case 11:
				fValue = "Jack";
				break;
			case 12:
				fValue = "Queen";
				break;
			case 13:
				fValue = "King";
				break;
		}

		switch (suit)
		{
			case 1:
				sValue = "Hearts";
				break;
			case 2:
				sValue = "Diamonds";
				break;
			case 3:
				sValue = "Clubs";
				break;
			case 4:
				sValue = "Spades";
				break;
		}
		return Phrase = "Card: " + fValue + " of " + sValue;
	}
}