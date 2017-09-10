//****************************************************************************************************
//	Dylan Jenkins		10/22/2013
//	Encrypt.java
//	Encrypt class used to encrypt student passwords and write the
//	student ID and encrypted password to a binary file.
//****************************************************************************************************

import java.io.*;
import java.util.Scanner;

public class Encrypt
{
	public static void main (String[] args) throws IOException
	{
		//********************************************************
		// Declarations.
		//********************************************************
		String ID = "";
		String Pass = "";
		String EncryptedPass = "";

		//********************************************************
		// Scanner object used to scan file.
		//********************************************************
		Scanner scan = new Scanner (new File("StudentData.txt"));

		//********************************************************
		// Create the binary output objects.
		//********************************************************
		FileOutputStream fstream = new FileOutputStream("Students.bin");
		DataOutputStream outputFile = new DataOutputStream(fstream);

		//*********************************************************************************************************************************
		// Writes student ID and the encrypted Password to a binary file and prints the student ID, password, and encrypted password.
		//*********************************************************************************************************************************
		while(scan.hasNext())
		{
			ID = scan.next();
			Pass = scan.next();
			EncryptedPass = Pass;

			Student student = new Student(ID, Pass, EncryptedPass);
			student.EncryptPassword(5);

			System.out.println(student.toString() + "\n");

			outputFile.writeUTF(student.getStudentID());
			outputFile.writeUTF(student.getEncryptedPass());
		}

		//********************************************************
		// Closes the output file.
		//********************************************************
		System.out.println("Finished.");
		outputFile.close();
	}

}