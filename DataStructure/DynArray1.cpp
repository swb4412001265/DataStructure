//Homework2 from Wenbo Su

#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
	
	int* Arr = NULL;  // Arr is pointer to an array of ints in heap
	int* temp = NULL; // temp defined likewise
	int count = 0;	  // track array length
	bool end = false; // flag to terminate while loop; AVOID using break stmt in loop

	cout << endl;	// provide blank line so user sees first prompt easily
	while (!cin.eof() && cin.good() && end == false)
	{
		temp = new(int[count+1]);  // ask for one new int in heap
		if (temp != NULL){  // if heap available
			cout << "Please enter an int number or EOF to terminate" << endl;
			cin >> *(temp + count);  // get user's next input
			if (!cin.eof() && cin.good()) {  // if valid input
				for (int i = 0; i < count; i++) // enter Arr array into temp array
					*(temp + i) = *(Arr + i);
				delete[] Arr; // delete current reference in Arr
				Arr = temp;   // assign reference in temp to Arr
			}
			else {  // if user entered an invalid value including EOF in input
				if (!cin.eof()) {
					cout << "Invalid Input" << endl;
				}
				end = true; // set flag to terminate while loop
			}
			count++;  // increment count of inputs for anticipated next input
			delete[] temp;	//heap temp's memory back to heap
			temp = NULL;	//point temp to NULL 
		}
		else {
			cout << "Heap exhausted." << endl;  
			end = true;  // set flag to terminate while loop here also
		}
	}
	count--;  // decrement count, which was incremented in anticipation of
				//  another valid input
	if (count > 0) {  // if positive count, display entries of input array
		cout << "Input Array is: " << endl;
		for(int j = 0; j < count; j++) // display array
			cout << *(Arr + j) << " ";
		cout << endl;  // return cursor to lefthand position
		}
//	system("PAUSE"); // in case your system expects PAUSE before ending program
	return 0;
}