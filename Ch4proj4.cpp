//Problem Solving With C++ - Walter Savitch
//Chapter 4
//Programming Project #4
//This program will read in a length in feet and inches and will output
//the equivalent length in meters and centimeters.

#include <iostream>
#include <conio.h>
#include <cmath>

using namespace::std;

void input(double &feet, double &inch);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the required data.

void output(double &feet, double &inch, double &total_centimeter);
//Precondition: The appropriate data has been acquired.
//Postcondition: The data has been printed to the screen.

double calc_cm(double &feet, double &inch);
//Precondition: The data for feet and inches has been acquired.
//Postcondition: The data for feet and inches has been converted 
//into centimeters.

double calc_meter(double &inter_cm);
//Precondition: The data for feet and inches has been acquired.
//Postcondition: The data for feet and inches has been converted
//into total meters minus leftover centimeters.

int main()
{
	char ans;
	double feet, inch, total_centimeter, final_meter;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	do{
		input(feet, inch);
		calc_cm(feet, inch);

		double inter_cm = calc_cm(feet, inch);

		output(feet, inch, inter_cm);	
		
		cout << "Again?" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y'); 
}

void input(double &feet, double &inch)
{
	cout << "FEET--> ";
	cin >> feet;
	cout << "INCHES--> ";
	cin >> inch;
}

void output(double &feet, double &inch, double &inter_cm)
{
	cout << "FEET: " << feet << endl;
	cout << "INCHES: " << inch << endl;
	cout << "--------------------" << endl;
	cout << "METERS: " << calc_meter(inter_cm)<< endl;
	cout << "CENTIMETERS: " << fmod(calc_cm(feet, inch), 100) << endl;
}

double calc_cm(double &feet, double &inch)
{
    double total_inch = (feet * 12) + inch;
    double total_centimeter = total_inch * 2.54;
    
	return total_centimeter;
}

double calc_meter(double &inter_cm)
{
	double leftover_cm = inter_cm - fmod(inter_cm, 100);
	double final_meter = leftover_cm/100;

	return final_meter;
}