#include <iostream>
using namespace std;
#include <iterator>

int main ( ) { 
double  sum1 = 0, num;
cout << "Enter a series of double-precision numbers." << endl;
std::istream_iterator<double> inputDouble (cin);
while ( !cin.eof ( ) && cin.good ( ) ) {
	num = *inputDouble;
	sum1+=num;
	++inputDouble;
	}
cout << "The sum is: ";
std::ostream_iterator<double> outputDouble (cout);
*outputDouble = sum1;
cout << endl;
return 0;
}
