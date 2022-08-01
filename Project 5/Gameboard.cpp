/***************************************************************************
 * Name: David Keen
 * Date and Time: 
 * Function: 
 * Input requirements:                                  
 * Output: 
 * Additional Comments:
 *                                                                     	
 ***************************************************************************/
 
 //TODO checkBounds and Destructor

//constants for size of the game board and chars in Gameboard
const int SIZE = 10;
const char HUMAN = 'H';
const char ZOMBIE = 'Z';
const char SOLDIER = 'S';
const char RADIATION = 'R';

#include <cstdlib>
#include <string>
#include "Gameboard.h"
#include <iostream>
#include <ctime>

//only constructor
Gameboard::Gameboard()
{
	//set the seed
	srand((unsigned) time(0)); 
	//day variable keep track of the round of simulaition
	day = 0; 
	// creates two d array that will be the board, and arrays for humans and zombies
	for (int i =0; i< SIZE; i++)// double loop that fills array to the empty char.
		{
			for(int j = 0; j< SIZE; j++)
			{
				//set all elements in the grid and the object arrays to null
				grid[i][j] = ' ';
				humans[i][j](i,j);//operator overload() to set coordinates of each value
				zombies[i][j](i,j);
			}
		}
}
Gameboard::~Gameboard()
{
	//this destructor results in error
	//delete [][] grid;
}
void Gameboard::radiation()
{
	int randomNumber = (rand() % 20) + 1;
	int rad = randomNumber;
	int rcount =  0;
	if(rad == 1)
	{
		while (rcount < 1)
		{
			randomNumber = (rand()%SIZE);
			int CoordX = randomNumber; //random int less than 10 
			randomNumber = (rand()%SIZE);
			int CoordY = randomNumber;
			if(grid[CoordX][CoordY]!= RADIATION || grid[CoordX][CoordY]!= ZOMBIE || grid[CoordX][CoordY]!= SOLDIER || grid[CoordX][CoordY]!= HUMAN)
			{
				grid[CoordX][CoordY] = RADIATION;
				rcount++;
			}
		}
	}
}
void Gameboard::updateGrid() //might need for World class, would function the same as round
{
	round();
}

bool Gameboard::checkBounds(int,int) //might need this for inheriting from World class as well, would be placed in the move() function for each player 
{
	//TODO
	return true;
} 
//everything runs in the sim function
void Gameboard::sim()
{
	//create and fill board
	initGrid();	
	//print original random grid to start
	printGrid();
	//user presses y then enter to see next day. (could not figure out how to allow for just pressing enter to continue)
	cout << "Press y to see the next day, or press any other key to exit ";
	char go = ' ';
	cin >> go;
	if(go != 'y')
	{
		cout << "Ending Simulation, Thanks for Playing!" << endl;
		exit(0);
	}
	//max is 1000 days
	while (day < 1000)
	{	
		//new round = new day
		day++;
		cout<< "Day "; cout << day;  cout << " is starting!" << endl;
		//each round is completed in the round() function
		updateGrid();
		cout << "Day "; cout << day; cout << " is now over. " << endl;
		//spwan humans every 30 days, spawn soldiers every 20 days, and eliminate radiation from the board every 60 days
		if(day%30 ==0)
		{
			//~spawnHuman();
		}
		if(day%20 ==0)
		{
			spawnSoldier();
		}
		if(day%60 == 0)
		{
			elimRadiation();
		}
		if (checkWin())
		{
			exit(0);
		}
		//user presses y to see next day
		cout << "Press y to see the next day, or press any other key to exit ";
		cin >> go;
		if(go != 'y')
		{
			cout << "Ending Simulation, Thanks for Playing" << endl;
			exit(0);
		}
	}
}
//each day, the round function is called
void Gameboard::round()
{
	//soldiers move first if there are any on the board
	//soldierMove();
	//then humans
	humanMove();
	//print so users can see what happend when the humans moved
	printGrid();
	cout << "The Humans have moved! See what they did above!" << endl;
	//zombies move after all humans
	zombieMove();
	//print grid again
	printGrid();
	cout << "The Zombies have moved! See what they did above!" << endl;
	radiation();
}

