//This program reads in numbers from a specified file, calculates the average and standard deviation
//and outputs the results to the screen.

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

using namespace::std;

void read_numbers(ifstream& in_stream, char file_name[25]);
//Precondition: in_stream has been connected to an input file with open.
//Postcondition: The contents of the file connected to instream have been
//read into the program and the average and standard deviation has been
//calculated and printed to the screen.

int main()
{
	ifstream fin;
	char file_name[25];

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout<< "This program reads numbers from a file and prints the average and standard deviation.\n";
	cout << endl;
	cout << "to the screen.\n";
	cout << endl;
	cout << "Enter the name of the .dat file you wish to analayze. (25 characters max)\n";
	cout << endl;
	cin >> file_name;
	cout <<endl;
	
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
	
	cout << "Press any key to escape.\n";
	getch();
}

void read_numbers(ifstream& in_stream, char file_name[25])
{
	double i,average,std_dev,sum=0, number=0;
	int count=0;

		while(in_stream >> i)
		{
			count++;
			sum += i;
		}

	average=sum/count;

	in_stream.clear();						//resets all internal error flags.
	in_stream.seekg(0, in_stream.beg);      //rewinds file pointer to very beginning.

		while(in_stream >> i)
		{
			number += pow(i-average,2.0);
		}

		double final_number = number/(count - 1);

		std_dev = sqrt(final_number);

	system("cls");
	cout << "Average: " << average << endl;
	cout << endl;
	cout << "Standard Deviation: "<< std_dev << endl;
	cout << endl;
}

