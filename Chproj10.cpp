//Problem Solving With C++ - Walter Savitch
//Chapter 4
//Programming Project #10
//This program allows the user to convert lengths/weights to imperial/metric.

#include <iostream>
#include <conio.h>
#include <cmath>

using namespace::std;

void convert_weight_menu(double &kilograms, double &grams, double &inter_ounce, double &pounds, double &ounces, 
							double &inter_gram);
//Precondition: The user has opted for choice #1 - to convert weights.
//Postcondition: All relevant data has been input by the user, all applicable functions have been called and the 
//converted reults have been printed to the screen.

void convert_length_menu(double &meter, double &centimeter, double &results_inch, double &total_inch, double &feet_to_cm,
							double &feet, double &inch, double &total_centimeter, double &inter_cm);
//Precondition: The user has opted for choice #2 - to convert lengths.
//Postcondition: All relevant data has been input by the user, all applicable functions have been called and the 
//converted reults have been printed to the screen.

double convert_imperial_weight(double &pounds, double &ounces, double &inter_gram);
//Precondition: The function convert_imperial has been called.
//Postcondition: The function convert-imperial has called the 
//functions input_imperial, calc_gram, calc_kg and output_imperial. 
//The final conversions have been printed to the screen.

double convert_metric_weight(double &kilograms, double &grams, double &inter_ounce);
//Precondition: The function convert_metric has been called.
//Postcondition: The function convert_metric has called the functions
//input_metric, calc_ounce, calc_pound and output_metric. The final
//conversions have been printed to the screen.

void input_imperial_weight(double &pounds, double &ounces);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the required data.

void output_imperial_weight(double &pounds, double &ounces, double &total_centimeter);
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

void input_metric_weight(double &kilograms, double &grams);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the required data.

void output_metric_weight(double &pounds, double &ounces, double &total_centimeter);
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

double convert_metric_length(double &meter, double &centimeter, double &results_inch, double &total_inch, double &feet_to_cm);
//Precondition: The convert_metric function has been called.
//Postcondition: All associated functions have been called and the results of the conversions
//have been output to the screen.

double convert_imperial_length(double &feet, double &inch, double &total_centimeter, double &inter_cm);
//Precondition: The convert_metric function has been called.
//Postcondition: All associated functions have been called and the results of the conversions
//have been output to the screen.

void input_metric_length(double &meter, double &centimeter);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the data for meter and centimeter.

void output_meter(double &meter, double &centimeter, double &results_inch, double &total_inch, double &feet_to_cm);
//Precondition: Meters and centimeters have been converted to feet and inches.
//Postcondition: The results of the conversions have been printed to the screen.

double calc_inch(double &meter, double &centimeter);
//Precondition: The user has input data for meter and centimeter.
//Postcondition: The data for meters and centimeters has been converted to inches.

double calc_foot(double &results_inch);
//Precondition: Meters and centimeters have been converted to inches and added together.
//Postcondition: Total inches have been converted to feet. The case of the variable 
//feet has been changed from type double to type int.

double calc_inches_leftover(double &results_inch);
//Precondition: The fraction part of feet exists.
//Postcondition: The fraction part of feet has been converted to leftover_inches.

void input_imperial_length(double &feet, double &inch);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the required data.

void output_imperial_length(double &feet, double &inch, double &total_centimeter);
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
	int choice_one, choice_two;
	double kilograms, grams, inter_ounce; // variables for converting kilograms to pounds
	double pounds, ounces, inter_gram; // variables for converting pounds to kilograms
	double meter, centimeter, results_inch, total_inch, feet_to_cm; // variables for converting meters to feet
	double feet, inch, total_centimeter, inter_cm; // variables for converting feet to meters

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	do{
		system("CLS");
		cout << "MENU" << endl;
		cout << "#1. CONVERT WEIGHTS" << endl;
		cout << "#2. CONVERT  LENGTHS" << endl;

		cout << "CHOICE--> ";
		cin >> choice_one;
		
		if(choice_one == 1){
			//convert weights
			convert_weight_menu(kilograms, grams, inter_ounce, pounds, ounces, inter_gram);
		}
		else if(choice_one == 2){
			//converts lengths
			convert_length_menu(meter, centimeter, results_inch, total_inch, feet_to_cm, feet, inch, 
									total_centimeter, inter_cm);
		}
		else{
			cout << "Invalid Choice!" << endl;
		}
				
		cout << "Again?(Y/N)" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}

