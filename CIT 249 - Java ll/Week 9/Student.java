//****************************************************************************************************
//	Dylan Jenkins		10/22/2013
//	Student.java
//	Student class used to create a studen object contains methods to encrypt and decrypt password
//	passed in by the file read.
//****************************************************************************************************

import java.util.Random;

public class Student
{
	//**********************************
	//	Declarations
	//**********************************
	private String StudentID;
	private String Password;
	private String EncryptedPass;
	private boolean encrypted;

	Random GEN = new Random();

	//**********************************
	//	Constructor
	//**********************************
	public Student(String sID, String Pass, String Encrypted)
	{
		StudentID = sID;
		Password = Pass;
		EncryptedPass = Encrypted;

		encrypted = false;
	}

	//*********************************
	//	Accessors
	//*********************************
	public String getStudentID()
	{
		return StudentID;
	}

	public String getPassword()
	{
		return Password;
	}

	public String getEncryptedPass()
	{
		return EncryptedPass;
	}

	//********************************
	//	Mutators
	//********************************
	public void setStudentID(String sID)
	{
		StudentID = sID;
	}

	public void setPassword(String Pass)
	{
		Password = Pass;
	}

	public void setEncryptedPass(String Encrypted)
	{
		EncryptedPass = Encrypted;
	}

	//*********************************
	// To string method
	//*********************************
	public String toString()
	{
		String Phrase;
		Phrase = "StudentID: " + StudentID + "\nPassword: " + Password + "\nEncrypted Password: " + EncryptedPass;
		return Phrase;
	}

	//*********************************
	//	Encrypted password method
	//*********************************
	public void EncryptPassword(int shift)
	{
		if(!encrypted)
		{
			String masked = "";
			for(int i=0; i<Password.length(); i++)
				masked = masked + (char)(Password.charAt(i)+shift);
			EncryptedPass = masked;
			encrypted = true;
		}
	}

	//*********************************
	//	Decrypted password method
	//*********************************
	public void DecryptPassword(int shift)
	{
		if(!encrypted)
		{
			String unmasked = "";
			for(int i=0; i<Password.length(); i++)
				unmasked = unmasked + (char)(Password.charAt(i)-shift);
			EncryptedPass = unmasked;
			encrypted = false;
		}
	}

}

