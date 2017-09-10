//	Author: Dylan Jenkins
//	Date: 3/22/2013
//	Purpose: Create a visual display of car radio with working radio stations, air conditioner, and volume control.

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.applet.AudioClip;
import java.net.URL;

public class JukeBoxControls extends JPanel
{
	//-------------------------------------------------------
	//	Declarations.
	//-------------------------------------------------------

	private JRadioButton Western_Beat, Classical_Melody, Jeopardy_Theme, New_Age_Rythm, Eighties_Jam, Alfred_Hitchcocks_Theme;
	private AudioClip[] music;
   	private AudioClip current;

   	public JukeBoxControls()
   	{
   		URL url, url1, url2, url3, url4, url5;
		url = url1 = url2 = url3 = url4 = url5 = null;

	//-------------------------------------------------------
	//	Obtain and store audio clips to play.
	//-------------------------------------------------------

	try
	{
		url = new URL ("file", "localhost", "westernBeat.wav");
	        url1 = new URL ("file", "localhost", "classical.wav");
	        url2 = new URL ("file", "localhost", "jeopardy.au");
	        url3 = new URL ("file", "localhost", "newAgeRythm.wav");
	        url4 = new URL ("file", "localhost", "eightiesJam.wav");
	        url5 = new URL ("file", "localhost", "hitchcock.wav");
	}

		catch (Exception exception) {}

		music = new AudioClip[6];
		music[0] = JApplet.newAudioClip (url);
		music[1] = JApplet.newAudioClip (url1);
		music[2] = JApplet.newAudioClip (url2);
		music[3] = JApplet.newAudioClip (url3);
		music[4] = JApplet.newAudioClip (url4);
		music[5] = JApplet.newAudioClip (url5);

	//-----------------------------------------------------------
	//	Setting up radio buttons and radio button colors.
	//-----------------------------------------------------------

		Western_Beat = new JRadioButton ("Western Beat");
		Western_Beat.setBackground (Color.green);
		Classical_Melody = new JRadioButton ("Classical Melody");
		Classical_Melody.setBackground (Color.green);
		Jeopardy_Theme = new JRadioButton ("Jeoprdy Theme");
		Jeopardy_Theme.setBackground (Color.green);
		New_Age_Rythm = new JRadioButton ("New Age Rythm");
		New_Age_Rythm.setBackground (Color.green);
		Eighties_Jam = new JRadioButton ("Eighties Jam");
		Eighties_Jam.setBackground (Color.green);
		Alfred_Hitchcocks_Theme = new JRadioButton ("Alfred Hitchcock's Theme");
		Alfred_Hitchcocks_Theme.setBackground (Color.green);

	//------------------------------------------------------------
	//	Grouping radio buttons together.
	//------------------------------------------------------------

		ButtonGroup group = new ButtonGroup();
		group.add(Western_Beat);
		group.add(Classical_Melody);
		group.add(Jeopardy_Theme);
		group.add(New_Age_Rythm);
		group.add(Eighties_Jam);
		group.add(Alfred_Hitchcocks_Theme);

	//----------------------------------------------------------
	//	Creating action listener for radio buttons.
	//----------------------------------------------------------

		RadioListener listener = new RadioListener();
		Western_Beat.addActionListener (listener);
		Classical_Melody.addActionListener (listener);
		Jeopardy_Theme.addActionListener (listener);
		New_Age_Rythm.addActionListener (listener);
		Eighties_Jam.addActionListener (listener);
		Alfred_Hitchcocks_Theme.addActionListener (listener);

	//----------------------------------------------------------------
	//	Adding buttons to the window and altering color/size.
	//----------------------------------------------------------------

		add (Western_Beat);
		add (Classical_Melody);
		add (Jeopardy_Theme);
		add (New_Age_Rythm);
		add (Eighties_Jam);
		add (Alfred_Hitchcocks_Theme);

		setBackground (Color.black);
		setPreferredSize (new Dimension(450, 200));
		}

	//------------------------------------------------------------
	//	Creating the radio button listener.
	//------------------------------------------------------------

		private class RadioListener implements ActionListener
		{
			public void actionPerformed (ActionEvent event)
			{
				Object source = event.getSource();

				if (current != null)
					current.stop();
				if (source == Western_Beat)
					current = music[0];
					current.play();

				if (current != null)
					current.stop();
				if (source == Classical_Melody)
					current = music[1];
					current.play();

				if (current != null)
					current.stop();
				if (source == Jeopardy_Theme)
					current = music[2];
					current.play();

				if (current != null)
					current.stop();
				if (source == New_Age_Rythm)
					current = music[3];
					current.play();

				if (current != null)
					current.stop();
				if (source == Eighties_Jam)
					current = music[4];
					current.play();

				if (current != null)
					current.stop();
				if (source == Alfred_Hitchcocks_Theme)
					current = music[5];
			   		current.play();
			}
		}


}
