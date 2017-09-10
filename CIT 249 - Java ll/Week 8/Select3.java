//**************************************************************************************************
//	Dylan Jenkins		10/10/2013
//	Select3.java
//	This program reads input from a text file. Displays students with more than 3 classes
//	along with creating a text file with the entire list of students.
//**************************************************************************************************

import java.io.*;
import java.util.Scanner;
import javax.swing.*;
import java.text.DecimalFormat;

public class Select3
{
	public static void main (String[] args) throws IOException
	{
		//**********************************************************
		//	Declarations.
		//**********************************************************
		String FirstName = "";
		String LastName = "";
		String City = "";
		String State = "";
		String NewFile = "SelectAll.txt";
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		int count4 = 1;
		int ID = 0;
		int Zip = 0;
		int Classes = 0;
		double AvgGPA = 0.0;
		double GPA = 0.0;

		//**********************************************************
		//	Creation of the file chooser dialog box.
		//**********************************************************
		JFileChooser chooser = new JFileChooser();

		//**********************************************************
		//	Formatting for GPA values.
		//**********************************************************
		DecimalFormat fmt = new DecimalFormat("0.00");

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
			//*************************************************************
			//	Creating file to write and reading input from other file.
			//*************************************************************
			File file = chooser.getSelectedFile();
			Scanner scan = new Scanner(file);

			FileWriter fw = new FileWriter(NewFile);
			BufferedWriter bw = new BufferedWriter(fw);
			PrintWriter outFile = new PrintWriter(bw);

			//**********************************************************
			//	While there is room on text file, continue reading.
			//**********************************************************
			while (scan.hasNext())
			{
				ID = scan.nextInt();
				FirstName = scan.next();
				LastName = scan.next();
				City = scan.next();
				State = scan.next();
				Zip = scan.nextInt();
				Classes = scan.nextInt();
				GPA = scan.nextDouble();

				if(Classes >= 3)
					System.out.println("Student ID:\t" + ID + "\nFirst Name:\t" + FirstName + "\nLast Name:\t" + LastName +
										"\nClasses:\t" + Classes + "\nGPA:\t\t" + fmt.format(GPA) + "\n");

				if(Classes==3)
					count1++;
				if(Classes==4)
					count2++;
				if(Classes>=5)
					count3++;

				//**********************************************************
				//	Write each student to the new text file.
				//**********************************************************
				outFile.println("Student: " + count4);
				outFile.println("\tStudent ID:\t" + ID);
				outFile.println("\tFirst Name:\t" + FirstName);
				outFile.println("\tLast Name:\t" + LastName);
				outFile.println("\tCity:\t\t" + City);
				outFile.println("\tState:\t\t" + State);
				outFile.println("\tZip:\t\t" + Zip);
				outFile.println("\tClasses:\t" + Classes);
				outFile.println("\tGPA:\t\t" + fmt.format(GPA));
				outFile.println();

				count4++;
				AvgGPA += GPA;
			}

			//**********************************************************
			//	Compute the average GPA and add to new file.
			//**********************************************************
			AvgGPA = (AvgGPA/count4);
			outFile.println("Total number of students: " + (count4 - 1));
			outFile.println("Average GPA of students: " + fmt.format(AvgGPA));

			outFile.close();

			//*******************************************************************
			//	Display the number of students taking said number of classes.
			//*******************************************************************
			System.out.println("Number of students taking 3 classes: " + count1);
			System.out.println("Number of students taking 4 classes: " + count2);
			System.out.println("Number of students taking 5+ classes: " + count3);
		}
	}


}