// Name: Savings.java
// Author: Dylan Jenkins
// Date: 1/23/2013
// Purpose: Calculate how long it will take to save a given amount of money.

import java.util.Scanner;

public class Savings
{
	public static void main (String[] args)
	{
		int Months = 0;
		float Goal = 0.0f;
		float Increment = 0.0f;

		Scanner scan = new Scanner (System.in);

		System.out.print ("Input the amount of money you wish to save: ");
		Goal = scan.nextFloat();

		System.out.print ("Input amount you will save each month: ");
		Increment = scan.nextFloat();

		Months = (int) Goal / (int) Increment;

		System.out.println ("It will take " + Months + " months to save up to your goal.");
	}
}