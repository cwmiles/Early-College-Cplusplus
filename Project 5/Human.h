/***************************************************************************
 * Name: David Keen
 * Date and Time: 
 * Function: 
 * Input requirements:                                  
 * Output: 
 * Additional Comments:
 *                                                                     	
 ***************************************************************************/
#include <iostream>
#include <string> 
using namespace std;

class Human {
	
	public:
		Human();
		Human(int,int);//all humans will be given coordinates on the board
		//~Human();
		
		void Hmove();
		void operator()(int,int);//sets location on board to a new location
		int getX(); // get X coordinate
		int getY(); //get Y coordinate
		bool isSoldier();
		bool isKilled();
		bool isMoved();
		void hasMoved(bool);
		void setX(int);
		void setY(int);
		void setSoldier(bool); //if they are a soldier, they will appear as an S and can kill Zombies they land on
		void setZombie(bool); // if they are zombies, they will be a Z on the board, and move like a Zombie
		void setKilled(bool); //if they are killed, they will not appear on the board at all
		
	private:
		int x;
		int y;
		bool soldier;
		bool killed;
		bool moved;
};
