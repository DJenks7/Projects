// ****************************************************************
// Mole.java
//
// Cindy S. Tucker
//
// Mole Class to be used in games
// ****************************************************************

import java.util.Scanner;
import java.util.Random;

public class Mole
{
	//----------------------------------------------------
	//  Instance data for mole class
	//  x and y coordinates of top left location (pixels)
	//  size of mole image (width and height)
	//  random generator
	//----------------------------------------------------


	private int xCoord, yCoord;
	private int moleWidth, moleHeight;
	private Random gen = new Random();
	private final int PANELWIDTH = 400;
	private final int PANELHEIGHT = 400;


    //--------------------------------------
    //  Mole constructor
    //--------------------------------------
    public Mole(int w, int h)
    {
		moleWidth = w;
		moleHeight = h;
		moveMole();
    }

	//--------------------------------------
    //Accessor for xCoord
    //--------------------------------------
    public int getX()
    {
		return xCoord;
    }

	//--------------------------------------
    //Accessor for yCoord
    //--------------------------------------
    public int getY()
    {
		return yCoord;
    }

	//--------------------------------------
    //Randomly place the mole on the board
    //--------------------------------------
    public void moveMole()
    {
		xCoord = gen.nextInt(PANELWIDTH - moleWidth);
		yCoord = gen.nextInt(PANELHEIGHT - moleHeight - moleHeight) + moleHeight;

    }

	//-----------------------------------------------------
    // Check to see the mole has been clicked (whacked)
    //-----------------------------------------------------
    public boolean checkWhack(int mouseX, int mouseY)
    {

		if (mouseX >= xCoord && mouseX <= xCoord + moleWidth && mouseY >= yCoord && mouseY <= yCoord + moleHeight)
			return true;
		else
			return false;

    }

}






