//Final question 1 from Wenbo Su

//1, 1, 2, 3, 5, 8, 13,

#include <iostream>
#include <cstdlib>
using namespace std;

class FIBO {
	public:
		FIBO () {count = 0;}
		int fibonacci (int);
    int printCount () const;   //(1)

	private:
    int count;    //(2)
};

int FIBO::fibonacci (int x) {
  	count++;   //(3)
    if ( x > 1 )
   		return (fibonacci (x - 2) + fibonacci (x - 1));
  	return 1; 
}

int FIBO::printCount() const{    //(4)
  //cout<<"COUNT is "<<count<<endl;
  return count;   
}

int main ( )
{FIBO A;
 int inputNumber, count = 0;
 cout << "To produce a list of the first n Fibonacci numbers " << endl;
 cout << "Enter an integer number > 0 and <= 20, followed by <Enter>: ";
 cin >> inputNumber;
 if (!cin.eof() && cin.good() && inputNumber > 0 && inputNumber <= 20 ) {
 		cout << "Fibonacci number is "; 
    	cout << A.fibonacci (inputNumber) << " ";
    	}
  else
		cout << "Invalid input value";
  cout<<endl;
  count = A.printCount();   //(5)
  cout<<"COUNT is "<<count<<endl; //(6)
  //cout << endl;
  cout << "Program terminating" << endl;
  
  return EXIT_SUCCESS;
}

