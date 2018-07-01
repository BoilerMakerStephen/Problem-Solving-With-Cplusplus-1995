//Problem Solving With C++ - Walter Savitch
//Chapter 3
//Programming Project #7
//This program is designed to calculate the annual after-tax cost of a new home

#include<iostream>
#include<conio.h>

using namespace::std;

const double rate=0.08, annual_cost=0.03, tax_savings=0.35;

double interest_cost(double init_cost, double down_payment);
double principal_cost(double init_cost, double down_payment);

int main()
{
	char ans;
	double init_cost, down_payment;

	cout << "This program computes the annual after-tax cost of a new home" << endl;
	cout << endl;
	cout << "for the first year of ownership." << endl;
	cout << endl;
	cout << "Press any key to continue..." << endl;

	getch();

	do{
		system("cls");
		cout << "Please enter the initial cost of your new home." << endl;
		cin >> init_cost;
		cout << endl;
		cout << "Please enter the down payment amount." << endl;
		cout << endl;
		cin >> down_payment;
		cout << endl;

		double rate_cost = interest_cost(init_cost, down_payment);

		double annual_int = principal_cost(init_cost, down_payment);

		double marginal_rate = rate_cost * tax_savings; //0.35

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "The interest cost of your loan for the first year is $" << rate_cost << "." << endl;
		cout << endl;
		cout << "The principal cost of your loan for the first year is $" << annual_int << "." << endl;
		cout << endl;
		cout << "The marginal tax savings on your loan for the first year is $" << marginal_rate << "." << endl;
		cout << endl;

		double final_cost = (rate_cost + annual_int) - marginal_rate;

		cout << "The total annual cost of your loan for the first year is $" << final_cost << "." << endl;
		cout << endl;
		cout << "Would you like to perform another loan calculation? Y/N." << endl;
		cin >> ans;

	}while(ans=='Y'||ans=='y');

	system("cls");

	cout << "Goodbye!" << endl;
	cout << endl;
	cout << "Press any key to continue..." << endl;
	getch();
}

double interest_cost(double init_cost, double down_payment)
{
	
	double final_loan = init_cost - down_payment;

	double rate_cost = final_loan * rate; //0.08

	return(rate_cost);
}

double principal_cost(double init_cost, double down_payment)
{
	double final_loan = init_cost - down_payment;

	double annual_int = final_loan * annual_cost; //0.03

	return(annual_int);
}