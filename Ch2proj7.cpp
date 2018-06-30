//Problem Solving With C++ - Walter Savitch
//Chapter 2
//Programming Project #7
//This program calculates the rate of inflation on a specific item
//at a user defined rate and term.

#include <iostream>

using namespace::std;

int main()
{
	char ans;
	double cost, percent, rate;
	int term;

	do{
		cout << "Enter original cost of item: \n";
		cin >> cost;
		cout << "Enter the rate of inflation as a percentage: \n";
		cin >> percent;
		cout << "Enter the term in years: \n";
		cin >> term;

		rate = percent * 0.01;

		for(int i = 0; i <= term; i++){
			cost +=  cost * rate;
		}

		//sets decimal places of type double to two
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "The cost of the item in " << term << " year(s) will be $" << cost << endl; 
				
		cout << "Do you wish to perform another calculation?(Y/N)\n";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}

