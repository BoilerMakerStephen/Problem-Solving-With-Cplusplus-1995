//Problem Solving With C++ - Walter Savitch
//Chapter 2
//Programming Project #1
//This program reads the weight of a package of breakfast cereal in ounces and 
//and outputs the weight in metrics tons. The program also calculates the amount
//of boxes required to contain 1 metric ton per box.

#include <iostream>

const double metric_ton = 35273.92; //in ounces

using namespace::std;

int main()
{
	double oats, fin_amt, box;
	char ans;

	do{
	cout << "Enter the weight of a box of cereal oats in ounces you wish"
		 << " to convert to metric tons:\n";
	cin >> oats;

	fin_amt = oats/metric_ton;

	cout << oats << " ounces of oats converts to " << fin_amt << " metric tons of cereal oats.\n";

	box = metric_ton/oats;

	cout << "It would take " << box << " boxes of cereal oats to yield one metric ton.\n";

	cout << "Do you wish to perform another calculation?\n";
	cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}

