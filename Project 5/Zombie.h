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

class Zombie{
	
	public:
		Zombie();
		Zombie(int,int);
		//~Zombie();
		void Zmove();//can move any direction
		void operator()(int,int);//sets location on board to a new location
		
		int getX(); // get X coordinate
		int getY(); //get Y coordinate
		
		bool isMoved();
		bool isKilled();
		void hasMoved(bool);
		void setKilled(bool); //if they are killed, they will not appear on the board at all and won't move
		
		void setX(int);
		void setY(int);
	
	private:
		bool killed;
		int x;
		int y;
		bool moved;
		
};
