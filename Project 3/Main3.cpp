#include <cstdlib>
#include <iostream>
#include <string>
#include "String.h"

using namespace std; 

int main(int argc, char** argv) 
{
	String s1; 
	String s2(5); 
	char test[5] = "Test";
	String s3(test); 
	String s4(s3);
	cout << "----------------------------------------------------" << endl; 
	cout << "Testing operator== function (should print Correct twice): " << endl;
	if(s4 == s3)
	{
		cout << "Correct" << endl;
	}
	else 
	{
		cout << "Incorrect" << endl; 
	}
	if(s1 == s3)
	{
		cout << "Incorrect" << endl;
	}
	else 
	{
		cout << "Correct" << endl;
	}
	cout << "----------------------------------------------------" << endl; 
	cout << "Testing operator[] function (should print T and then an empty line): " << endl;
	cout << s3[0] << endl; 
	cout << s3[7] << endl;
	cout << "----------------------------------------------------" << endl; 
	cout << "Testing operator= function (should print Test twice): " << endl;
	s1 = s2 = s3; 
	s1.print(); 
	s2.print(); 
	cout << "----------------------------------------------------" << endl; 
	cout << "Testing operator+ function (should print TestTest): " << endl;
	s1 = s2 + s3; 
	s1.print();
	
	return 0; 
}