//function to print contents of grid to standard output
void Gameboard::printGrid()
{
	//should it be checking all elements of the zombie array and human array?
	cout << "   |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |" << endl;
	cout << "----------------------------------------------------------------" << endl;
		for(int i = 0; i< SIZE; i++)
		{
			cout<< i;
			cout<< "  |";
			 for(int j = 0; j<SIZE; j++)
			 {
				 cout<< "  ";
				 cout<< grid[i][j];
				 cout<<  "  |";
			 }
			 cout<< endl;
			 cout<< "----------------------------------------------------------------"<<endl;
		}
}
//fill board (create board is basically the constructor)
void Gameboard::initGrid() 
{
		cout<<endl;
		cout<< "Oh No! Some of the Resident's of CaseyDale have become Zombies! " << endl;
		cout<< "Will the humans survive? Or will Zombies take over?" << endl;
		int randomNumber;
		int HCount = 0;
		int ZCount = 0;
		//fill board with 15 humans
		while(HCount<15) 
		{
			randomNumber = (rand()%SIZE);
			int CoordX = randomNumber; //random int less than 10 
			randomNumber = (rand()%SIZE);
			int CoordY = randomNumber; //random int less than 10
			//make sure space is empty
			if(grid[CoordX][CoordY] == ' ')
			{
				humans[CoordX][CoordY].setKilled(false);
				grid[CoordX][CoordY] = HUMAN;
				HCount++;
			}
		}
		//fill board with 3 zombies
		while(ZCount<3)
		{
			randomNumber = (rand()%SIZE);
			int CoordX = randomNumber;
			randomNumber = (rand()%SIZE);
			int CoordY = randomNumber;
			//make sure space is empty
			if(grid[CoordX][CoordY] == ' ') 
			{
				zombies[CoordX][CoordY].setKilled(false);
				grid[CoordX][CoordY] = ZOMBIE;
				ZCount++;
			}
		}
}
bool Gameboard::checkWin()
{
		bool win = false;
		int Hcount = 0;
		int Zcount = 0;
		//check every space in the board for any humans and zombies
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(grid[i][j] == HUMAN || grid[i][j] == SOLDIER)
				{
					Hcount++;
				}
				if(grid[i][j] == ZOMBIE)
				{
					Zcount++;
				}
			}
		}
		//if there are no humans remaining, the zombies have won
		if(Hcount == 0)
		{
			cout << "Simulation is over and Zombies win!" << endl;
			win = true;
		}
		//if there are no zombies remaining, the humans have won
		else if(Zcount == 0)
		{
			cout << "Simulation is over and Humans win!" <<endl;
			win = true;
		}
		return win;

}
//changes human to soldier every 20 rounds
void Gameboard::spawnSoldier()
{
		cout << "A soldier will be spawned in next round!" << endl;
		int randomNumber;
		int SCount = 0;
		int AreHumans = 0;
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(grid[i][j] == HUMAN)
				{
					AreHumans++;
				}
			}
		 }
		//if no humans left (only soldiers and zombies, don't add another soldier)
		if(AreHumans != 0)
		{
			 while(SCount<1) 
			{
				//get random corrdinates on board, if that space has a human on it, make that human a soldier
				randomNumber = (rand() % 10);
				int CoordX = randomNumber;
				randomNumber = (rand() % 10);
				int CoordY = randomNumber;
				if(grid[CoordX][CoordY] == HUMAN)
				{
					grid[CoordX][CoordY] = SOLDIER;
					humans[CoordX][CoordY].setSoldier(true);
					SCount++;
				}
			}
		}
}

