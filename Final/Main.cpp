#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int* insert(int*, int, int, int); 
int main(){
     int* arr = new int[4];
     int size = 4; 
     for(int i = 0; i < size; i++) arr[i] = i;
     arr = insert(arr, size, 2, 7);
     cout << arr[2] << arr[0] << arr[3] << arr[4] << size << endl;
}
int* insert(int* _arr, int _size, int _ind, int _val){
      int * ret = new int[++_size]; 
      for(int i = 0; i < _ind; i++)  ret[i] = _arr[i]; 
      ret[_ind] = _val; 
      for(int i = _ind; i < _size-1; i++) ret[i+1] = _arr[i];
      return ret; 
}