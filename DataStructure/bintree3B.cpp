// Author: John Maslanka
// Date:   23-Jul-2002
// Installation: Home PC with MicroSoft Visual C++ V6.0
//
// C++ program to illustrate Binary Tree development and
// access using a Node class to develop and query individual 
// Nodes of the tree and a BT class to develop and query the
// entire tree. Each node is created only when it is needed 
// to contain a new character value entered by the user. 
// This example uses the Data Structure technique known as 
// Aggegation.  Also, it uses a Container class.
//
// Edit 11/10/2014 from Jim Goddard - pretty print of a binary 
// tree after Main & Savitch Data Structures book p 506
//
// Edit 7/28/2016  Deleted usage of Count to control actions in
// main. Replaced with getRefToRoot method for that purpose.

#include <iostream>
#include <iomanip>  // for setw
#include <cstdlib>
#include <string>
using namespace std;

class Node {
	private: 
		string val; // current value in collating sequence
		Node* lh; // pointer to left-hand descendant Node
		Node* rh; // pointer to right-hand descendant Node
		// Node* parent;
	public: 
		Node () { lh = rh = NULL; val = ""; }  // Node () {}
		void   putVal (string v) { val = v; }
		string getVal ()		 { return val; }
		void   putLH (Node* x)   { lh = x; }
		Node*  getLH ()			 { return lh; }
		void   putRH (Node* x)   { rh = x; }
		Node*  getRH ()			 { return rh; }
		//void setParent(Node*);
		//Node* getParent();
		void   write (Node* n);
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
private:
	Node* addNode (Node*, string); //
	Node* findInsertion (Node*, string); //
	void inOrder (Node*); //
	void preOrder (Node*); //
	void postOrder (Node*); //
    void locate (Node*, string); //
	void treePrint(Node*, int); //
public:
	BT ();
	Node* getRefToRoot();
	void addRootNode (string);
	void inOrderTraverse ();
	void preOrderTraverse ();
	void postOrderTraverse ();
    void locateRoot (string);
	void treePrintWrapper();
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
  }
  else
		{
		if ( v < x )  
			if( tree -> getLH () !=NULL )
			{ tree = findInsertion (tree -> getLH(), v);
			   return tree;		// *** from Paul Pollack 11/13/13 ***new addition to prevent 
								// a new node from being added twice
			}
		  else
			{ Node* temp = NULL;
			  temp = addNode (temp, v);
			  tree ->putLH(temp); }
	  else // if ( v > x )
		  if (tree -> getRH () !=NULL )
		    { tree = findInsertion (tree -> getRH(), v);
			   return tree;		// *** from Paul Pollack 11/13/13 ***new addition to prevent 
								// a new node from being added twice
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
		  // cout << "Its LH reference is "  << (int)(y -> getLH()) << endl << "Its RH reference is " << (int)(y -> getRH()) << endl;
		}
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
void BT::preOrderTraverse ()
	{ //tree = root;
	  cout << endl;
	  preOrder (root); }
void BT::preOrder (Node* n)
	{ if (n == NULL) return;
	  n->write (n);
	  // cout << endl;
	  preOrder (n->getLH());
	  preOrder (n->getRH()); }
void BT::postOrderTraverse ()
	{ //tree = root;
	  cout << endl;
	  postOrder (root); }
void BT::postOrder (Node* n)
	{ if (n != NULL) //return;
		{ postOrder (n->getLH());
		  postOrder (n->getRH());
		  n->write (n);
		//  cout << endl;
		}
	}
void BT::treePrintWrapper() {
	cout << "Root ";
  treePrint(root, 0);
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
//Node* test;
// Create inorder Binary treee
cout << "To create your Binary tree, use the menu below." << endl << endl;
while (!cin.eof() && op != 'E' && op != 'e')  // build a binary tree in this while loop
{//cout << "Enter your operation:  Add a node, Show lists, Display a node, Exit: ";
   cout << "Enter your operation using the capital letter shown in your selection." << endl; 
   cout << "Add a node, display Tree, Show lists, Display a node, Exit: ";
   cin >> op;
   if (!cin.eof () && op != 'E' && op != 'e')
	switch (op)
	{
	case 'A': case 'a':
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
		     // cout << "Pre-Order Tree Traversal:";
		     // TREE.preOrderTraverse();
		     // cout << endl;
		     // cout << "Post-Order Tree Traversal:";
		     // TREE.postOrderTraverse();
			 // cout << endl;
			}
		break;
		}
	case 'T': case 't':
		{if (TREE.getRefToRoot ())
			{ cout << endl << "Display Tree:" << endl;
			  TREE.treePrintWrapper ();
		      cout << endl;
			}
		break;
		}
	case 'D': case 'd':
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
	case 'E': case 'e':
		{ break;
		}
	default:
		{ cout << "Invalid operation. Try again!" << endl;
		  break;
		}
	  }
	}
//    system("PAUSE");
    return EXIT_SUCCESS;
}