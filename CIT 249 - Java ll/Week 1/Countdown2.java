//*****************************************************************************
//	Author:  Dylan Jenkins
//	Date: 8/27/2013
//	Purpose: To create a countdown timer until the beginning of a concert.
//*****************************************************************************

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Countdown2 extends JPanel
{
	//***********************************
	//	Declarations
	//***********************************
	private JButton Start = new JButton ("Start"), Stop = new JButton ("Stop!");
	private JRadioButton Ten = new JRadioButton ("10 Sec."), One = new JRadioButton ("1 Min."), Five = new JRadioButton ("5 Min.");
	private ImageIcon image = new ImageIcon ("DaftPunk.jpg");
	private int count;
	private JLabel imageLabel = new JLabel (image), counter = new JLabel (Integer.toString(count));
	private Timer countdown = new Timer(1000, new TimerListener());

	public Countdown2()
	{
		//**********************************************
		//	Sets up layout and counter label display
		//**********************************************
		setLayout (new BorderLayout());
		setBackground (Color.black);

		counter.setFont (new Font("Helvetica", Font.PLAIN, 50));
		counter.setForeground (Color.yellow);

		//******************************************
		//	Listener setup & assignment
		//******************************************
		ButtonListener listener1 = new ButtonListener();
		RadioListener listener2 = new RadioListener();

		Start.addActionListener (listener1);
		Stop.addActionListener (listener1);

		Ten.addActionListener(listener2);
		One.addActionListener(listener2);
		Five.addActionListener(listener2);

		//****************************************************************
		//	Radio button panel & grouping to display together in layout
		//****************************************************************
		JPanel subPanel = new JPanel();
		subPanel.add(Ten);
		subPanel.add(One);
		subPanel.add(Five);

		ButtonGroup group = new ButtonGroup();
		group.add(Ten);
		group.add(One);
		group.add(Five);

		//*****************************************************
		//	Adding buttons, images and coutner to layout
		//*****************************************************
		add (imageLabel, BorderLayout.NORTH);
		add (Start, BorderLayout.WEST);
		add (counter, BorderLayout.CENTER);
		add (Stop, BorderLayout.EAST);
		add (subPanel, BorderLayout.SOUTH);
	}

	//*********************************************************************
	//	Button listener to start and stop timer and reset countdown
	//*********************************************************************
	private class ButtonListener implements ActionListener
	{
		public void actionPerformed (ActionEvent event)
		{

			if (event.getSource() == Start)
			{
				countdown.start();
			}

			if (event.getSource() == Stop)
			{
				countdown.stop();
				JOptionPane.showMessageDialog (null, "The Show is Over, Sorry Folks.");
				counter.setText("");
			}
		}
	}

	//***********************************************************************************
	//	Radio button listener to set the countdown timer to one of three choices
	//***********************************************************************************
	private class RadioListener implements ActionListener
	{
		public void actionPerformed (ActionEvent event)
		{
			if (event.getSource() == Ten)
			{
				count = 10;
				counter.setText(Integer.toString(count));
			}

			if (event.getSource() == One)
			{
				count = 60;
				counter.setText(Integer.toString(count));
			}

			if (event.getSource() == Five)
			{
				count = 300;
				counter.setText(Integer.toString(count));
			}

		}
	}

	//*******************************************************************************
	//	Timer listener to subtract and display countdown text and stop timer
	//*******************************************************************************
	private class TimerListener implements ActionListener
	{
		public void actionPerformed (ActionEvent event)
		{
			if (count > 0)
			{
				count--;
				counter.setText(Integer.toString(count));
			}

			if (count == 0)
			{
				JOptionPane.showMessageDialog(null, "Let The Show Begin!!");
				countdown.stop();
			}
		}
	}


}