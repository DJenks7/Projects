//*****************************************************************
//	Author: Dylan Jenkins
//	Date: 3/25/2013
//	Purpose: Creation of volume slider for JukeBox.
//*****************************************************************

import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;

public class vSlider extends JPanel
{
	private JSlider vSlider;
	private JLabel vLabel;
	private JPanel controls;

	public vSlider()
	{
		//----------------------------------------------------------
		//	Creating Volume Slider to control volume.
		//----------------------------------------------------------

			vSlider = new JSlider(JSlider.HORIZONTAL, 0, 5, 1);
			vSlider.setMajorTickSpacing (1);
			vSlider.setPaintTicks (true);
			vSlider.setPaintLabels (true);
			vSlider.setAlignmentX (Component.RIGHT_ALIGNMENT);

		//----------------------------------------------------------
		//	vLabel assignment.
		//----------------------------------------------------------

			vLabel = new JLabel ("Music Volume: 1");
			vLabel.setFont (new Font("Helvetica", Font.PLAIN, 8));
			vLabel.setAlignmentX (Component.RIGHT_ALIGNMENT);

			controls = new JPanel();
			BoxLayout layout = new BoxLayout (controls, BoxLayout.Y_AXIS);
			controls.setLayout (layout);
			controls.add (vLabel);
			controls.add (vSlider);
			controls.add (Box.createRigidArea (new Dimension (0, 20)));

			add (controls);

		//-----------------------------------------------------------
		//	Creating change listener for volume slider.
		//-----------------------------------------------------------

			SliderListener vListener = new SliderListener();
			vSlider.addChangeListener (vListener);

	}

	private class SliderListener implements ChangeListener
	{
		private int volume;

		public void stateChanged (ChangeEvent event)
		{
			if (volume == 0)
				vLabel.setFont (new Font("Helvetica", Font.PLAIN, 4));
			if (volume == 1)
				vLabel.setFont (new Font("Helvetica", Font.PLAIN, 8));
			if (volume == 2)
				vLabel.setFont (new Font("Helvetica", Font.PLAIN, 12));
			if (volume == 3)
				vLabel.setFont (new Font("Helvetica", Font.PLAIN, 16));
			if (volume == 4)
				vLabel.setFont (new Font("Helvetica", Font.PLAIN, 20));
			if (volume == 5)
				vLabel.setFont (new Font("Helvetica", Font.PLAIN, 24));

			volume = vSlider.getValue();
			Integer.toString(volume);
			vLabel.setText ("Music Volume: " + volume);
		}
	}


}