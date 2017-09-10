//******************************************************
//	Dylan Jenkins
//	4/2/2013
//	WhackAMole.java
//	Simulate a Whack A Mole game driver.
//******************************************************

import javax.swing.*;
import java.awt.event.*;
import javax.swing.*;

public class WhackAMole
{
	//---------------------------------------
	//	Displays frame for WhackAMole game
	//---------------------------------------

	public static void main (String[] args)
	{
		JFrame frame = new JFrame ("Whack A Mole!");
		frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

		frame.getContentPane().add(new WhackAMolePanel());

		frame.pack();
		frame.setVisible (true);
	}
}

