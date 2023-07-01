/***************************************************************************
 * Name: Cort Miles
 * 
 * Email: cwmiles@email.sc.edu
 * 
 * Function: Class file with the method names and instance variables
 * 
 * Input: None
 * 
 * Output: None
 * 
 * Additional Comments: You made this assigment super hard. Please give us no more homework, thanks.
 ***************************************************************************/
#include <string>
#include <iostream>

using namespace std;

class Sequence
{
    //public methods below
    public: 
    Sequence();
    Sequence(string);
    ~Sequence();
    int getLength();
    void printSequence();
    string getSequence();
    int isOverlapping(Sequence & obj2);
    void operator+=(Sequence & rhs);

    //private variables below
    private:
    char * sequence;
    int length;

};
