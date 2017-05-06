// Program Name Array3.cpp  Author John M  5/22/2015
// A somewhat more complicated program to define, expand and use an array of 
//   integers in the program's heap. This program contains the beginning of the
//   concept and implementation of "dynamic" array.
// This program accesses the array elemenets using "indirection"

#include <iostream> 
#include <iomanip>
using namespace std;

int main () {
	int i; int j; 
	int* Arr; // define Arr as a reference variable to an int and acquire
	Arr = new (int[5]); // access to space for 5 ints in the program's Heap.
	if (Arr != NULL) {
		cout << "Value in variable Arr points to the location " << (size_t) Arr << endl;
		for (i = 0; i < 5; i++){  // define a for loop header with index i which 
								// starts at 0 and is incremented by 1 each pass
								// thru the loop. Loop terminates when i >= 5. 
			*(Arr+i) = (i+1) * i;
			}
		cout << "First array is ";
		for (j = 0; j < 5; j++)  // loop to display array elements
			cout << *(Arr+j) << " ";
		cout << endl;
		cout << "Value in variable Arr points to Heap location " << (size_t) Arr << endl;
		cout << "Location of i is " << size_t (&i) << endl;
		cout << "Location of j is " << size_t (&j) << endl;

		// Now I want to do the same thing for five more array elements.
		// Procedure is somewhat more complex because we cannot depend on the
		// next five elements of the Heap being available.  To make sure that
		// transition to an array of ten elements is done properly and safely,
		// we go through several steps. (1) We ask for a new array of ten ints 
		// in the Heap. (2) We copy the first five ints to the new array. 
		// (3) We use/fill the five new elements with their values. (4) We
		// give up access to the old array.

		int* temp; // define a temp variable to hold the reference to new array
		temp = new (int[10]);  // Ask memory manager for ten elements of Heap
		if (temp != NULL) {  // Ask if we if we got the Heap space
			cout << "Reference to new Heap is " << (size_t) temp << endl;
			for (i = 0; i < 5; i++) {// Move first five elements from array Arr
				*(temp+i) = *(Arr+i);    // to new array referenced by temp
			}
			for (i = 5; i < 10; i++) { // enter next 5 elements into new array
				*(temp+i) = (i+1) * i;
			}
		delete [] Arr; // Return original array to memory manager
		Arr = temp;  // Assign the reference in temp to reference variable Arr
		cout << "New array is ";
		for (j = 0; j < 10; j++)  // loop to display array elements (again)
			cout << *(Arr+j) << " ";
		cout << endl;
		cout << "Value in variable Arr points to the location " << (size_t) Arr << endl;
		cout << "Location of i is " << size_t (&i) << endl;
		cout << "Location of j is " << size_t (&j) << endl;
		}
		else
			cout << "Insufficient Heap resource." << endl;  // If we get here the Heap is out of space
		}
	else
		cout << "Insufficient Heap resource." << endl;  // If we get here the Heap is out of space
	return 0;
}