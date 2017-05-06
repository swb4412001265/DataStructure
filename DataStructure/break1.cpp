#include <iostream>
using namespace std;
#include <cstdlib>


class HanLieShi {
public:
	HanLieShi();
	void testBreak();
	~HanLieShi();

private:
	//int a;
};

HanLieShi::HanLieShi () {cout<<"code starts"<<endl;}

HanLieShi::~HanLieShi() {cout<<"code ends"<<endl;}

void HanLieShi::testBreak(){
	int i = 0;
	while(i < 10){
		i++;
		cout<<"i:"<<i<<endl;
		//cout<endl;
		}
}

int main(){
	HanLieShi a;
	a.testBreak();
	cout<<"Check if Class is done"<<endl;
	return 0;
}
