//Problem Solving With C++ - Walter Savitch
//Chapter 2
//Programming Project #2
//This program calculates the lethal dose of artificial sweetener to mice.
//This amount is then correlated to the lethal dose in a specific human dieter.

#include <iostream>

const double diet_soda = 0.001; //Percent of diet soda that is artificial sweetener
const double pound = 0.00220462; // grams to pounds

using namespace::std;

int main()
{
	char ans;
	double lethal_dose, mouse_weight, dieter_weight_current, desired_weight,
		mouse_weight_pounds, mouse_lethal_current, lethal_dose_current, lethal_dose_desired;

	//sets decimal places of type double to four
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);

	do{
		cout << "Enter the lethal dose of artificial sweetener, as a percentage\n"
			 << "of a can of soda, needed to kill a mouse:\n";
		cin >> lethal_dose;
		cout << "Enter the weight of the mouse in grams:\n";
		cin >> mouse_weight;
		cout << "Enter the current weight of the dieter:\n";
		cin >> dieter_weight_current;
		cout << "Enter the desired weight of the dieter:\n";
		cin >> desired_weight;

		mouse_weight_pounds = mouse_weight * pound;

		mouse_lethal_current = lethal_dose/diet_soda;

		lethal_dose_current = dieter_weight_current/mouse_weight_pounds;

		lethal_dose_desired = desired_weight/mouse_weight_pounds;


		cout << "Mouse weight in pounds: " << mouse_weight_pounds << endl;
		cout << "Dieter's current weight in pounds: " << dieter_weight_current << endl;
		cout << "Dieter's desired weight in pounds: " << desired_weight << endl;
		cout << "Number of soda cans required to kill mouse: " << mouse_lethal_current << endl;
		cout << "Numbere of soda cans required to kill " << dieter_weight_current << " pound human: " 
			 << lethal_dose_current << endl;
		cout << "Number of soda cans required to kill " << desired_weight << " pound human: "
			 << lethal_dose_desired << endl;

		cout << "Do you wish to perform another calculation? (Y/N)\n";
		cin >> ans;

	}while(ans == 'Y' || ans == 'y');
}