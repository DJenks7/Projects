//********************************************************************
//  Volunteer2.java       Java Foundations
//
//  Solution to Programming Project 9.1
//********************************************************************

import java.text.*;

public class Volunteer2 extends StaffMember2 implements ChristmasBonus
{
	DecimalFormat DF = new DecimalFormat("#.00");

   //-----------------------------------------------------------------
   //  Constructor: Sets up this volunteer using the specified
   //  information.
   //-----------------------------------------------------------------
   public Volunteer2 (String eName, String eAddress, String ePhone)
   {
      super (eName, eAddress, ePhone);
   }

   //-----------------------------------------------------------------
   //  Returns a zero pay value for this volunteer.
   //-----------------------------------------------------------------
   public double pay()
   {
      return 0.0;
   }

   public double BonusPay()
   {
		double BONUS = 100;
		System.out.println("Christmas Bonus: $" + DF.format(BONUS));
		return BONUS;
   }
}
