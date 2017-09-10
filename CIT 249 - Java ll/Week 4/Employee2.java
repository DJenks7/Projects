//********************************************************************
//  Employee2.java       Java Foundations
//
//  Solution to Programming Project 9.1
//********************************************************************

import java.text.*;

public class Employee2 extends StaffMember2 implements ChristmasBonus
{
   protected String socialSecurityNumber;
   protected double payRate;
   DecimalFormat DF = new DecimalFormat("#.00");

   //-----------------------------------------------------------------
   //  Constructor: Sets up this employee with the specified
   //  information.
   //-----------------------------------------------------------------
   public Employee2 (String eName, String eAddress, String ePhone,
                    String socSecNumber, double rate)
   {
      super (eName, eAddress, ePhone);

      socialSecurityNumber = socSecNumber;
      payRate = rate;
   }

   //-----------------------------------------------------------------
   //  Returns information about an employee as a string.
   //-----------------------------------------------------------------
   public String toString()
   {
      String result = super.toString();

      result += "\nSocial Security Number: " + socialSecurityNumber;

      return result;
   }

   //-----------------------------------------------------------------
   //  Returns the pay rate for this employee.
   //-----------------------------------------------------------------
   public double pay()
   {
      return payRate;
   }

   public double BonusPay()
   {
	   double BONUS = payRate * 0.10;
	   System.out.println("Christmas Bonus: $" + DF.format(BONUS));
	   return BONUS;
   }
}
