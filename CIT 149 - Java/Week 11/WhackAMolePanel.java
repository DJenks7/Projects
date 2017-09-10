//*************************************************
//	WhackAMole.java			Dylan Jenkins
//	4/4/2013
//	Whack A Mole game interface.
//*************************************************

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class WhackAMolePanel extends JPanel
{
	//-----------------------------
	//	Declarations.
	//-----------------------------

	private JButton Start = new JButton("Start"), Stop = new JButton("Stop");
	private ImageIcon CurrentImage = new ImageIcon ("nomole.png");
	private Timer timer = new Timer(1000, new TimerListener());
	private Mole mole = new Mole(43, 43);
	private int hits = 0;
	private boolean click;

	public WhackAMolePanel ()
	{
		//---------------------------------------------------
		//	Addition of buttons and Button Listener.
		//---------------------------------------------------
		addMouseListener (new ClickListener());

		ButtonListener listener = new ButtonListener();
		Start.addActionListener (listener);
		Stop.addActionListener (listener);

		setPreferredSize (new Dimension(400, 400));
		setBackground (Color.white);
		add (Start);
		add (Stop);
	}

	//--------------------------------------
	//	Draws image in current location.
	//--------------------------------------

	public void paintComponent (Graphics page)
	{
		super.paintComponent (page);
		CurrentImage.paintIcon (this, page, mole.getX(), mole.getY());
	}

	//-----------------------------------------------------
	//	Click events to check if mole was clicked.
	//-----------------------------------------------------

	private class ClickListener implements MouseListener
	{

	public void mousePressed (MouseEvent event)
	{
		click = mole.checkWhack(event.getX(), event.getY());

		if (click == true)
		{
			hits = hits + 1;
			mole.moveMole();
			repaint();
		}
	}

	public void mouseClicked (MouseEvent event) {}
	public void mouseReleased (MouseEvent event) {}
	public void mouseEntered (MouseEvent event) {}
	public void mouseExited (MouseEvent event) {}
	}

	//---------------------------------------------------
	//	Button Listener for Start and Stop buttons.
	//---------------------------------------------------

	private class ButtonListener implements ActionListener
	{
		public void actionPerformed (ActionEvent event)
		{
			if (event.getSource() == Start)
			{
				CurrentImage = new ImageIcon ("mole.jpg");
				mole.moveMole();
				timer.start();
				repaint();
			}

			if (event.getSource() == Stop)
			{
				CurrentImage = new ImageIcon ("nomole.png");
				timer.stop();
				JOptionPane.showMessageDialog (null, hits);
				hits = 0;
				repaint();
			}
		}
	}

	//--------------------------------------------
	//	Timer Listener for the timer.
	//--------------------------------------------

	private class TimerListener implements ActionListener
	{
		public void actionPerformed (ActionEvent event)
		{
			mole.moveMole();
			repaint();
		}
	}

}