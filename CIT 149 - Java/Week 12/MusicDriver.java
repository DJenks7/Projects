//******************************************
//	Dylan Jenkins		4/12/13
//	MusicDriver.java
//	Driver for program.
//******************************************

import javax.swing.*;
import java.awt.*;

public class MusicDriver
{
	public static void main (String[] args)
	{
		JFrame frame = new JFrame ("Cast Your Vote!");
		frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().add(new MusicPanel());

		frame.pack();
		frame.setVisible(true);
	}

}
