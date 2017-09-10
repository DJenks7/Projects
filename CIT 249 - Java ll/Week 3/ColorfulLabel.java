//********************************************************************************************************************
//	Author: Dylan Jenkins
//	Date 9/9/13
//	Purpose: Label creation
//********************************************************************************************************************

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class ColorfulLabel extends JLabel
{
	//****************************************************************************
	//	Creates JLabel for math problem display (PRO in MainPanel.java)
	//****************************************************************************
	public ColorfulLabel(Color COLOR)
	{
		super();
		setBackground(COLOR);
		setPreferredSize(new Dimension (125, 25));
		setFont(new Font("Helvetica", Font.PLAIN, 20));
	}


}