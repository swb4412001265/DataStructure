// John Maslanka  BagMenuProg3A-nc.cpp archaic Baglist Demo 9/12/2012

// Author:	John Maslanka
// Date:	9/12/2012
// Original unContainerized BagList program with class
// Please observe how much knowledge the application has of the underlying Node class.
//
// Bugfix 9/17/2014: test in main for valid return reference value from putNode method.

#include <iostream>
using namespace std;
#include <cstdlib>


//into Node.h file
class Node {
public:
	Node ();
	Node* putNode (Node*, double);  // setNode
	Node* findNode (Node*, double);  // getNode
	void  getList (Node*);			// display contents of entire list
	Node* deleteNode (Node*, double);  //delte a member of the list
private:
	double nr;
	Node* nextPtr;  //Please do not define data members in public of a class.
};


//into Node.cpp file1
Node::Node () {}  //Please definea default constructor for every class you defined

Node* Node::putNode (Node* NodePtr, double udata) {
	Node* temp = NULL;
	temp = new Node();  // new operator asks memory manager for Heap space to set
						// up a Node object. Memory manager returns a reference 
						// to space acquired or a NULL value if space not 
						// available.
	if (temp) {	// Test if space availaable
		temp->nextPtr = NodePtr;	// If space available fill reference and
		temp->nr = udata;			// fields
	}
	return temp;  // For both cases return the reference to the caller to decide
					// how to handle that value
}
Node* Node::findNode (Node* NodePtr, double udata){
	Node* temp;
	for (temp = NodePtr; temp != NULL && temp->nr != udata; 
		                    temp = temp->nextPtr);
	return temp;
}
void Node::getList(Node* NodePtr) {
	Node* temp;
	for (temp = NodePtr; temp != NULL; temp = temp->nextPtr) 
		cout << " User Data " << temp->nr << endl;
}
Node* Node::deleteNode (Node* NodePtr, double udata) {
	Node* delPtr = findNode (NodePtr, udata); // Locate Node to be deleted
	if (delPtr != NULL) {  // Node not found, skip to end of method
		if (delPtr == NodePtr) { // Is Node to be deleted the first Node?
			// Yes, remove it from list
			NodePtr = delPtr->nextPtr; 
		}
		else { // Search list again for Node to be deleted. If we come 
			// here we know that a Node to be deleted has been found.
			Node* prevPtr; // Define new pointers within method
			Node* temp = NodePtr; // Assign initial pointer to temp.
			// Move through list to find Node to be deleted.  
			//  (Note: If it is the last Node, its predecessor's NextPtr 
			//  field will wind up being set to NULL as the result of 
			//  this process.)
			for (prevPtr = NULL; temp != delPtr; 
				prevPtr = temp, temp = temp->nextPtr) ;
			// Reset next pointer in list member Node prior to Node to 
			//  be deleted.
			prevPtr->nextPtr = delPtr->nextPtr; 
		}
		delete delPtr; // Return its Heap space to the memory manager.
		delPtr = NULL; // Just to be careful, clears any previous reference 
						// retained in this variable. (Important if delPtr
						// used later in this method.)
	}
	return NodePtr;  // return status to caller
}

int main () { 

	Node* listHdr = NULL;  // Reference field keeps current location of head of list in the Heap
    double udata;
	bool cont = true;
    char sel;
	Node A;    // define a node in the compiled code to support calls to methods of the class
    while (!cin.eof()&&cin.good()&&cont == true) { 
	  cout << "Enter your function: Add, Exit, Find, List, Delete: ";
	  cin >> sel;
	  if (!cin.eof()) { 
	    switch (sel) {	
		case 'A': case 'a': { 
		    cout << "Enter a double-precision number or control-z to end ";
		    cin >> udata;
		    if (!cin.eof() && cin.good()){ 
				//Node* temp1;  // Bugfix: Declare a temp data field to receive // commemted in class Feb 17
								// the return reference from puNode method
				Node* temp1 = A.putNode(listHdr, udata);  // Bug fix: Assign return from putNode method
				if (temp1 != NULL)		// Bugfix: test return value to makes sure that it is a 
										// valid reference 
					listHdr = temp1;	// Bugfix: finally assign returned reference to listHdr
				else  // Bugfix: if return value is Null, display message
					cout << "No more Heap memory. No more Data can be added to list." << endl;
				} 
			else
				if (!cin.eof())
					cout << "Invalid data entered" << endl;
		    break;
		    } 
		case 'E': case 'e': {
			cont = false;
			break;
			} 
		case 'F': case 'f': {
			cout << "Please Enter User Data value to find: ";
			cin >> udata;
			if (!cin.eof() && cin.good()) 
				// Either a reference or NULL is returned
				if (A.findNode(listHdr, udata)) 
					cout << "Node " << udata << " found" << endl;
				else
					cout << "Node " << udata << " not found" << endl; 
			break;
			}
		case 'L': case 'l': {
			if (listHdr != NULL){
				cout << "List of nodes" << endl;  // Title of displayed list
				A.getList(listHdr);
				}//5
			else
				cout << "List is Empty";
			cout << endl;
			break;
			}
		case 'D': case 'd': {
		    cout << "Enter a double-precision number or control-z to end ";
		    cin >> udata;
		    if (!cin.eof() && cin.good()){ 
				if (listHdr == A.deleteNode (listHdr, udata))
					cout << "Node deleted from list.";
				else
					cout << "Node not found on list.";
				}
			cout << endl;
			break;
			}
		default: {
			cout << "Invalid selection entered." << endl;
			break;
			 }
		   }
	    }
	}
	system ("PAUSE");
	return 0;
}