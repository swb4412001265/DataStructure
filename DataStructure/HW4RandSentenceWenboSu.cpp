#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#define NUM 10
/*
class word
{
public:
	word();
	~word(){};
	void putNouns(string);
	string getNouns(string);
	void putVerbs(string);
	string getVerbs();
private:
	string nouns[];
	string verbs[];
};

word::word(){
	string nouns[] = {};
	string verbs[] = {};
}

void word::putNouns(string a[]){
	nouns = a;
}

string word::getNouns(){
	return nouns;
}

void word::putVerbs(string a[]){
	verbs = a;
}

string word::getVerbs(){
	return verbs;
}

class wordContainner
{
public:
	wordContainner();
	~wordContainner();
	string connetcSentence(string,string); 
	void display();
private:
	string finalSentence;
};
	
	wordContainner::display(string a[]){
		cout<<"The"
	}

	wordContainner::connetcSentence(string a[],string b[]){
		for (int i = 0; i < 10; ++i)
		{
			finalSentence[i] = "The " + a[i] + b[i];
		}

	}
*/
int main()
{
	string *temp1 = new string [NUM];
	string *temp2 = new string [NUM];
	bool checkFlag = true;
	int num;
	for (int i = 0; i < NUM; ++i)
	{	
		cout<<"Please input a noun"<<"["<<i+1<<"]: ";
		cin>>*(temp1 + i);
		if (cin.eof()){
			cout<<"You put EOF to exit the system"<<endl;
			delete [] temp1;
			delete [] temp2;
			exit(1);
			//return 0;
		}
		cout<<endl;
		for (int j = 0; j < i; ++j)
		{
			if(*(temp1 + j) == *(temp1 + i)) {
				cout<<"You just input as same as noun"<<"["<<j+1<<"]"
				<<" and Please input a unique noun:"<<endl;
				//checkFlag = true;
				i--;
				break;
			}
		}		
	
		
	}


	for (int i = 0; i < NUM; ++i)
	{	
		cout<<"Please input a verb"<<"["<<i+1<<"]: ";
		cin>>*(temp2 + i);
		if (cin.eof()){
			cout<<"You put EOF to exit the system"<<endl;
			delete [] temp1;
			delete [] temp2;
			exit(1);
			//return 0;
		}
		cout<<endl;
		for (int j = 0; j < i; ++j)
		{
			if(*(temp2 + j) == *(temp2 + i)) {
				cout<<"You just input as same as verb"<<"["<<j+1<<"]"
				<<" and Please input a unique verb:"<<endl;
				//checkFlag = true;
				i--;
				break;
			}
		}
	}
	
	while(checkFlag){
		cout<<"Please input a num(1-100) that defines how many sentences you want to print out:";
		cin>>num;
		if (cin.eof()) 
		{
			cout<<"You put EOF to exit the system"<<endl;
			checkFlag = false;
			delete [] temp1;
			delete [] temp2;
			exit(1);
		}
		else if (!cin.good())
		{
			cout<<"You input an invalid number and Please input a num:"<<endl;
			cin.clear();
			cin.ignore();
			//continue;
		}
		else if (num < 1 or num > 100)
		{
			cout<<"The number is out of range (1-100)and Please input a num:"<<endl;
			cin.clear();
			cin.ignore();
			//continue;
		}	
		else	
			checkFlag = false;
	}

	cout<<"The output will be:"<<endl;
	string *temp3 = new string [num];
	for (int i = 0; i < num; ++i)
	{	
		*(temp3 + i) = "The " + *(temp1 + (rand()% NUM)) + " " + 
		*(temp2 + (rand()% NUM)) + " " +
		+ "the " + *(temp1 + (rand()% NUM)) + ".";
		//srand (time(NULL));		//make sure every time seed is different
		cout<<"Here are the generated sentences: "<<*(temp3 + i)<<endl;
	}
	delete [] temp1;
	delete [] temp2;
	delete [] temp3;
	return 0;
}
