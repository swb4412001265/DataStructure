//Final question 4 from Wenbo Su

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

template < class X >             // define template function for sorting
void swap ( X* v1, X* v2 )
{ if(*v1 > *v2){
  X temp = *v1;
  *v1 = *v2;
  *v2 = temp;
}
}

int main () {
    int i, j, x[200000];
    int n;
    cout << "Enter the number of integers to be entered: ";
    cin >> n;
    if (!cin.eof() && cin.good())
    {
    for (i = 0; !cin.eof() && cin.good() && i < n; ++i)  
    cin >> x[i];  
    if (!cin.eof() && cin.good()) {  
        cout << "Initial array is ";
    for (i = 0; i < n; ++i)
      cout << x[i] << " ";
      cout << endl; 
    // beginning of sorting code
    for (i = 0; i < n-1; ++i)
      for (j = 0; j < n-1-i; ++j)
         swap (x+j, x+j+1);
    // end of sorting code
      cout << "Sorted array is ";
    for (i = 0; i < n; ++i)
        cout << " " << x[i];
        cout << endl;
      }
    else
    cout << "Invalid input" << endl;
    }
    cout << "Program terminating" << endl;
    system("PAUSE");



    int k, l,o; 
    double m[200000];
    cout << "Enter the number of decimal to be entered: ";
    cin >> o;
    if (!cin.eof() && cin.good())
    {
    for (k = 0; !cin.eof() && cin.good() && k < o; ++k)  
     cin >> m[k];  
    if (!cin.eof() && cin.good()) {  
    cout << "Initial array is ";
    for (k = 0; k < o; ++k)
      cout << m[k] << " ";
    cout << endl; 
    // beginning of sorting code
    for (k = 0; k < o-1; ++k)
      for (l = 0; l < o-1-k; ++l)
         swap (m+l, m+l+1);
    // end of sorting code
    cout << "Sorted array is ";
    for (k = 0; k < o; ++k)
       cout << " " << m[k];
    cout << endl;
      }
    else
    cout << "Invalid input" << endl;
    }
   cout << "Program terminating" << endl;
   system("PAUSE");
      return EXIT_SUCCESS;
}