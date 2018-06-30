//Problem Solving With C++ - Walter Savitch
//Chapter 3
//Programming Project #5
//Calculates the amount of total interest paid over a predefined
//term on a credit card balance

#include <iostream>
#include <conio.h>

double calc_int(double principal, double rate, int term);

using namespace std;

int main()
{
	char ans;
	double principal, rate;
	int term;

	cout << "This program is designed to calculate the amount of total interest " << endl;
	cout << "paid over a predefined term on a credit card balance." << endl;
	cout << endl;
	cout << "Press any key to continue..." << endl;
	getch();

	do{
		system("cls");
		cout << "Please enter the principal amount of the credit card balance." << endl;
		cin >> principal;
		cout << "Please enter the interest rate as decimal." << endl;
		cin >> rate;
		cout << "Please enter the term in months." << endl;
		cin >> term;

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		double new_amt = calc_int(principal, rate, term);

		double difference = new_amt - principal;

		cout << "The amount of interest accrued over " << term << " months is $" << difference << endl;
		cout << endl;
		cout << "Would you like to calculate another amount? (Y/N)" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');

	system("cls");
	cout << "Goodbye!" << endl;
	cout << endl;
	cout << "Press any key to escape..." << endl;
	getch();
}

double calc_int(double principal, double rate, int term)
{
	int i = 1;
	double inter_amt, new_amt;

	while(i <= term)
	{
		inter_amt = principal * rate;
		principal = inter_amt + principal;
		i++;
	}

	new_amt = principal;

	return(new_amt);
}

