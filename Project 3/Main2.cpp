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
	cout << "Testing clear() function (should print NULL): " << endl;
	s4.clear();
	s4.print();
	cout << "Length of s4 (should be 0): " << s4.length() << endl;
	cout << "----------------------------------------------------" << endl; 
	cout << "Testing empty() function (should print Correct twice): " << endl;
	if(s4.empty())
	{
		cout << "Correct" << endl; 
	}
	else 
	{
		cout << "Incorrect" << endl;
	}
	if(s3.empty())
	{
		cout << "Incorrect" << endl; 
	}
	else 
	{
		cout << "Correct" << endl;
	}
	cout << "----------------------------------------------------" << endl; 
	cout << "Testing find() function: " << endl;
	char test2[20] = "ATGTCTTGATGCATGGTTA"; 
	String s5(test2); 
	char sub1[3] = "TT"; 
	cout << "TT was found at (should be 5): " << s5.find(sub1,0) << endl;
	char sub2[4] = "TTT"; 
	cout << "TTT was found at (should be -1): " << s5.find(sub2,0) << endl;
	
	
	return 0; 
	
}
