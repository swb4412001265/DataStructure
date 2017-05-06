//Midterm homework problem2 from Wenbo Su

#include <string>
#include <iostream>
using namespace std;

//#include "Node.h"
class Node {
public:
	Node () {}
	Node* putNode (Node*, string);
	string getNodeData ();
	Node* getNextPointer ();
	void putNextPointer (Node*);
private:
	string st;
	Node* nextPtr;
};

#include <cstdlib>

Node* Node::getNextPointer (){
	return nextPtr;
}
void Node::putNextPointer (Node* x){
	this->nextPtr = x;
}
Node* Node::putNode (Node* x, string s) {
	Node* temp = NULL;
	if (temp = new Node()) {
		temp->nextPtr = x;
		temp->st = s;
	}
	return temp;
}
string Node::getNodeData() {
	return st;
}

//#include "BagList.h"
class BagList {  //Container class
public:
	BagList ();
	bool putANode (string);
	void getList ();
	Node* findNode (string);
	void  deleteNode (string);
private:
	Node* ListPointer;
	Node* FirstNode;
};


BagList::BagList () 
	{ListPointer = NULL;}
bool BagList::putANode (string udata) {
	bool x = false;
	int acsValue = 0;
	Node* temp1;
	Node A;
	cout<<"This is the string you entered:"<<udata<<endl;
	for (int i = 0; i < udata.size()-1; ++i)	//this two for loop for sorting string
	{
		for (int j = 0; j < udata.size()-1-i; ++j)
		{
			if( (int)udata[j]> (int)udata[j+1] ){
				int temp = (int)udata[j];
				udata[j] = udata[j+1];
				udata[j+1] = temp;
			} 
		}
	}
	cout<<"This is the string after sorting:"<<udata<<endl;	//print out string after sorting.
	temp1 = A.putNode (ListPointer, udata);
	if (temp1 != NULL)
	{	ListPointer = temp1;
		x = true;
	}
	return x;
}
void BagList::getList() { // return value shoould be a string of concatenated variables
	Node* temp;
	for (temp = ListPointer; temp != NULL;
									temp = temp->getNextPointer()) 
		cout << " User Data " << temp->getNodeData () << endl;
}
Node* BagList::findNode (string udata){
	Node* temp;
	for (temp = ListPointer; temp != NULL && temp->getNodeData () != udata; 
		                    temp = temp->getNextPointer());
	return temp;
}
void BagList::deleteNode (string udata) {  // suggested by Yelena Oulenova
	Node* delPtr = findNode (udata); 
	if (delPtr != NULL) {
		if (ListPointer == delPtr)
			ListPointer = delPtr->getNextPointer();
		else { 	Node* previousPtr; 
			Node* temp = ListPointer; 
			for (previousPtr = NULL; temp != delPtr; 
				previousPtr = temp, temp = temp->getNextPointer());
			previousPtr->putNextPointer(delPtr->getNextPointer());
		}
		delete delPtr;
		delPtr = NULL; //clears any previous reference retained in this variable
		cout << "Node deleted: " << udata << endl;
	}
	else
		cout << "Node not found: " << udata << endl;
}

int main () {
    BagList A;  // declare a Container object
    string udata;
	bool cont = true;
    char sel;
    while (!cin.eof() && cont == true) {
	cout << "Enter your function: Add, Delete, Exit, Find, List: ";
	cin >> sel;
	if (!cin.eof()) {
	    switch (sel) {		
		case 'A': case 'a': {
		    cout << "Enter a string of characters or control-z to end ";
		    cin >> udata;
		    if (!cin.eof())
				cont = A.putANode(udata); // put in message instead of using cont.
		    break;
		}
		case 'D': case 'd': { 
			cout << "Please Enter User Data value to delete: ";
			cin >> udata;
			if (!cin.eof()) 
				A.deleteNode (udata);
			break;
			}
		case 'E': case 'e': {
			cont = false;
			break;
			}
		case 'F': case 'f': {
			cout << "Please Enter User Data value to find: ";
			cin >> udata;
			if (!cin.eof()) 
				if (A.findNode(udata))
					cout << "Node " << udata << " found" << endl;
				else
					cout << "Node " << udata << " not found" << endl; 
			break;
			}
		case 'L': case 'l': {
			cout << "List of nodes" << endl;
			A.getList();
			cout << endl;
			break;
			}
		default: {
			cout << "Invalid function entered." << endl;
			break;
			 }
		   }
	    }
	}
//	system ("PAUSE");
	return 0;
}