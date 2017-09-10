// Author: Dylan Jenkins
// Date: 1/23/2013
// Purpose: To divide marathon runners times in minutes to hours and minutes as the remainder.

import java.util.Scanner;

public class Marathon
{

	public static void main (String[] args)
	{

		String Name = " ";
		int Minutes = 0;
		int Time = 0;
		int Remainder = 0;

		Scanner scan = new Scanner (System.in);

		System.out.print ("Enter runners name: ");
		Name = scan.nextLine();

		System.out.print ("Enter runners time(in minutes): ");
		Minutes = scan.nextInt();

		Time = Minutes / 60;
		Remainder = Minutes % 60;

		System.out.println (Name + "'s Time: " + Time + " Hours & " + Remainder + " Minutes.");

		boolean hasNext;("Enter another runner?: ");
	}
}