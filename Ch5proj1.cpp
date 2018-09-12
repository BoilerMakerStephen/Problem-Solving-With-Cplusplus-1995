//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #1
//This program will search a file of numbers of type int and write the largest 
//and smallest numbers to the screen.

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

void read_numbers(ifstream& in_stream, char file_name[16]);
//Precondition: in_stream has been connected to an input file with open.
//Postcondition: The contents of the file connected to in_stream have been 
//read into the program and analyzed for the largest and smallest numbers

int main()
{
	ifstream fin;
	char file_name[16];

	cout << "This program reads numbers from a file and prints the largest\n";
	cout << endl;
	cout << "and smallest numbers to the screen.\n";
	cout << endl;
	cout << "What is the name of the .dat file you wish to connect to.\n";
	cout << endl;
	cin >> file_name;
	
	fin.open(file_name);
	if(fin.fail())
	{
		cout << endl;
		cout << "Input file opening failed.\n";
		cout << endl;
		cout << "Press any key to escape.\n";
		cout << endl;
		getch();
		exit(1);
	}

	read_numbers(fin, file_name);
	fin.close();
	cout << endl;
	cout << "Press any key to escape.\n";
	getch();
}

void read_numbers(ifstream& in_stream, char file_name[16])
{
	double i, max = INT_MIN, min = INT_MAX; //INT_MIN and INT_MAX are constants and represent the min/max
											//integer value type int can hold.
		while(in_stream >> i)
		{
			if(i > max)
				max = i;
			if(i < min)
				min = i;
		}
	cout << endl;
	cout << "Smallest number in " << file_name << ": "<<min<<endl;
	cout << endl;
	cout << "Largest number in "<< file_name <<": "<<max<<endl;
}
	
	

	