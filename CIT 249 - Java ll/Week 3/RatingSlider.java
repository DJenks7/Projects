//********************************************************************************************************************
//	Author: Dylan Jenkins
//	Date 9/9/13
//	Purpose: Slider creation
//********************************************************************************************************************

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class RatingSlider extends JSlider
{
	//*********************************************************************
	//	Creates JSlider (DIFF in MainPanel.java)
	//*********************************************************************
	public RatingSlider()
	{
		super();
		setMajorTickSpacing(1);
		setPaintTicks(true);
		setPaintLabels(true);
		setBackground(Color.white);
		setPreferredSize(new Dimension (250, 45));
		setOrientation(HORIZONTAL);
		setMaximum(3);
		setMinimum(1);
		setValue(1);
	}


}
