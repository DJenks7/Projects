//********************************************************************
//	Dylan Jenkins			9/16/13
//	Commission.java
//	Represents an commission employee being the child class of hourly
//********************************************************************

public class Commission extends Hourly2 implements ChristmasBonus
{
	private double TOTAL;
	private double COMMISSION;

   public Commission (String eName, String eAddress, String ePhone,
                  String socSecNumber, double rate, double eCommission)
   {
      super (eName, eAddress, ePhone, socSecNumber, rate);

      COMMISSION = eCommission;
   }

   public void addSales(double totalSales)
   {
   		TOTAL += totalSales;
   }

   public double pay()
   {
	    double PAY = super.pay();

   		double payment = PAY + COMMISSION;

   		TOTAL = 0;
   		hoursWorked = 0;

   		return payment;
   }

   public String toString()
   {
   		String Phrase = super.toString();

   		Phrase += "\nTotal Sales: " + TOTAL;

   		return Phrase;
   }

   public double BonusPay()
   {
	   double BONUS = payRate * 12;
	   System.out.println("Christmas Bonus: $" + DF.format(BONUS));
	   return BONUS;
   }


}