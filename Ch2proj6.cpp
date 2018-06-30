//Problem Solving With C++ - Walter Savitch
//Chapter 2
//Programming Project #6
//This program reads the number of hours worked in a week and the 
//number of dependents of an employee. The program will then output
//gross pay, each withholding amount and the net take-home pay for 
//the week.

#include <iostream>

const double wage = 16.78;
const double union_dues = 10.00;

using namespace::std;

int main()
{
	char ans;
	double hours_worked, gross_pay, soc_sec, fed_tax, health_ins, net_pay;
	int dependents;

	do{
		cout << "Enter the hours worked: \n";
		cin >> hours_worked;
		cout << "Enter number of dependents: \n";
		cin >> dependents;

		gross_pay = hours_worked * wage;
		soc_sec = gross_pay * 0.06;
		fed_tax = gross_pay * 0.14;
		
		if(dependents >= 3){
			health_ins = 35.00;
			net_pay = gross_pay - soc_sec - fed_tax - union_dues - health_ins;
		}
		else
		{
			health_ins = 0.00;
			net_pay = gross_pay - soc_sec - fed_tax - union_dues;
		}

		//sets decimal places of type double to two
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		
		cout << "Gross Pay $" << gross_pay << endl;
		cout << "Social Security: $" << soc_sec << endl;
		cout << "Federal Income Tax: $" << fed_tax << endl;
		cout << "Union Dues: $" << union_dues << endl;
 		cout << "Health Insuarance: $" << health_ins << endl;
		cout << "Net Pay: $" << net_pay << endl;

		cout << "Do you wish to perform another calculation?(Y/N)\n";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}