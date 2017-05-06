// John Maslanka, Small Stack program, revised 3/2/2010, 2/14/2013

//include this material in the first file that uses it.i.e Node.h in this case.
//also use #pragma once to allow each #include library to be used only once.
#include <iostream>
#include <string>
using namespace std;


// class Node definition into file Node.h

class Node
{
public:
	Node();
	Node(string);
	void   putNextPtr (Node* ptr);
	Node*  getNextPtr ();  //You can use it even though class is not
							//fully defined.
	void   putData (string D);
	string getData (); 
private:
	string Data;
	Node* Next;    
};

// full method definitions for class Node into file named Noded.cpp

Node::Node()
{
	Data = "";
	Next = NULL;
}

Node::Node(string A)
{
	Data = A;
	Next = NULL;
}
void   Node::putNextPtr (Node* ptr) 
		{Next = ptr;}
Node*  Node::getNextPtr () 
		{return Next;}
void   Node::putData (string D) 
		{Data = D;}
string Node::getData () 
		{return Data;} 

// class Stack definition into the file named Stack.h

class Stack   //Container Class
{
public:
	Stack();
	void Push(string);
	bool isEmpty();
	string Peek();
	string Pop();
	~Stack();
private:
	Node* StackPointer;
//	Node* previous;
};

// full method definitions for class Stack into the file named Stack.cpp

Stack::Stack()     //every class should ahve 
{
	// StackPointer = previous = NULL;
	StackPointer = NULL;
}

void Stack::Push(string A)
{
	if (StackPointer == NULL)
	{  // create first Node on the Stack
		StackPointer = new Node(A);
	}
	else
	{
	Node* nodePtr = new Node(A); // create all successive nodes
	nodePtr->putNextPtr (StackPointer); // tie new node into the stack
	StackPointer = nodePtr;
	}
}

string Stack::Peek()
{	string myData = "";
	if (StackPointer != NULL)
		myData = StackPointer->getData();
	return myData;
}

string Stack::Pop()
{	string myData = "";
	if (StackPointer != NULL)
	{
		Node* nodePtr = StackPointer;
		StackPointer = StackPointer->getNextPtr();
		myData = nodePtr->getData();
		delete nodePtr;
		nodePtr = NULL;
	}
	return myData;
}

bool Stack::isEmpty(){
	
	bool flag = false;
	if (StackPointer == NULL)
	{
		flag = true;
	}
	return flag;

}
Stack::~Stack ()
{	Node* nodePtr = StackPointer;
	int ct = 0;
	if (nodePtr != NULL)
		while (nodePtr)
		{	Node* temp = nodePtr;
			nodePtr = nodePtr->getNextPtr();
			delete temp;
			ct++;
		}
	cout << "Number of Stack entries deleted is " << ct << endl;

}


//main goes to a file named StackApp.cpp
int main()
{
	char Option;
	string userData;
	Stack myStack;
	cout << "Welcome to the Stack program." << endl;
	int i = 0;
	while (!cin.eof())
	{		cout << "Press 1 to Push, 2 to Pop, 3 to Peek, ^z to end" << endl;
		cout << "Option: ";
		cin >> Option;
		if (!cin.eof()&& cin.good()) {
		switch (Option)
		{
		case '1':
			cout << "Enter Your Data: ";
			cin >> userData;
			if (cin.eof())
			{
				exit(1);
			}
			myStack.Push(userData);
			cout << "User's Data " << userData << " is Pushed onto the stack!" << endl;
			i++;
			break;
		case '2':
		if (!myStack.isEmpty()){
			userData = myStack.Pop();
			/*if (userData == "")
			{
				cout << "Stack Is Empty!" << endl;
			}*/
			cout << "Popped Element is: " << userData << endl;
			}

		else{
			cout<<"Stack Is Empty"<<endl;
			}	
			break;
		
		case '3':
			if (!myStack.isEmpty())
			{
				userData = myStack.Peek();
				cout << "Peeked Element is: " << userData << endl;
			}

			else
			{
			cout<<"Stack Is Empty"<<endl;
			}	
			break;
		default:
			cout << "Invalid Selection. Try Again..." << endl;
			break;
		}
	  }
	}
cout << "\n\n***Thank You For Using My Stack Program***\n\n";
return 0;
}