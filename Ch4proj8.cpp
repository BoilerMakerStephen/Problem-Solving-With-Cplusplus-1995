//Problem Solving With C++ - Walter Savitch
//Chapter 4
//Programming Project #8
//This program reads in weight in kilograms and grams and will output the equivalent weight
//in pounds and ounces.

#include <iostream>
#include <conio.h>
#include <cmath>

using namespace::std;

void input(double &kilograms, double &grams);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the required data.

void output(double &pounds, double &ounces, double &total_centimeter);
//Precondition: The appropriate data has been acquired.
//Postcondition: The data has been printed to the screen.

double calc_ounce(double &kilograms, double &grams);
//Precondition: The data for kilograms and grams has been acquired.
//Postcondition: The data for kilograms and grams has been converted 
//into total ounces.

double calc_pounds(double &inter_ounce);
//Precondition: The data for total ounces has been acquired.
//Postcondition: The data for total ounces has been converted
//into total pounds minus leftover ounces.

int main()
{
	char ans;
	double kilograms, grams;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	do{
		input(kilograms, grams);
		
		double inter_ounce = calc_ounce(kilograms, grams);

		output(kilograms, grams, inter_ounce);	
		
		cout << endl;
		cout << "Again?" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y'); 
}

void input(double &kilograms, double &grams)
{
	system("CLS");
	cout << "KILOGRAMS--> ";
	cin >> kilograms;
	cout << "GRAMS--> ";
	cin >> grams;
}

void output(double &kilograms, double &grams, double &inter_ounce)
{
	system("CLS");
	cout << "KILOGRAMS: " << kilograms << endl;
	cout << "GRAMS: " << grams << endl;
	cout << "--------------------" << endl;
	cout << "POUNDS: " << calc_pounds(inter_ounce) << endl;
	cout << "OUNCES: " << fmod(calc_ounce(kilograms, grams), 16) << endl; 
}

double calc_ounce(double &kilogram, double &gram)
{
    double total_gram = (kilogram * 1000) + gram;
    double total_ounce = total_gram * 0.035274;
    
	return total_ounce;
}

double calc_pounds(double &inter_ounce)
{
	double leftover_ounce = inter_ounce - fmod(inter_ounce, 16);
	double final_pound = leftover_ounce/16;

	return final_pound;
}