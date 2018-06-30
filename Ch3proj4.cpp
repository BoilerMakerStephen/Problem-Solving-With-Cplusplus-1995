//Problem Solving With C++ - Walter Savitch
//Chapter 3
//Programming Project #4
//Calculates the rate of inflation for one item,
//then calculates the price for the next two years.

#include <iostream>
#include <conio.h>

double function(double pastPrice, double presentPrice);
double function_1(double presentPrice, double rate);

using namespace std;

int main()
{
	char item[100], ans;
	double pastPrice, presentPrice;

	do{
		system("cls");
		cout << "Enter the name of the item for which you would like to calculate\n";
		cout << "the rate of inflation - do not use spaces.\n";
		cin >> item;
		cout << "Enter the price of one " << item << " one year ago.\n";
		cin >> pastPrice;
		cout << "Enter the price of one " << item << " today.\n";
		cin >> presentPrice;

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		double rate = function(pastPrice, presentPrice) * 100;
		double new_rate = (rate * 0.01) + 1;
		double cost_1 = function_1(presentPrice, new_rate);
		double cost_2 = cost_1 * new_rate;

		cout << "The current rate of inflation for one " << item << " is " << rate << "%." << endl;
		cout << endl;
		cout << "The price of one " << item << " one year from now is $" << cost_1 << "." << endl;
		cout << endl;
		cout << "The price of one " << item << " two years from now is $" << cost_2 << "." << endl;
		cout << endl;
		cout << "Would you like calculate another item? (Y/N)\n";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');

	system("cls");
	cout << "Goodbye!" << endl;
	cout << "Press any key to quit...\n";
	getch();
}

double function(double pastPrice, double presentPrice)
{
	return((presentPrice - pastPrice)/pastPrice);
}

double function_1(double presentPrice, double new_rate)
{
	double cost_1 = presentPrice * new_rate;

	return(cost_1);
}