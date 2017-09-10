//******************************************************
//	Author: Dylan Jenkins
//	Date: 3/25/2013
//	Purpose: Sets up AC panel.
//******************************************************

import javax.swing.*;
import java.awt.*;

public class ACPanel extends JPanel
{
	private boolean on;
	private ImageIcon AirConditioning;
	private JLabel imageLabel;

	public ACPanel()
	{
		AirConditioning = new ImageIcon ("ac.jpg");
		setBackground (Color.blue);

		on = false;
		imageLabel = new JLabel (AirConditioning);
		add(imageLabel);

		imageLabel.setVisible (false);
	}

	public void paintComponent (Graphics page)
	{
		super.paintComponent(page);

		if (on)
			imageLabel.setVisible (true);
		else
			imageLabel.setVisible (false);
	}

	public void setOn (boolean ac)
	{
		on = ac;
	}
}