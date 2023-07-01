/**
 * 
 * @author Cort Miles
 *
 */
import java.util.Random;
import java.io.*;
public class CrisisSim{
	
	public static final int SIZE = 10;
	public static char[][] Board = new char[SIZE][SIZE];// creates two d array that will be the board
	public static char Empty = '-';
	public static char Tmp = 'T';
	public static char Human = 'H';
	public static char Zombie = 'Z';
	public static char Soldier = 'S';
	public static char Radiation = 'R';
	
	public static void main(String[] args) 
	{
		run();
	}
	public static void run()
	{

		createBoard();	
		fillBoard();
		printBoard();
		int count = 0; // use this for methods to determine if they are ran!
		for (int i = 0; i<1000; i++)
		{	
			count++;
			System.out.println("Round " + (i+1) + " is starting!");
			round();
			System.out.println(" Also round " + (i+1) + " is now over.");
			if(count%25 ==0)
			{
				spawnHuman();
			}
			if(count%25==0)
			{
				spawnSoldier();
			}
			if(count%50 == 0)
			{
				elimRadiation();
			}
			promptEnterKey();
		}
	}
	
	public static void promptEnterKey()
	{
		System.out.println("Press \"ENTER\" to continue...");
        try {
            int read = System.in.read(new byte[2]);
        } catch (IOException e) {
            e.printStackTrace();
        }
		   
	}
	
