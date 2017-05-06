// Program Name: ArrayAccess.cpp  Author: John Maslanka  Date: 7/11/2016
// This program creates a static array then accesses its elements in three
// different approaches -- first using the array name and an index to access
// the individual elements, second using the array name and a displacement
// factor under dereferencing to access the individual elements, and third
// using acombination of array name, integer displacement and indexing.

#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
	
	//int *Array = new int[];
	int Array[10] = {0,1,2,3,4,5,6,7,8,9};  // Arr is pointer to an array of ints 
											//in the program's compiled space
	
	int i, n;
	// First using the array name and an index
	for (i = 0; i < 10; i++)
		cout << " " << Array[i];
	cout << endl;
	// Second using indirection
	for (n = 0; n < 10; n++)
		cout << " " << *(Array + n);
	cout << endl;
	//Third using the array name plus an index to start
	for (n = 4, i = 0; i < 6; i++)
		cout << " " << (Array + n)[i];
	cout << endl;
	//system("PAUSE"); // in case your system expects PAUSE before ending program

	cout<<" "<<sizeof(int)<<endl;
	cout<<" "<<sizeof(size_t)<<endl; //For size_t's length, it depends on your system:32 bit will get 4 bytes.


	return 0;
}