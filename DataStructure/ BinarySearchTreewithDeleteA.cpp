// Author: John Maslanka
// Date:   23-Jul-2002/ 30-Apr-2014
// Installation: Home PC with MicroSoft Visual C++ V10.0
//
// C++ program to illustrate Binary Tree development and
// access using a Node class to develop and query individual 
// Nodes of the tree and a BST class to develop and query the
// entire tree. Each node is created only when it is needed 
// to contain a new character value entered by the user. 
// This example uses the Data Structure technique known as 
// Aggegation.  Also, it uses a Container class for the
// Binary Search Tree.
// 
// Edit 10/27/2013   Code for AVL tree balancing. Original
// code from Jeremy Wright.
//
// Edit 11/10/2014   Code to display a binary tree after 
// Main & Savitch p 506, from Jimmy Goddard.
//
// Edit 10/24/2015  Code to delete a node. Original from
// Colin Horowitz

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
//#include "node.h"
//#include "bintree.h"
using namespace std;

class Node {
private: 
  string val; // user input provides value in collating sequence
  Node* lh; // pointer to left-hand descendant Node
  Node* rh; // pointer to right-hand descendant Node
  Node* parent; //pointer to parent Node or NULL if root Node
public: 
	     Node () { lh = rh = parent = NULL; val = ""; }
  void   putVal (string v) { val = v; }
  string getVal () { return val; }
  void   putLH (Node* x) { lh = x; }
  Node*  getLH () { return lh; }
  void   putRH (Node* x) { rh = x; }
  Node*  getRH () { return rh; }
  void   setParent(Node* x) {parent = x;}
  Node*  getParent() {return parent;}
};

class BST { // Container for Binary Search Tree
private:
  Node* root;
  Node* tree;
private:
  Node* addNode (Node*, string);
  Node* findInsertion (Node* tree, string v);
  void inOrder (Node*);
  void preOrder (Node*);
  void postOrder (Node*);
  void locate (Node*, string);
  void rotateRight (Node*);
  void rotateLeft (Node*);
  void postInsertionBalance (Node*);
  void treeDisplay(Node*, int);
  Node* findNode(string);
public:
  BST ();
  void addRootNode (string);
  void inOrderTraverse ();
  void preOrderTraverse ();
  void postOrderTraverse ();
  void locateRoot (string);
  int  balanceFactor(Node*);
  int  subTreeHeight(Node*);
  void treeDisplayRoot();
  void deleteNode(string);
  Node* getRefToRoot();
};

BST::BST () { // Default Constructor
	root = tree = NULL; 
} 
Node* BST::getRefToRoot()
	{return root;}
void BST::addRootNode (string v)
{ if (root == NULL)
    {
	  root = tree = addNode (tree, v);
    }
  else
    { tree = root;
      tree = findInsertion (tree, v);
    }
}