	public static void spawnSoldier()
	{
		System.out.println("A soldier has been spawned for next round!");
		Random R = new Random();
		int SCount = 0;
		int AreHumans = 0;
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(Board[i][j] == Human)
				{
					AreHumans++;
				}
			}
		}
		if(AreHumans != 0)
		{
			while(SCount<1) 
			{
				int CoordX = R.nextInt(SIZE);
				int CoordY = R.nextInt(SIZE);
				if(Board[CoordX][CoordY] == Human)
				{
					Board[CoordX][CoordY] = Soldier;
					SCount++;
				}
			}
		}
	}
	
	public static void spawnHuman()
	{
		System.out.println("Another Human has been spawned for next round!");
		Random R = new Random();
		int HCount = 0;
		while(HCount<1) 
		{
			int CoordX = R.nextInt(SIZE);
			int CoordY = R.nextInt(SIZE);
			if(Board[CoordX][CoordY] == ' ')
			{
				Board[CoordX][CoordY] = Human;
				HCount++;
			}
		}
	}
	
	public static void elimRadiation()
	{
		for (int i =0; i< SIZE; i++)// double loop that fills array with dashes.
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(Board[i][j] == Radiation)
					Board[i][j] = ' ';
			}
		}
	}
	public static void printBoard()
	{
		System.out.println("   |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |");
		System.out.println("----------------------------------------------------------------");
		for(int i = 0; i< SIZE; i++)
		{
			System.out.print( +i +"  |");
			 for(int j = 0; j<Board.length;j++)
			 {
				 System.out.print("  "+Board[i][j]+ "  |");
			 }
			 System.out.println("");
			 System.out.println("----------------------------------------------------------------");
		}
	}
	
	public static void createBoard() 
	{
		for (int i =0; i< SIZE; i++)// double loop that fills array with dashes.
		{
			for(int j = 0; j< SIZE; j++)
			{
			Board[i][j] = ' ';
			}
		}
	}
	
	public static void checkWin()
	{
		boolean win = false;
		int Hcount = 0;
		int Zcount = 0;
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(Board[i][j] == Human || Board[i][j] == Soldier)
				{
					Hcount++;
				}
				if(Board[i][j] == Zombie)
				{
					Zcount++;
				}
			}
		}
		if(Hcount == 0)
		{
			System.out.println("Simulation is over and Zombies win!");
			win = true;
		}
		else if(Zcount == 0)
		{
			System.out.println("Simulation is over and Humans win!");
			win = true;
		}
		
	}
	
	public static void fillBoard()
	{
		System.out.println("Humans and Zombies are being Spawned!");
		Random R = new Random();
		int HCount = 0;
		int ZCount = 0;
		while(HCount<15) {
			int CoordX = R.nextInt(SIZE);
			int CoordY = R.nextInt(SIZE);
			if(Board[CoordX][CoordY] == ' ') {
				Board[CoordX][CoordY] = Human;
				HCount++;
			}
		}
		while(ZCount<3) {
			int CoordX = R.nextInt(SIZE);
			int CoordY = R.nextInt(SIZE);
			if(Board[CoordX][CoordY] == ' ') {
				Board[CoordX][CoordY] = Zombie;
				ZCount++;
			}
		}
	}
	public static void round()
	{
		soldierMove();
		humanMove();
		printBoard();
		System.out.println("The Humans have moved! See what they did above!");
		zombieMove();
		printBoard();
		System.out.println("The Zombies have moved! See what they did above!");
		
	}
	public static void humanMove() // this method allows the humans to move
	{
		for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(Board[i][j] == Human)
				{
					Random rand = new Random();
					int val = rand.nextInt(2)+1;
					if(val == 1)
					{
						int dir = rand.nextInt(4)+1;
						if(dir == 1)//moves right if empty
						{
							if(j == 9 ||Board[i][j+1] == Tmp)
								continue;
							else if(Board[i][j+1] == ' ')
							{
								Board[i][j] = ' ';
								Board[i][j+1] = Tmp;
							}
							else if(Board[i][j+1] == Radiation)
							{
								Board[i][j] = ' ';
								Board[i][j+1] = Radiation;
							}
						}
						else if(dir == 2)//moves down if empty
						{
							if(i == 9||Board[i+1][j] == Tmp)
								continue;
							else if(Board[i+1][j] == ' ')
							{
								Board[i][j] = ' ';
								Board[i+1][j] = Tmp;
							}
							else if(Board[i+1][j] == Radiation)
							{
								Board[i][j] = ' ';
								Board[i+1][j] = Radiation;
							}
						}
						else if(dir == 3)//moves left if empty
						{
							if (j==0)
								continue;
							else if(Board[i][j-1] == ' ')
							{
								Board[i][j] = ' ';
								Board[i][j-1] = Human;
							}
							else if(Board[i][j-1] == Radiation)
							{
								Board[i][j] = ' ';
								Board[i][j-1] = Radiation;
							}
						}
						else if(dir == 4)//moves up if empty
						{
							if(i==0)
								continue;
							else if(Board[i-1][j] == ' ')
							{
								Board[i][j] = ' ';
								Board[i-1][j] = Human;
							}
							else if(Board[i-1][j] == Radiation)
							{
								Board[i][j] = ' ';
								Board[i-1][j] = Radiation;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(Board[i][j] == Tmp)
				{
					Board[i][j] = Human;
				}
			}
		}
	} 
	
	public static void soldierMove()
	{
		for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(Board[i][j] == Soldier)
				{
					Random rand = new Random();
					int val = rand.nextInt(2)+1;
					if(val == 1)
					{
						int dir = rand.nextInt(4)+1;
						if(dir == 1)//moves right if empty
						{
							if(j == 9 || Board[i][j+1] == Tmp)
								continue;
							else if(Board[i][j+1] == ' '|| Board[i][j+1] == Zombie)
							{
								Board[i][j] = ' ';
								Board[i][j+1] = Tmp;
							}
							else if(Board[i][j+1] == Radiation)
							{
								Board[i][j] = ' ';
								Board[i][j+1] = Radiation;
							}
						}
						else if(dir == 2)//moves down if empty
						{
							if(i == 9 || Board[i+1][j] == Tmp)
								continue;
							else if(Board[i+1][j] == ' '|| Board[i+1][j] == Zombie)
							{
								Board[i][j] = ' ';
								Board[i+1][j] = Tmp;
							}
							else if(Board[i+1][j] == Radiation)
							{
								Board[i][j] = ' ';
								Board[i+1][j] = Radiation;
							}
						}
						else if(dir == 3)//moves left if empty
						{
							if (j==0)
								continue;
							else if(Board[i][j-1] == ' '|| Board[i][j-1] == Zombie)
							{
								Board[i][j] = ' ';
								Board[i][j-1] = Soldier;
							}
							else if(Board[i][j-1] == Radiation)
							{
								Board[i][j] = ' ';
								Board[i][j-1] = Radiation;
							}
						}
						else if(dir == 4)//moves up if empty
						{
							if(i==0)
								continue;
							else if(Board[i-1][j] == ' '|| Board[i-1][j] == Zombie)
							{
								Board[i][j] = ' ';
								Board[i-1][j] = Soldier;
							}
							else if(Board[i-1][j] == Radiation)
							{
								Board[i][j] = ' ';
								Board[i-1][j] = Radiation;
							}
						}
					}
				}
			}
		}
		int cyclecount = 0;
		for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(Board[i][j] == Tmp)
				{
					Board[i][j] = Soldier;
					cyclecount++;
				}
			}
		}
		if(cyclecount>0)
		{
			printBoard();
			System.out.println(cyclecount +" soldiers have moved, see what they did above.");
			
		}
	} 
	
	public static void zombieMove()
	{
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(Board[i][j] == Zombie)
				{
					Random rand = new Random();
					int val = rand.nextInt(4)+1;
					if(val > 1)
					{
						int dir = rand.nextInt(8)+1;
						int rad = rand.nextInt(20)+1;
						if(dir == 1)//moves right if able
						{
							if(j==9 || Board[i][j+1] == Tmp)
								continue;
							if(Board[i][j+1] == ' ')
							{
								if(rad==1)
								{
									Board[i][j] = Radiation;
									Board[i][j+1] = Tmp;
								}
								else
								{
									Board[i][j] = ' ';
									Board[i][j+1] = Tmp;
								}
							}
							else if(Board[i][j+1] == Human)
							{
								int choice = rand.nextInt(8)+1; //80% chance to kill human and 20% chance to infect them
								if(choice > 2)
								{
									/*if(rad==1)
									{
									Board[i][j] = Radiation; //THIS IS CODE FOR ZOMBIE LEAVING RADIATION WHEN KILLING HUMAN IF WANTED
									Board[i][j+1] = Zombie;
									}
									*/
									Board[i][j] = ' ';
									Board[i][j+1] = Tmp;
								}
								else
								{
									Board[i][j] = Zombie;
									Board[i][j+1] = Tmp;
								}
							}
						}
						else if(dir == 2)//moves down if able
						{
							if(i==9 || Board[i+1][j] == Tmp)
								continue;
							if(Board[i+1][j] == ' ')
							{
								if(rad==1)
								{
									Board[i][j] = Radiation;
									Board[i+1][j] = Tmp;
								}
								else
								{
									Board[i][j] = ' ';
									Board[i+1][j] = Tmp;
								}
							}
							else if(Board[i+1][j] == Human)
							{
								int choice = rand.nextInt(8)+1; //80% chance to kill human and 20% chance to infect them
								if(choice > 2)
								{
									Board[i][j] = ' ';
									Board[i+1][j] = Tmp;
								}
								else
								{
									Board[i][j] = Zombie;
									Board[i+1][j] = Tmp;
								}
							}
						}
						else if(dir == 3)//moves left if able
						{
							if(j==0)
								continue;
							if(Board[i][j-1] == ' ')
							{	
								if(rad==1)
								{
									Board[i][j] = Radiation;
									Board[i][j-1] = Zombie;
								}
								else
								{
									Board[i][j] = ' ';
									Board[i][j-1] = Zombie;
								}
							}
							else if(Board[i][j-1] == Human)
							{
								int choice = rand.nextInt(8)+1;
								if(choice > 2)
								{
									Board[i][j] = ' ';
									Board[i][j-1] = Zombie;
								}
								else
								{
									Board[i][j] = Zombie;
									Board[i][j-1] = Zombie;
								}
							}
						}
						else if(dir == 4)//moves up if able
						{
							if(i==0)
								continue;
							if(Board[i-1][j] == ' ')
							{
								if(rad==1)
								{
									Board[i][j] = Radiation;
									Board[i-1][j] = Zombie;
								}
								else
								{
									Board[i][j] = ' ';
									Board[i-1][j] = Zombie;
								}
							}
							else if(Board[i-1][j] == Human)
							{
								int choice = rand.nextInt(8)+1;
								if(choice > 2)
								{
									Board[i][j] = ' ';
									Board[i-1][j] = Zombie;
								}
								else
								{
									Board[i][j] = Zombie;
									Board[i-1][j] = Zombie;
								}
							}
						}
						else if(dir == 5)//moves up to the right if able (diagonal move)
						{
							if(i==0 || j==9)
								continue;
							if(Board[i-1][j+1] == ' ')
							{
								if(rad==1)
								{
									Board[i][j] = Radiation;
									Board[i-1][j+1] = Zombie;
								}
								else
								{
									Board[i][j] = ' ';
									Board[i-1][j+1] = Zombie;
								}
							}
							else if(Board[i-1][j+1] == Human)
							{
								int choice = rand.nextInt(8)+1;
								if(choice > 2)
								{
									Board[i][j] = ' ';
									Board[i-1][j+1] = Zombie;
								}
								else
								{
									Board[i][j] = Zombie;
									Board[i-1][j+1] = Zombie;
								}
							}
						}
						else if(dir == 6)//moves up to the left if able
						{
							if(j==0 || i==0)
								continue;
							if(Board[i-1][j-1] == ' ')
							{
								if(rad==1)
								{
									Board[i][j] = Radiation;
									Board[i-1][j-1] = Zombie;
								}
								else
								{
									Board[i][j] = ' ';
									Board[i-1][j-1] = Zombie;
								}
							}
							else if(Board[i-1][j-1] == Human)
							{
								int choice = rand.nextInt(8)+1;
								if(choice > 2)
								{
									Board[i][j] = ' ';
									Board[i-1][j-1] = Zombie;
								}
								else
								{
									Board[i][j] = Zombie;
									Board[i-1][j-1] = Zombie;
								}
							}
						}
						else if(dir == 7)//moves down to the left if able
						{
							if(i==9 || j==0 || Board[i+1][j-1] == Tmp)
								continue;
							if(Board[i+1][j-1] == ' ')
							{
								if(rad==1)
								{
									Board[i][j] = Radiation;
									Board[i+1][j-1] = Tmp;
								}
								else
								{
									Board[i][j] = ' ';
									Board[i+1][j-1] = Tmp;
								}
							}
							else if(Board[i+1][j-1] == Human)
							{
								int choice = rand.nextInt(8)+1;
								if(choice > 2)
								{
									Board[i][j] = ' ';
									Board[i+1][j-1] = Tmp;
								}
								else
								{
									Board[i][j] = Zombie;
									Board[i+1][j-1] = Tmp;
								}
							}
						}
						else if(dir == 8)//moves down to the right if able
						{
							if(i==9 || j==9 || Board[i+1][j+1] == Tmp)
								continue;
							if(Board[i+1][j+1] == ' ')
							{
								if(rad==1)
								{
									Board[i][j] = Radiation;
									Board[i+1][j+1] = Tmp;
								}
								else
								{
									Board[i][j] = ' ';
									Board[i+1][j+1] = Tmp;
								}
							}
							else if(Board[i+1][j+1] == Human)
							{
								int choice = rand.nextInt(8)+1;
								if(choice > 2)
								{
									Board[i][j] = ' ';
									Board[i+1][j+1] = Tmp;
								}
								else
								{
									Board[i][j] = Zombie;
									Board[i+1][j+1] = Tmp;
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(Board[i][j] == Tmp)
				{
					Board[i][j] = Zombie;
				}
			}
		}
	}
	
}


	
