//--------------------------------------------------------------
// A driver program for Horse class
// Save this program in the same location as your Horse class
// Compile your Horse class.  Compile this driver program.
// Run the driver program to test your class
//--------------------------------------------------------------


import java.util.Scanner;
import java.util.Calendar;

public class HorseDriver
{
	public static void main (String[] args)
	{
		Scanner in = new Scanner (System.in);

		//-----------------------------------------------------------------------------------------------
		// New objects are instantiated using the Horse class
		// 2 objects use a constructor with 6 parameters
		// 1 object uses a default constructor (no parameters)
		//-----------------------------------------------------------------------------------------------

		Horse TomsHorse = new Horse("Shiraz", 1340, 2010, 'M', "Run for Gold", "Miss Auburn");
		Horse BobsHorse = new Horse("Lady Luck", 1280, 2009, 'F', "Man of Mine", "Duchess of Lex");
		Horse myHorse = new Horse();

		//-----------------------------------------------------------------------------------------------
		// Variables are declared
		//-----------------------------------------------------------------------------------------------

		String name = "", sire = "", dam = "", sGender = "";
		int myAge = 0;
		String fullGender;

		int weight = 0, birthYear = 0;
		char gender = ' ';
		int currentYear = Calendar.getInstance().get(Calendar.YEAR);

		//-----------------------------------------------------------------------------------------------
		// Data is input for myHorse
		//-----------------------------------------------------------------------------------------------

		while (name.equals(""))
		{
			System.out.print ("What is your horse's name? ");
			name = in.nextLine();
		}

		while (weight <= 0 || weight >= 2500)
		{
			System.out.print ("What is your horse's weight (between 1 and 2500 pounds)? ");
			weight = in.nextInt();
		}

		while (birthYear < 1950 || birthYear > currentYear)
		{
			System.out.print ("What year was your horse born (4-digit year between 1950 and present) ");
			birthYear = in.nextInt();
			sGender = in.nextLine();
		}

		while (gender == ' ')
		{
			System.out.print ("What gender is your horse (use M or F)? ");
			sGender =in.nextLine();
			gender = (char) sGender.charAt(0);



		}

		while (sire.equals(null))
		{
			System.out.print ("Who is the sire of your horse (father's name)? ");
			sire = in.nextLine();
		}

		while (dam.equals(null))
		{
			System.out.print ("Who is the dam of your horse (mother's name)? ");
			dam = in.nextLine();
		}

		System.out.println();


		//-----------------------------------------------------------------------------------------------
		// The data values for myHorse are updated using the setters (mutators) in the Horse class
		//-----------------------------------------------------------------------------------------------

		myHorse.setName(name);
		myHorse.setWeight(weight);
		myHorse.setBirthYear(birthYear);
		myHorse.setGender(gender);
		myHorse.setSire(sire);
		myHorse.setDam(dam);


		//-----------------------------------------------------------------------------------------------
		// Examples of using getters (accessors) to "access" instance data from an object in the Horse class
 		//-----------------------------------------------------------------------------------------------

		System.out.println ("Tom\'s horse is named " + TomsHorse.getName() + " and weighs " + TomsHorse.getWeight() + " pounds.\n");
		System.out.println ("Bob\'s horse is " + BobsHorse.getName() + ". She was born of " + BobsHorse.getSire() + " and " + BobsHorse.getDam() + ".\n");
		System.out.println ("My horse is named " + myHorse.getName() + " and was born in " + myHorse.getBirthYear() + "\n");



		//-----------------------------------------------------------------------------------------------
		// Examples of using the toString( ) method to display instance data from a class
		// Also, uses the calculateHorseAge( ) method
		//-----------------------------------------------------------------------------------------------


		System.out.println (BobsHorse + "\n" + "Age: " +  BobsHorse.calculateHorseAge() +"\n\n");


	}
}