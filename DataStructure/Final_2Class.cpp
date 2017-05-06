#include <iostream>
#include <string>
using namespace std;
#define MAX 23 

class Node
{
public:
	Node(){};
	~Node(){};
//	void putName(string *);
	string getName(int);
	bool* getOccupied(int);
	int* getFirstHash(int);
	int* getI();
	
private:
	string name[MAX];
	int firstHash[MAX];
	bool occupied[MAX];
	int* i;	
};
/*
Node::Node(){
	occupied[MAX] = { MAX*false };
}
*/

string Node::getName(int x){
	return name[x];
}
bool* Node::getOccupied(int x){
	return occupied+x;
}
int* Node::getFirstHash(int x){
	return firstHash+x;
}
int* Node::getI(){
	return i;
}

class Hash
{
public:
	Hash();
	~Hash(){};
	void getInputLine();
	void listHashTable();
private:
	char inputLine[80];
	int hashValue;
	int modHash;
};
Hash::Hash(){
	hashValue = 0;
}

void Hash::getInputLine(){
	Node A;
	bool full = false;
	for (int i = 0; i < MAX; ++i)
	{
		*(A.getOccupied(i)) = false;
	}
	//A.getOccupied(MAX) = { MAX * false };
	while (!cin.eof() && full == false) { // test for EOF, for hash table not full
		cout <<"Please enter a string of characters followed by <Enter>." << endl 
			 << "Terminate by entering EOF (control-z on keyboard in Windows." 
			 << endl;
		cin.getline(inputLine, 80); 
		if (!cin.eof()) {
			//hashValue = 0;  // calculate initial hash value
			for (*(A.getI()) = 0; *(A.getI()) < strlen (inputLine); (*(A.getI()))++){  
				hashValue += (int) inputLine[*(A.getI())];      
				}
		modHash = hashValue % MAX;	// test initial hash value for available //  array entry
			if (*(A.getOccupied(modHash)) == false) { 
				A.getName(modHash) = inputLine;	
				*(A.getFirstHash(modHash)) = modHash;
				*(A.getOccupied(modHash)) = true;
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
				for (*(A.getI()) = 0; *(A.getI()) < MAX && found == false && full == false; (*(A.getI()))++){
					// test found == false, need to stop execution of this 
					// loop when an available array position is found
					if (*(A.getOccupied(*(A.getI()))) == false){ // test if selected hash
   // table element is occupied 
						A.getName(*(A.getI())) = inputLine;											
						*(A.getFirstHash(*(A.getI()))) = modHash;
						*(A.getOccupied(*(A.getI()))) = true;
						cout << "Your input line " << inputLine 
							<< " hashes to " << *(A.getI()) << endl;
						found = true; // Set array position found
					}
					else
						if (*(A.getI()) >= MAX-1) { 
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
}
void Hash::listHashTable(){
	Node A;
	for (*(A.getI()) = 0; *(A.getI()) < MAX; (*(A.getI()))++)  // finally, list members of hash table
		if (*(A.getOccupied(*(A.getI()))) == true)
			cout << " Position in table is " << *(A.getI()) << " Hashed to " 
	<< *(A.getFirstHash(*(A.getI()))) 
				<< ".\tString is " << A.getName(*(A.getI())) << endl;
}


int main()
{	Hash A;
	A.getInputLine();
	A.listHashTable();
	return 0;
}