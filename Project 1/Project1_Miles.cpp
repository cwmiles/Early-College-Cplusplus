/*
Cort Miles
9/6 at 1:30pm
This program takes in users name and then asks for a command
A or B and then prints a specific output based on the command
The output is either the users name and hello, or a countdown with goodbye.
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string fName;
    string lName;
    char cmd;
    cout << "Enter your first name: "; // type your first name
    cin >> fName;
    cout << "Enter your last name: " ;//type your last name
    cin >> lName;
    cout << "Enter your command: ";
    cin >> cmd;
    if(cmd == 'A')
    {
        cout << "Hello, " << fName << " " << lName;
    }
    else if (cmd == 'B')
    {
        cout << "10\n9\n8\n7\n6\n5\n4\n3\n2\n1\nGoodbye";
    }
    else 
    {
        cout << "Invalid command!";
    }

}