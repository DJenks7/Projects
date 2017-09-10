//************************************************************************
//	Dylan Jenkins		11/14/2013
//	DatabaseRead.java
//	Takes 4 SQL databases, reads them and prints two reports containing
//		information from the records.
//************************************************************************

import java.sql.*;
import java.io.*;
import java.text.DecimalFormat;

public class DatabaseRead
{
	public static void main (String args[]) throws IOException
	{
		//************************************************************************
		//	Declarations.
		//************************************************************************
		Connection con = null;

		DecimalFormat fmt = new DecimalFormat("0.00");

		String ID = "", ID2 = "";
		String FirstName = "";
		String LastName = "";
		String Major = "";
		String Course = "", CourseID = "";
		String CourseDesc = "";
		String Hours = "";
		String CurrentClasses = "";
		double GPA = 0.00;

		int Count1 = 0, Count2 = 0, Count3 = 0;
		double Avg1 = 0.00, Avg2 = 0.00, Avg3 = 0.00;

		String ReportOne = "PreRegistration.txt";
		String ReportTwo = "Major&GPA.txt";

		//************************************************************************
		//	File, Buffered, and Print Writer objects used to print to files.
		//************************************************************************
		FileWriter fw1 = new FileWriter(ReportOne);
		BufferedWriter bw1 = new BufferedWriter(fw1);
		PrintWriter outFile1 = new PrintWriter(bw1);

		FileWriter fw2 = new FileWriter(ReportTwo);
		BufferedWriter bw2 = new BufferedWriter(fw2);
		PrintWriter outFile2 = new PrintWriter(bw2);

		try
		{
			//************************************************************************
			//	Driver to read database.
			//************************************************************************
			Class.forName("com.mysql.jdbc.Driver");

			//************************************************************************
			//	Declaring connection con to the database folder.
			//************************************************************************
			con = DriverManager.getConnection("jdbc:mysql://localhost/StudentsReg?","root","");

			if (con != null)
			{
				System.out.println("We have connected to a database!");

				Statement s = con.createStatement();

				s.execute("SELECT students.StudentID, students.FirstName, students.LastName, students.Major, students.GPA, students.CurrentClasses FROM students");
				ResultSet rs = s.getResultSet();

				if (rs != null)
				{
					//************************************************************************
					//	If the result isnt empty, while there is another row of data...
					//************************************************************************
					while ( rs.next() )
					{
						//************************************************************************
						//	Declaring variables from database.
						//************************************************************************
						ID = rs.getString(1);
						FirstName = rs.getString(2);
						LastName = rs.getString(3);
						Major = rs.getString(4);
						GPA = rs.getDouble(5);
						CurrentClasses = rs.getString(6);

						Statement s2 = con.createStatement();

						s2.execute("SELECT registration.StudentID, registration.CourseID FROM registration");
						ResultSet rs2 = s2.getResultSet();

						if (rs2 != null)
						{
							while( rs2.next() )
							{
								//************************************************************************
								//	If the result isnt empty, while there is another row of data...
								//************************************************************************
								ID2 = rs2.getString(1);
								Course = rs2.getString(2);

								Statement s3 = con.createStatement();

								s3.execute("SELECT courses.CourseID, courses.CourseDesc, courses.Hours FROM courses");
								ResultSet rs3 = s3.getResultSet();

								if (rs3 != null)
								{
									while ( rs3.next() )
									{
										//************************************************************************
										//	If the result isnt empty, while there is another row of data...
										//************************************************************************
										CourseID = rs3.getString(1);
										CourseDesc = rs3.getString(2);
										Hours = rs3.getString(3);

										if(Course.equals(CourseID) && ID.equals(ID2))
										{
											//************************************************************************
											//	If the student is registered, print the students
											//		ID, First and Last name, Major, GPA, and Current Classes.
											//************************************************************************
											outFile1.println("Student ID:\t\t" + ID);
											outFile1.println("First Name:\t\t" + FirstName);
											outFile1.println("Last Name:\t\t" + LastName);
											outFile1.println("Major:\t\t\t" + Major);
											outFile1.println("Course ID:\t\t" + CourseID);
											outFile1.println("Course Description:\t" + CourseDesc);
											outFile1.println("Hours:\t\t\t" + Hours);
											outFile1.println();
										}
									}
								}
							}
						}
						s2.close();

						Statement s4 = con.createStatement();

						s4.execute("SELECT * FROM students ORDER BY major ASC");
						s4.execute("SELECT * FROM students ORDER BY gpa ASC");

						if(Major.equals("CSC") || Major.equals("ACC") || Major.equals("MGT"))
						{
							//************************************************************************
							//	If the students major is "CSC", "ACC", "MGT", print the students
							//		ID, First and Last name, Major, GPA, and Current Classes.
							//************************************************************************
							outFile2.println("Student ID:\t\t" + ID);
							outFile2.println("First Name:\t\t" + FirstName);
							outFile2.println("Last Name:\t\t" + LastName);
							outFile2.println("Major:\t\t\t" + Major);
							outFile2.println("GPA:\t\t\t" + GPA);
							outFile2.println("Current Classes:\t" + CurrentClasses);
							outFile2.println();

							if(Major.equals("CSC"))
							{
								Count1++;
								Avg1 += GPA;
							}

							if(Major.equals("ACC"))
							{
								Count2++;
								Avg2 += GPA;
							}

							if(Major.equals("MGT"))
							{
								Count3++;
								Avg3 += GPA;
							}
						}
					}

					//************************************************************************
					//	Declaring the averages.
					//************************************************************************
					Avg1 = Avg1/Count1;
					Avg2 = Avg2/Count2;
					Avg3 = Avg3/Count3;

					//************************************************************************
					//	Print number of students per major and average GPA.
					//************************************************************************
					outFile2.println("Number of Students in CSC Major: " + Count1);
					outFile2.println("Average GPA in CSC Major: " + fmt.format(Avg1));
					outFile2.println();
					outFile2.println("Number of Students in ACC Major: " + Count2);
					outFile2.println("Average GPA in CSC Major: " + fmt.format(Avg2));
					outFile2.println();
					outFile2.println("Number of Students in MGT Major: " + Count3);
					outFile2.println("Average GPA in CSC Major: " + fmt.format(Avg3));
					outFile2.println();
				}

				s.close();
				outFile1.close();
				outFile2.close();
				con.close();
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