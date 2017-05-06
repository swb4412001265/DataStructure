#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

void func(int a){
	if (a>0){
		a=a/2;
		cout<<"1111"<<endl;
		func(a);
	}
	cout<<"a:"<<a<<endl;
}

int main(int argc, char const *argv[])
{
	int a;
	cout<<"input a:";
	cin>>a;
	func(a);
	return 0;
}