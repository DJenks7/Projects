//****************************************************************************************************
//	Dylan Jenkins		10/22/2013
//	Decrypt.java
//	Decrypt class used to decrypt student passwords, display them, and write a new text file
//	containing the student ID, encrypted and decrypted passwords.
//****************************************************************************************************

import java.io.*;
import java.util.Scanner;

public class Decrypt
{
	public static void main (String[] args) throws IOException
	{
		//********************************************************
		// Declarations.
		//********************************************************
		String StudentID = "";
		String Password = "";
		String EncryptedPassword;
		boolean endOfFile = false;

		//********************************************************
		//	Create the binary input and output objects.
		//********************************************************
		FileInputStream fstream = new FileInputStream("Students.bin");
		DataInputStream inputFile = new DataInputStream(fstream);

		FileOutputStream fstream2 = new FileOutputStream("Students.ran");
		DataOutputStream outFile = new DataOutputStream(fstream2);

		System.out.println("Reading from the file...");
		System.out.println("Writing to new file as well...");

		//*********************************************************************************************************
		//	Reads and writes from and to the file and displays student ID, password, and encrypted password.
		//*********************************************************************************************************
		while(!endOfFile)
		{
			try
			{
				StudentID = inputFile.readUTF();
				Password = inputFile.readUTF();
				EncryptedPassword = Password;

				Student student = new Student(StudentID, Password, EncryptedPassword);
				student.DecryptPassword(5);

				System.out.println("\nStudent ID: " + student.getStudentID());
				System.out.println("Encrypted Password: " + student.getPassword());
				System.out.println("Decrypted Password: " + student.getEncryptedPass());

				outFile.writeUTF(student.toString());
			}
			catch (EOFException e)
			{
				endOfFile = true;
			}
		}

		//********************************************************
		//	Closes the input and output files.
		//********************************************************
		inputFile.close();
		System.out.println("\nFinished.\n");
		outFile.close();

	}


}