//Problem Solving With C++ - Walter Savitch
//Chapter 4
//Programming Project #7
//This program reads in weight in pounds and ounces and will output the equivalent weight
//in kilograms and grams.

#include <iostream>
#include <conio.h>
#include <cmath>

using namespace::std;

void input(double &pounds, double &ounces);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the required data.

void output(double &pounds, double &ounces, double &total_centimeter);
//Precondition: The appropriate data has been acquired.
//Postcondition: The data has been printed to the screen.

double calc_gram(double &pounds, double &ounces);
//Precondition: The data for pounds and ounces has been acquired.
//Postcondition: The data for pounds and ounces has been converted 
//into grams.

double calc_kg(double &inter_gram);
//Precondition: The data for pounds and ounces has been acquired.
//Postcondition: The data for pounds and ounces has been converted
//into total kilograms minus leftover grams.

int main()
{
	char ans;
	double pounds, ounces, total_centimeter, final_meter;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	do{
		input(pounds, ounces);
		
		double inter_gram = calc_gram(pounds, ounces);

		output(pounds, ounces, inter_gram);	
		
		cout << endl;
		cout << "Again?" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y'); 
}

void input(double &pounds, double &ounces)
{
	system("CLS");
	cout << "POUNDS--> ";
	cin >> pounds;
	cout << "OUNCES--> ";
	cin >> ounces;
}

void output(double &pounds, double &ounces, double &inter_gram)
{
	system("CLS");
	cout << "POUNDS: " << pounds << endl;
	cout << "OUNCES: " << ounces << endl;
	cout << "--------------------" << endl;
	cout << "KILOGRAMS: " << calc_kg(inter_gram) << endl;
	cout << "GRAMS: " << fmod(calc_gram(pounds, ounces), 100) << endl; 
}

double calc_gram(double &pounds, double &ounces)
{
    double total_ounce = (pounds * 16) + ounces;
    double total_gram = total_ounce * 28.34952;
    
	return total_gram;
}

double calc_kg(double &inter_gram)
{
	double leftover_gram = inter_gram - fmod(inter_gram, 1000);
	double final_kg = leftover_gram/1000;

	return final_kg;
}