//homework 5 Binary tree from Wenbo Su
//Did not delete all other commented code since showing how to debug
//Please let me know if you can not compile this. 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

//const int NUM = 25;

class Node
{
	public:
		Node () { lh = rh = NULL; val = ""; }  // Node () {}
		void   putVal (string v) { val = v; }
		string getVal ()		 { return val; }
		void   putLH (Node* x)   { lh = x; }
		Node*  getLH ()			 { return lh; }
		void   putRH (Node* x)   { rh = x; }
		Node*  getRH ()			 { return rh; }
	private:
		string val; // current value in collating sequence
		Node* lh; // pointer to left-hand descendant Node
		Node* rh; // pointer to right-hand descendant Node	
};


class BT
{
public:
	BT(){};
//	string* getInput();		//for non-static input
	string* sortInput(string*);
//	void FindMiddle(int, int, int, int, int);

	Node* sortedArrayToTree(string* , int, int);	
	void treePrint(Node*, int);

private:
//	Node* root;
//	Node* tree;
//	string nameArray[NUM];
	Node* addNode(string);
};

//BT::BT () { root = tree = NULL; }    // BT::BT () {}

/*
string* BT::getInput(){		
	cout<<"Please input 13 names into array:"<<endl;
	string* v;
	for (int i = 0; i < 13; ++i)
	{
		cin>>nameArray[i];
		//cout<<endl;
		//cout<<nameArray[i];
	}
	return nameArray;
}
*/

string* BT::sortInput(string* v){	//sorted the input array
	string temp;
	for (int i = 0; i < 13; ++i)
	{
		for (int j = 0; j < 13-i; ++j)
		{
			if (v[j] > v[j+1])
			{
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
	
	cout<<"PrintOut Sorted Array:"<<endl;
	
	for (int i = 0; i < 13; ++i)
	{
		cout<<v[i]<<endl;
	}
	
	cout<<endl;
	return v;
}

Node* BT::addNode(string v) 
	{ 	Node* x;
		if (x = new Node())
		 {x->putVal (v);
		  x->putLH(NULL);
		  x->putRH(NULL);} 
	  //cout<<"x: "<<(size_t)x<<endl;
	  return x; }



Node* BT::sortedArrayToTree(string* arr, int x, int y)	//put sorted array into Binary tree
{
	if(x > y)		//x is start index and y is end index and arr is input sorted array
		return NULL;
	int mid = (x+y)/2;	//find the balanced number

	Node* tree = addNode(arr[mid]);		//add new node
	cout<<"arr["<<mid<<"]"<<arr[mid]<<endl;
	cout<<"tree1: "<<(size_t)tree<<endl;
	tree->putLH(sortedArrayToTree(arr,x,mid-1));	//recursion for adding to left
	cout<<"test"<<endl;
	tree->putRH(sortedArrayToTree(arr,mid+1,y));	//recursion for adding to right
	cout<<"tree2: "<<(size_t)tree<<endl;
	return tree;
}


void BT::treePrint(Node* ref, int depth) {	//print out tree based on Prosessor's code
  // from Main & Savitch page 506
  cout << setw(4*depth) << ""; // indentation
  if (ref == NULL) {
    // reached a NULL reference in an interior node
    cout << "[NULL]" << endl;
  } else if (ref->getLH() == NULL && ref->getRH() == NULL) {
    // a leaf
    cout << "Value " << ref->getVal() << " at Ref " << (size_t) ref;
    cout << " [leaf]" << endl;
  } else {
    // a nonleaf - interior node
    cout << "Value " << ref->getVal() << " at Ref " << (size_t) ref << endl;
	cout << "LH" << depth+1;
    treePrint(ref->getLH(), depth + 1);
	cout << "RH" << depth+1;
    treePrint(ref->getRH(), depth + 1);
  }
}


/*
void BT::FindMiddle(Node* A, int x, int y, int level, int nr, int round)
{ int mid;
	//Node* A;
  if (abs(x-y)<2)
     { if (x==1) 
          cout << level << " " << setw(2) <<"x "<<nameArray[x] << endl;

       if (y==nr) 
          cout << level << " " << setw(2) <<"y "<<nameArray[y] << endl;
       return;
     }
  if ((y+x)%2)
     { mid=(x+y+round)/2;
       cout << level << " " << setw(2) <<"1 mid "<<nameArray[mid] << endl;
     }
 else
     { mid = (x+y)/2;
       cout << level << " " << setw(2) <<"2 mid "<<nameArray[mid] << endl;
     }

  FindMiddle(x,mid,(level+1),nr,-1); // round down left
  
  FindMiddle(mid,y,(level+1),nr,1);  // round up right

  return;
}
*/

int main()
{ 
	string* temp1;
	Node* temp2;
	BT A;
	string array[] = {"William", "Ben", "Edward", "Kevin", "Greer", "Tim", "Nate", "John", "Raziel", "Rongjuan", "Ofer", "Steve", "Ian"};
	//A.getInput();
	temp1 = A.sortInput(array);	

    //A.FindMiddle(1,13,(level+1),13,1);
	
	temp2 = A.sortedArrayToTree(temp1,0,12);
	A.treePrint(temp2,0);
	cout<<endl;
	

  	return 0;
}



 