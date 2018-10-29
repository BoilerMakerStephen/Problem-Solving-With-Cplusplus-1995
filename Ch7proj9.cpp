//Problem Solving With C++ - Walter Savitch
//Chapter 7
//Programming Project #9
//The value of e^x can be approximated by the sum:
//1 + x + x^2/2! + x^3/3! + ... + x^n/n!
//This program takes a value x as input and outputs this sum for n taken
//to be each of the values 1 to 100. The program will also output e^x calculated
//using the predefined function exp.

#include <iostream>
#include <conio.h>
#include <math.h>

double exponent(double &x);
//Precondition: The user has entered a value for x.
//Postcondition: A value for exp(x) has been returned using the predefined exp() function.
double factorial(double &x);
//Precondition: The user has entered a value for x.
//Postcondition: The factorial for x has been calculated.
double approximated(double &x);
//Precondition: The user has entered a value for x.
//Postcondition: An approximated value for exp(x) has been returned.

using namespace std;

int main()
{
	double x;
	char ans;
	
	do{
		system ("CLS");
		cout << "Enter x value: " << endl;
		cin >> x;
		cout << "Exponent: " << exponent(x) << endl;
		cout << "Factorial: " << factorial(x) << endl;
		cout << "Approximated: " << approximated(x) << endl;
		cout << "Difference: " << exponent(x) - approximated(x) << endl;
		cout << "Again?(Y/N) ";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
	cout << "Press any key to quit...";
	getch();

}

double exponent(double &x){
	
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
		
	return exp(x);
}

double factorial(double &x)
{
	double factorial = 1;

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);

	for(int i = 1; i <= x; i++){
		factorial *= i;
	}

	return factorial;	
}

double approximated(double &x)
{
	double approximated = 0;
	double factorial = 1;
	double close_approx;

	for(int i = 2; i <= 100; i++){
		factorial *= i;
		approximated += pow(x, i)/factorial;	
	}

	close_approx = 1 + x + approximated;

	return close_approx;
}