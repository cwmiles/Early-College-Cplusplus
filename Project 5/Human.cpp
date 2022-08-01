/***************************************************************************
 * Name: David Keen 
 * Date and Time: 
 * Function: 
 * Input requirements:                                  
 * Output: 
 * Additional Comments:
 *                                                                     	
 ***************************************************************************/
#include "Human.h"
Human::Human()
{
	x = 0;
	y = 0;
}
Human::Human(int i, int j)
{
	x = i;
	y = j;
	soldier = false;
	killed = true;
	moved = false;
}
//~ Human::~Human()
//~ {
	//~ delete Human;
//~ }

void Human::operator()(int a,int b)
{
	if(getX()>=0 && getX()<10 && getY()>=0 && getY()<10)
	{
		x = a;
		y = b;
	}
}
int Human::getX()
{
	return x;
}
int Human::getY()
{
	return y;
}
void Human::Hmove()
{ 
		int randomNumber;
		randomNumber = (rand() % 2);
		int val = randomNumber;
		//can move
		if(val == 0)
		{
			//humans can move up, down, left, or right. So 4 possible outcomes
			randomNumber = (rand() % 4) + 1;
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
			else if(dir ==4)
			{
				if(x != 0)
				{
					//this(getX(),getY()-1);
					setX(getX()-1);
				}
			}
		}
}
bool Human::isSoldier()
{
	return soldier;
}
bool Human::isKilled()
{
	return killed;
}
void Human::setSoldier(bool a)
{
	soldier = a;
}
void Human::setKilled(bool a)
{
	killed = a;
}
void Human::setX(int a)
{
	x = a;
}
void Human::setY(int b)
{
	y = b;
}
bool Human::isMoved()
{
	return moved;
}
void Human::hasMoved(bool a)
{
	moved = a;
}

