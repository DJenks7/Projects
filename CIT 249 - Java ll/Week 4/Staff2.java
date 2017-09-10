//********************************************************************
//  Staff2.java       Java Foundations
//
//  Solution to Programming Project 9.1
//********************************************************************

public class Staff2
{
   private StaffMember2[] staffList;

   //-----------------------------------------------------------------
   //  Constructor: Sets up the list of staff members.
   //-----------------------------------------------------------------
   public Staff2 ()
   {
      staffList = new StaffMember2[8];

      staffList[0] = new Executive2 ("Sam", "123 Main Line",
         "555-0469", "123-45-6789", 2423.07);

      staffList[1] = new Employee2 ("Carla", "456 Off Line",
         "555-0101", "987-65-4321", 1246.15);
      staffList[2] = new Employee2 ("Woody", "789 Off Rocker",
         "555-0000", "010-20-3040", 1169.23);

      staffList[3] = new Hourly2 ("Diane", "678 Fifth Ave.",
         "555-0690", "958-47-3625", 10.55);

      staffList[4] = new Volunteer2 ("Norm", "987 Suds Blvd.",
         "555-8374");
      staffList[5] = new Volunteer2 ("Cliff", "321 Duds Lane",
         "555-7282");

      staffList[6] = new Commission ("Ron", "546 Mainland Dr.",
      	"555-8141", "547-87-9845", 11.75, .20);
      staffList[7] = new Commission ("Sammy", "180 Barkley Lane",
      	"555-6256", "695-14-3824", 14.50, .15);

      ((Executive2)staffList[0]).awardBonus (500.00);

      ((Commission)staffList[6]).addHours(35);
      ((Commission)staffList[6]).addSales(400);

      ((Commission)staffList[7]).addHours(40);
      ((Commission)staffList[7]).addSales(950);

      ((Hourly2)staffList[3]).addHours (40);
   }

   //-----------------------------------------------------------------
   //  Pays all staff members.
   //-----------------------------------------------------------------
   public void payday ()
   {
      double amount;

      for (int count=0; count < staffList.length; count++)
      {
         System.out.println (staffList[count]);

         amount = staffList[count].pay();  // polymorphic

         if(count == 0)
         {
			 ChristmasBonus bonus;
			 bonus = new Executive2("Sam", "123 Main Line", "555-0469", "123-45-6789", 2423.07);
			 bonus.BonusPay();
		 }
         if(count == 1)
         {
			 ChristmasBonus bonus;
			 bonus = new Employee2("Carla", "456 Off Line", "555-0101", "987-65-4321", 1246.15);
			 bonus.BonusPay();
		 }
		 if(count == 2)
		 {
			 ChristmasBonus bonus;
			 bonus = new Employee2("Woody", "789 Off Rocker", "555-0000", "010-20-3040", 1169.23);
			 bonus.BonusPay();
		 }
		 if(count == 3)
		 {
			 ChristmasBonus bonus;
			 bonus = new Hourly2("Diane", "678 Fifth Ave.", "555-0690", "958-47-3625", 10.55);
			 bonus.BonusPay();
		 }
		 if(count == 4)
		 {
			ChristmasBonus bonus;
			bonus = new Volunteer2("Norm", "987 Suds Blvd.", "555-8374");
			bonus.BonusPay();
		}
		if(count == 5)
		{
			ChristmasBonus bonus;
			bonus = new Volunteer2("Cliff", "321 Duds Lane", "555-7282");
			bonus.BonusPay();
		}
		if(count == 6)
		{
			ChristmasBonus bonus;
			bonus = new Commission("Ron", "546 Mainland Dr.", "555-8141", "547-87-9845", 11.75, .20);
			bonus.BonusPay();
		}
		if(count == 7)
		{
			ChristmasBonus bonus;
			bonus = new Commission("Sammy", "180 Barkley Lane", "555-6256", "695-14-3824", 14.50, .15);
			bonus.BonusPay();
		}

         if (amount == 0.0)
            System.out.println ("Thanks!");
         else
            System.out.println ("Paid: " + amount);

         System.out.println ("-----------------------------------");
      }
   }
}
