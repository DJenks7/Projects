//
//
//
//
//

public class Sorting
{
	public static void selectionSort (Comparable[] data)
	{
		int min;

		for (int i=0; i<data.length-1; i++)
		{
			min = i;
			for (int x=i+1; x<data.length; x++)
				if(data[x].compareTo(data[min]) < 0)
					min = x;

			swap (data, min, i);
		}
	}

	private static void swap (Comparable[] data, int I1, int I2)
	{
		Comparable temp = data[I1];
		data[I1] = data[I2];
		data[I2] = temp;
	}

}