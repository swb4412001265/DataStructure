//Final question2 from Wenbo Su
#include <iostream>
#include <string>
using namespace std;
#define MAX 23 

class Hash      	//
{
public:
	Hash();
	~Hash(){};
	void getInputLine();	//method of put input into Hash table
	void listHashTable();	//method of show contents of Hash table
private:
	bool full;
	char inputLine[80];
	int hashValue;
	int modHash;
	int i;
	string name[MAX];
	int firstHash[MAX];
	bool occupied[MAX];	
};

Hash::Hash(){
	full = false;
	for (int i = 0; i < MAX; ++i)
	{
		occupied[i] = false;	
	}
	
}

void Hash::getInputLine(){
	while (!cin.eof() && full == false) { // test for EOF, for hash table not full
		cout<<"Please enter a string of characters followed by <Enter>." << endl 
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
					cout<< "Hash collision! We need to find an open table entry."
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
							cout<< "Your input line " << inputLine 
								<< " hashes to " << i << endl;
							found = true; // Set array position found
						}
						else
							if (i >= MAX-1) { 
								cout<< "Sorry! Table is full!" 
									<<" We cannot place your entry." 
									<< endl << endl;
								full = true;  // set state flag to say 
					//  hash array to full
							}
					}
				}
		}
	}				
}

void Hash::listHashTable(){
	for (i = 0; i < MAX; i++)  // finally, list members of hash table
		if (occupied[i] == true)
			cout<< " Position in table is " << i << " Hashed to " 
				<< firstHash[i] 
				<< ".\tString is " << name[i] << endl;		
}

class container  		//container class 
{
public:
	container(){};
	~container(){};
	void interaction();		//method of putting getInputLine and listHashTable together
};
void container::interaction(){
	Hash A;
	A.getInputLine();
	A.listHashTable();
}

int main()
{
	container A;
	A.interaction();
	return 0;
}


