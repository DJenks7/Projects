//*********************************************************
//	Author: Dylan Jenkins
//	Date: 3/25/2013
//	Purpose: Sets up controls for AC check box.
//*********************************************************

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class acControls extends JPanel
{
	private ACPanel AirConditioning;
	private JCheckBox Air;
	private JLabel imageLabel;

	public acControls (ACPanel ac)
	{
		AirConditioning = ac;
//--------------------------------------------------------
//	Creating Air conditioning check box.
//--------------------------------------------------------

		Air = new JCheckBox ("Air Conditioning");
		Air.setBackground (Color.blue);

//--------------------------------------------------------
//	Create item listener for Air conditioning check box.
//--------------------------------------------------------

	AirListener AListener = new AirListener();
	Air.addItemListener (AListener);

	add (Air);
	}

//----------------------------------------------------------------
//	Creation of Air listener to listen for check box selection.
//----------------------------------------------------------------

	class AirListener implements ItemListener
	{
		public void itemStateChanged (ItemEvent event)
		{
			if (Air.isSelected())
				AirConditioning.setOn (true);
			else
				AirConditioning.setOn (false);
				AirConditioning.repaint();
		}
	}

}