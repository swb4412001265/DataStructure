// Author: John Maslanka
// Program bintree3B2.cpp -- create a binary tree
// Date:   23-Jul-2002
// Installation: Home PC with MicroSoft Visual C++ V6.0

//Final question 3 from Wenbo Su

#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <string>
using namespace std;

class Node {
	private: 
		string val; // current value in collating sequence
		Node* lh; // pointer to left-hand descendant Node
		Node* rh; // pointer to right-hand descendant Node

	public: 
		Node () { lh = rh = NULL; val = ""; }  // Node () {}
		void   putVal (string v) { val = v; }
		string getVal ()	    { return val; }
		void   putLH (Node* x)   { lh = x; }
		Node*  getLH ()	    { return lh; }
		void   putRH (Node* x)   { rh = x; }
		Node*  getRH ()	    { return rh; }
		void	write (Node*);
};
		 
void Node::write (Node* n) { // Diagnostic to display a node of a Binary Tree
	cout << "Value " << val << " in Node at " << (size_t)n;
	cout << "\t Its LH child "  << (size_t)(lh) << "\t Its RH child " 
				  << (size_t)(rh) << endl;
		}

class BT {  // Container class - does most of the work
private:
	Node* root;
	Node* tree;
	Node* subtree;		//(1)add 

private:
	Node* addNode (Node*, string); //
	Node* findInsertion (Node*, string); //
	void inOrder (Node*); //
    	void locate (Node*, string); //
	void treePrint(Node*, int); //
public:
	BT ();
	Node* getRefToRoot();
	void addRootNode (string);
	void inOrderTraverse ();
    void locateRoot (string);
	//void treePrintWrapper();
	Node* getSubtree(){		//(2)
		return subtree;		//(3)
	}
	int findSubtree(Node* );	//(4)
};

Node* BT::getRefToRoot() 
	{return root;}

BT::BT () { root = tree = NULL; }    // BT::BT () {}

void BT::addRootNode (string v)
	{ if (root == NULL)
		{root = tree = addNode (tree, v);
	 //	 cout << "ptr to root " << root << endl;
        }
	  else
		{ tree = root;
		  tree = findInsertion (tree, v);
		} }

Node* BT::findInsertion (Node* tree, string v)
{ string x;
  x = tree -> getVal();
  if ( x == v) 
  {
	cout << "Duplicate user values not allowed in this tree" << endl;
	return tree;
  } else {
	if ( v < x ) 
		if( tree -> getLH () !=NULL )
			{ tree = findInsertion (tree -> getLH(), v);
			   return tree; 
			}
		  else
			{ Node* temp = NULL;
			  temp = addNode (temp, v);
			  tree ->putLH(temp); }
	  else // if ( v > x )
		  if (tree -> getRH () !=NULL )
		    { tree = findInsertion (tree -> getRH(), v);
			   return tree;	
			}
		  else
			{ Node* temp = NULL;
			  temp = addNode (temp, v);
			  tree ->putRH(temp); }
	  }
	  return tree; 
}
Node* BT::addNode (Node* x, string v)
	{ if (x = new Node())
		{ x->putVal (v);
		  x->putLH(NULL);
		  x->putRH(NULL); }
	  return x; }
void BT::locateRoot (string v) {
    if ( root == NULL )
       cout << "Tree is empty" << endl;
    else
       locate ( root, v );
    }
void BT::locate (Node* y, string v) {  // Bug mentioned by Dan Glade
    string x;
    x = y -> getVal ();
    if ( v == x )
	{ cout << "Value " << v << " is in Node at address " << (size_t)y << endl;	
	 	subtree = y;	 }//(5)
    else if ( v <= x )
        if ( y -> getLH() != NULL )
            locate (y-> getLH(), v);
        else
            cout << "Value not in tree" << endl;
    else // if ( v > x )
        if ( y -> getRH() != NULL )
            locate ( y-> getRH(), v );
        else
            cout << "Value not in tree" << endl;
    }

int BT::findSubtree(Node * y){    //(6)
    int sum;
    if(y->getRH() == NULL && y->getLH()==NULL)
    sum = 1;
   // else if (y->getLH()=NULL)
    sum+=findSubtree(y->getLH());

    sum+=findSubtree(y->getRH());   												
   
    return sum;
}

void BT::inOrderTraverse ()
	{ //tree = root;
	  cout << endl;
	  inOrder (root); }
void BT::inOrder (Node* n)
	{ if (n != NULL) {
	  inOrder (n->getLH());
	  n->write (n);
	  // cout << endl;
	  inOrder (n->getRH());
	}
	return;
}

void BT::treePrint(Node* ref, int depth) {
  // from Main & Savitch page 506
  cout << setw(4*depth) << ""; // indentation
  if (ref == NULL) {
    // reached a NULL reference in an interior node
    cout << "[NULL]" << endl;
  } else if (ref->getLH() == NULL && ref->getRH() == NULL) {
    // a leaf
    cout << "Value " << ref->getVal() << " at Ref " << (size_t) root;
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


int main () {
string x;
char op = ' ';
BT TREE;
cout << "To create your Binary tree, use the menu below." << endl << endl;
while (!cin.eof() && op != 'E' && op != 'e')  // build a binary tree in this while loop
{cout << "Enter your operation using the Capital letter in your selection." << endl; 
   cout << "(A)dd a node, display (T)ree, (S)how lists, display a (N)ode, (C)ount subtree, (E)xit: ";
   //(7)add Count subtree option
   cin >> op;
   if (!cin.eof () && op != 'E' && op != 'e')
	switch (op)
	{case 'A': case 'a':
		{ cout << "Enter your string: ";
		  cin >> x;
		  if (!cin.eof())
			 TREE.addRootNode (x);
		  break;
		}
	case 'S': case 's':
		{if ( TREE.getRefToRoot ())
			{ cout << endl << "In-OrderTree Traversal:";
			  TREE.inOrderTraverse ();
		      cout << endl;
			}
		break;
		}
	case 'T': case 't':
		{if (TREE.getRefToRoot ())
			{ cout << endl << "Display Tree:" << endl;
			  //TREE.treePrintWrapper ();
		      cout << endl;
			}
		break;
		}
	case 'N': case 'n':
        	{ cout << endl << "Enter User value of Node to Display: ";
          	  cin >> x;
          	  if (!cin.eof())
			  if (TREE.getRefToRoot ())
					TREE.locateRoot ( x );
			  else
					cout << endl << "Tree is empty. No entries found.";
		  			cout << endl;
		  break;
		}
	case 'C': case 'c':		//(8)add whole case option
		{
			cout << endl << "Enter User value of Node to Count subtree: ";	
          	cin >> x;
          	if (!cin.eof())
          	if (TREE.getRefToRoot ()){
				TREE.locateRoot ( x );
          		//TREE.findSubtree(TREE.getSubtree())
   				cout<<"The subtree count is "<<	TREE.findSubtree(TREE.getSubtree())<<endl;
          		}
          	else
				cout << endl << "Tree is empty. No entries found.";
		  		cout << endl;
		  break;		
		}
	case 'E': case 'e':
		{ break;
		}
	default:
		{ cout << "Invalid operation. Try again!" << endl;
		  break;
		}
	  }
	}
    return EXIT_SUCCESS;
}
