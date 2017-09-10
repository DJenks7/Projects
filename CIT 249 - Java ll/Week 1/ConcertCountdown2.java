//*****************************************************************************
//	Author:  Dylan Jenkins
//	Date: 8/27/2013
//	Purpose: Driver for the concert countdown timer.
//*****************************************************************************

import java.awt.*;
import javax.swing.*;

public class ConcertCountdown2 extends JPanel
{

	public static void main(String[] args)
	{
		JFrame frame = new JFrame ("Countdown!");
		frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

		frame.getContentPane().add (new Countdown2());

		frame.pack();
		frame.setVisible(true);
	}
}