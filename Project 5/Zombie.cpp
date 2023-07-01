/***************************************************************************
 * Name: Cort Miles
 * Date and Time: 
 * Function: 
 * Input requirements:                                  
 * Output: 
 * Additional Comments:
 *                                                                     	
 ***************************************************************************/
#include "Zombie.h"

Zombie::Zombie()
{
	x = 0;
	y=0;
}
Zombie::Zombie(int i, int j)
{
	int x = i;
	int y = j;
	killed = true;
	moved = false;
}
//~ Zombie::~Zombie()
//~ {
	//~ delete Zombie;
//~ }

void Zombie::Zmove()
{
		int randomNumber;
		randomNumber = (rand() % 4) +1;
		int val = randomNumber;
		//can move
		if(val > 1)
		{
			//zombies can move all directions
			randomNumber = (rand() % 8) + 1;
			int dir = randomNumber;
			if(dir == 1)//moves right if space is empty
			{
			//if we are on the rightmost row or the space to the right is already going to be changed to a human, go to the next loop.
				if(y != 9 )
				{
					//this(getX(),getY()+1);	
					setY(getY()+1);
				}
			}
	
			else if(dir == 2)//moves down
			{
				if(x != 9)
				{
					//this(getX()+1,getY());
					setX(getX()+1);
				}
			}
			else if(dir == 3)//moves left
			{
				if(y != 0)
				{
					//this(getX()-1,getY());
					setY(getY()-1);
				}
			}
			else if(dir ==4) // moves up
			{
				if(x != 0)
				{
					//this(getX(),getY()-1);
					setX(getX()-1); 
				}
			}
			else if(dir == 5)//moves down and right
			{
			//if we are on the rightmost row or the space to the right is already going to be changed to a human, go to the next loop.
				if(y != 9 && x !=9)
				{
					//this(getX()+1,getY()+1);	
					setX(getX()+1);
					setY(getY()+1); 
				}
			}
			else if(dir == 6)//moves down and left
			{
			//if we are on the rightmost row or the space to the right is already going to be changed to a human, go to the next loop.
				if(x != 9 && y!=0 )
				{
					//this(getX()-1,getY()+1);	
					setX(getX()+1);
					setY(getY()-1); 
				}
			}
			else if(dir == 7)//moves up and right
			{
			//if we are on the rightmost row or the space to the right is already going to be changed to a human, go to the next loop.
				if(x != 0 && y!=9)
				{
					//(getX()+1,getY()-1);
					setX(getX()-1);
					setY(getY()+1); 
					
				}
			}
			else if(dir == 8)//moves up and left
			{
			//if we are on the rightmost row or the space to the right is already going to be changed to a human, go to the next loop.
				if(y != 0  && x!=0)
				{
					//this(getX()-1,getY()-1);	
					setX(getX()-1);
					setY(getY()-1); 
				}
			}
		}
}
void Zombie::operator()(int a,int b)
{
	if(getX()>=0 && getX()<10 && getY()>=0 && getY()<10)
	{
		x = a;
		y = b;
	}
}
int Zombie::getX()
{
	return x;
}
int Zombie::getY()
{
	return y;
}
void Zombie::setKilled(bool a)
{
	killed = a;
}
bool Zombie::isKilled()
{
	return killed;
}
void Zombie::setX(int a)
{
	x = a;
}
void Zombie::setY(int b)
{
	y = b;
}
bool Zombie::isMoved()
{
	return moved;
}
void Zombie::hasMoved(bool a)
{
	moved = a;
}


