//********************************************************************
//  Executive2.java       Java Foundations
//
//  Solution to Programming Project 9.1
//********************************************************************

public class Executive2 extends Employee2 implements ChristmasBonus
{
   private double bonus;

   //-----------------------------------------------------------------
   //  Constructor: Sets up this executive with the specified
   //  information.
   //-----------------------------------------------------------------
   public Executive2 (String eName, String eAddress, String ePhone,
                     String socSecNumber, double rate)
   {
      super (eName, eAddress, ePhone, socSecNumber, rate);

      bonus = 0;  // bonus has yet to be awarded
   }

   //-----------------------------------------------------------------
   //  Awards the specified bonus to this executive.
   //-----------------------------------------------------------------
   public void awardBonus (double execBonus)
   {
      bonus = execBonus;
   }

   //-----------------------------------------------------------------
   //  Computes and returns the pay for an executive, which is the
   //  regular employee payment plus a one-time bonus.
   //-----------------------------------------------------------------
   public double pay()
   {
      double payment = super.pay() + bonus;

      bonus = 0;

      return payment;
   }

   public double BonusPay()
   {
	   double BONUS = payRate * 0.15;
	   System.out.println("Christmas Bonus: $" + DF.format(BONUS));
	   return BONUS;
   }
}
