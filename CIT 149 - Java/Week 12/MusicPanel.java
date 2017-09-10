//**************************************
//	Dylan Jenkins		4/12/13
//	MusicPanel.java
//	GUI for voting and text display.
//**************************************

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MusicPanel extends JPanel
{
	//	DECLARATIONS

	private JComboBox VoteCombo;
	private JButton Vote, End;
	private JTextArea text = new JTextArea(25, 20);
	private int[] votes = new int[15];
	private Histogram histo = new Histogram(0, 4, 5, 9, 10, 14);

	public MusicPanel()
	{
		// SETTING UP COMBO BOX

		String[] VoteNums = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14"};

		VoteCombo = new JComboBox (VoteNums);
		VoteCombo.setBackground (Color.yellow);

		//	BUTTON SETUP

		Vote = new JButton ("Vote!");
		Vote.setBackground (Color.green);

		End = new JButton ("End Voting");
		End.setBackground (Color.red);

		//	TEXT AREA SETUP

		JScrollPane Pane = new JScrollPane(text);
		text.setEditable (false);
		text.setBackground (Color.cyan);

		//	ADDITION OF LISTENERS

		Vote.addActionListener (new VoteListener());
		End.addActionListener (new EndListener());

		//	SETUP PANEL AND ADD ITEMS

		setPreferredSize (new Dimension (250, 450));
		setBackground (Color.black);
		add (VoteCombo);
		add (Vote);
		add (End);
		add (text);
	}

	//	VOTE BUTTON LISTENER

	private class VoteListener implements ActionListener
	{
		public void actionPerformed (ActionEvent event)
		{
			int I = (int) VoteCombo.getSelectedIndex();

			votes[I] = votes[I] + 1;

			if (I >= 0 || I <= 4)
			{
				histo.addToRange1();
			}

			if (I >= 5 || I <= 9)
			{
				histo.addToRange2();
			}

			if (I >= 10 || I <= 14)
			{
				histo.addToRange3();
			}
		}
	}

	//	END BUTTON LISTENER

	private class EndListener implements ActionListener
	{
		public void actionPerformed (ActionEvent event)
		{
			int i = 0;
			String phrase = histo.toString();

			text.append("Band\tVotes\n");

			for (int LIMIT = 0; LIMIT <= 15 && i <= 14; LIMIT++, i++)
			{
				text.append(LIMIT + "\t" + votes[i] + "\n");
			}

			text.append("\n" + phrase);
		}
	}


}