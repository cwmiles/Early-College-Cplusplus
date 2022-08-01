/*
Cort Miles
9/6 at 1:30pm
This program takes in users name and then asks for a command
A or B and then prints a specific output based on the command


*/
#include <iostream>

void sum(int a, int b, int x); 
using namespace std;

int main(int argc, char **argv){

     int a(10), b(30), x(0);

     sum(a,b,x); 

     cout << “The value of x is: “ << x ;

     return 0; 

}

void sum(int a, int b, int x) {

        x = a + b;

}
