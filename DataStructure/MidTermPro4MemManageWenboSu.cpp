//Midterm homework3 from Wenbo Su
#include <string>
#include <iostream>
using namespace std;

int* getHeapMemory(){
	unsigned long int n=1024;
	int * temp;
	unsigned long int sum = n;
	try {
		bool flag = false;
		while(flag == false){
			temp = new int[n]; //assign heap memory 
			cout<<"The first byte of temp reference is "<<(size_t)temp<<endl;

			if (temp!=NULL)
			{
				if (n==1024)
				{
					cout<<"Total of assigend heap memory is "<<sum/256<<"k"<<endl;
					cout<<endl;
					n=2*n;
				}
				else 
				{
					sum +=n;
					n=2*n;
					cout<<"Total of assigend heap memory is "<<sum/256<<"k"<<endl;		//calculate the total memory assigened to heap
					cout<<endl;			
				}
			}	
			else 
			{
				cout<<"Heap memory is exhasted!"<<endl;		
				flag = true;
				return NULL;
			}		
		}		
	} catch (bad_alloc & ex) {		//Print out when memory exhausted.
			cout<<"Heap memory is exhasted!"<<endl;
			return NULL;
	}	
	return temp;
}


int main(int argc, char const *argv[])
{
	cout<<getHeapMemory()<<endl;
	return 0;
	
}