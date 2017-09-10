//************************************************************************
//	Dylan Jenkins		11/5/2013
//	RacePanel.java
//	Panel to hold the race data and rectangles to be printed.
//************************************************************************

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class RacePanel extends JPanel
{
	//************************************************************************
	//	Declarations.
	//************************************************************************
	private final int BOARDWIDTH = 600, BOARDHEIGHT = 200;

	private JLabel winner, win;
	private int runner1 = 0, runner2 = 0;
	private boolean WIN = false;

	Random gen = new Random();

	//************************************************************************
	//	Rectangles to be printed and act as the "runners".
	//************************************************************************
	Rectangle r1 = new Rectangle (runner1, 50, 5, 5);
	Rectangle r2 = new Rectangle (runner2, 100, 5, 5);

	//************************************************************************
	//	Threads to be used to move the runners.
	//************************************************************************
	private Thread Runner1 = new RunnerThread();
	private Thread Runner2 = new RunnerThread();

	public RacePanel()
	{
		//************************************************************************
		//	Adds labels to a panel to display the winner of the race.
		//************************************************************************
		winner = new JLabel ("Winner: ");
		win = new JLabel ("TBA");

		winner.setForeground(Color.white);
		win.setForeground(Color.white);

		add (winner);
		add (win);

		setPreferredSize (new Dimension(BOARDWIDTH, BOARDHEIGHT-50));

		setBackground (Color.black);
	}

	//************************************************************************
	//	Method to start the race when user clicks start button.
	//************************************************************************
	public void BeginRacing()
	{
		Runner1.start();
		Runner2.start();
	}

	//************************************************************************
	//	Paints the image of the rectangles on the panel.
	//************************************************************************
	public void paintComponent (Graphics page)
	{
		super.paintComponent(page);

		page.fillRect(runner1, 50, 5, 5);

		page.fillRect(runner2, 100, 5, 5);

		update(page);
	}

	//************************************************************************
	//	Updates the rectangles to print at new location.
	//************************************************************************
	public void update(Graphics page)
	{
		for(int i=0; i<=runner1; i++)
		{
			page.setColor(Color.orange);
			page.fillRect(i, 50, 5, 5);
		}

		for(int x=0; x<=runner2; x++)
		{
			page.setColor(Color.green);
			page.fillRect(x, 100, 5, 5);
		}
	}

	//************************************************************************
	//	Thread used to generate random numbres to move the runners.
	//************************************************************************
	class RunnerThread extends Thread {
		public void run()
		{
			while(runner1 != BOARDWIDTH || runner2 != BOARDWIDTH)
			{
				runner1 += gen.nextInt(5) + 1;
				runner2 += gen.nextInt(5) + 1;

				repaint();

				if(WIN == false && runner1 >= 600)
				{
					win.setText("Runner One Won!");
					WIN = true;
				}

				if(WIN == false && runner2 >= 600)
				{
					win.setText("Runner Two Won!");
					WIN = true;
				}

				try
				{
					Runner1.sleep(25);
					Runner2.sleep(25);
				}
				catch(InterruptedException e)
				{
				}
			}
		}
	}


}