//********************************************************************************************************************
//	Author: Dylan Jenkins
//	Date 9/9/13
//	Purpose: Driver to run the program as a whole
//********************************************************************************************************************

import java.awt.*;
import javax.swing.*;

public class Addition
{
	public static void main(String[] args)
	{
		//****************************************************************************
		//	Driver for initial start of program and frame setup
		//****************************************************************************
		JFrame frame = new JFrame ("Elementary Addition");
		frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

		frame.getContentPane().add(new MainPanel());

		frame.pack();
		frame.setVisible(true);
	}


}