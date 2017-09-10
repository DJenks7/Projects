//****************************************************************************************************
//	Dylan Jenkins		10/22/2013
//	StudentData.java
//	Reads student information form a random text file, creates a student ID for each entry
//	and writes to a text document the student DI and password.
//****************************************************************************************************

import java.io.*;
import javax.swing.*;
import java.util.Random;
import java.util.Scanner;

public class StudentData
{
	public static void main (String[] args) throws IOException
	{
		//********************************************************
		//	Random number generator creation and declarations.
		//********************************************************

		Random GEN = new Random();

		String FirstName = "";
		String LastName = "";
		String Password = "";
		String NewFile = "StudentData.txt";
		String StudentID = "";

		//********************************************************
		// File chooser dialog box.
		//********************************************************
		JFileChooser chooser = new JFileChooser();

		//**********************************************************
		//	Call of the file chooser dialog box.
		//**********************************************************
		int status = chooser.showOpenDialog(null);

		//**********************************************************
		//	If selected item isnt blank, begin reading file.
		//**********************************************************
		if (status != JFileChooser.APPROVE_OPTION)
			System.out.println("No File Chosen, Try Again.");
		else
		{
			File file = chooser.getSelectedFile();
			Scanner scan = new Scanner(file);

			FileWriter fw = new FileWriter(NewFile);
			BufferedWriter bw = new BufferedWriter(fw);
			PrintWriter outFile = new PrintWriter(bw);

			System.out.println("Writing Data to file...");

			while(scan.hasNext())
			{
				FirstName = scan.next();
				LastName = scan.next();
				Password = scan.next();

				StudentID = FirstName.substring(0,1) + LastName.substring(0,1) + GEN.nextInt(10) + GEN.nextInt(10) + GEN.nextInt(10) + GEN.nextInt(10);

				outFile.println(StudentID);
				outFile.println(Password);
			}

			outFile.close();
			System.out.println("\nFinished");
		}
	}

}