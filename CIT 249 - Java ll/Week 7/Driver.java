//
//
//
//
//

public class Driver
{
	public static void main(String[] args)
	{
		MovieShowing[] Movies = new MovieShowing[20];

		Movies[0] = new MovieShowing("Cinemark", "The Girl with the Dragon Tattoo", "Mon-Fri 7:30 & 9:30\n\t\tSat & Sun 5:00 & 7:00", "R", "$7.00", "$0.00");
		Movies[1] = new MovieShowing("Cinemark", "The Avengers", "Mon-Fri 7:30 & 9:30\n\t\tSat & Sun 4:45 & 6:45", "PG-13", "$7.00", "$3.50");
		Movies[2] = new MovieShowing("Cinemark", "Red Dawn", "Mon-Fri 7:30 & 9:30\n\t\tSat & Sun 3:30 & 5:00", "PG-13", "$7.00", "$3.50");
		Movies[3] = new MovieShowing("Cinemark", "Wrath of the Titans", "Mon-Fri 7:30 & 9:30\n\t\tSat & Sun 5:00 & 7:00", "PG-13", "$7.00", "$3.50");
		Movies[4] = new MovieShowing("Cinemark", "X-Men Origins: Wolverine", "Mon-Fri 7:30 & 9:30\n\t\tSat & Sun 4:45 & 6:00", "PG-13", "$7.00", "$3.50");
		Movies[5] = new MovieShowing("Cinemark", "Man on a Ledge", "Mon-Fri 7:30 & 9:30\n\t\tSat & Sun 2:45 & 5:00", "PG-13", "$7.00", "$3.50");
		Movies[6] = new MovieShowing("Cinemark", "Zero Dark Thirty", "Mon-Fri 7:00 & 9:00\n\t\tSat & Sun 3:00 & 6:30", "R", "$7.00", "$0.00");
		Movies[7] = new MovieShowing("AmStar 14", "The Avengers", "Mon-Fri 6:30 & 8:30\n\t\tSat & Sun 3:30 & 5:00", "PG-13", "$6.50", "$3.00");
		Movies[8] = new MovieShowing("AmStar 14", "Red Dawn", "Mon-Fri 5:45 & 7:45\n\t\tSat & Sun 7:00 & 8:00", "PG-13", "$6.50", "$3.00");
		Movies[9] = new MovieShowing("AmStar 14", "Chronicle", "Mon-Fri 6:30 & 8:00\n\t\tSat & Sun 7:00 & 8:00", "PG-13", "$6.50", "$3.00");
		Movies[10] = new MovieShowing("AmStar 14", "Men in Black 3", "Mon-Fri 6:00 & 7:00\n\t\tSat & Sun 3:00 & 6:30", "PG-13", "$6.50", "$3.00");
		Movies[11] = new MovieShowing("AmStar 14", "Battleship", "Mon-Fri 7:00 & 8:00\n\t\tSat & Sun 4:45 & 6:00", "PG-13", "$6.50", "$3.00");
		Movies[12] = new MovieShowing("AmStar 14", "The Boondock Saints", "Mon-Fri 7:30 & 9:00\n\t\tSat & Sun 3:00 & 6:30", "R", "$6.50", "$0.00");
		Movies[13] = new MovieShowing("AmStar 14", "Arthur", "Mon-Fri 6:30 & 7:45\n\t\tSat & Sun 5:00 & 7:00", "PG-13", "$6.50", "$3.00");
		Movies[14] = new MovieShowing("AmStar 14", "Die Another Day", "Mon-Fri 5:45 & 7:30\n\t\tSat & Sun 5:00 & 7:00", "PG-13", "$6.50", "$3.00");
		Movies[15] = new MovieShowing("Cinema 6", "21 Jump Street", "Mon-Fri 7:00 & 9:00\n\t\tSat & Sun 5:00 & 7:00", "R", "$5.00", "$$0.00");
		Movies[16] = new MovieShowing("Cinema 6", "The Avengers", "Mon-Fri 7:00 & 9:00\n\t\tSat & Sun 3:00 & 6:30", "PG-13", "$5.00", "$2.50");
		Movies[17] = new MovieShowing("Cinema 6", "Arthur", "Mon-Fri 8:00 & 9:00\n\t\tSat & Sun 3:30 & 5:00", "PG-13", "$5.00", "$2.50");
		Movies[18] = new MovieShowing("Cinema 6", "Battleship", "Mon-Fri 7:45 & 9:30\n\t\tSat & Sun 4:45 & 6:00", "PG-13", "$5.00", "$2.50");
		Movies[19] = new MovieShowing("Cinema 6", "The Boondock Saints", "Mon-Fri 7:30 & 9:00\n\t\tSat & Sun 3:00 & 6:30", "R", "$5.00", "$0.00");

		Sorting.selectionSort(Movies);

		for (Comparable Movie: Movies)
			System.out.println(Movie);
	}


}