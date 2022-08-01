/***************************************************************************
 * Name: Cort Miles
 * 
 * Email: cwmiles@email.sc.edu
 * 
 * Function: Class file with all the methods
 * 
 * Input: None
 * 
 * Output: None
 * 
 * Additional Comments: You made this assigment super hard. Please give us no more homework, thanks.
 * 
 * Copyright (C) 2020 by Cort Miles                                        
 *                                                                         *
 ***************************************************************************/
#include "String.h"

using namespace std;

String::String() //Default constructor
{
	size = 0;
	data = new char[0];
}

String::String(int _size)//Constructs string of a specific size
{
	size = _size;
	data = new char[size];
}

String::String(char str[])//Constructs a string from an array of characters
{
	size = getSize(str);
	data = new char[size];
	for(int i = 0; i < size; i++)
	{ 
		data[i] = str[i];
	}
}

String::String(const String& str) //copies a string from param
{
	size = str.length();
	data = new char[size];
	for(int i = 0; str[i] != '\0'; i++)
	{
		data[i] = str[i];
	}
}

String::~String()//deletes String data
{
	delete [] data;
}

int String::length() const //returns string length
{
	return size;
}

int String::getSize(const char str[]) const //gets size of the string
{
        int cnt = 0;
        int i = 0;
        for(int i = 0; str[i] != '\0'; i++)
		{
			cnt++;
		}
        return cnt;
}

void String::print() const //prints the string
{
	if(size == 0)
	{
		cout << "NULL" << endl;
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			cout << data[i];
		}
		cout << endl;
	}
}

void String::clear() //clears the string
{
	for(int i = 0; i < size; i++)
	{
		data[i] = '\0';
	}
	size = 0;
}

bool String::empty() const //Checks to see if the string is empty
{
	bool emptyString = true;
	for(int i = 0; i < size; i++)
	{
		if(data[i] != '\0')
		{
			emptyString = false;
		}
	}
	return emptyString;
}

int String::find(char substr[], int startIndex) const // Finds a specific string inside of another string to see if it exists
{
	int subSize = getSize(substr);
	int cnt = 0;
	for(int i = startIndex; i < size; i++)
	{
		if(data[i] == substr[0])
		{
			cnt = i;
			for(int j = 0; j < subSize; j++)
			{
				if(data[cnt] == substr[j])
				{
					cnt++;
				}
				else
				{
					break;
				}
			}
			if(cnt == subSize)
			{
				return (cnt);
			}
		}
		cnt = 0;
	}
	return -1;
}

char String::operator[](int index) const //creates the operator
{
	return data[index];
}

const String& String::operator=(const String str) //sets string equal to another string
{
	size = str.length();
	delete [] data;
	data = new char[size];
	for(int i = 0; i < size; i++)
	{
		data[i] = str[i];
	}
	return *this;
}

const String String::operator+(const String& str) const // adds strings together
{
	String tmp(size + str.length());
	for(int i = 0; i < size; i++)
	{
		tmp.data[i] = data[i];
	}
	for(int i = 0; i < str.length(); i++)
	{
		tmp.data[size + i] = str[i];
	}
	return tmp;
}

bool String::operator==(const String& str) const //checks to see if two strings are the same 
{
	bool equals = true;
	if(size != str.length())
	{
		return false;
	}
	for(int i = 0; i < size; i++)
	{
		if(data[i] != str[i])
		{
			equals = false;
		}
	}
	return equals;
}