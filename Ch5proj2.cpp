//This program reads in numbers of type double from a specified file, calculates 
//the average and outputs the results to the screen.

#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

void read_numbers(ifstream& in_stream, char file_name[25]);
//Precondition: instream has been connected to a file with open.
//Postcondition: The contents of the file connected to in_stream have been read 
//into the program and the average calculated. The results are then printed to
//the screen.

int main()
{
	ifstream fin;	
	char file_name[25];

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "This file reads numbers from a file and prints the average to the screen.\n";
	cout << endl;
	cout << "What is the name of the .dat file you wish to connect to? (25 characters max)\n";
	cout << endl;
	cin >> file_name;
	cout << endl;
	
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

void read_numbers(ifstream& in_stream, char file_name[25])
{
	double i, average, sum=0;
	int count=0;

		while(in_stream >> i)
		{
			count++;
			sum += i;
		}

	average=sum/count;
	
	cout << "Average in " << file_name << ": " << average << endl;
}