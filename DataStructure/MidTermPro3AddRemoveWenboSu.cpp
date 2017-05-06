//Midterm homework 3 from Wenbo Su
//Adding person and list but stuck at line #55.

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

// #include "Node.h"
class Node {  // Definition of a Node on the Queue
	public: 
		Node (){};						// default constructor
		Node* Admit (Node*, string);     // add a Node to the end of the Queue
		Node* Serve (Node*);  // remove a Node from the front of the Queue
        string Peek ();          // get user from front node in Queue
		Node* getNextPointer ();  // get pointer to next Entrant back in Queue
//		string getNodeData ();	  // return user data from current Entrant
		Node* Remove(int);
		Node* getPriorPointer ();
		void putNextPointer(Node*);
		void putPriorPointer(Node*);
		int getpersonNum();
	private: 
		string item;    // user data 
           // following are the two pointers
		Node* prior; // the one ahead of you in the line
		Node* next;  // the one behind you in the line
		int personNum;	//person's number to each who enters the Queue
		Node* record;
};
/*Node::Node(){
	record = NULL;
}*/
// #include "Node.cpp"
Node* Node::Admit (Node* endPtr, string a)
	{Node* temp = NULL;
	 if (temp = new Node)
		{temp->item = a;
		 temp->next = NULL;
		 static int a = 1;
		 temp->personNum = a;	//assign person's number to Node
	 	 cout<<"personNum for temp: "<<temp->personNum<<endl;
		 a++;
		 temp->prior = endPtr;
		 if ( endPtr != NULL)
			{ endPtr->next = temp;
			}
		cout<<"temp="<<temp<<endl;
		}
	 else
		cout << "Dynamic memory exhausted" << endl;
	 
	 if (temp->personNum == 1)
	 {
	 	record = temp;		//Here is the issue, I am not able to store record value.
	 	cout<<"555555"<<endl;
	 }
	 cout<<"record="<<record<<endl;
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
	{
		return item;
		 }
Node* Node::getNextPointer () 
	{ return next; }
Node* Node::getPriorPointer ()
	{ return prior;}
void Node::putNextPointer (Node* x)
	{ this->next = x;}
void Node::putPriorPointer (Node* x)
	{ this->prior = x;}
int Node::getpersonNum(){
	return personNum;
}
//string Node::getNodeData ()
//	{return item;} 

Node* Node::Remove(int Num){
	Node* temp;
	cout<<"44444"<<endl;
	cout<<"record2="<<record<<endl;
	for ( temp = record;temp!=NULL && temp->personNum!=Num;temp=temp->next);
	cout<<"33333"<<endl;
	if (temp == NULL)
	{
		cout<<"system's memory is exhausted."<<endl;
		exit(1);
	}
	cout<<"temp's address:"<<(size_t)temp<<endl;
	//delete temp;
	return temp;
}
// #include "Queue.h"
class Queue 
{
public:
	Queue ();
	bool admitEntrant (string);
	void serveSeniorEntrant ();
	string peekSeniorEntrant ();
	void dumpQueueFromFront ();
	void RemoveJumpOut(int);
	void getList();
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
	  cout<<"end="<<end<<endl;
	  cout<<"front"<<front<<endl;
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
			{front = A.Serve (front);	//put front's next to front
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
void Queue::RemoveJumpOut(int Num){
	Node* delPtr;
	Node* temp = NULL;
	Node A;
	cout<<"111111"<<endl;
	delPtr = A.Remove(Num);
	cout<<"22222"<<endl;
	if (delPtr != NULL)
	{
		if (end == delPtr)
		{
			end = end->getPriorPointer();
		}
		else
		{
			temp = delPtr->getNextPointer();
			temp->putPriorPointer(delPtr->getPriorPointer());
		}
		if (front == delPtr)
		{
			front = front->getNextPointer();
		}
		else
		{
			temp = delPtr->getPriorPointer();
			temp->putNextPointer(delPtr->getNextPointer());
		}
	}
}
void Queue::getList(){
	Node*temp;
	for (temp = front; temp!= NULL;temp = temp->getNextPointer())
	{
		cout<<"User's number: "<<temp->getpersonNum()<<endl;
	}
}
int main () {
Queue Q;
char resp = ' '; 
string cval;
int num;
cout << "Actions: Admit, Serve, Peek, Report,Remove(D or d),list"
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
	   case 'D': case 'd':{
	   	 //int num;
	   	 cout<< "Please enter the number of the person that wants to jump out the line:";
	   	 cin>> num;
	   	 //if (!cin.eof()&&cin.good())
	   	 Q.RemoveJumpOut(num);
	   	 cout<<"You enter number is: "<<num<<endl;
	   	 cout<<"Delete is successful."<<endl;
	   	 break;
	   	}
	   	case 'L': case 'l': {
	   		Q.getList();
	   		cout<<endl;
	   		break;
	   	} 
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