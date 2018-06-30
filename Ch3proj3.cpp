//Problem Solving With C++ - Walter Savitch
//Chapter 3
//Programming Project #3
//Calculates the rate of inflation for one year for one item.

#include <iostream>
#include <conio.h>

double function(double pastPrice, double presentPrice);

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

		cout << "The current rate of inflation for one " << item << " is " << rate << "%" << endl;
		cout << endl;
		cout << "Would you like to calculate another item? (Y/N)\n";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');

	system("cls");
	cout << "Goodbye!" << endl; 
	cout << "Press any key to continue...\n";
	getch();
}

double function(double pastPrice, double presentPrice)
{
	return((presentPrice - pastPrice)/pastPrice);
}