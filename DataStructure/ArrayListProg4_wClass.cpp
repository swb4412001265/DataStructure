// John Maslanka  ArrayListProg3-withclass.cpp to parallel my Baglist Demo with class
// 10/6/2014

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#define XMAXSIZE 10

class Array {
public:
	Array() {listIdx = -1;}
	bool addElement (string);
	bool deleteElement (string);
	bool findElement (string);
	string listElements ();
private:
	string X [XMAXSIZE];
	int listIdx;
};

bool Array::addElement (string data) {
	bool ret = true;
	if (listIdx < XMAXSIZE){
		X[++listIdx] = data;
	//cout<<"listIdx:"<<listIdx<<endl;
	}
	else
		ret = false;
	return ret;
}

bool Array::findElement (string data) {
	bool found = false;
	for (int i = 0; i < listIdx+1 && found == false; i++){
		if ((X[i] == data)){
			found = true;
		}
	}
	return found;
}

bool Array::deleteElement(string data) {
	bool found = false;
	if (findElement (data)) {
		for (int i = 0; i < listIdx+1 && found == false; i++){
		  if ((X[i] == data)){
			int idxToDelete = i;
			int j = idxToDelete + 1;
			for (; j <= listIdx; j++)
				X[j-1] = X [j];
			X[listIdx--] = "";
			found = true;
		  }
		}
	}
	return found;
}

string Array::listElements (){
	string elementList = "";
	if (listIdx > -1){
		// for(int i = 0; i <= listIdx; i++)
		for ( int i = listIdx; i >= 0; i--)
			elementList += "\n " + X[i];

	}
	return elementList;
}

int main () {
	Array A;
    string udata;
	bool cont = true;
    char sel;
    while (!cin.eof() && cont == true) {
	  cout << "Enter your function: Add, Find, List, Delete, Exit or control-z: ";
	  cin >> sel;
	  if (!cin.eof()) {
	    switch (sel) {		
		  case 'A': case 'a': {
			cout << "Enter your string ";
			cin >> udata;
			if (!cin.eof()) {
				if (!A.addElement(udata))
					cout << "Element not added. Array already full" << endl;
				}
		    break;
		    }
		  case 'E': case 'e': {
			cont = false;
			break;
			}
		  case 'D': case 'd': {
			cout << "Please Enter User Data value to delete: ";
			cin >> udata;
			if (!cin.eof()) {
				if (A.deleteElement (udata)) {
					cout << "Entry " << udata << " deleted" << endl;
				}
				else
					cout << "Entry " << udata << " not found" << endl; 
				}
			break;
			}
		case 'F': case 'f': {
			cout << "Please Enter User Data value to find: ";
			cin >> udata;
			if (!cin.eof()) {
				if (A.findElement(udata))
					 cout << "Entry " << udata << " found" << endl; 
				else
					 cout << "Entry " << udata << " not found" << endl;
				  
				}
			break;
			}
		case 'L': case 'l': {
			string W = A.listElements();
			if (W != ""){
				cout << "List of Entries" << endl;  // check this placement
				cout << W << endl;
			}
			else
				cout << "List is Empty";
			cout << endl;
			break;
			}
		default: {
			cout << "Invalid function entered." << endl;
			break;
			 }
		   }
	    }
	}
	//system ("PAUSE");
	return 0;
}