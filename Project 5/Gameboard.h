/***************************************************************************
 * Name: Cort Miles
 * Date and Time: 
 * Function: 
 * Input requirements:                                  
 * Output: 
 * Additional Comments:
 *                                                                     	
 ***************************************************************************/
#include <iostream>
#include <string> 
#include <cstdlib>
#include <fstream>
#include "World.h"
#include "Human.h"
#include "Zombie.h"
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
using namespace std;

class Gameboard : public World { //: public World (must inherit from world)
	
	public:
	
		Gameboard();
		~Gameboard();
		//default methods from world class
		void printGrid();
		void updateGrid();
		void sim();
		
		//added methods
		void humanMove();
		bool checkWin();
		//~ void promptEnterkey();
		void zombieMove();
		void round();
		void spawnSoldier();
		//void spawnHuman();
		void elimRadiation();
		//void soldierMove(); //soldiers are humans
		void radiation();
		
	protected:
		//all from world class
		void initGrid();
		//have not implemented yet, logic is in move function
		bool checkBounds(int,int);
		
		int day; 
		//array of chars or array of Player objects?
		char grid[10][10]; //no need to redeclare
		Human humans[10][10];
		Zombie zombies[10][10];
		
		
	
};
#endif /* GAMEBOARD_H */