Node* BST::findInsertion (Node* tree, string v)
{ string x;
  x = tree -> getVal();
  //cout << count << " compare " << v << " and " << x << endl;
  if ( v < x ) //look to left of cureent node
    if( tree -> getLH () !=NULL )
      { tree = findInsertion (tree -> getLH(), v);
	return tree;		// *** from Paul Pollack 11/13/13 *** prevent 
						// a new node from being added twice
      }
    else
      { Node* temp = NULL;
		temp = addNode (temp, v);
		tree ->putLH(temp);
		temp ->setParent(tree); //added functionality for parents
		postInsertionBalance(temp); //balance the tree
      }
  else if ( v > x )  // look to right of current node
    if (tree -> getRH () !=NULL )
      { tree = findInsertion (tree -> getRH(), v);
		return tree;  // from Paul Pollack 11/13/13 same as above 
      }
    else
      { Node* temp = NULL;
		temp = addNode (temp, v);
		tree ->putRH(temp);
		temp ->setParent(tree);  //added functionality for parents
		postInsertionBalance(temp); //balance the tree
      }
  else
	  cout << "Node " << x << " found -- already in Binary Tree." << endl;
  return tree;
}
Node* BST::addNode (Node* x, string v)
{ if (x = new Node)
    { x->putVal (v);
      x->putLH(NULL);
      x->putRH(NULL); 
      x->setParent(NULL);
    }
  return x;
}
void BST::locateRoot (string v) {
  if ( root == NULL )
    cout << "Tree is empty" << endl;
  else
    locate ( root, v );
}
void BST::locate (Node* y, string v) {  // Bug mentioned by Dan Glade
  string x;
  x = y -> getVal ();
  if ( v == x )
    { cout << "Value " << v << " is in Node at reference " << (int)y << endl;
	  cout << " Left Child ref " << (int)y->getLH() << "    Right Child ref " << (int)y->getRH();
	  cout << "    Parent ref " << (int)y->getParent() << endl;
    }
  else if ( v < x )
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



void BST::inOrderTraverse ()
{ cout << endl;
  inOrder (root); 
}
void BST::inOrder (Node* n)
{ if (n != NULL) {
    inOrder (n->getLH());
    cout << n->getVal() << endl;
    inOrder (n->getRH());
  }
  return;
}
void BST::preOrderTraverse ()
{ cout << endl;
  preOrder (root); 
}
void BST::preOrder (Node* n)
{ if (n == NULL) return;
  cout << n->getVal() << endl;
  preOrder (n->getLH());
  preOrder (n->getRH()); 
}
void BST::postOrderTraverse ()
{ cout << endl;
  postOrder (root); 
}
void BST::postOrder (Node* n)
{ if (n != NULL) //return;
    { postOrder (n->getLH());
      postOrder (n->getRH());
      cout << n->getVal() << endl;
    }
}
void BST::treeDisplayRoot() {
  treeDisplay(root, 0);
}

void BST::treeDisplay(Node* ref, int depth) {
  // from Main & Savitch page 506
  cout << setw(4*depth) << ""; // indentation
  if (ref == NULL) {
    // reached a NULL reference in an interior node
    cout << "[NULL]" << endl;
  } else if (ref->getLH() == NULL && ref->getRH() == NULL) {
    // a leaf
    cout << "Value " << ref->getVal() << " at Ref " << (int) ref;
    cout << " [leaf]" << endl;
  } else {
    // a nonleaf - interior node
	if ( depth == 0 )
		cout << "            Root ";
    cout << "Value " << ref->getVal() << " at Ref " << (int) ref << endl;
	cout << "Left Child  " << depth+1;
    treeDisplay(ref->getLH(), depth + 1);
	cout << "Right Child " << depth+1;
    treeDisplay(ref->getRH(), depth + 1);
  }
}
// This BST procedure uses rotations to do AVL-balance whenever a Node is added.  
// In order to do this in all levels of the tree, it calculates a balance 
// factor, and uses this to determine when to rotate Nodes of the tree.  The 
// rotations are made so as to preserve the navigation of the tree. 
// The AVL balancing technique allows us to circumvent the problem of balancing 
// the input (more about this later in the course), when we can rebalance the 
// tree after each node is added. However, the AVL technique consumes much 
// overhead. For ease of programming, nodes now keep track of their parents to 
// facilitate the rotating procedure. 
// Note that the AVL technique does not handle the problem of deleting a Node
// from a BST.

int BST::balanceFactor(Node* n)  //Added by Jeremy Wright
{
  return subTreeHeight(n->getLH()) - subTreeHeight(n->getRH());
}

int BST::subTreeHeight(Node* n) //tells the height of the larger subtree under this node.
{
  int subHeightL;
  int subHeightR;
  if(n == NULL)
    {
      return -1;
    }
  if(n->getLH() == NULL)
    {
      if(n->getRH() == NULL)
		{
		  return 0;
		}
      else
		{
		  subHeightR = subTreeHeight(n->getRH())+1;
		  return subHeightR;
		}
    }
  else if(n->getRH() == NULL)
    {
      subHeightL = subTreeHeight(n->getLH())+1;
      return subHeightL;
    }
  else
    {
      subHeightL = subTreeHeight(n->getLH()) + 1;
      subHeightR = subTreeHeight(n->getRH()) + 1;
      if(subHeightL > subHeightR)
		{
		  return subHeightL;
		}
      else
		{
		  return subHeightR;
		}
    }
}
void BST::rotateRight(Node* subRoot)  //rotates a tree right, with subRoot as 
	                              // its original root and pivot as the new root
{ cout << "Begin rotateRight" << endl;
  Node* pivot = subRoot->getLH();   //new root of this subtree is the left child
  Node* parentRoot = subRoot->getParent();  //store parent of subtree
  subRoot->putLH(pivot->getRH());  //the root takes the right child of the pivot 
									// to preserve BST structure
  if(subRoot->getRH() != NULL)
    {
      subRoot->getRH()->setParent(subRoot);  //make sure child knows its parent
    }
  pivot->putRH(subRoot); //the root becomes the right child of the pivot
  subRoot->setParent(pivot);
  cout << "Continue rotateRight" << endl;
  if(subRoot == root)
    {
      root = pivot;
      pivot->setParent(NULL);
    }
  else  //connect subtree to its parent
    {
      if(parentRoot->getLH() == subRoot)
		{
		  parentRoot->putLH(pivot); 
		  pivot->setParent(parentRoot);
		}
      else
		{
		  parentRoot->putRH(pivot);
		  pivot->setParent(parentRoot);
		}
    }
  cout << "End of rotateRight" << endl;
}
void BST::rotateLeft(Node* subRoot) //Rotates tree left as Rotate_Right
{
  //  cout << "ROTATING LEFT" << endl;
  Node* pivot = subRoot->getRH();   
  Node* parentRoot = subRoot->getParent();
  subRoot->putRH(pivot->getLH());
  if(subRoot->getRH() != NULL)
    {
      subRoot->getRH()->setParent(subRoot);
    }
  pivot->putLH(subRoot);
  subRoot->setParent(pivot);
  if(subRoot == root) // Need to test if entire tree is balanced!!!
    {
      root = pivot;
      pivot->setParent(NULL);
    }
  else
    {
      if(parentRoot->getLH() == subRoot)
		{
		  parentRoot->putLH(pivot);
		  pivot->setParent(parentRoot);
		}
      else
		{
		  parentRoot->putRH(pivot);
		  pivot->setParent(parentRoot);
		}
    } 
}
void BST::postInsertionBalance (Node* n)  //Run after every insertion to 
	// balance the tree.  Any imbalances can be dealt with by looking at 
	// the parent line to root of the new Node as mentioned above.
{ Node* p;
  if(balanceFactor(n) == 2)
    {
      p = n->getLH();
      if(balanceFactor(p) == -1)
		{
		  rotateLeft(p);
		}
      rotateRight(n);
    }
  else if(balanceFactor(n) == -2)
    {
      p = n->getRH();
      if(balanceFactor(p) == 1)
		{
		  rotateRight(p);
		}
      rotateLeft(n);
    }
  if(n != root) //run until we travel up to root
    {
      postInsertionBalance(n->getParent());
    }
}
void BST::deleteNode(string deleteThis)
{
	//First find the node to delete
	Node* nodeToDelete = findNode(deleteThis);
	
	if (nodeToDelete && nodeToDelete->getParent() )
	{	//If it exists and is not the root, delete it 
		//4 possibilities with left having children or not and right having children or not
		if ( nodeToDelete->getLH() == NULL && nodeToDelete->getRH() == NULL )
		{
			//Now have to find if node is left or right child of its parent
			if(nodeToDelete->getParent()->getLH() == nodeToDelete )
			{	//If the parent's left child node is delete node, change that
				nodeToDelete->getParent()->putLH(NULL);
				delete nodeToDelete;
			}
			else {
				//Otherwise it was the right child
				nodeToDelete->getParent()->putRH(NULL);
				delete nodeToDelete;
			}
		}	//End case 1 - leaf node
		//Cases 2/3 are similar - only 1 child
		else if ( nodeToDelete->getLH() != NULL && nodeToDelete->getRH() == NULL )
		{
			//Now have to find if node is left or right child of its parent
			if(nodeToDelete->getParent()->getLH() == nodeToDelete )
			{	//If the parent's left child node is delete node, change that to the sole child node
				nodeToDelete->getParent()->putLH( nodeToDelete->getLH() );
				
				//Change the former child node's parent to deleted node's parent as well
				nodeToDelete->getLH()->setParent( nodeToDelete->getParent() );
				delete nodeToDelete;
			}
			else {
				//Otherwise it was the right child that will be the sole child node
				nodeToDelete->getParent()->putRH( nodeToDelete->getLH() );
				
				//Change the former child node's parent to deleted node's parent as well
				nodeToDelete->getLH()->setParent( nodeToDelete->getParent() );
				delete nodeToDelete;
			}
		}	//End case 2, only left child
		
		else if ( nodeToDelete->getLH() == NULL && nodeToDelete->getRH() != NULL )
		{
			//Now have to find if node is left or right child of its parent
			if(nodeToDelete->getParent()->getLH() == nodeToDelete )
			{	//If the parent's left child node is delete node, change that to the sole child node
				nodeToDelete->getParent()->putLH( nodeToDelete->getRH() );
				
				//Change the former child node's parent to deleted node's parent as well
				nodeToDelete->getRH()->setParent( nodeToDelete->getParent() );
				delete nodeToDelete;
			}
			else {
				//Otherwise it was the right child that will be the sole child node
				nodeToDelete->getParent()->putRH( nodeToDelete->getRH() );
				
				//Change the former child node's parent to deleted node's parent as well
				nodeToDelete->getRH()->setParent( nodeToDelete->getParent() );
				delete nodeToDelete;
			}
		}	//End case 3, only right child
		//Case 4 hardest - have to move right child tree to bottom right of left child tree
		else {
			//Else is if both right and left children exist - the framework is similar to if only the left
			//child tree existed, but more steps have to be taken with the right child tree
			
			//Now have to find if node is left or right child of its parent
			if(nodeToDelete->getParent()->getLH() == nodeToDelete )
			{	//If the parent's left child node is delete node, change that to the sole child node
				nodeToDelete->getParent()->putLH( nodeToDelete->getLH() );
				
				//Change the former child node's parent to deleted node's parent as well
				nodeToDelete->getLH()->setParent( nodeToDelete->getParent() );
				
				//Now find bottom right side of the left child tree
				Node* index = nodeToDelete->getLH();
				while(index->getRH() != NULL)
				{
					index = index->getRH();
				}
				//Now at bottom right of left child tree
				index->putRH( nodeToDelete->getRH() );
				nodeToDelete->getRH()->setParent( index );
					
				
				delete nodeToDelete;
			}
			else {
				//Otherwise it was the right child that will be the sole child node
				nodeToDelete->getParent()->putRH( nodeToDelete->getLH() );
				
				//Change the former child node's parent to deleted node's parent as well
				nodeToDelete->getLH()->setParent( nodeToDelete->getParent() );
				
				//Now find bottom right side of the left child tree
				Node* index = nodeToDelete->getLH();
				while(index->getRH() != NULL)
				{
					index = index->getRH();
				}
				//Now at bottom right of left child tree
				index->putRH( nodeToDelete->getRH() );
				nodeToDelete->getRH()->setParent( index );
				
				delete nodeToDelete;
			}
		}	//End case 4, 2 children
	}	//End if node for deletion was found and was not the root
	
	else if (nodeToDelete)
	{	//If node is root node, it will have been found, but not have parent
		//Code is very similar to previous case, except now parent changes are root node changes
		// 4 possibilities with left having children or not and right having children or not
		// or both having children
		if ( nodeToDelete->getLH() == NULL && nodeToDelete->getRH() == NULL )
		{ //
			root = NULL;		//Tree has been fully deleted here
			delete nodeToDelete;
		
		}	//End case 1 - leaf node
		//Cases 2/3 are similar - only 1 child
		else if ( nodeToDelete->getLH() != NULL && nodeToDelete->getRH() == NULL )
		{
			root = nodeToDelete->getLH();
			nodeToDelete->getLH()->setParent(NULL);
			delete nodeToDelete;
		}	//End case 2, only left child
		
		else if ( nodeToDelete->getLH() == NULL && nodeToDelete->getRH() != NULL )
		{
			root = nodeToDelete->getRH();
			nodeToDelete->getRH()->setParent(NULL);
			delete nodeToDelete;
		}	//End case 3, only right child
		//Case 4 hardest - have to move right child tree to bottom right of left child tree
		//  arbitrarily select the Left Child to be the Root node
		else {
			
			root = nodeToDelete->getLH();
			nodeToDelete->getLH()->setParent(NULL);
				
			//Now find bottom right side of the left child tree
			Node* index = nodeToDelete->getLH();
			while(index->getRH() != NULL)
			{
				index = index->getRH();
			}
			//Now at bottom right of left child tree
			index->putRH( nodeToDelete->getRH() );
			nodeToDelete->getRH()->setParent( index );
				
			delete nodeToDelete;
			
		}	//End case 4, root had 2 children
	}	//End if root node
	
	else {
		//Otherwise nodeToDelete could not be found
		cout << deleteThis << " Delete not successful. Node not in tree." << endl;
	}

	
	return;
}	//End deleteNode function

Node* BST::findNode(string findThis)
{
	Node* index = root;
	
	while ( (index != NULL) && (index->getVal() != findThis) )
	{	//As long as there is more tree to search, and the value hasn't been found yet
		if ( index->getVal() > findThis )
		{	//If value at index is more than the looked for value, look to left children
			index = index->getLH();
		}
		else if ( index->getVal() < findThis )
		{	//If value at index is less than looked for value, look to right children
			index = index->getRH();
		}
		//If it is the same, don't modify index
	}
	//Index now is either where the value is looked for value
	//or null, if value was not in tree, or if tree is empty
	return index;
}

int main () {
	string avalue;
	BST TREE;
/*	char yn;
	char filename [256];
	cout << " Do you wish to enter a file name and extension? (Y/N): ";
	cin >> yn;
	if (yn == 'Y' || yn == 'y') {
		cout << "Please enter filename and extension: ";
		cin >> filename;
		if (cin.eof())
			exit (1);
		fstream inFile (filename, ios::in);
		if (!inFile) {
			cout << "Could not open file. Terminating." ;
			exit (2);
		}
		while(!inFile.eof() && inFile.good()) {
			inFile >> avalue;
			if ( !inFile.eof() && inFile.good())
				{
				 TREE.addRootNode(avalue);
				}
			}
	}
	// End of procedure to read data from a sequential text file which was
	//  created using NotePad and to enter that data into a binary tree.
	*/

  string x;
  char op = ' ';
  char confirm = ' ';

  // Create Binary treee
  cout << "To create your Binary tree, use the menu below." << endl << endl;
  cout << "Enter your operation using the capital letter shown in your selection." << endl; 
  cout << "Add node, show Node, Delete node, Show sorted list, show Tree, Help, Exit: " << endl;
  while (!cin.eof() && op != 'E' && op != 'e')  // build bi Nodenary tree in this loop
    { cout << "Enter your operation: ";
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
	  case 'D': case 'd':
		{ cout << "Which value would you like to delete from the tree?\n";
		  cin >> x;
		  if ( !cin.eof() )
			{ TREE.deleteNode(x);
			}
		  break;
		}
	  case 'S': case 's':
	    {if ( TREE.getRefToRoot ())
			{ cout << endl << "In-OrderTree Traversal" << endl;
			  TREE.inOrderTraverse ();
//			  cout << "Pre-Order Tree Traversal" << endl << endl;
//			  TREE.preOrderTraverse();
//			  cout << "Post-Order Tree Traversal" << endl << endl;
//			  TREE.postOrderTraverse();
			}
		else
			cout << "Tree is empty." << endl;
	    break;
	    }
	  case 'N': case 'n':
	    { cout << endl << "Enter User value of Node to Display: ";
	      cin >> x;
	      if (!cin.eof())
			 {if ( TREE.getRefToRoot ())
				{ TREE.locateRoot ( x );
				}
			 else
				  cout << "Tree is empty." << endl;
		     }
		  cout << endl;
	      break;
	    }
	  case 'T': case 't':
		{if ( TREE.getRefToRoot ())
			{ cout << endl << "Display Tree:" << endl;
			  TREE.treeDisplayRoot ();
			}
		else
			cout << endl << "Tree is empty.";
	    cout << endl;
		break;
		}
	  case 'H': case 'h':
		{ cout << "Enter your operation using the capital letter shown in your selection." << endl; 
		  cout << "Add a node, display a Node, Show sorted list, display Tree, Help, Exit" << endl;
		  break;
		}
	  case 'E': case 'e':
	    { break;
	    }
	  default:
	    { cout << "Invalid operation. Try again!" << endl;
		  cout << "Operations are " << endl;
		  cout << "Add a node, display a Node, Show sorted list, display Tree, Help, Exit" << endl;
	      break;
	    }
	  }
    }
    system("PAUSE");
  return EXIT_SUCCESS;
}