//display menu for weight conversions
void convert_weight_menu(double &kilograms, double &grams, double &inter_ounce, double &pounds, double &ounces, 
							double &inter_gram)
{
	int choice;

	cout << "#1. KILOGRAMS/GRAMS TO POUNDS/OUNCES" << endl;
	cout << "#2. POUNDS/OUNCES TO KILOGRAMS/GRAMS" << endl;
	cin >> choice;

	if(choice == 1){
			//convert kilograms to pounds
			convert_metric_weight(kilograms, grams, inter_ounce);
		}
		else if(choice == 2){
			//convert pounds to kilograms
			convert_imperial_weight(pounds, ounces, inter_gram);
		}
		else{
			cout << "Invalid Choice!" << endl;
		}
	
	return ;
}

//display menu for length conversions
void convert_length_menu(double &meter, double &centimeter, double &results_inch, double &total_inch, double &feet_to_cm,
							double &feet, double &inch, double &total_centimeter, double &inter_cm)
{
	int choice;

	cout << "#1. METERS/CENTIMETERS TO FEET/INCHES" << endl;
	cout << "#2. FEET/INCHES TO METERS/CENTIMETERS" << endl;
	cin >> choice;
	
	if(choice == 1){
		//convert meters to feet
		convert_metric_length(meter, centimeter, results_inch, total_inch, feet_to_cm);
	}
	else if(choice == 2){
		//convert feet to meters
		convert_imperial_length(feet, inch, total_centimeter, inter_cm);
	}
	else{
		cout << "Invalid Choice!" << endl;
	}
		
	return;
}

//convert from imperial weight measurement to metric weight measurement
double convert_imperial_weight(double &pounds, double &ounces, double &inter_gram)
{
    input_imperial_weight(pounds, ounces);
		
	inter_gram = calc_gram(pounds, ounces);

	output_imperial_weight(pounds, ounces, inter_gram);	
    
    return 0;
}

//convert from metric weight measurement to imperial weight measurement
double convert_metric_weight(double &kilograms, double &grams, double &inter_ounce)
{
    input_metric_weight(kilograms, grams);
		
	inter_ounce = calc_ounce(kilograms, grams);

	output_metric_weight(kilograms, grams, inter_ounce);	
    
    return 0;
}

//enable user to input imperial weight measurements
void input_imperial_weight(double &pounds, double &ounces)
{
	system("CLS");
	cout << "POUNDS--> ";
	cin >> pounds;
	cout << "OUNCES--> ";
	cin >> ounces;
}

//output results of conversion of imperial weights to metric weights
void output_imperial_weight(double &pounds, double &ounces, double &inter_gram)
{
	system("CLS");
	cout << "POUNDS: " << pounds << endl;
	cout << "OUNCES: " << ounces << endl;
	cout << "--------------------" << endl;
	cout << "KILOGRAMS: " << calc_kg(inter_gram) << endl;
	cout << "GRAMS: " << fmod(calc_gram(pounds, ounces), 100) << endl; 
}

//convert pounds and ounces to total grams
double calc_gram(double &pounds, double &ounces)
{
    double total_ounce = (pounds * 16) + ounces;
    double total_gram = total_ounce * 28.34952;
    
	return total_gram;
}

//convert grams to whole kilograms
double calc_kg(double &inter_gram)
{
	double leftover_gram = inter_gram - fmod(inter_gram, 1000);
	double final_kg = leftover_gram/1000;

	return final_kg;
}

//enable user to input metric weight measurements
void input_metric_weight(double &kilograms, double &grams)
{
	system("CLS");
	cout << "KILOGRAMS--> ";
	cin >> kilograms;
	cout << "GRAMS--> ";
	cin >> grams;
}

