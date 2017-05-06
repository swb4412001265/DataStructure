// Author:	John Maslanka and CS341 class -- Doubly Linked Bag List
// Date:	10/7/2009 
// Edit:	Create DoubleLinkMenu top-level access to DoubleLinkList application
// Edit:	Update input data type to string

#include <string>
#include <iostream>
using namespace std;

class Node {
public:
	Node () {}
	Node* putOneNode (Node*, string);
	string getUserData ();
	Node* getNextPointer ();
	void putNextPointer (Node*);
	Node* getPriorPointer ();
	void putPriorPointer (Node*);
private:
	string str;
	Node* nextPtr;
	Node* priorPtr;
};

Node* Node::getNextPointer (){
	return nextPtr;
}
void Node::putNextPointer (Node* x){
	this->nextPtr = x;
}
Node* Node::getPriorPointer (){
	return priorPtr;
}
void Node::putPriorPointer (Node* x){
	this->priorPtr = x;
}
Node* Node::putOneNode (Node* x, string y) {
	Node* temp = NULL;
	if (temp = new Node()) {
		temp->nextPtr = x;
		temp->priorPtr = NULL;
		temp->str = y;
	}
	return temp;
}
string Node::getUserData() {
	return str;
}

class DoubleLinkList {  // My Container class
public:
	DoubleLinkList ();
	bool putNode (string);  // Admit to list
	void getListForward ();   //
	void dumpListForward ();   //
	void getListReverse ();	  // 
	Node* findNode (string);  // 
	bool  deleteNode (string); // Serve - delete one Node
	bool  deleteToEnd (string);  // delete an entire population from current position to end of list

private:
	Node* FwdListPointer;
	Node* RevListPointer;
	Node* previous;
};


//#include <iostream>
//using namespace std;


DoubleLinkList::DoubleLinkList () 
	{FwdListPointer = RevListPointer = previous = NULL;}

bool DoubleLinkList::putNode (string s) {
	bool x = false; 
	Node* temp1;
	Node* tempfwd;
	Node A;
	cout << "FwdListPointer = " << (int) FwdListPointer << endl;
	temp1 = A.putOneNode (FwdListPointer, s);
	cout << "temp1 = " << (int) temp1 << endl;
	if (temp1 != NULL)
	{	if (FwdListPointer == NULL && RevListPointer == NULL){
			FwdListPointer = RevListPointer = temp1;
			cout << "FwdListPointer = " << (int) FwdListPointer << endl;
			cout << "RevListPointer = " << (int) RevListPointer << endl;
			}
		else
			{tempfwd = FwdListPointer;
			 tempfwd->putPriorPointer (temp1); 
			 cout << "tempfwd->getPriorPointer = " << (int) tempfwd->getPriorPointer() << endl;
			 FwdListPointer = temp1;
			 cout << "FwdListPointer = " << (int) FwdListPointer << endl;
			}
		x =true;
	}
	return x;
}
Node* DoubleLinkList::findNode (string udata){
	Node* temp; 
	previous = FwdListPointer;
	for (temp = FwdListPointer; temp != NULL && temp->getUserData () != udata; 
		                   previous = temp, temp = temp->getNextPointer());
	return temp;
}
void DoubleLinkList::getListForward() {
	Node* temp;
	for (temp = FwdListPointer; temp != NULL;
									temp = temp->getNextPointer()) 
		cout << " User Data " << temp->getUserData () << endl;
}
void DoubleLinkList::dumpListForward() {
	Node* temp;
	cout << endl << "Forward ListPointer " << (int)FwdListPointer 
		 << "   Reverse ListPointer " << (int)RevListPointer << endl;
	for (temp = FwdListPointer; temp != NULL;
									temp = temp->getNextPointer()) { 
		cout << " User Data " << temp->getUserData ();
		cout << "   Ref to Node " << (int)temp;
		cout << "   Next Ptr " << (int)temp->getNextPointer();
		cout << "\t   Prior Ptr " << (int)temp->getPriorPointer();
		cout << endl;
	}
}
void DoubleLinkList::getListReverse() {
	Node* temp;
	for (temp = RevListPointer; temp != NULL;
									temp = temp->getPriorPointer()) 
		cout << " User Data " << temp->getUserData () << endl;
}
// from Yelena Oulanova
bool DoubleLinkList::deleteNode (string udata) {
	Node* delPtr;
	Node* temp = NULL;     // temporary pointer variable to a Node - is internal to this method
	bool status = false;
	delPtr = findNode (udata);
	cout << "FwdListPointer = delPtr = " << (int) delPtr << endl;
	if (delPtr != NULL){   // a live pointer?
		if (FwdListPointer == delPtr) { // contains same value as forward list pointer instance variable?
			cout << "FwdListPointer = " << (int) FwdListPointer << endl;
			FwdListPointer = FwdListPointer->getNextPointer();  //yes - get next ptr from first Node and
																// move it to the forward list ptr
			cout << "FwdListPointer = " << (int) FwdListPointer << endl;
		}
		else  // forward list pointer not equal to delPtr - points to an interior Node on the list
		{
			temp = delPtr->getPriorPointer(); // get prior ptr from Node referred to by delPtr and assign it to temp
			cout << "temp = " << (int) temp << endl;
			temp->putNextPointer(delPtr->getNextPointer());  // get next ptr to next Node and put it into
			                                 // the prior node's next ptr
			cout << "temp->getNextPointer = " << (int) temp->getNextPointer() << endl;
		}
		// these statements should have comments which are symmetricdal to comments for the forward list ptr
		//  above (Left to the students.)
		if (RevListPointer == delPtr) {
			cout << "RevListPointer = " << (int) RevListPointer << endl;
			RevListPointer = RevListPointer->getPriorPointer();
			cout << "RevListPointer = " << (int) RevListPointer << endl;
			cout << "FwdListPointer = " << (int) FwdListPointer << endl;
			}
		else
		{
			temp = delPtr->getNextPointer();
			temp->putPriorPointer(delPtr->getPriorPointer());
			cout << "delPtr->getPriorPointer = " << (int) delPtr->getPriorPointer() << endl;
		}
		delete delPtr; // release Node pointed to by the delPtr
		status = true;
	}
	return status;
}
bool DoubleLinkList::deleteToEnd (string udata) {
    // NOTE: to invert the logic (delete in the opposite direction) use RevListPointer and getPriorPointer()
    Node* temp = NULL;
	Node* delPtr;
    int numDel = 0;
	delPtr = findNode (udata);
    if (delPtr != NULL) {
        if ((temp = delPtr->getNextPointer()) != NULL) temp->putPriorPointer(NULL);
        if (delPtr == RevListPointer) RevListPointer = NULL;
        FwdListPointer = delPtr->getNextPointer();

        while(delPtr != NULL) {
            temp = delPtr->getPriorPointer();
            delete delPtr;
            delPtr = temp;
            numDel++;
        }
        delete delPtr;
        numDel++;
    }
    return (numDel > 0); // return true if anything was deleted.
}

