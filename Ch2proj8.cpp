//Problem Solving With C++ - Walter Savitch
//Chapter 2
//Programming Project #8
//This program calculates the months required to pay off a 
//$1000.00 loan.

#include <iostream>
#include <conio.h>


const double mnth_pmnt = 50.00;

using namespace::std;

int main()
{
	int term = 0;
	double loan_amt = 1000.00;
	double interest_paid = 0.00;
	
	cout << "This program calculates the months required to pay off a $1000\n"
		 << "loan at 18% interest per year and payments of $50 per month.\n";
	cout << "Press any key to begin...\n";
	getch();

	//sets decimal places of type double to two
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "REMAINING BALANCE AFTER EACH PAYMENT\n";
	while(loan_amt > 0.00){
		interest_paid += loan_amt * 0.015;
		loan_amt += (loan_amt * 0.015) - mnth_pmnt;
		term++;
		cout << "$" << loan_amt << endl;
	}
	
	cout << "Interest Paid: $" << interest_paid << endl;
	cout << "It will take " << term << " months to pay of a $1000.00 loan at 18% interest.\n";

	cout << "Press any key to escape...\n";
	getch();
}