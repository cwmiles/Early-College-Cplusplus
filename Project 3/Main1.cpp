#include <cstdlib>
#include <iostream>
#include <string>
#include "String.h"

using namespace std; 

int main(int argc, char** argv) 
{
	cout << "----------------------------------------------------" << endl; 
	cout << "Testing default constructor (should print NULL): " << endl;
	String s1; 
	s1.print(); 
	cout << "Length of s1 (should be 0): " << s1.length() << endl; 
	cout << "----------------------------------------------------" << endl; 
	cout << "Testing alt constructor String(int) (should print empty line): " << endl;
	String s2(5); 
	s2.print(); 
	cout << "Length of s2 (should be 5): " << s2.length() << endl;
	cout << "----------------------------------------------------" << endl; 
	cout << "Testing alt constructor String(char[]) (should print Test): " << endl;
	char test[5] = "Test";
	String s3(test); 
	s3.print(); 
	cout << "Length of s3 (should be 4): " << s3.length() << endl; 
	cout << "----------------------------------------------------" << endl; 
	cout << "Testing copy constructor (should print Test): " << endl;
	String s4(s3); 
	s4.print(); 
	cout << "Length of s4 (should be 4): " << s4.length() << endl;
	
	return 0; 
	
}
