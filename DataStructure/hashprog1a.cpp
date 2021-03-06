// John Maslanka October 2009 HashProg1.cpp
// A program which does hashing of user data to a fixed-length array.
// Edits 10/24/2014 JM -- (1) Remove two break; statements from the code. (2) Define 
// a "full" boolean variable to discontinue processing when the array is found to be full.
// (3) Define a "found" boolean variable to indicate that a location in the array has been
// found for a new entry. The "found" variable terminates further search for a new location
// for an input value when a location has been successfully found.

#include <iostream>
#include <string>
using namespace std;
#define MAX 23 

int main () {
	bool full = false;   // boolean set to false, changed to true when hash table is full
	char inputLine[80] = "";      
	int hashValue, modHash, i;//hashValue is the total number of all the hashValues
	string name [MAX];  // This line and the following two establish the information which
	int firstHash [MAX];  // is preserved for each entry of the hash array
	bool occupied [MAX] = {MAX * false};  //put the hash value is not occupied
	for (int i = 0; i < MAX; ++i)
	{
		cout<<occupied[i]<<" ";
	}
	while (!cin.eof() && full == false) { // test for EOF, also test for hash table not full
		cout <<"Please enter a string of characters followed by <Enter>." << endl 
			<< "Terminate by entering EOF (control-z on keyboard in Windows." << endl;
		cin.getline(inputLine, 80); 
		if (!cin.eof()) {
			hashValue = 0;  // calculate initial hash value
			for (i = 0; i < strlen (inputLine); i++){  
				hashValue += (int) inputLine[i];      
				}
			modHash = hashValue % MAX;	// test initial hash value for available array entry
			if (occupied[modHash] == false) { 
				name[modHash] = inputLine;	
				firstHash[modHash] = modHash;
				occupied [modHash] = true;
				cout << "Your input line " << inputLine << " hashes to "
					<< modHash << endl;
				}
			else   // initial tet failed, look for an alternate location in the array
				{ 
				cout << "Hash collision! We need to find an open table entry." << endl;
				bool found = false;  // declare binary state variable "found": 
									 // false means an available  array position 
								     // not found, true means it is found.
				for (i = 0; i < MAX && found == false && full == false; i++){
					// test found == false, need to stop execution of this loop when 
					//  an available array position is found
					if (occupied[i] == false){ // test if selected hash table element is occupied 
						name[i] = inputLine; // remove unnecessary { left curly bracket
						firstHash[i] = modHash;
						occupied [i] = true;
						cout << "Your input line " << inputLine 
							<< " hashes to " << i << endl;
						found = true; // Set array position found
						// remove unnecessary } right curly bracket
						// remove break; statement
					}
					else
						if (i >= MAX-1) { 
							cout << "Sorry! Table is full!" <<" We cannot place your entry." 
								  << endl << endl;
							full = true;  // set state flag hash array full
							// remove break; statement
						}
					  }
					}
				}
			}
		for (i = 0; i < MAX; i++)  // finally, list members of hash table
		if (occupied[i] == true)
			cout << " Position in table is " << i << " Hashed to " << firstHash[i] 
					<< ".\tString is " << name[i] << endl;
	return 0;
}
