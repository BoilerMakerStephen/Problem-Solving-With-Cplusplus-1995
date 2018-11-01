//Problem Solving With C++ - Walter Savitch
//Chapter 9
//Programming Project #4
//Returns the standard deviation of user supplied numbers

#include <iostream>
#include <conio.h>
#include <math.h>

const int MAX_LIST_SIZE = 100;

using namespace std;

void calc_std_dev(double std_dev[MAX_LIST_SIZE], int& length);
//Precondition: The length of the array has been defined by the user.
//The array std_dev has been filled.
//Postcondition: The standard deviation has been calculated and output
//to the screen.

int main()
{
	int length = 0;
	double std_dev[MAX_LIST_SIZE];
	int i = 0;
	char ans;

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);

	do{
		system("CLS");
		cout << "How many numbers will be entered?" << endl;
		cin >> length;
		cout << "Enter the numbers you would like to find the standard deviation for: " << endl;
		for(int i = 0; i < length; i++){
			cin >> std_dev[i];
		}
		calc_std_dev(std_dev, length);

		cout << "Would you like to analyze another set of numbers(Y/N)? " << endl;
		cin >> ans;
	}while(ans== 'Y' || ans == 'y');
}

void calc_std_dev(double std_dev[MAX_LIST_SIZE], int& length)
{
	double sum = 0;
	double avg = 0;
	double std_err = 0;
	double new_sum = 0;
	double S = 0;
		
	for(int i = 0; i < length; i++){
		sum += std_dev[i];
	}

	avg = sum/length;
	
	for(int i = 0; i < length; i++){
		std_err += pow(std_dev[i] - avg, 2);
	}

	new_sum = std_err/length;
	S = sqrt(new_sum);

	cout << "Standard Deviation: " << S << endl;
}