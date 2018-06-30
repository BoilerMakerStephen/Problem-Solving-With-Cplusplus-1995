//Problem Solving With C++ - Walter Savitch
//Chapter 3
//Programming Project #1
//This program converts litres per mile to gallons per mile.

#include <iostream>
#include <conio.h>

const double gallon = 0.24671; //litres

using namespace::std;

double convert(double litres, double miles);

int main()
{
	double litres, miles;
	char ans;

	do{
		system("cls");
		cout << "Please enter the amount of litres your car consumed" << endl;
		cin >> litres;
		cout << "Please enter the number of miles your car has travelled" << endl;
		cin >> miles;

		double mpg = convert(litres, miles);

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "Your car gets " << mpg << " mpg." << endl;
		cout << endl;
		cout << "Would you like to perform another calculation?(Y/N)\n";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');

	system("cls");
	cout << "Goodbye!" << endl;
	cout << "Press any key to escape..." << endl;
	getch();
}

double convert(double litres, double miles)
{
	double mpg = miles/(litres * gallon);

	return mpg;	
}