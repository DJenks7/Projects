//********************************************************************
//  JukeBox.java       Java Foundations
//
//  Demonstrates the use of a combo box.
//********************************************************************

import javax.swing.*;
import java.awt.*;

public class JukeBox
{
   //-----------------------------------------------------------------
   //  Creates and displays the controls for a juke box.
   //-----------------------------------------------------------------

   public static void main (String[] args)
   {
      JFrame frame = new JFrame ("Java Juke Box");
      frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

	  JukeBoxControls panel = new JukeBoxControls();

      ACPanel ac = new ACPanel();

      acControls Controls = new acControls(ac);

      vSlider volume = new vSlider();

      JPanel ButtonPanel = new JPanel();
      panel.add (Controls);
      panel.add (ac);
      panel.add (volume);

      frame.getContentPane().add(panel);

      frame.pack();
      frame.setVisible(true);
   }
}
