//Problem Solving With C++ - Walter Savitch
//Chapter 4
//Programming Project #6
//This program will convert from meters/centimeters to feet/inches or 
//vice versa.

#include <iostream>
#include <conio.h>
#include <cmath>

using namespace::std;

double convert_metric(double &meter, double &centimeter, double &results_inch, double &total_inch, double &feet_to_cm);
//Precondition: The convert_metric function has been called.
//Postcondition: All associated functions have been called and the results of the conversions
//have been output to the screen.

double convert_imperial(double &feet, double &inch, double &total_centimeter, double &inter_cm);
//Precondition: The convert_metric function has been called.
//Postcondition: All associated functions have been called and the results of the conversions
//have been output to the screen.

void input_metric(double &meter, double &centimeter);
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

void input_imperial(double &feet, double &inch);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the required data.

void output_imperial(double &feet, double &inch, double &total_centimeter);
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
	int choice;
	double meter, centimeter, results_inch, total_inch, feet_to_cm; //variables for convert metric to imperial
	double feet, inch, total_centimeter, final_meter, inter_cm; //variables for convert imperial to metric

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "MENU" << endl;
	cout << "#1. CONVERT FEET/INCHES TO METERS/CENTIMETERS" << endl;
	cout << "#2. CONVERT METERS/CENTIMETERS TO FEET/INCHES" << endl;
	
	
	do{
		cout << "CHOICE--> ";
		cin >> choice;
		
		if(choice == 1){
				convert_imperial(feet, inch, total_centimeter, inter_cm);
			}
			else if(choice == 2){
				convert_metric(meter, centimeter, results_inch, total_inch, feet_to_cm);
			}
			else{
				cout << "Invalid Choice!" << endl;
			}
			
		cout << "Again?" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}

//convert to imperial
void input_metric(double &meter, double &centimeter)
{
	cout << "METER--> ";
	cin >> meter;
	cout << "CENTIMETER--> ";
	cin >> centimeter;
}

//convert to imperial
void output_metric(double &meter, double &centimeter, double &results_inch, double& total_inch, double &feet_to_cm)
{
	cout << "------------------------------" << endl;
	cout << "FEET: " << calc_foot(results_inch) << endl;
	cout << "INCH: " << calc_inches_leftover(results_inch) << endl;
}

//convert to imperial
double calc_inch(double &meter, double &centimeter)
{
   double inch_from_cm = centimeter * 0.3937007874;
   double inch_from_meter = (meter * 100) * 0.3937007874;
   double total_inch = inch_from_cm + inch_from_meter;
  
   return total_inch;
}

//convert to imperial
double calc_foot(double &results_inch)
{
	double feet = results_inch/12;
	
	int number = (int)feet;

    return number;
}

//convert to imperial
double calc_inches_leftover(double &results_inch)
{
    double leftover_inches = results_inch - (calc_foot(results_inch) * 12);

	return leftover_inches;
}

//convert to imperial
double convert_metric(double &meter, double &centimeter, double &results_inch, double &total_inch, double &feet_to_cm)
{
    //double meter, centimeter, total_inch, feet;
    
    input_metric(meter, centimeter);
	results_inch = calc_inch(meter, centimeter);
	output_metric(meter, centimeter, results_inch, total_inch, feet_to_cm);
    
    return 0;
}

//convert to metric
void input_imperial(double &feet, double &inch)
{
	cout << "FEET--> ";
	cin >> feet;
	cout << "INCHES--> ";
	cin >> inch;
}

//convert to metric
void output_imperial(double &feet, double &inch, double &inter_cm)
{
	cout << "FEET: " << feet << endl;
	cout << "INCHES: " << inch << endl;
	cout << "--------------------" << endl;
	cout << "METERS: " << calc_meter(inter_cm) << endl;
	cout << "CENTIMETERS: " << fmod(calc_cm(feet, inch), 100) << endl;
}

//convert to metric
double calc_cm(double &feet, double &inch)
{
    double total_inch = (feet * 12) + inch;
    double total_centimeter = total_inch * 2.54;
    
	return total_centimeter;
}

//convert to metric
double calc_meter(double &inter_cm)
{
	double leftover_cm = inter_cm - fmod(inter_cm, 100);
	double final_meter = leftover_cm/100;

	return final_meter;
}

//convert to metric
double convert_imperial(double &feet, double &inch, double &total_centimeter, double &inter_cm)
{
    input_imperial(feet, inch);
	
	inter_cm = calc_cm(feet, inch);

	output_imperial(feet, inch, inter_cm);	
    
    return 0;
}


