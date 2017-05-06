/*A copy of the source code for my first C++ hash program is given below. 
 Regrettably, this source code contains no C++ classes. Please reconstruct 
 this source code as follows.  Divide the program into three parts so that 
 (1) one part contains the basic algorithms for placing an element into the hash table.  
 (2) The second part is a container class which contains the user interactions along with the calls 
 to the methods of the basic class in part (1).  
 The third part is the main which contains a skeleton which accesses the container class in part (2).
  Also, as  afterthoughts, (1) you may consider writing in better access procedures to examine your hash array, 
  lso you may count and report the number of accesses required to find each specific entry in the table.
*/

#include <iostream>
#include <string>
using namespace std;
#define MAX 23 

int main () {
	bool full = false;   // boolean set to false, changed to true when hash table full
	char inputLine[80] = "";      
	int hashValue, modHash, i;
	string name [MAX];  // This line and the following two establish the information w
	int firstHash [MAX];  // preserved for each entry of the hash array
	bool occupied [MAX] = {MAX * false};  //
	while (!cin.eof() && full == false) { // test for EOF, for hash table not full
		cout <<"Please enter a string of characters followed by <Enter>." << endl 
			<< "Terminate by entering EOF (control-z on keyboard in Windows." 
	<< endl;
		cin.getline(inputLine, 80); 
		if (!cin.eof()) {
			hashValue = 0;  // calculate initial hash value
			for (i = 0; i < strlen (inputLine); i++){  
				hashValue += (int) inputLine[i];      
				}
	modHash = hashValue % MAX;	// test initial hash value for available //  array entry
			if (occupied[modHash] == false) { 
				name[modHash] = inputLine;	
				firstHash[modHash] = modHash;
				occupied [modHash] = true;
				cout << "Your input line " << inputLine << " hashes to "
					<< modHash << endl;
				}
			else   // test failed, look for alternate location in array
				{ 
		cout << "Hash collision! We need to find an open table entry."
 	<< endl;
				bool found = false;  // declare binary state variable "found": 
						     // false means an available array position 
						     // not found, true means it is found.
				for (i = 0; i < MAX && found == false && full == false; i++){
					// test found == false, need to stop execution of this 
					// loop when an available array position is found
					if (occupied[i] == false){ // test if selected hash
   // table element is occupied 
						name[i] = inputLine;											
						firstHash[i] = modHash;
						occupied [i] = true;
						cout << "Your input line " << inputLine 
							<< " hashes to " << i << endl;
						found = true; // Set array position found
					}
					else
						if (i >= MAX-1) { 
							cout << "Sorry! Table is full!" 
	<<" We cannot place your entry." 
								<< endl << endl;
							full = true;  // set state flag to say 
//  hash array to full
						}
					  }
				     }
				}
			}
		for (i = 0; i < MAX; i++)  // finally, list members of hash table
		if (occupied[i] == true)
			cout << " Position in table is " << i << " Hashed to " 
	<< firstHash[i] 
				<< ".\tString is " << name[i] << endl;
	return 0;
}
