//Midterm homework 1 from Wenbo Su

#include <iostream>
#include <cstdlib>
using namespace std;
class calculator		//define all the arithmetic operations
{
public:
	calculator(){};
	~calculator(){};
	double add(double, double);
	double subtract(double ,double);
	double multiply(double ,double);
	double divide(double ,double); 
};
double calculator::add(double a, double b){
	return (a + b);
}
double calculator::subtract(double a, double b){
	return (a - b);
}
double calculator::multiply(double a, double b){
	return (a * b);
}
double calculator::divide(double a, double b){
	if (b == 0)		//terminate program if meeting this condition
	{
		cout<<"Error! You can not divide number by zero."<<endl;
		exit(1);
		return 0;
	}
	else
		return (a / b);
}

class container_Calculator		//container class for handling operations
{
public:
	container_Calculator(){};
	~container_Calculator(){};
	double calculationResult(double ,double ,char);
};
double container_Calculator::calculationResult(double a,double b,char oprter){
	calculator Q;
	switch (oprter){
		case '+':
			return Q.add(a ,b);
		case '-':
			return Q.subtract(a ,b);
		case '*':
			return Q.multiply(a ,b);
		case '/':
			return Q.divide(a ,b);
		default:{
			cout<<"Invalid Input for operator."<<endl;
			return 0;
		}
	}
}


int main(int argc, char const *argv[])
{
	double num1;
	double num2;
	char arithmetic;
	container_Calculator *A = new container_Calculator;		//assign a heap memory to object
	bool flag = true;
	while (flag)
	{
		cout<<"Please input the first number:";
		cin>>num1;
		cout<<endl;
		if (cin.eof())
		{
			cout<<"System is done since EOF."<<endl;
			flag = false;
			delete A;		//clear memory if EOF happens
			return 0;
		}
		else if(!cin.good())
		{
			cout<<"You give an Invalid a input, please try again.";
			cout<<endl;
			cin.clear();		//clear cin's staus	
			cin.ignore();		//ignore cin's invalid input
			continue;
		}		
		
	
		cout<<"Please input the operator:";
		cin>>arithmetic;
		cout<<endl;
		if (cin.eof())
		{
			cout<<"System is done since EOF."<<endl;
			flag = false;
			delete A;	
			return 0;
		}
		else if(!cin.good())
		{
			cout<<"You give an Invalid a input, please try again.";
			cout<<endl;
			cin.clear();
			cin.ignore();
			continue;
		}	
		cout<<endl;
		cout<<"Please input the second number:";
		cin>>num2;
		
		if (cin.eof())
		{
			cout<<"System is done since EOF."<<endl;
			flag = false;
			delete A;
			return 0;
		}
		else if(!cin.good())
		{
			cout<<"You give an Invalid a input, please try again.";
			cout<<endl;
			cin.clear();
			cin.ignore();
			continue;
		}	
		cout<<"You result is "<<A->calculationResult(num1 ,num2 ,arithmetic);
		cout<<endl;
	}
	return 0;
}

