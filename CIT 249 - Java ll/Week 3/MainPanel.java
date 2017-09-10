//********************************************************************************************************************
//	Author: Dylan Jenkins
//	Date 9/9/13
//	Purpose: Main Panel setup to create all gui objects
//********************************************************************************************************************

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.util.Random;

public class MainPanel extends JPanel
{
	//*********************************************************************
	//	Declarations
	//*********************************************************************
	Random gen = new Random();
	private JPanel STUFF = new JPanel();
	private JSlider DIFF;
	private JLabel PRO;
	private JTextField ANSW;
	private int ONE, TWO, SUM;

	public MainPanel()
	{
		ANSW = new ColorfulTextField(Color.yellow, 10);
		PRO = new ColorfulLabel(Color.cyan);
		DIFF = new RatingSlider();

		//*********************************************************************
		//	Creating DIFF JSlider setting details and adding listener
		//*********************************************************************
		SliderListener sListener = new SliderListener();
		DIFF.addChangeListener(sListener);

		//*********************************************************************
		//	Adding action listener to the ANSW JTextField
		//*********************************************************************
		ANSW.addActionListener(new aListener());

		//*********************************************************************
		//	Generate first set of numbers for problem on launch
		//*********************************************************************
		ONE = gen.nextInt(10);
		TWO = gen.nextInt(10);
		SUM = ONE + TWO;
		PRO.setText(ONE + " + " + TWO + " = ");

		//*********************************************************************
		//	Creating gui layout and placing on panel to display correctly
		//*********************************************************************
		STUFF.setLayout (new BorderLayout());
		STUFF.add (PRO, BorderLayout.CENTER);
		STUFF.add (ANSW, BorderLayout.EAST);
		STUFF.add (DIFF, BorderLayout.SOUTH);
		STUFF.setBackground(Color.cyan);

		add(STUFF);
	}

	//*********************************************************************
	//	Slider listener for DIFF JSlider
	//*********************************************************************
	public class SliderListener implements ChangeListener
	{
		public void stateChanged(ChangeEvent event)
		{
			//*********************************************************************************************
			//	Takes DIFF JSlider value and generates random number for PRO JLabel display
			//*********************************************************************************************
			if(DIFF.getValue() == 1)
			{
				ONE = gen.nextInt(10);
				TWO = gen.nextInt(10);
				SUM = ONE + TWO;
				PRO.setText(ONE + " + " + TWO + " = ");
			}
			if(DIFF.getValue() == 2)
			{
				ONE = gen.nextInt(99) + 9;
				TWO = gen.nextInt(99) + 9;
				SUM = ONE + TWO;
				PRO.setText(ONE + " + " + TWO + " = ");
			}
			if(DIFF.getValue() == 3)
			{
				ONE = gen.nextInt(999) + 99;
				TWO = gen.nextInt(999) + 99;
				SUM = ONE + TWO;
				PRO.setText(ONE + " + " + TWO + " = ");
			}
		}
	}

	//*********************************************************************
	//	Action listener for ANSW JTextField
	//*********************************************************************
	public class aListener implements ActionListener
	{

		public void actionPerformed (ActionEvent event)
		{
			String TOTAL = String.valueOf(SUM);
			String text = ANSW.getText();

			//****************************************************************************************************************************************
			//	Checks total value from ANSW JTextField to see if answer is correct, generating next problem and reset the text in the JTextField
			//****************************************************************************************************************************************
			if(text.equals(TOTAL))
			{
				JOptionPane.showMessageDialog(null, "Correct!!");
				if(DIFF.getValue() == 1)
				{
					ONE = gen.nextInt(10);
					TWO = gen.nextInt(10);
					SUM = ONE + TWO;
					PRO.setText(ONE + " + " + TWO + " = ");
				}
				if(DIFF.getValue() == 2)
				{
					ONE = gen.nextInt(99) + 9;
					TWO = gen.nextInt(99) + 9;
					SUM = ONE + TWO;
					PRO.setText(ONE + " + " + TWO + " = ");
				}
				if(DIFF.getValue() == 3)
				{
					ONE = gen.nextInt(999) + 99;
					TWO = gen.nextInt(999) + 99;
					SUM = ONE + TWO;
					PRO.setText(ONE + " + " + TWO + " = ");
				}
				ANSW.setText("");
			}
			else
			{
				JOptionPane.showMessageDialog(null, "Incorrect, Try Again.\n" + "Answer: " + TOTAL);
				if(DIFF.getValue() == 1)
				{
					ONE = gen.nextInt(10);
					TWO = gen.nextInt(10);
					SUM = ONE + TWO;
					PRO.setText(ONE + " + " + TWO + " = ");
				}
				if(DIFF.getValue() == 2)
				{
					ONE = gen.nextInt(99) + 9;
					TWO = gen.nextInt(99) + 9;
					SUM = ONE + TWO;
					PRO.setText(ONE + " + " + TWO + " = ");
				}
				if(DIFF.getValue() == 3)
				{
					ONE = gen.nextInt(999) + 99;
					TWO = gen.nextInt(999) + 99;
					SUM = ONE + TWO;
					PRO.setText(ONE + " + " + TWO + " = ");
				}
				ANSW.setText("");
			}
		}
	}


}