int main () { // 1
	DoubleLinkList A;
	string str, udata;
    bool cont = true;
	char sel;
	Node* nodePtr = NULL;
	while (!cin.eof() && cont) { //2
		cout << "Enter your function:\n Add, Remove(M), DeleteToEnd(T), Exit," << endl;
		cout << "  Find, ListForward, ListReverse(R), DumpList(D): ";
		cin >> sel;
		if (!cin.eof()) {//3
		switch (sel) {		//4
			case 'A': case 'a': { //5
				cout << "Enter a string, or control-z to end ";
				cin >> str;
				if (!cin.eof())
					cont = A.putNode(str);
				else
					cont = false;
				break;
			}//4
			case 'M': case 'm': {//5 //assume that the current found node is to be deleted
				 cout << "Please Enter User Data value to remove: ";
				 cin >> udata;
				 if (!cin.eof()) {//6
					if (A.deleteNode (udata))
					  {//7
						cout << "Delete was successful" << endl;
					  }//6
					else
					{ //7
						cout << "Delete was not successful" << endl;
					}//6
				 }//5  new curly bracket
				 break;
				}//4
			case 'T': case 't': { // assume that the current found node is to be deleted // 6
				 cout << "Please Enter User Data value to delete to end: ";
				 cin >> udata;
				 if (!cin.eof()) { //7
					if (A.deleteToEnd (udata))
					  {//8
						cout << "Delete to end was successful" << endl;
					  }//7
					else
						cout << "Delete to end was not successful" << endl;
				}//6
				else
					cout << "Valid Find not run previously." << endl;
				break;
			   }//5
			case 'E': case 'e': {//6
				cont = false;
				break;
				}//5
			case 'F': case 'f': {//6
				cout << "Please Enter User Data value to find: ";
				cin >> udata;
				if (!cin.eof()) {//7
					nodePtr = A.findNode(udata);
					if (nodePtr == NULL)
						cout << "Data not found." << endl;
					else
						cout << "Your data was found: " << nodePtr->getUserData() << endl;
				}//6
				else 
					cont = false;
				break;
				}//5
			case 'L': case 'l': {//6
				cout << "Forward List of nodes" << endl;
				A.getListForward();
				cout << endl;
				break;
				} //5
			case 'R': case 'r': {//6
				cout << "Reverse List of nodes" << endl;
				A.getListReverse();
				cout << endl;
				break;
				}//5
			case 'D': case 'd': {//6
				cout << "Forward dump of List" << endl;
				A.dumpListForward();
				cout << endl;
				break;
				}//5	
			default: {//6
				cout << "Invalid function entered." << endl;
					 }//5
			}//4
		}//3
	}//2
	return 0;
}//1