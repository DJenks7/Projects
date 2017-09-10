//
//
//
//
//

public class MovieShowing implements Comparable
{
	private String Theater;
	private String MovieTitle;
	private String ShowTime;
	private String Rating;
	private String AdultTicket;
	private String ChildTicket;

	public MovieShowing (String mTheatre, String mTitle, String mTime, String mRating, String aTicket, String cTicket)
	{
		Theater = mTheatre;
		MovieTitle = mTitle;
		ShowTime = mTime;
		Rating = mRating;
		AdultTicket = aTicket;
		ChildTicket = cTicket;
	}

	public String toString()
	{
		String Phrase;

		Phrase = "Theater:\t" + Theater + "\nMovieTitle:\t" + MovieTitle +
				"\nShow Time:\t" + ShowTime + "\nRating:\t\t" + Rating +
				"\nAdult Ticket(s):\t" + AdultTicket + "\nChild Ticket(s):\t" + ChildTicket;

		return Phrase;
	}

	public int compareTo (Object other)
	{
		int result;

		if(Theater.equals(((MovieShowing)other).Theater))
			result = MovieTitle.compareTo(((MovieShowing)other).MovieTitle);
		else
			result = Theater.compareTo(((MovieShowing)other).Theater);

		return result;
	}
}