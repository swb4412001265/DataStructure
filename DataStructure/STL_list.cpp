#include <iostream>
using namespace std;
#include <list>

int main() { 
 std::list<double> doubleList;
 double num;
 while ( cout << "Enter a number: ", cin >> num, 
                       !cin.eof ( ) && cin.good ( ))  
			    doubleList.push_front (num);
 if ( !doubleList.empty ( ))
	{ std::ostream_iterator <double> output ( cout, " " );
	   std::copy ( doubleList.begin( ), doubleList.end( ), output );
	}
 cout << endl;
 return 0; 
}
