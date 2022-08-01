/***************************************************************************
 * Name: Cort Miles
 * 
 * Email: cwmiles@email.sc.edu
 * 
 * Function: Class file that runs the others
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
#include <fstream>
using namespace std;

Sequence* readData(string file_handle, int& size);
Sequence* reconstructSequences(Sequence * all_seqs, int size);

int main(int argc, char** argv)
{
    string file_handle = argv[2];
    int size = atoi(argv[1]);
    Sequence* ori_seq = readData(file_handle, size);
    ori_seq[0].printSequence();
    cout << endl;
    return 0;

    
}
Sequence* readData(string file_handle, int& size)
{
    ifstream inFile; 
    Sequence* comb_seq = new Sequence[size];
    inFile.open(file_handle);
    string line(""), seq("");
    int i = 0;
    while(i< size)
    {
        getline(inFile,line);
        if(line[0] != '>')
        {
            comb_seq[i] = new Sequence(line);
        }
        i++;
    }
    size = sizeof(comb_seq) / sizeof(Sequence);
    return comb_seq;

}

Sequence* reconstructSequences(Sequence * all_seqs, int size)
{
    //this is interesting....
}

