//Problem Solving With C++ - Walter Savitch
//Chapter 4
//Programming Project #2
//This program computes the standard deviation of four scores

#include <iostream>
#include <conio.h>
#include <math.h>

const int num = 4;

double calc_mean(double s1, double s2, double s3, double s4);
//Precondition: Four numbers have been entered by the user.
//Postcondition: The mean of the the four numbers entered by the user has been calculated.

double calc_sum(double s1, double s2, double s3, double s4, double mean);
//Precondition: The mean of four numbers has been calculated.
//Postcondition: The discriminant has been calculated and returned.

double std_dev(double s1, double s2, double s3, double s4, double mean, double sum);
//Precondition: The discriminant of the standard deviation formula has been calculated.
//Postcondition: The standard deviation of the four numbers entered by the user has been
//calculated and returned.

using namespace::std;

int main()
{
	char ans;
	double s1, s2, s3, s4;
	double mean = 0, sum = 0;

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);

	do{
		cout << "number--> ";
		cin >> s1;
		cout << "number--> ";
		cin >> s2;
		cout << "number--> ";
		cin >> s3;
		cout << "number--> ";
		cin >> s4;
				
		cout << "STANDARD DEVIATION: " << std_dev(s1, s2, s3, s4, mean, sum) << endl;

		cout << "Again?" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}

double calc_mean(double s1, double s2, double s3, double s4)
{
	double var_1 = (s1 + s2 + s3 + s4)/num;

	return var_1;
}

double calc_sum(double s1, double s2, double s3, double s4, double mean)
{
	s1 = pow((s1 - mean), 2);
	s2 = pow((s2 - mean), 2);
	s3 = pow((s3 - mean), 2);
	s4 = pow((s4 - mean), 2);

	double var_2 = s1 + s2 + s3 + s4;

	return var_2;
}

double std_dev(double s1, double s2, double s3, double s4, double mean, double sum)
{
	mean = calc_mean(s1, s2, s3, s4);

	sum = calc_sum(s1, s2, s3, s4, mean);
		
	double sd = sqrt(sum/(num - 1));

	return sd;
}

