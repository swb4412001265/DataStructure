#include <iostream>
using namespace std;

// template class copied from www.cprogramming.com/tutorial/templates.html 7/26/2016

template <class A_Type> 
class calc
{
  public:
    A_Type multiply(A_Type x, A_Type y);
    A_Type add(A_Type x, A_Type y);
    A_Type subtract(A_Type x, A_Type y);  // added by JM
};
template <class A_Type> 
A_Type calc<A_Type>::multiply(A_Type x,A_Type y)
{
  return x*y;
}
template <class A_Type> 
A_Type calc<A_Type>::add(A_Type x, A_Type y)
{
  return x+y;
}
template <class A_Type> 
A_Type calc<A_Type>::subtract(A_Type x, A_Type y)
{
  return x-y;
}

int main () 
{ cout << "Integer arithmetic" << endl;
  int a = 2, b = 3;
  calc<int> Iarithmetic;
  cout << "sum =        " << Iarithmetic.add (a, b) << endl;
  cout << "Difference = " << Iarithmetic.subtract (a, b) << endl;
  cout << "Product =    " << Iarithmetic.multiply (a, b) << endl;
  cout << "Double Precision arithmetic" << endl;
  double pi = 3.1416, e = 2.7182;
  calc<double> Darithmetic;
  cout << "sum =        " << Darithmetic.add (pi, e) << endl;
  cout << "Difference = " << Darithmetic.subtract (pi, e) << endl;
  cout << "Product =    " << Darithmetic.multiply (pi, e) << endl;
}
