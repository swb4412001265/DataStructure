// Author: John Maslanka
// Date:   26-Jan-2002; 
// A Container Queue class using a linked list of Node
// objects to illustrate FIFO (first-in-first-out)
// behavior.
// Installation: Home PC with MicroSoft Visual C++ V6.0
//
// Edit:	8-Mar-2004 removed cout << from Serve method
// Edit:	02/20/2012 change user data type from char to string, change menu 
//			to all letters.
// Edit:	02/20/2012 insert container class Queue
// Edit:	11/07/2014 from Peter Nachtygal when list becomes empty also set 
//			end pointer to NULL.

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

// #include "Node.h"
class Node {  // Definition of a Node on the Queue
	public: 
		Node (){}						// default constructor
		Node* Admit (Node*, string);     // add a Node to the end of the Queue
		Node* Serve (Node*);  // remove a Node from the front of the Queue
        string Peek ();          // get user from front node in Queue
		Node* getNextPointer ();  // get pointer to next Entrant back in Queue
//		string getNodeData ();	  // return user data from current Entrant
	private: 
		string item;    // user data 
           // following are the two pointers
		Node* prior; // the one ahead of you in the line
		Node* next;  // the one behind you in the line
		static int personNum;	
};

// #include "Node.cpp"
int Node::personNum = 1;
Node* Node::Admit (Node* endPtr, string a)
	{Node* temp = NULL;
	 if (temp = new Node)
		{temp->item = a;
		 temp->next = NULL;
		 temp->prior = endPtr;
		 if ( endPtr != NULL)
			{ endPtr->next = temp;
			}

		}
	 else
		cout << "Dynamic memory exhausted" << endl;
	 
	 //cout<<"personNum2: "<<temp->personNum<<endl;
	 return temp;
	}
Node* Node::Serve (Node* y)
	{Node* temp;
	 temp = y->next;
	 delete y;
	 if (temp != NULL)
		temp->prior = NULL;
	 return temp;
	}
string Node::Peek ()  // like Stack Peek but peek front
	{return item;}
Node* Node::getNextPointer () 
	{ return next; }
//string Node::getNodeData ()
//	{return item;} 

// #include "Queue.h"
class Queue 
{
public:
	Queue ();
	bool admitEntrant (string);
	void serveSeniorEntrant ();
	string peekSeniorEntrant ();
	void dumpQueueFromFront ();
private:
	Node* front;  // the one about to be served at the front of the line - head
	Node* end;    // the one at the end of the line - tail
	bool  peekFlag;  //check if Senior entrant is peeked befor being served
};

// #include "Queue.cpp"
Queue::Queue () 
	{ front = end = NULL;
	  peekFlag = false; }
bool Queue::admitEntrant ( string x )
	{ bool admitSuccess = false;
	  Node A;
	  end = A.Admit (end, x);
	  if (end != NULL)
		{ if (front == NULL)
			front = end;
		  admitSuccess = true;
		}
	  return admitSuccess;
	}
string Queue::peekSeniorEntrant ()
	{ peekFlag = true;
	  string returnValue = "";
	  if (front != NULL)
		{ returnValue = front-> Peek ();
		}
	  else
	    { peekFlag = false;
		  cout << "Queue is empty." << endl;
		}
	  return returnValue;
	}
void  Queue::serveSeniorEntrant ()
	{ Node A;
	  if (peekFlag == true)
		if (front != NULL)
			{front = A.Serve (front);
	         if (front == NULL)  // fix from Peter Nachtygal  11/7/2014
				{				 // If front has become NULL
				 end = NULL;	 // set end to NULL also because Queue is 
				}				 // now empty
			}
		else
		  cout << "Queue is empty." << endl;
	  else
		  if (front == NULL)
			  cout << "Queue is empty." << endl;
		  else
			  cout << "Senior Queue Member has not been Peeked." << endl;
	  peekFlag = false;
	}
void  Queue::dumpQueueFromFront ()
	{ if (front != NULL)
		{ cout << " Dumping Queue from most senior to most junior..." << endl;
		  Node* temp;
		  for (temp = front; temp != NULL; temp = temp -> getNextPointer ())
			 cout << "  " << temp -> Peek () << endl;
		}
	 else
		cout << "Queue is empty." << endl;
	}

int main () {
Queue Q;
char resp = ' '; 
string cval;
cout << "Actions: Admit, Serve, Peek, Report,"
     << " Help, Quit or ^Z" << endl;
while (!cin.eof() && resp != 'Q' && resp != 'q') {
  cout << "Enter action selection: ";
  cin >> resp;
  if (!cin.eof())
	{
     switch (resp) {
	   case 'A': case 'a': // Admit
         	cout << "Enter name to enter into Node: ";
         	cin >> cval;
			if (!cin.eof()) 
				{ if ( Q.admitEntrant (cval) )
					cout << "Added entrant " << cval << " to list." << endl;
				else
					cout << "Failed to add entrant " << cval << " to list." << endl;
				}
		 break;	
	   case 'S': case 's': // Serve
		 Q.serveSeniorEntrant ();
		 break;
	   case 'P': case 'p': // Peek
		 cout << Q.peekSeniorEntrant () << endl;
		 break;	
	   case 'R': case 'r':
		 Q.dumpQueueFromFront();
		 break;
	   case 'h': case 'H':
		 cout << "Actions: Admit, Serve, Peek, Report,"
		     << " Help, Quit or ^Z" << endl;
		 break;
	   case 'Q': case 'q':
		   break;
	   default:
		 cout << " Invalid Action. Try again." << endl;
	  }
	cin.clear();
	}
  }
  cout << "Thank you for using my Queue program." << endl;
  system("PAUSE");
  return EXIT_SUCCESS;
}