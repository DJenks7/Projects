//************************************************************************
//	Dylan Jenkins		11/4/2013
//	RunnerStart.java
//	Applet for two racing runners represented by lines.
//************************************************************************

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class RunnerStart extends JApplet implements ActionListener
{
	//************************************************************************
	//	Declarations.
	//************************************************************************
	private final int BOARDWIDTH = 600, BOARDHEIGHT = 200;

	private JButton StartRace;
	private RacePanel race;

	private String winner;

	private JPanel Panel, Button;

	//************************************************************************
	//	Required init method to display panels, button(s), and racers.
	//************************************************************************
	public void init()
	{
		//************************************************************************
		//	Panel to hold the start button and a panel to hold the rectangles.
		//************************************************************************
		Button = new JPanel();
		Button.setOpaque(true);
		Button.setPreferredSize (new Dimension(BOARDWIDTH, 50));
		Button.setBackground (Color.black);

		//************************************************************************
		//	Start button.
		//************************************************************************
		StartRace = new JButton ("Start the Race!");
		StartRace.setBackground (Color.orange);

		StartRace.addActionListener (this);

		Button.add (StartRace);

		race = new RacePanel();

		Panel = new JPanel();
		Panel.add (Button);
		Panel.add (race);

		getContentPane().add(Panel);
		setSize (BOARDWIDTH, BOARDHEIGHT);
	}

	//************************************************************************
	//	Listener for the button to start the race.
	//************************************************************************
	public void actionPerformed (ActionEvent event)
	{
		if (event.getSource() == StartRace)
		{
			StartRace.setEnabled(false);
			race.BeginRacing();
		}
	}


}