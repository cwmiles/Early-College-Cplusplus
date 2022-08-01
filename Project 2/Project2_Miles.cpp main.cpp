// Author: Cort Miles
// Date: 9/19/2020 12:30pm
// This program sorts the numbers in an nX20 dimensional 2d array in ascending order
// Input: The number of rows is given by input and it uses a text file
// Output: The original array followed by the sorted array

#include <cstdlib>
#include <iostream>

using namespace std;

const int SIZE = 20;//constant integer to be used for every array

void readData(int[][SIZE], int);
void printData(int array[][SIZE], int);
void mySort(int array[][SIZE], int);

int main (int argc, char **argv) // thanks for the clutch start to this method, but i also finished strong and completed it
{
	if(argc != 2)
	{
		cout << "Usage: ./a.out <num_rows>" << endl;
		exit(0);
	}
	int rows = atoi(argv[1]);

	int array[rows][SIZE];

	cout << "Before Sorting" << endl;

	readData(array, rows);
	printData(array, rows);

	cout << "After Sorting" << endl;

	mySort(array, rows);
	printData(array, rows);


	return 0;
}

void printData(int array[][SIZE], int rows)// hopefully this will print the data... test it and find out
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void readData(int array[][SIZE], int rows) //this reads data.....i think
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			cin >> array[i][j];
		}
	}
}

void mySort(int array[][SIZE], int rows) //this is the best and most efficient mysort ever created
{
        int temp;
	bool swap = true;
	while(swap == true)
	{
		swap = false;
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < SIZE; j++)
			{
				if(array[i][j] > array[i][j+1] && (i != rows-1 || j != SIZE-1))
				{
					swap = true;
					temp = array[i][j+1];
					array[i][j+1] = array[i][j];
					array[i][j] = temp;
				}
			}
		}
	}
}
