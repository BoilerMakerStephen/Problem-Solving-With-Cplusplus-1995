//Problem Solving With C++ - Walter Savitch
//Chapter 6
//Programming Project #4
//Counter program

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//Class for a counter type
class CounterType
{
public:
	CounterType();
	//Constructor
	CounterType(int num);
	//Constructor
	void closeFile(ofstream& fout);
	//Postcondition: Output file has been created and 
	//fin has been connected
	int increaseCount();
	//Increases count
	int decreaseCount();
	//Decreases count
	void currentValue();
	//Returns the current value
	void countStream(ofstream& fout);
	//Outputs the current value to a stream
private:
	int count;
};

int main()
{
	CounterType test(12);
	ofstream fout;
		
	test.closeFile(fout);

	test.currentValue();
	//test.countStream(fout);

	fout.close();

	cout << "Data has been printed to the output file." << endl;
	cout << "Press any key to escape..." <<endl;
	getch();
}

CounterType::CounterType()
{
	int count = 0;
}

CounterType::CounterType(int num)
{
	count = num;
}

void CounterType::closeFile(ofstream& fout)
{
	char outfileName[25];

	cout << "Enter output file name(max 25 characters)." << endl;
	cin >> outfileName;

	fout.open(outfileName);
	if(fout.fail()){
		cout << "Output file opening failed." << endl;
		exit(1);
	}
}

int CounterType::increaseCount()
{
	return(++count);
}

int CounterType::decreaseCount()
{
	return(--count);
}

void CounterType::currentValue()
{
	if(count < 1){
		cout << "Cannot decrement less than zero." << endl;
	}
	else
		cout << "The count is " << increaseCount() << endl;
	
}

void CounterType::countStream(ofstream& fout)
{
	if(count < 1){
		fout << "Cannot decrement less than zero" << endl;
	}
	else{
		fout << "The count is " << increaseCount() << endl;
	}
}