//output results of conversion of metric weights to imperial weights
void output_metric_weight(double &kilograms, double &grams, double &inter_ounce)
{
	system("CLS");
	cout << "KILOGRAMS: " << kilograms << endl;
	cout << "GRAMS: " << grams << endl;
	cout << "--------------------" << endl;
	cout << "POUNDS: " << calc_pounds(inter_ounce) << endl;
	cout << "OUNCES: " << fmod(calc_ounce(kilograms, grams), 16) << endl; 
}

//convert kilograms and grams to total ounces
double calc_ounce(double &kilogram, double &gram)
{
    double total_gram = (kilogram * 1000) + gram;
    double total_ounce = total_gram * 0.035274;
    
	return total_ounce;
}

//convert ounces to whole pounds
double calc_pounds(double &inter_ounce)
{
	double leftover_ounce = inter_ounce - fmod(inter_ounce, 16);
	double final_pound = leftover_ounce/16;

	return final_pound;
}

//enable user to input metric length measurements
void input_metric_length(double &meter, double &centimeter)
{
	system("CLS");
	cout << "METER--> ";
	cin >> meter;
	cout << "CENTIMETER--> ";
	cin >> centimeter;
}

//function to output results of conversion of metric lengths to imperial lengths
void output_metric_length(double &meter, double &centimeter, double &results_inch, double& total_inch, double &feet_to_cm)
{
	system("CLS");
	cout << "METER: " << meter << endl;
	cout << "CENTIMETER: " << centimeter << endl;
	cout << "------------------------------" << endl;
	cout << "FEET: " << calc_foot(results_inch) << endl;
	cout << "INCH: " << calc_inches_leftover(results_inch) << endl;
}

//convert meters and centimeters to total inches
double calc_inch(double &meter, double &centimeter)
{
   double inch_from_cm = centimeter * 0.3937007874;
   double inch_from_meter = (meter * 100) * 0.3937007874;
   double total_inch = inch_from_cm + inch_from_meter;
  
   return total_inch;
}

//return whole number of feet
double calc_foot(double &results_inch)
{
	double feet = results_inch/12;
	
	int number = (int)feet;

    return number;
}

//return inches left over after returning whole number feet
double calc_inches_leftover(double &results_inch)
{
    double leftover_inches = results_inch - (calc_foot(results_inch) * 12);

	return leftover_inches;
}

//convert metric lengths to imperial lengths
double convert_metric_length(double &meter, double &centimeter, double &results_inch, double &total_inch, double &feet_to_cm)
{
    //double meter, centimeter, total_inch, feet;
    
    input_metric_length(meter, centimeter);
	results_inch = calc_inch(meter, centimeter);
	output_metric_length(meter, centimeter, results_inch, total_inch, feet_to_cm);
    
    return 0;
}

//enable user to input imperial length measurements
void input_imperial_length(double &feet, double &inch)
{
	system("CLS");
	cout << "FEET--> ";
	cin >> feet;
	cout << "INCHES--> ";
	cin >> inch;
}

//output results of conversion of imperial lengths to metric lengths
void output_imperial_length(double &feet, double &inch, double &inter_cm)
{
	cout << "FEET: " << feet << endl;
	cout << "INCHES: " << inch << endl;
	cout << "--------------------" << endl;
	cout << "METERS: " << calc_meter(inter_cm) << endl;
	cout << "CENTIMETERS: " << fmod(calc_cm(feet, inch), 100) << endl;
}

//convert feet and inches to total centimeters
double calc_cm(double &feet, double &inch)
{
    double total_inch = (feet * 12) + inch;
    double total_centimeter = total_inch * 2.54;
    
	return total_centimeter;
}

//return whole number of meters
double calc_meter(double &inter_cm)
{
	double leftover_cm = inter_cm - fmod(inter_cm, 100);
	double final_meter = leftover_cm/100;

	return final_meter;
}

//convert imperial lengths to metric lengths
double convert_imperial_length(double &feet, double &inch, double &total_centimeter, double &inter_cm)
{
    input_imperial_length(feet, inch);
	
	inter_cm = calc_cm(feet, inch);

	output_imperial_length(feet, inch, inter_cm);	
    
    return 0;
}
