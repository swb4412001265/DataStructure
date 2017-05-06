// Author:  John Maslanka   Date: November 2002    Course: CS341 Fall 2002
// Brief Description: This program accepts as input the number of elements which
//  are contained in a binary tree.  As output, it provides an integer for each
//  position in the balanced tree.  This integer will be the depth from the root
//  at which an element will be placed.
// Edit: Nov 2002 by student Ryan Balter 
//  Problem: A few elements were assigned higher level numbers when open 
//  positions were still available at lower levels.
//  Description: Provide the "round" parameter to tell whether to round an 
//  individual position number up or down depending on the nunerical span between 
//  individual positions on a given level of a binary tree. The round parameter 
//  will contain either -1 or +1 to indicate either round down or round up.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

void FindMiddle(int x, int y, int level, int nr, int round)
{ int mid;
  if (abs(x-y)<2)
     { if (x==1) 
          cout << level << " " << setw(2) << x << endl;
       if (y==nr) 
          cout << level << " " << setw(2) << y << endl;
       return;
     }
  if ((y+x)%2)
     { mid=(x+y+round)/2;
       cout << level << " " << setw(2) << mid << endl;
     }
 else
     { mid = (x+y)/2;
       cout << level << " " << setw(2) << mid << endl;
     }
  FindMiddle(x,mid,(level+1),nr,-1); // round down left
  FindMiddle(mid,y,(level+1),nr,1);  // round up right
  return;
}

int main()
{ int nr, level=0;
  cout << "Enter integer number of elements: ";
  if (cin >> nr)
     if (nr>2)
        FindMiddle(1,nr,(level+1),nr,1);
  return 0;
}