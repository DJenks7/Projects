//--------------------------------------------------------------
// Driver program for Customer class
// Illustrates the use of user-defined classes.
//--------------------------------------------------------------


import java.util.Scanner;
import java.text.DecimalFormat;

public class CarDriver
{
	public static void main (String[] args)
	{
		Scanner in = new Scanner (System.in);
		DecimalFormat fmt = new DecimalFormat ("$#,##0.##");

		//----------------------------------------------------------------------------------------------
		// New objects are instantiated using the Customer class (Henry and Julie)
		// Henry is instantiated with data values using a constructor with a parameter list
		// Julie is instantiated with a constructor with no parameters so that mutators can be demonstrated later.
		//----------------------------------------------------------------------------------------------

		Customer Henry = new Customer("Henry", 150.89F, 315.15F);   //Henry's data

		Customer Julie = new Customer();							// Julie is created but has no data values yet

		//----------------------------------------------------------------------------------------------
		// Variables are declared
		//----------------------------------------------------------------------------------------------

		float total1, total2;
		String customerName;
		float customerParts, customerLabor;

		//----------------------------------------------------------------------------------------------
		// Data is input for the Julie object - This illustrates the use of mutators (setting object values)
		//----------------------------------------------------------------------------------------------
		System.out.print ("Customer name: ");
		customerName = in.nextLine();


		System.out.print ("Cost of parts: ");
		customerParts = in.nextFloat();

		System.out.print ("Cost of labor: ");
		customerLabor = in.nextFloat();
		System.out.println();


		//----------------------------------------------------------------------------------------------
		// The values input for Julie are assigned to the data items for the object named Julie
    	//----------------------------------------------------------------------------------------------
		Julie.setName(customerName);
		Julie.setParts(customerParts);
		Julie.setLabor(customerLabor);


		//----------------------------------------------------------------------------------------------
		// At this point the objects named Henry and Julie have data values.
		//
		// The calcTotal() method in the Customer class will be used to total the bill for Henry and Julie
		//----------------------------------------------------------------------------------------------


		total1 = Henry.calcTotal();
		total2 = Julie.calcTotal();

		System.out.println("====Examples of using calctotal method=====");
		System.out.println("Henry Total: " + fmt.format(total1));
		System.out.println("Julie Total: " + fmt.format(total2));
		System.out.println();

		//----------------------------------------------------------------------------------------------
		// Some programs need to access individual data values from an object.  To do this, use accessors.
		// Below are examples of using accessors.
		//----------------------------------------------------------------------------------------------

		System.out.println("====Examples of using accessors=====");
		System.out.println ("Name of first customer: " + Henry.getName());
		System.out.println ("Labor charge for second customer:" + fmt.format(Julie.getLabor()));
		System.out.println();


		//----------------------------------------------------------------------------------------------
		// Example of using a class method:  Printing a record
		//----------------------------------------------------------------------------------------------
		System.out.println("====Examples of toString method=====");
		System.out.println(Henry.toString());
		System.out.println(Julie.toString());
		System.out.println();

	}
}