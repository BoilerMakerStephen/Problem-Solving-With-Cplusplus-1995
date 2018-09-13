//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #3
//This program reads in numbers from a specified file, calculates the average and standard deviation
//and outputs the results to the screen.

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

using namespace::std;

double calc_avg(ifstream& in_stream, char file_name[25]);
//Precondition: in_stream has been connected to an input file with open.
//Postcondition: The contents of the file connected to in_stream have been
//read and the average calculated and returned.

double calc_sd(ifstream& in_stream, char file_name[25], double &average);
//Precondition: in_stream has been connected to an input file with open.
//Postcondition: The contents of the file connected to in_stream have been 
//read and using the returned average from the function calc_avg the standard 
//devaition has been calculated and returned.

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

	double average = calc_avg(fin, file_name);

	cout << "Average: " << average << endl;
	cout << "Standard Deviation: " << calc_sd(fin, file_name, average) << endl;
	cout << endl;	
	cout << "Press any key to escape.\n";
	getch();
}

double calc_avg(ifstream& in_stream, char file_name[25])
{
	double i, average, sum=0;
	int count=0;

	in_stream.open(file_name);
	if(in_stream.fail()){
		cout << endl;
		cout << "Input file opening failed" << endl;
		cout << endl;
		cout << "Press any key to escape..." << endl;
		getch();
		exit(1);
	}

		while(in_stream >> i)
		{
			count++;
			sum += i;
		}
	
	in_stream.close();

	return average = sum/count;
}
		
double calc_sd(ifstream& in_stream, char file_name[25], double &average)
{
	double i, number = 0, std_dev, count = 0;
	
	in_stream.open(file_name);
	if(in_stream.fail()){
		cout << "Input file opening failed." << endl;
		cout << endl;
		cout << "Press any key to escape..." << endl;
		getch();
		exit(1);
	}

	while(in_stream >> i)
		{
			count++;
			number += pow(i-average,2.0);
		}

		double final_number = number/(count - 1);

		in_stream.close();

		return std_dev = sqrt(final_number);
}

