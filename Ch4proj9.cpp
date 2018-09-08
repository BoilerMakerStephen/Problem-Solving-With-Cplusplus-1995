//Problem Solving With C++ - Walter Savitch
//Chapter 4
//Programming Project #9
//This program will convert from kilograms/grams to pounds/ounces or 
//vice versa.

#include <iostream>
#include <conio.h>
#include <cmath>

using namespace::std;

double convert_imperial(double &pounds, double &ounces, double &inter_gram);
//Precondition: The function convert_imperial has been called.
//Postcondition: The function convert-imperial has called the 
//functions input_imperial, calc_gram, calc_kg and output_imperial. 
//The final conversions have been printed to the screen.

double convert_metric(double &kilograms, double &grams, double &inter_ounce);
//Precondition: The function convert_metric has been called.
//Postcondition: The function convert_metric has called the functions
//input_metric, calc_ounce, calc_pound and output_metric. The final
//conversions have been printed to the screen.

void input_imperial(double &pounds, double &ounces);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the required data.

void output_imperial(double &pounds, double &ounces, double &total_centimeter);
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

void input_metric(double &kilograms, double &grams);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the required data.

void output_metric(double &pounds, double &ounces, double &total_centimeter);
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
	int choice;
	double pounds, ounces, inter_gram; //variables for imperial
	double kilograms, grams, inter_ounce; //variables for metric

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "MENU"<< endl;
	cout << "#1. CONVERT POUNDS/OUNCES TO KILOGRAMS/GRAMS" << endl;
	cout << "#2. CONVERT KILOGRAMS/GRAMS TO POUNDS/OUNCES" << endl;

	do{
		cout << "CHOICE--> ";
		cin >> choice;
		
		if(choice == 1){
			convert_imperial(pounds, ounces, inter_gram);
		}
		else if(choice == 2){
			convert_metric(kilograms, grams, inter_ounce);
		}
		else{
			cout << "Invalid Choice!" << endl;
		}
		
		cout << endl;
		cout << "Again?" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
	
}

//function for imperial
double convert_imperial(double &pounds, double &ounces, double &inter_gram)
{
    input_imperial(pounds, ounces);
		
	inter_gram = calc_gram(pounds, ounces);

	output_imperial(pounds, ounces, inter_gram);	
    
    return 0;
}

//function for metric
double convert_metric(double &kilograms, double &grams, double &inter_ounce)
{
    input_metric(kilograms, grams);
		
	inter_ounce = calc_ounce(kilograms, grams);

	output_metric(kilograms, grams, inter_ounce);	
    
    return 0;
}

//function for imperial
void input_imperial(double &pounds, double &ounces)
{
	system("CLS");
	cout << "POUNDS--> ";
	cin >> pounds;
	cout << "OUNCES--> ";
	cin >> ounces;
}

//function for imperial
void output_imperial(double &pounds, double &ounces, double &inter_gram)
{
	system("CLS");
	cout << "POUNDS: " << pounds << endl;
	cout << "OUNCES: " << ounces << endl;
	cout << "--------------------" << endl;
	cout << "KILOGRAMS: " << calc_kg(inter_gram) << endl;
	cout << "GRAMS: " << fmod(calc_gram(pounds, ounces), 100) << endl; 
}

//function for imperial
double calc_gram(double &pounds, double &ounces)
{
    double total_ounce = (pounds * 16) + ounces;
    double total_gram = total_ounce * 28.34952;
    
	return total_gram;
}

//function for imperial
double calc_kg(double &inter_gram)
{
	double leftover_gram = inter_gram - fmod(inter_gram, 1000);
	double final_kg = leftover_gram/1000;

	return final_kg;
}

//function for metric
void input_metric(double &kilograms, double &grams)
{
	system("CLS");
	cout << "KILOGRAMS--> ";
	cin >> kilograms;
	cout << "GRAMS--> ";
	cin >> grams;
}

//function for metric
void output_metric(double &kilograms, double &grams, double &inter_ounce)
{
	system("CLS");
	cout << "KILOGRAMS: " << kilograms << endl;
	cout << "GRAMS: " << grams << endl;
	cout << "--------------------" << endl;
	cout << "POUNDS: " << calc_pounds(inter_ounce) << endl;
	cout << "OUNCES: " << fmod(calc_ounce(kilograms, grams), 16) << endl; 
}

//function for metric
double calc_ounce(double &kilogram, double &gram)
{
    double total_gram = (kilogram * 1000) + gram;
    double total_ounce = total_gram * 0.035274;
    
	return total_ounce;
}

//function for metric
double calc_pounds(double &inter_ounce)
{
	double leftover_ounce = inter_ounce - fmod(inter_ounce, 16);
	double final_pound = leftover_ounce/16;

	return final_pound;
}