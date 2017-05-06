#include <iostream>
using namespace std;
#include <list>
int main ( ) { 
std::list<double> doubleList;
doubleList = (std::list<double>)NULL;
std::list<double>::iterator Lptr;
double num;
while ( cout << "Enter a number: ", cin >> num, 
               !cin.eof( ) && cin.good ( ))  
			doubleList.push_back (num);
            cout << "List contains ";
	if ( !doubleList.empty( )) {
		for (Lptr = doubleList.begin( ); 
			Lptr != doubleList.end( ); ++Lptr)
				cout << *Lptr << " ";
	cout << endl;
	doubleList.erase (doubleList.begin( ), doubleList.end( ) );
	if ( doubleList.empty ( ))
		cout << "List is now empty" << endl; 
	}
return 0;
}
