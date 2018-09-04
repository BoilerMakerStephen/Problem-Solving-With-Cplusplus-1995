//Problem Solving With C++ - Walter Savitch
//Chapter 4
//Programming Project #5
//This program will read in a length in meters and centimeters and will output
//the equivalent length in feet and inches.

#include <iostream>
#include <conio.h>
#include <cmath>

using namespace::std;

void input(double &meter, double &centimeter);
//Precondition: The "input" function has been called.
//Postcondition: The user has entered the data for meter
//and centimeter.

void output(double &meter, double &centimeter, double &results_inch, double &total_inch, double &feet);
//Precondition: Meters and centimeters have been converted to feet and inches.
//Postcondition: The results of the conversions have been printed to the screen.

double calc_inch(double &meter, double &centimeter);
//Precondition: The user has input data for meter and centimeter.
//Postcondition: The data for meters and centimeters has been converted
//to inches.

double calc_foot(double &results_inch);
//Precondition: Meters and centimeters have been converted to inches and added together.
//Postcondition: Total inches have been converted to feet. The case of the variable 
//feet has been changed from type double to type int.

double calc_inches_leftover(double &results_inch);
//Precondition: The fraction part of feet exists.
//Postcondition: The fraction part of feet has been converted to leftover_inches.

int main()
{
	char ans;
    double meter, centimeter, total_inch, feet;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	do{

		input(meter, centimeter);
		double results_inch = calc_inch(meter, centimeter);
		output(meter, centimeter, results_inch, total_inch, feet);

		cout << "Again?" << endl;
		cin >> ans;
	
	}while(ans == 'Y' || ans == 'y');
}

void input(double &meter, double &centimeter)
{
	cout << "METER--> ";
	cin >> meter;
	cout << "CENTIMETER--> ";
	cin >> centimeter;
}

void output(double &meter, double &centimeter, double &results_inch, double& total_inch, double &feet)
{
	cout << "FEET: " << calc_foot(results_inch) << endl;
	cout << "INCH: " << calc_inches_leftover(results_inch) << endl;
}

double calc_inch(double &meter, double &centimeter)
{
   double inch_from_cm = centimeter * 0.3937007874;
   double inch_from_meter = (meter * 100) * 0.3937007874;
   double total_inch = inch_from_cm + inch_from_meter;
  
   return total_inch;
}

double calc_foot(double &results_inch)
{
	double feet = results_inch/12;
	
	int number = (int)feet;

    return number;
}

double calc_inches_leftover(double &results_inch)
{
    double leftover_inches = results_inch - (calc_foot(results_inch) * 12);

	return leftover_inches;
}
