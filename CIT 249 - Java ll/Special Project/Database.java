//************************************************************************************
//	Dylan Jenkins		12/1/13
//	Database.java
//	This program is designed to read an Excel .csv file and create
//	an SQL database, add a new empty field (column) to the database or
//	remove an existing one, search the database, and print the database.
//************************************************************************************

import java.sql.*;
import java.io.*;
import javax.swing.*;
import java.util.Scanner;

public class Database
{
	public static void main (String args[]) throws IOException
	{
		//****************************************************************************
		//	Delcarations.
		//****************************************************************************
		int Entry;
		String FileName;
		String Search;
		String NewField;
		String FieldName;
		String TableName = "";
		String Remove;
		Boolean Found = false;
		Boolean result2 = true;
		Boolean result3 = true;

		//****************************************************************************
		//	Declarations used when reading file.
		//****************************************************************************
		String ID = "", First = "", Last = "", Address = "", City = "";
		String State = "", Zip = "", EMail = "", Phone = "", Tracking = "";

		String Menu = "1.	Read an .scv file.\n" +
					"2.	Add new field to database.\n" +
					"3.	Search database.\n" +
					"4.	Remove new field from database.\n" +
					"5.	Print database to a file.\n" +
					"6.	Quit.\n" +
					"\n(Valid entry is a number between 1-6)\n" +
					"Enter Option: ";

		//	Used for printing to file.
		String Temp = "";

		//****************************************************************************
		//	Creates connection.
		//****************************************************************************
		Connection con = null;

		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			con = DriverManager.getConnection("jdbc:mysql://localhost/StudentsReg?","root","");

			//	If connected to the database.
			if(con != null)
			{
				//	Creates scanner object for input.
				Scanner scan = new Scanner (System.in);

				//	Creates file choosing object.
				JFileChooser chooser = new JFileChooser();

				System.out.println("Hello!");
				System.out.println("This program will assist you with the creation " +
									"of an SQL database.");
				System.out.println();
				System.out.println("Enter a number for you selection.");
				System.out.println();
				System.out.print(Menu);
				Entry = scan.nextInt();

				while(Entry != 6)
				{
					if(Entry == 1)
					{
						//************************************************************
						//	Opens file choosing dialog box.
						//************************************************************
						int status = chooser.showOpenDialog(null);

						if (status != JFileChooser.APPROVE_OPTION)
							System.out.println("No File Chosen, Try Again.");
						else
						{
							System.out.println("\nReading entry...");

							File file = chooser.getSelectedFile();

							Scanner scan2 = new Scanner(file);
							scan2.useDelimiter(",");

							System.out.print("\nEnter desired database table name: ");

							TableName = scan.next();

							//************************************************************
							//	Creates table.
							//************************************************************
							Statement s = con.createStatement();

							boolean result = s.execute("CREATE TABLE " + TableName + " (Number INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY (Number), " +
											"FirstName varchar(255), LastName varchar(255), Address varchar(255), City varchar(255), State varchar(255), " +
											"Zip varchar(255), EMail varchar(255), Phone varchar(255), Tracking varchar(255))");

							System.out.println("\n\tTable creation result: " + result);
							System.out.println("\t(false is the expected result)\n");
							System.out.println("Reading file and inserting data...\n");

							//************************************************************
							//	Scanning file while there is still data.
							//************************************************************
							while(scan2.hasNextLine())
							{
								ID = scan2.next();
								First = scan2.next();
								Last = scan2.next();
								Address = scan2.next();
								City = scan2.next();
								State = scan2.next();
								Zip = scan2.next();
								EMail = scan2.next();
								Phone = scan2.next();
								Tracking = scan2.nextLine();

								Tracking = Tracking.substring(1);

								//************************************************************
								//	Inserting data into the database.
								//************************************************************
								Statement s2 = con.createStatement(ResultSet.TYPE_FORWARD_ONLY, ResultSet.CONCUR_UPDATABLE);
								int rowCount = s2.executeUpdate("INSERT " + TableName + " (FirstName, LastName, Address, City, State, Zip, EMail, Phone, Tracking) " +
															"VALUES ('" + First + "','" + Last + "','" + Address + "','" + City + "','" + State +
															"','" + Zip + "','" + EMail + "','" + Phone + "','" + Tracking + "')");
								s2.close();
							}

							s.close();
							System.out.println("Complete!\n");
							System.out.print(Menu);
							Entry = scan.nextInt();
						}
					}
					if(Entry == 2)
					{
						System.out.print("Enter desired new column field name: ");

						FieldName = scan.next();

						System.out.println("\nAdding entry...\n");

						//************************************************************
						//	Add a new column to the table.
						//************************************************************
						Statement s3 = con.createStatement();
						result2 = s3.execute("ALTER TABLE " + TableName + " ADD COLUMN (" + FieldName + " varchar(255))");
						s3.close();

						System.out.println("\tTable modification result: " + result2 + "");
						System.out.println("\t(false is the expected result)\n");

						System.out.print(Menu);
						Entry = scan.nextInt();
					}
					if(Entry == 3)
					{
						//************************************************************
						//	Obtain search item.
						//************************************************************
						System.out.println("\nCase sensetive, when searching for a");
						System.out.println("name make sure to capitalize first letter.\n");
						System.out.print("Enter item to search for: ");
						Search = scan.next();

						System.out.println("\nSearching...\n");

						File file = chooser.getSelectedFile();

						Scanner scan3 = new Scanner(file);
						scan3.useDelimiter(",");

						//************************************************************
						//	While file has more data.
						//************************************************************
						while(scan3.hasNextLine())
						{
							ID = scan3.next();
							First = scan3.next();
							Last = scan3.next();
							Address = scan3.next();
							City = scan3.next();
							State = scan3.next();
							Zip = scan3.next();
							EMail = scan3.next();
							Phone = scan3.next();
							Tracking = scan3.nextLine();

							Tracking = Tracking.substring(1);

							String Message = "ID:\t\t" + ID + "\nFirst Name:\t" + First + "\nLast Name:\t" + Last +
											"\nAddress:\t" + Address + "\nCity:\t\t" + City + "\nState:\t\t" + State +
											"\nZip:\t\t" + Zip + "\nE-Mail:\t\t" + EMail + "\nPhone #:\t" + Phone + "\nTracking #:\t" +
											Tracking + "\n";

							//************************************************************
							//	If Search item is the same as any item
							//	in the database.
							//************************************************************
							if(ID.equals(Search))
							{
								System.out.println(Message);
								Found = true;
							}

							if(First.equals(Search))
							{
								System.out.println(Message);
								Found = true;
							}

							if(Last.equals(Search))
							{
								System.out.println(Message);
								Found = true;
							}

							if(Address.equals(Search))
							{
								System.out.println(Message);
								Found = true;
							}

							if(City.equals(Search))
							{
								System.out.println(Message);
								Found = true;
							}

							if(State.equals(Search))
							{
								System.out.println(Message);
								Found = true;
							}

							if(Zip.equals(Search))
							{
								System.out.println(Message);
								Found = true;
							}

							if(EMail.equals(Search))
							{
								System.out.println(Message);
								Found = true;
							}

							if(Phone.equals(Search))
							{
								System.out.println(Message);
								Found = true;
							}

							if(Tracking.equals(Search))
							{
								System.out.println(Message);
								Found = true;
							}
						}

						if(Found == false)
						{
								System.out.println("Sorry, item not found.\n");
						}

						System.out.print(Menu);
						Entry = scan.nextInt();
					}
					if(Entry == 4)
					{
						//************************************************************
						//	Obtain field to remove.
						//************************************************************
						System.out.println("\nRemember it is case sensetive. Exact name required.");
						System.out.print("What field do you wish to remove?: ");
						Remove = scan.next();

						System.out.println("\nRemoving Entry...\n");

						//************************************************************
						//	Remove field from database.
						//************************************************************
						Statement s4 = con.createStatement();
						result3 = s4.execute("ALTER TABLE " + TableName + " DROP COLUMN " + Remove + "");

						System.out.println("\tTable Modification result: " + result3 + "");
						System.out.println("\t(false is the expected result)\n");

						System.out.print(Menu);
						Entry = scan.nextInt();
					}
					if(Entry == 5)
					{
						//************************************************************
						//	Obtain file name.
						//************************************************************
						System.out.print("Enter desired file name: ");
						FileName = scan.next();
						FileName = FileName + ".txt";

						FileWriter fw1 = new FileWriter(FileName);
						BufferedWriter bw1 = new BufferedWriter(fw1);
						PrintWriter outFile = new PrintWriter(bw1);

						System.out.println("\nPrinting...\n");

						Statement s5 = con.createStatement();

						s5.execute("SELECT * FROM " + TableName + "");
						ResultSet rs = s5.getResultSet();

						ResultSetMetaData rsmd = rs.getMetaData();
						int NumColumns = rsmd.getColumnCount();

						//************************************************************
						//	While file has more data.
						//************************************************************
						while( rs.next() )
						{
							//	Left out labels in report to ensure
							//		no mixing up wrong labels and data.
							for(int i=1; i<=NumColumns; i++)
							{
								Temp = rs.getString(i);

								outFile.println(Temp);
							}
							outFile.println();
						}

						outFile.close();
						System.out.print(Menu);
						Entry = scan.nextInt();
					}
					if(Entry < 1 || Entry > 6)
					{
						System.out.println("\nInvalid Entry, try again.\n");
						System.out.print(Menu);
						Entry = scan.nextInt();
					}
				}
			}
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