//****************************************************************************
//	Dylan Jenkins		4/29/13
//	AnimalsDriver.java
//	Driver program for the Critter superclass that uses its subclasses.
//****************************************************************************

public class AnimalsDriver
{
	public static void main (String[] args)
	{
		//-------------------------------------------------------
		//	Declarations of String to be passed into Critters
		//-------------------------------------------------------

		String S1 = "Have a height and weight";
		String S2 = "Can be domesticated or are domesticated";
		String S3 = "Are living creatures";
		String S4 = "Has a backbone";
		String S5 = "Frog";
		String S6 = "Insects";
		String S7 = "Can swim!";
		String S8 = "Owl";
		String S9 = "Insects/Small Critters";
		String S10 = "Has ability to fly!";
		String S11 = "Has two legs, with talons for grabbing prey";
		String S12 = "Ferret";
		String S13 = "Small Critters";
		String S14 = "Long in Length, similar to a Weasel";
		String S15 = "Used to draw out/go get rabbits from their hole by hunters";
		String S16 = "Has long tongue to catch prey";
		String S17 = "Powerful legs for jumping/climbing";
		String S18 = "Big powerful eyes for hunting and night vision";
		String S19 = "Can rotate head around to look behind itself";
		String S20 = "Has fairly strong musky odor";
		String S21 = "Hops around with back arched up when playing, its quite funny";

		//-----------------------------
		//	Creating Critters
		//-----------------------------

		Frog frog = new Frog(S1, S2, S3, S4, S5, S6, S7, S16, S17);
		Bird bird = new Bird(S1, S2, S3, S4, S8, S9, S10, S11, S18, S19);
		Ferret ferret = new Ferret(S1, S2, S3, S4, S12, S13, S14, S15, S20, S21);

		//-----------------------------
		//	Call to Frog Mutators
		//-----------------------------

		frog.setSpecies(S5);
		frog.setPrey(S6);
		frog.setSwim(S7);
		frog.setTongue(S16);
		frog.setJump(S17);

		//-----------------------------
		//	Call to Frog Accessors
		//-----------------------------

		frog.getSpecies();
		frog.getPrey();
		frog.getSwim();
		frog.getTongue();
		frog.getJump();

		//-----------------------------
		//	Call to Frog toString
		//-----------------------------

		System.out.println(frog.toString());

		//-----------------------------
		//	Call to Bird Mutators
		//-----------------------------

		bird.setSpecies(S8);
		bird.setPrey(S9);
		bird.setFly(S10);
		bird.setLegs(S11);

		//-----------------------------
		//	Call to Bird Accessors
		//-----------------------------

		bird.getSpecies();
		bird.getPrey();
		bird.getFly();
		bird.getLegs();

		//-----------------------------
		//	Call to Bird toString
		//-----------------------------

		System.out.println("\n-------------------------------------------------");
		System.out.println("\n" + bird.toString());

		//-----------------------------
		//	Call to Ferret Mutators
		//-----------------------------

		ferret.setSpecies(S12);
		ferret.setPrey(S13);
		ferret.setLength(S14);
		ferret.setUse(S15);
		ferret.setOdor(S20);
		ferret.setFun(S21);

		//-----------------------------
		//	Call to Ferret Accessors
		//-----------------------------

		ferret.getSpecies();
		ferret.getPrey();
		ferret.getLength();
		ferret.getUse();
		ferret.getOdor();
		ferret.getFun();

		//-----------------------------
		//	Call to Ferret toString
		//-----------------------------

		System.out.println("\n-------------------------------------------------");
		System.out.println("\n" + ferret.toString());
	}

}