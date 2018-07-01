//Problem Solving With C++ - Walter Savitch
//Chapter 3
//Programming Project #6
//Calculates the gravitational attractive force between two bodies.

#include<iostream>
#include <conio.h>
#include <math.h>

using namespace::std;

const double gravity = 0.00000000006673;

double function(double mass_1, double mass_2, double distance);

int main()
{
	char ans;
	double mass_1, mass_2, distance, force;

	cout << "This program is designed to calculate the gravitational" << endl;
	cout << endl;
	cout << "attractive force between two bodies." << endl;
	cout << endl;
	cout << "Press any key to continue..." << endl;

	getch();

	do{
		system("cls");
		cout << "Please enter the mass of the first object." << endl;
		cin >> mass_1;
		cout << endl;
		cout << "Please enter the mass of the second object." << endl;
		cin >> mass_2;
		cout << endl;
		cout << "Please enter the distance between the two objects." << endl;
		cin >> distance;
		cout << endl;

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(12);

		force = function(mass_1, mass_2, distance);

		cout << "The gravitational attractive force between the two objects is " << force << " dynes." << endl;
		cout << endl;
		cout << "Would you like to perform another calculation?" << endl;
		cin >> ans;
	}while(ans=='Y'||ans=='y');

	system("cls");
	cout << "Goodbye!" << endl;
	cout << endl;
	cout << "Press any key to continue..." << endl;

	getch();
}

double function(double mass_1, double mass_2, double distance)
{
	double a  = gravity * mass_1 * mass_2;

	double b = pow(distance, 2);
	
	double force = a/b;
	
	return(force);
}