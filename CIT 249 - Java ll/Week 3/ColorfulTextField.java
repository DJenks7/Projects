//********************************************************************************************************************
//	Author: Dylan Jenkins
//	Date 9/9/13
//	Purpose: Text Field creation
//********************************************************************************************************************

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class ColorfulTextField extends JTextField
{
	//****************************************************************************
	//	Creates JTextField for user input of solution (ANSW in MainPanel.java)
	//****************************************************************************
	public ColorfulTextField(Color COLOR, int INT)
	{
		super();
		setColumns(INT);
		setBackground(COLOR);
	}


}