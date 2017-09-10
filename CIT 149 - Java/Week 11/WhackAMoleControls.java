//**************************************************
// WhackAMoleControls.java		Dylan Jenkins
// 4/3/2013
// Mole timer and picture settings.
//**************************************************

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class WhackAMoleControls extends JPanel
{
	private final int WIDTH = 400, HEIGHT = 400;
	private final int DELAY = 5;

	private JButton Start = new JButton("Start"), Stop = new JButton("Stop");
	private ImageIcon CurrentImage = new ImageIcon ("nomole.png");
	private Timer timer = new Timer(DELAY, new TimerListener());
	private Mole mole = new Mole(43, 43);
	private int x = mole.getX(), y = mole.getY();

	public WhackAMoleControls ()
	{
		ButtonListener listener = new ButtonListener();
		Start.addActionListener (listener);
		Stop.addActionListener (listener);

		setPreferredSize (new Dimension(WIDTH, HEIGHT));
		setBackground (Color.white);
		add (Start);
		add (Stop);
	}

	public void paintComponent (Graphics page)
	{
		super.paintComponent (page);
		CurrentImage.paintIcon (this, page, x, y);
	}

	private class ButtonListener implements ActionListener
	{
		public void actionPerformed (ActionEvent event)
		{
			if (event.getSource() == Start)
				CurrentImage = new ImageIcon ("mole.jpg");
				timer.start();
				repaint();

			if (event.getSource() == Stop)
				CurrentImage = new ImageIcon ("nomole.png");
				timer.stop();
				repaint();
		}
	}

	private class TimerListener implements ActionListener
	{
		public void actionPerformed (ActionEvent event)
		{
			mole.moveMole();
			x = mole.getX();
			y = mole.getY();
			repaint();
		}
	}

}