// John Maslanka, Small Stack program, revised 3/2/2010, 2/14/2013, 2/25/2016
// Node class is low-level data-management class, Stack class is the Container 
// class. Main manages user input. DumpStack method added 2/25/2016

#include <iostream>
#include <string>
using namespace std;

// class Node definition
class Node
{
public:
	Node();
	Node*  push(Node*, string);
	string peek(Node*);
	Node*  pop(Node*);
	bool   isEmpty(Node*);
	void   List (Node*);
private:
	string Data;
	Node*  Next;    
};


// full method definitions for class Node

Node::Node() {}
Node* Node::push(Node* Ptr, string data) {
	Node* temp = new Node();
	if (temp != NULL) {
		temp->Next = Ptr;
		temp->Data = data;
		
		cout<<"temp="<<(size_t)temp<<endl;}
	else
		{
		cout << "Heap exhausted!" << endl;
		}
	return temp;
	}
Node* Node::pop(Node* Ptr) {
	Node* temp = Ptr->Next;
	delete Ptr;
	return temp;
	}
string Node::peek(Node* Ptr) {
	return Ptr->Data;
	}
void Node::List(Node* Ptr){
	Node* temp = new Node();
	if (temp != NULL)
		for (temp = Ptr; temp != NULL; temp = temp->Next)
			cout << temp->Data << endl;
	else
		cout << "Heap exhausted!" << endl;
	}
bool Node::isEmpty(Node* Ptr) {
	bool tf = false;
	if (Ptr == NULL)
		tf =  true;
	return tf;
}

int main()
{
	char Option;
	string userData;
	Node myStack;
	Node* myStackPtr = NULL;
	cout << "Welcome to my Stack program." << endl;
	cout << "Enter 1 to Push, 2 to Pop, 3 to Peek, 4 to List, H to help, ctrl-z to end" << endl;
	while (!cin.eof())
	{	cout << "Option: ";
		cin >> Option;
		if (!cin.eof()&& (Option > '0' && Option < '5' || Option == 'H' || Option == 'h')) {
		switch (Option)
		{
		case '1':
			cout << "Enter Your Data: ";
			cin >> userData;
			if (!cin.eof())
			{
				cout<<"myStack="<<(size_t) &myStack<<endl;
				cout<<"myStackPtr="<<(size_t) myStackPtr<<endl;
				myStackPtr = myStack.push(myStackPtr, userData);
				cout<<"after myStackPtr = myStack.push(myStackPtr, userData);"<<endl;
				cout<<"myStack="<<(size_t) &myStack<<endl;
				cout<<"myStackPtr="<<(size_t) myStackPtr<<endl;
				if (myStackPtr != NULL)
					cout << "User's Data " << userData << " is Pushed onto the stack!" << endl;
				else
					cout << "Heap is overflowed!";
			}
			break;
		case '2':
			if (!myStack.isEmpty(myStackPtr)) {
				myStackPtr = myStack.pop(myStackPtr);
				}
			else
				{
				cout << "Stack Is Empty!" << endl;
				}
			break;

		case '3':
			if (!myStack.isEmpty(myStackPtr)) {
				userData = myStack.peek(myStackPtr);
				cout << "Peeked Element is: " << userData << endl;
				}
			else
				{
				cout << "Stack Is Empty!" << endl;
				}
			break;
		case '4':
			if (!myStack.isEmpty(myStackPtr)) {
				myStack.List(myStackPtr);
				}
			else
				{
				cout << "Stack Is Empty!" << endl;
				}
			break;
		case 'H': case 'h':
			cout << "Enter 1 to Push, 2 to Pop, 3 to Peek, 4 to List, H to help, ctrl-z to end" << endl;
			break;
		default:
			cout << "Invalid Selection. Try Again..." << endl;
			break;
		}
	  }
	}
cout << "\n***Thank You For Using my no-container Stack Program***\n";
return 0;
}