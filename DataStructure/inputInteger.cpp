//input two integer k and n:k stands for hwo many integer and n stands for the sum of these k integers.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
//#include "node.h"
//#include "bintree.h"
using namespace std;

/*class inputInteger
{
public:
	inputInteger(){};
	~inputInteger(){};
	func(int,int);

private:
	//int k;
	//int n;
};
*/
int func(int n){
	//int sum = 0;
	int a[]= {1,2,3,4,5,6,7,8,9};
	int *b = new int [100];
	int *c = new int [100];
	int *d = new int [100];
	int l = 0;
	if (n<3 || n>27)
	{
		cout<<"can not find the combinations";
		exit(1);
	}
	else {
		for(int i = 0;i < 9; ++i){
			for(int j = 0; j<9; ++j){
				for (int k = 0; k < 9; ++k)
				{
					if (n == a[i] + a[j] +a[k])
					{
						*(b+l)=i+1;
						*(c+l)=j+1;
						*(d+l)=k+1;
						l++;
					}	
					else
					continue;				
				}
			}
		}
		
	}
	for (int i = 0; i <l; ++i)
	{
		cout<<"["<<*(b+i)<<","<<*(c+i)<<","<<*(d+i)<<"]"<<endl;
	}
	delete [] b;
	delete [] c;
	delete [] d;
	//cout <<"111";

	return 0;
}
int main(int argc, char const *argv[])
{
	int n;
	cout<<"Please input n: ";
//	cin>>k;
	cin>>n;
	func(n);
	return 0;
}