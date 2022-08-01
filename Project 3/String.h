/***************************************************************************
 * Name: Casey Cole
 * Email: coleca@email.sc.edu
 * Function: String object header file
 * 
 * Copyright (C) 2020 by Casey Cole                                        *
 *                                                                         *
 ***************************************************************************/
#include <iostream>
using namespace std;

class String {
	public: 
		String(); 
		String(int); 
		String(char[]); 
		String(const String&); 
		~String();
		
		int length() const; 
		void clear(); 
		bool empty() const; 
		int find(char[], int) const; 
		void print() const; 
		
		bool operator==(const String&) const; 
		const String operator+(const String&) const;  
		const String & operator=(const String);
		char operator[](int) const; 
		
	private: 
		char* data; 
		int size; 
        int getSize(const char[]) const;
};