//eliminate all radiation from the board
void Gameboard::elimRadiation()
{
	cout << "The powerful rays of the sun will eliminate all radiation spots from the board!" << endl;
	//check board for any radiation spots and make them empty
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(grid[i][j] == RADIATION)
					grid[i][j] = ' ';
			}
		}
}
//move all humans on the board (not soldiers)
void Gameboard::humanMove()
{
		//loop through entire grid
		for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(grid[i][j])
				{
				humans[i][j].hasMoved(false);
				}
			}
		}
		for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if((grid[i][j] == HUMAN || grid[i][j] == SOLDIER) && (humans[i][j].isKilled() == false && humans[i][j].isMoved() == false))
				{
					//set all elements in the grid and the object arrays to null
					//move the individual human in the array
					humans[i][j].Hmove();
					int x = humans[i][j].getX();
					int y  = humans[i][j].getY();
					humans[i][j].setKilled(true);//assume that it innactive and not showing on board
					humans[i][j](i,j);//set coordinates back because we already have the new coordinates
					//if that space currently has another human, soldier in it, move back to the previous space
					if(grid[x][y] == HUMAN || grid[x][y] == SOLDIER || (grid[i][j] == HUMAN && grid[x][y] == ZOMBIE))
					{
						humans[i][j].setKilled(false);
					}
					else if(grid[x][y] == ZOMBIE && grid[i][j] == SOLDIER)
					{
							//zombie has been killed by soldier
							grid[x][y] = SOLDIER;
							grid[i][j] = ' ';
							zombies[x][y].setKilled(true);
							humans[x][y].setKilled(false);
							humans[x][y].setSoldier(true);
							humans[i][j].setSoldier(false);
							humans[x][y].hasMoved(true); //implement all over still
						
					}
					else if(grid[x][y] == RADIATION)
					{
						//make that human object in the array null because it has been killed by radiation
						humans[i][j].hasMoved(true);
						grid[i][j] = ' ';
					}
					else if((grid[x][y] == ' ' && grid[i][j] == HUMAN) || (grid[x][y] == ' ' && grid[i][j] == SOLDIER))
					{
						//since the human has moved to new coordinates, delete the old human and create a new human in the new spot
						humans[x][y].setKilled(false);
						if(humans[i][j].isSoldier() == true && grid[i][j] == SOLDIER)
						{
							humans[x][y].setSoldier(true);
							grid[x][y] = SOLDIER;
							humans[i][j].setSoldier(false);
						}
						else
						{
							grid[x][y] = HUMAN;
						}
						grid[i][j] = ' ';
						humans[x][y].hasMoved(true);
					}
					
				}
			}
		}
	}
//zombies move after humans
void Gameboard::zombieMove()
{
		for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(grid[i][j] == ZOMBIE)
				{
				zombies[i][j].hasMoved(false);
				zombies[i][j].setKilled(false);
				}
			}
		}
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if((grid[i][j] == ZOMBIE) && (zombies[i][j].isKilled() == false && zombies[i][j].isMoved() == false))
				{
					//move the individual zombie in the array
					zombies[i][j].Zmove();
					int x = zombies[i][j].getX();
					int y = zombies[i][j].getY();
					zombies[i][j](i,j); //have the new coordinates so we can reset the old ones
					zombies[i][j].setKilled(true); //asumes it moved
					if(grid[x][y] == ZOMBIE || grid[x][y] == RADIATION || grid[x][y] == SOLDIER)
					{
						//move zombie back to original spot
						zombies[i][j].setKilled(false);
						zombies[i][j].hasMoved(true);
					}
					else if(grid[x][y] == HUMAN)
					{
						humans[x][y].setKilled(false);
						int randomNumber = (rand() % 10) + 1;
						int choice = randomNumber; //50% chance to kill human and 50% chance to infect them
						if(choice > 5)//infect
						{
							zombies[x][y].setKilled(false);
							grid[x][y] = ZOMBIE;
							zombies[i][j].hasMoved(true);
						}
						else//kill and move into their place
						{
							zombies[x][y].setKilled(false);
							grid[i][j] = ' ';
							grid [x][y] = ZOMBIE;
						}
						zombies[x][y].hasMoved(true);
					}
					else if(grid[x][y] == ' ') //moves to the new spot
					{
						zombies[x][y].setKilled(false);
						grid[x][y] = ZOMBIE;
						grid[i][j] = ' ';
						zombies[x][y].hasMoved(true);
					}
				}
			}
		}
	}		
				
			
