/***************************************************************************
 * Name: Cort Miles
 * 
 * Email: cwmiles@email.sc.edu
 * 
 * Function: Class file with all the methods used
 * 
 * Input: None
 * 
 * Output: None
 * 
 * Additional Comments: You made this assigment super hard. Please give us no more homework, thanks.
 * 
 * Copyright (C) 2020 by Cort Miles                                        
 *                                                                         *
 ***************************************************************************/#include <string>
#include <iostream>
#include "Sequence.h"

using namespace std;

Sequence::Sequence() //creates a new sequence and fills it with nothing
{
    sequence = new char[100];
    for (int i=0; i<100; i++)
    {
        sequence[i] = '\0';
    }
    length = 100;
}

Sequence::Sequence(string inp) // fills the created sequence with input from file
{
    for (int i=0; i<100; i++)
    {
    sequence[i] = inp[i];
    }
}

Sequence::~Sequence() // deconstructor for sequence
{
    delete [] sequence;  
}

int Sequence::getLength() // returns the variable length
{
    return length;
}

void Sequence::printSequence() // prints the sequence out in the given format
{
    for(int i = 0; i<100; i++)
    {
        cout << sequence[i];
        for(int j=0; j%i != 0; j++)
        {
            //if ... prints after last characters make a if statement 
            //before to break the for loop
            cout << "...";
        }
    }
}

string Sequence::getSequence() // gets the sequence
{
    string abc = "";
    for(int i = 0; i<100;i++)
    {
        abc += sequence[i];
    }
}

int Sequence::isOverlapping(Sequence & obj2) /*Checks to see if there is any overlap between the the two 
                                             sequences sequence and obj2 sequence*/
{
    int count = 0;
    for(int i = 0; i<100; i++)
    {
        if(sequence[i] == obj2.sequence[i])
        {
            count++;
        }
    }
    if(count!=0)
    {
        return count;
    }
    else
    {
        return -1;
    }
}

void Sequence::operator+=(Sequence & rhs) // combines the two sequences and doesnt repeat the parts that overlap
{
    //Sequence and rhs is the other sequence or string
    int same = isOverlapping(rhs);
    char* temp = sequence;
    sequence = new char[200-same];
    //this method should work but need to test first
    
    for(int i=0; i<length; i++)
    {
        sequence[i] = temp[i];
    }    
    for(int j=length; j<200-same; j++)
    {
        sequence[j] = rhs.sequence[j-length+same];
    }   
    length = 200-same; 
    delete []temp;    //deleteds the temp sequence to ensure no memory leaks                                                                            
}