//Problem Solving With C++ - Walter Savitch
//Chapter 2
//Programming Project #3
//This program calculates six months of retroactive pay after an
//employee raise.

#include <iostream>
#include <conio.h>

const double raise = 1.076; //amount of raise

using namespace::std;

int main()
{
	char ans;
	double annual_salary, new_salary, difference, retro_pay;
	
	do{
		cout << "Enter the amount of the employee's annual salary: \n";
		cin >> annual_salary;

		new_salary = annual_salary * raise;
		difference = new_salary - annual_salary;
		retro_pay = difference/2;

		//sets decimal places of type double to two
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << endl;
		cout << "Employee's original salary: $" << annual_salary << endl;
		cout << "Employee's new salary after applying 7.6% raise: $" << new_salary << endl;
		cout << "Retroactive pay due: $" << retro_pay << endl;

		cout << "Would you like to perform another calculation?(Y/N).\n";
		cin >> ans;

	}while(ans == 'Y' || ans == 'y');
}