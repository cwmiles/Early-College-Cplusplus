/***************************************************************************
 * Name: David Keen
 * Date and Time: 
 * Function: 
 * Input requirements:                                  
 * Output: 
 * Additional Comments:
 *                                                                     	
 ***************************************************************************/
 
#ifndef WORLD_H
#define WORLD_H
#include <cstdlib>

using namespace std; 

class World 
{
	
	public: 
		World() {};
		
		virtual void printGrid() = 0;
		virtual void updateGrid() = 0;
		
	protected:
		int day; 
		char grid[10][10];
		
		virtual void initGrid() = 0;
		virtual bool checkBounds(int,int) = 0;
	
};

#endif /* WORLD_H */
