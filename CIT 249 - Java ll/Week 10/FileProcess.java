//****************************************************************************************************
//	Dylan Jenkins		10/29/2013
//	FileProcess.java
//	Reads exel delimiter file once and writes two seperate reports containing
//	name, average, and total number per grade value to one and name, average, final,
//	and difference between final and average to the other if their major is CIT.
//****************************************************************************************************

import java.util. Scanner;
import java.io.*;
import java.text.DecimalFormat;

public class FileProcess
{
	public static void main(String[] args) throws IOException
	{
		//********************************************************
		//	Declarations for reading from and writing to file.
		//********************************************************
		String StudentID;
		String LastName;
		String FirstName;
		int Q1, Q2, Q3;
		int Final;
		int[] H = new int[11];
		String Major;
		String GPA;

		String NewFileOne = "ReportOne.txt";
		String NewFileTwo = "ReportTwo.txt";

		//********************************************************
		//	Declarations for calculations.
		//********************************************************
		double A1 = 0, Average;
		int lowest = 0;
		int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;

		//********************************************************
		//	Decimal formatting.
		//********************************************************
		DecimalFormat fmt = new DecimalFormat("0.00");

		//********************************************************
		//	Scanner object.
		//********************************************************
		Scanner scan = new Scanner(new File("Students.csv"));
		scan.useDelimiter(",|\n");

		//********************************************************
		//	File writing objects.
		//********************************************************
		FileWriter fw1 = new FileWriter(NewFileOne);
		BufferedWriter bw1 = new BufferedWriter(fw1);
		PrintWriter outFile1 = new PrintWriter(bw1);

		FileWriter fw2 = new FileWriter(NewFileTwo);
		BufferedWriter bw2 = new BufferedWriter(fw2);
		PrintWriter outFile2 = new PrintWriter(bw2);

		System.out.println("Reading from file...");
		System.out.println("Writing to file...");

		//********************************************************
		//	Reading file.
		//********************************************************
		while (scan.hasNext())
		{
			//	Scan file and obtain variable values.
			StudentID = scan.next();
			LastName = scan.next();
			FirstName = scan.next();
			Q1 = scan.nextInt();
			Q2 = scan.nextInt();
			Q3 = scan.nextInt();
			Final = scan.nextInt();

			for(int i=0; i<11; i++)
				H[i] = scan.nextInt();

			Major = scan.next();
			GPA = scan.next();

			//********************************************************
			//	Set the lowest homework score.
			//********************************************************
			lowest = H[0];

			for(int i=0; i<11; i++)
				if(H[i] <= lowest)
					lowest = H[i];

			//********************************************************
			//	Add homework scores, leaving out the lowest.
			//********************************************************
			for(int i=0; i<11; i++)
				if(H[i] != lowest)
					A1 = A1 + H[i];

			//********************************************************
			//	Compute average.
			//********************************************************
			A1 = A1/10;

			Average = (Q1 + Q2 + Q3 + Final + A1)/5;

			//********************************************************
			// Count number of student grades.
			//********************************************************
			if(100 >= Average && Average >= 90)
				count1++;
			if(90 > Average && Average >= 80)
				count2++;
			if(80 > Average && Average >= 70)
				count3++;
			if(70 > Average && Average >= 60)
				count4++;
			if(Average < 60)
				count5++;

			//********************************************************
			//	Writing to files.
			//********************************************************
			outFile1.println("Name:\t\t" + FirstName + " " + LastName);
			outFile1.println("Average:\t" + fmt.format(Average) + "%");
			outFile1.println();

			if(Major.equals("CIT"))
			{
				outFile2.println("Name:\t\t" + FirstName + " " + LastName);
				outFile2.println("Average:\t" + fmt.format(Average) + "%");
				outFile2.println("Final Exam:\t" + Final);
				outFile2.println("Difference:\t" + fmt.format(Final-Average));
				outFile2.println();
			}
		}

		outFile1.println("Number of Students Who Earned an");
		outFile1.println("A: " + count1 + "   " + "B: " + count2 + "   " + "C: " +
							count3 + "   " + "D: " + count4 + "   " + "E: " + count5);
		outFile1.close();
		outFile2.close();
		System.out.println("Finished!");
	}


}