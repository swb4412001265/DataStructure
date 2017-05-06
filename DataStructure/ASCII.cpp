#include <string>
#include <iostream>
using namespace std;

class HASH
{
public:
	HASH();
	~HASH();
	
};
HASH::HASH(){}
HASH::~HASH(){}


int main()
{
	//HASH A;
	char argc = 'a';
	char most = 'z';
	for (;(int)argc<(int)most;(int)argc++)
		cout<<"ASCII code of argc"<<"("<<argc<<") is "<<(int)argc<<endl;
	return 0;
}