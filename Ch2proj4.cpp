//Problem Solving With C++ - Walter Savitch
//Chapter 2
//Programming Project #4
//This program calculates the face value required on a discount 
//installment loan to provide the consumer with the amount needed.

#include <iostream>
#include <math.h>

using namespace::std;

int main()
{
	char ans;
	double loan_amt, int_rate, pmnt, monthly_rate, num, denom;
	int duration;

	do{
		cout << "Enter the amount the consumer needs to receive: \n";
		cin >> loan_amt;
		cout << "Enter the interest rate as a decimal: \n";
		cin >> int_rate;
		cout << "Enter the duration of the loan in months: \n";
		cin >> duration;
		
		monthly_rate = int_rate/12;

		//Calculation done by solving for the numerator then the denominator
		//then using those variables to solve for the payment.
		denom = pow((1 + monthly_rate), duration) - 1;						 
		num = loan_amt * (monthly_rate * pow((1 + monthly_rate), duration));
		pmnt = num/denom;
		
		//sets decimal places of type double to two
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "Loan Payment: $" << pmnt << endl;

		cout << "Would you like to calculate another consumer loan?(Y/N)\n";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}

