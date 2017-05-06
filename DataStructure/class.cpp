#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

class name
{
public:
	name();
	~name(){};
	void name1();
	void name2();
	void name3();
private:
	int a;	
};

name::name(){a = 0;}
void name::name2(){a=1;}
void name::name1()
{
	//a =2;
	cout<<"a: "<<a<<endl;
}
void::name::name3(){a=2;}
int main(int argc, char const *argv[])
{
	name A;
	A.name2();
	A.name1();
	A.name3();
	A.name1();
	return 0;
}
