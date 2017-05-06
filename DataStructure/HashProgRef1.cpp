// HashProgRef1.cpp  John Maslanka 11/20/2009. Hash program Array elements tied 
//  to link lists.  See Main and Savitch Data Structures etc, pp 590-615.
// This program uses a string entered by the user to develop a hash value which 
//  provides an index into an array as a candidate to place a new entry. If the 
//  array entry is already occupied, the program creates a new node om a linked 
//  list associated with the array element.

#include <iostream>
#include <string>
using namespace std;
#define MAX 23   // specify the number of array elements to be available

class Node {
public:
	Node () {}
	Node* putOneNode (Node*, string);
	string getOneNode ();
	Node* getNextPointer ();
	void putNextPointer (Node*);
private:
	string str;
	Node* nextPtr;
};

#include <cstdlib>

Node* Node::getNextPointer (){
	return nextPtr;
}
void Node::putNextPointer (Node* x){
	this->nextPtr = x;
}
Node* Node::putOneNode (Node* x, string s) {
	Node* temp;
	temp = new Node();
	if (temp) {
		temp->nextPtr = x;
		temp->str = s;
	}
	return temp;
}
string Node::getOneNode() {
	return str;
}

class HashList {
public:
	HashList ();
	bool putNode (string);
	void displayList ();
	Node* findNode (string);
	void  deleteNode (string);
	Node* getListPointer();
private:
	Node* ListPointer;
};

//#include "Node.h"
//#include "HashList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

HashList::HashList () 
	{ListPointer = NULL;}

bool HashList::putNode (string udata) {
	bool x = false;
	Node A;
	Node* temp1;
	temp1 = A.putOneNode (ListPointer, udata);
	if (temp1 != NULL)
	{	ListPointer = temp1;
		x = true;
	}
	return x;
}
Node* HashList::getListPointer () {
	return ListPointer;
	}
Node* HashList::findNode (string udata){
	Node* temp;
	for (temp = ListPointer; temp != NULL && temp->getOneNode() != udata; 
		                    temp = temp->getNextPointer());
	return temp;
}
void HashList::displayList() {
	Node* temp;
	for (temp = ListPointer; temp != NULL;
									temp = temp->getNextPointer()) 
		cout << " " <<temp->getOneNode ();
	cout << endl;
}
void HashList::deleteNode (string udata) {
	Node* delPtr = findNode (udata); 
	if (delPtr != NULL) {
		if (ListPointer == delPtr)
			ListPointer = delPtr->getNextPointer();
		else { 	
			Node* previousPtr; 
			Node* temp = ListPointer; 
			for (previousPtr = NULL; temp != delPtr; 
				previousPtr = temp, temp = temp->getNextPointer());
			previousPtr->putNextPointer(delPtr->getNextPointer());
		}
		delete delPtr;
	}
	else
		cout << "Invalid data entered" << endl;
}


int main () {  // 1
	char inputLine[80] = "";       // input buffer
	int hashValue, modHash, i;
	HashList namePtr [MAX];
	while (!cin.eof()) {  //2        // while loop to accept user data and to develop hashed entry
		cout << "Please enter a string of characters followed by <Enter>. " << endl;
		cin.getline(inputLine, 80);       // get user input string -- up to 80 characters
		if (!cin.eof()) {    //3    // accept user input
			hashValue = 0;
			for (i = 0; i < strlen (inputLine); i++){ //4  // calculate hash value by adding the ASCII
				hashValue += (int) inputLine[i];        //  equivalents of the user's input characters
				} //3
			modHash = hashValue % MAX;				// reduce hash value to be within the table
			namePtr[modHash].putNode (inputLine);
		}		//2
	} // 1
	for (i = 0; i < MAX; i++) { //2     // list the contents of the array
		if(namePtr[i].getListPointer()) {
			cout << "Position in table is " << i << " Attached List follows " << endl;
			namePtr[i].displayList();
			}
		} //1
	cout << "Please enter user value to retrieve " << endl;
	cin.clear();
	cin.getline(inputLine, 80);       // get user input string -- up to 80 characters
	if (!cin.eof()) {       // accept user input
		hashValue = 0;
		for (i = 0; i < strlen (inputLine); i++){ //4  // calculate hash value by adding the ASCII
			hashValue += (int) inputLine[i];        //  equivalents of the user's input characters
			} 
		modHash = hashValue % MAX;				// reduce hash value to be within the table
		// Inserted Sat PM 10/20/2012
		if (namePtr[modHash].getListPointer()){  // use getListPointer method to get onto target list
			cout << "List " << modHash << " at location " << namePtr[modHash].getListPointer() 
				<< " contains ";  // report list header at target location
			namePtr[modHash].displayList(); // report list at target location
			if (namePtr[modHash].findNode (inputLine))
				cout << "User value " << inputLine << " is at location " 
					<< namePtr[modHash].findNode (inputLine) << endl; //Report target entry and its location
			else
				cout << "User value " << inputLine << " is not in database." << endl;

			}
		else
			cout << "List " << modHash << " is empty." << endl;  // else as stated in this cout.
		// End of insertion 10/20/2012
	}
return 0;
}
