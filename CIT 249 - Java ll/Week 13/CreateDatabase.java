//*****************************************************************************************
//	Dylan Jenkins		11/19/2013
//	CreateDatabase.java
//	Program to connect to SQL database, read a excel delimiter file and
//	put the data from the file into the database.
//*****************************************************************************************

import java.sql.*;
import java.io.*;
import java.util.Scanner;

public class CreateDatabase
{
	public static void main (String args[]) throws IOException
	{
		//*********************************************************************************
		//	Declarations.
		//*********************************************************************************
		Connection con = null;

		String ID = "", Gender = "", First = "", Middle = "", Last = "";
		String Address = "", City = "", State = "", Zip = "", Birthday = "";
		String CardType = "", CardNumber = "", CardExpiration = "";

		String ReportFile = "Report.txt";

		FileWriter fw1 = new FileWriter(ReportFile);
		BufferedWriter bw1 = new BufferedWriter(fw1);
		PrintWriter outFile = new PrintWriter(bw1);

		//*********************************************************************************
		//	Try connection, if connected create table.
		//*********************************************************************************
		try
		{
			Class.forName("com.mysql.jdbc.Driver");

			con = DriverManager.getConnection("jdbc:mysql://localhost/StudentsReg?","root","");

			if (con != null)
			{
				//*********************************************************************************
				//	If connected, display message and create a blank database table.
				//*********************************************************************************
				System.out.println("Connection Made! Creating table...");

				Statement s = con.createStatement();

				boolean result = s.execute("CREATE TABLE Customers (Number INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY (Number), Gender varchar(255), " +
											"GivenName varchar(255), MiddleInitial varchar(255), Surname varchar(255), StreetAddress varchar(255), " +
											"City varchar(255), State varchar(255), ZipCode varchar(255), Birthday varchar(255), CCType varchar(255), " +
											"CCNumber varchar(255), CCExpires varchar(255))");

				System.out.println("\n\tTable creation result: " + result);
				System.out.println("\t(false is the expected result)");

    			//*********************************************************************************
    			//	Scan excel delimiter file, reading and adding data to recently made table.
    			//*********************************************************************************
    			System.out.println("\nScanning excel file to fill database...\n");

    			Scanner scan = new Scanner(new File("Customers.csv"));
				scan.useDelimiter(",");

				while (scan.hasNextLine())
				{
					//*********************************************************************************
					//	Initalizing the variables as data from the file.
					//*********************************************************************************
					ID = scan.next();
					Gender = scan.next();
					First = scan.next();
					Middle = scan.next();
					Last = scan.next();
					Address = scan.next();
					City = scan.next();
					State = scan.next();
					Zip = scan.next();
					Birthday = scan.next();
					CardType = scan.next();
					CardNumber = scan.next();
					CardExpiration = scan.nextLine();

					CardExpiration = CardExpiration.substring(1);

					if(State.equals("KY"))
					{
						//*********************************************************************************
						//	If the database customer lives in Kentucky, Write to the report...
						//*********************************************************************************
						outFile.println("ID:\t\t" + ID);
						outFile.println("First Name:\t" + First);
						outFile.println("Middle:\t\t" + Middle);
						outFile.println("Last Name:\t" + Last);
						outFile.println("City:\t\t" + City);
						outFile.println("State:\t\t" + State);
						outFile.println("Birthday:\t" + Birthday);
						outFile.println("Card Type:\t" + CardType);
						outFile.println();
					}

					//*********************************************************************************
					//	Insert the data from excel file into the database.
					//*********************************************************************************
					Statement s2 = con.createStatement(ResultSet.TYPE_FORWARD_ONLY, ResultSet.CONCUR_UPDATABLE);
					int rowCount = s2.executeUpdate("INSERT Customers (Gender, GivenName, MiddleInitial, Surname, StreetAddress, City, State, " +
													"ZipCode, Birthday, CCType, CCNumber, CCExpires) " +
													"VALUES ('" + Gender + "','" + First + "','" + Middle + "','" + Last + "','" + Address + "','" + City +
													"','" + State + "','" + Zip + "','" + Birthday + "','" + CardType + "','" + CardNumber + "','" + CardExpiration + "')");
				}
			}

			outFile.close();
			con.close();
			System.out.println("Complete!");

		}
		catch (SQLException ex)
		{
		      System.out.println("SQLException: " + ex.getMessage());
		      ex.printStackTrace();
		}
		catch (Exception ex)
		{
		      System.out.println("Exception: " + ex.getMessage());
		      ex.printStackTrace();
    	}
	}


}
