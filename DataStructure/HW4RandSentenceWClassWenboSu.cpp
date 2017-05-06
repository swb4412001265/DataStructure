//homework 4 Random sentences from Wenbo Su

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int NUM = 10;		//define string length is 10

class word
{
public:
	word();
	~word();
	void putNouns();
	string getNouns(int);
	void putVerbs();
	string getVerbs(int);
private:
	string *nouns;
	string *verbs;
};

word::word(){		//constructor	
	nouns = verbs = NULL;
}
word::~word(){		//deconstructor and free memory
	delete [] nouns;
	delete [] verbs;
}
void word::putNouns(){
	nouns = new string [NUM];
	for (int i = 0; i < NUM; ++i)
	{	
		cout<<"Please input a noun"<<"["<<i+1<<"]: ";
		cin>>*(nouns + i);
		if (cin.eof()){
			cout<<"You put EOF to exit the system"<<endl;
			delete [] nouns;	//clear heap memory if eof
			exit(1);		//exit the program
			//return 0;
		}
		cout<<endl;
		for (int j = 0; j < i; ++j)	
		{
			if(*(nouns + j) == *(nouns + i)) {		//check if there is duplicated input
				cout<<"You just input as same as noun"<<"["<<j+1<<"]"
				<<" and Please input a unique noun:"<<endl;
				i--;
				break;
			}
		}		
	}
}

string word::getNouns(int a){
	return *(nouns + a);
}

void word::putVerbs(){
	verbs = new string [NUM];
	for (int i = 0; i < NUM; ++i)
		{	
			cout<<"Please input a verb"<<"["<<i+1<<"]: ";
			cin>>*(verbs + i);
			if (cin.eof()){
				cout<<"You put EOF to exit the system"<<endl;
				delete [] verbs;	//clear heap memory if eof happends
				delete [] nouns;
				exit(1);
			}
			cout<<endl;
			for (int j = 0; j < i; ++j)
			{
				if(*(verbs + j) == *(verbs + i)) {		//check if there is duplicated input
					cout<<"You just input as same as verb"<<"["<<j+1<<"]"
					<<" and Please input a unique verb:"<<endl;
					i--;
					break;
				}
			}
		}
	}

string word::getVerbs(int a){
	return *(verbs + a);
}

class wordContainner		//containner class for display and connect random sentences
{
public:
	wordContainner();
	~wordContainner();
	void connetcSentence(); 
	void display();
private:
	string *finalSentence;	//define random sentences	
	int num;	//define input num for how many sentences you want to print out
};

wordContainner::wordContainner(){	//constructor	
	finalSentence = NULL;
	num = 0;
}
wordContainner::~wordContainner(){	//deconstruction and free memory
	delete [] finalSentence;
}	
void wordContainner::connetcSentence(){
	
	word A;		//call word class object to pass in nouns and verbs
	A.putNouns();
	A.putVerbs();
	bool checkFlag = true;	
	while(checkFlag){	//for input num checking
		cout<<"Please input a num(1-100) that defines how many sentences you want to print out:";
		cin>>num;
		if (cin.eof()) 
		{
			cout<<"You put EOF to exit the system"<<endl;
			checkFlag = false;
			delete [] finalSentence;
			exit(1);
		}
		else if (!cin.good())	//check if input is not int
		{
			cout<<"You input an invalid number and Please input a num:"<<endl;
			cin.clear();
			cin.ignore();
			//continue;
		}
		else if (num < 1 || num > 100)		//check if num is out of range
		{
			cout<<"The number is out of range (1-100)and Please input a num:"<<endl;
			cin.clear();
			cin.ignore();
			//continue;
		}	
		else	
			checkFlag = false;
	}

	finalSentence = new string [num];	//create finalSentences
	for (int i = 0; i < num; ++i)	
	{	
		*(finalSentence + i) = "The " + A.getNouns(rand()%10) + " " + 
		A.getVerbs(rand()% 10) + " " +
		+ "the " + A.getNouns(rand()% 10) + ".";
	}	
}

void wordContainner::display(){
	for (int i = 0; i < num; ++i)
	{
		cout<<"Here are the generated sentences: "<<*(finalSentence + i)<<endl;
	}
}

int main()
{
	wordContainner A;
	A.connetcSentence();
	A.display();
	return 0;
}
