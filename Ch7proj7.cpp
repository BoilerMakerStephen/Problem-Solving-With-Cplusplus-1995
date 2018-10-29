//Problem Solving With C++ - Walter Savitch
//Chapter 7
//Programming Project #7
//This is a stub to calculate interest payments for an Ammortization table.

#include <iostream>
#include <conio.h>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double principal; //initial balance of loan
	double rate; //interest rate of loan
	double monthly_payment; //monthly payment of loan
	double periodic_rate; //monthly interest rate
	double term_int_pmnt; //interest paid on loan per term
	double principal_pmnt; //principal paid on loan per term
	double total_int = 0; //total interest paid on loan
	int term; //term of the loan
	
	cout << setw(60);
	cout << "AMMORTIZATION TABLE" << endl;
	cout << "Enter Principal: ";
	cin >> principal;
	cout << "Enter rate: ";
	cin >> rate;
	cout << "Enter term: ";
	cin >> term;

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
		
	periodic_rate = ((rate)/12.0) * 0.01;
		
	monthly_payment = principal * (periodic_rate * (pow((1+periodic_rate), term))/(pow((1 + periodic_rate), term) - 1));
	
	cout << endl;
	cout << "Principal: $" << principal << endl;
	cout << "Rate: " << rate << "%" << endl;
	cout << "Term: " << term << endl;
	cout << "Monthly Payment: $" << monthly_payment << endl;
	cout << "Periodic Rate: " << periodic_rate << "%" << endl;
	cout <<endl;

	double new_amount = principal;
	for(int i = 1; i <= term; i++){
		term_int_pmnt = new_amount * periodic_rate;
		principal_pmnt  = monthly_payment - term_int_pmnt;
		new_amount = new_amount - principal_pmnt;
		
		cout << setfill('-') << setw(100) << endl;
		cout << " " << endl;
		cout << "Period " << i <<endl;
		cout << "Amount Owing: " << new_amount << endl;
		cout << "Principal Payment: " << principal_pmnt << endl;
		cout << "Interest Payment: " << term_int_pmnt << endl;
		
		total_int = term_int_pmnt + total_int;
		
	}
	cout << endl;
	cout << "Total Interest Paid: " << total_int <<endl;
	cout <<endl;
	cout << "Press any key to quit..." <<endl;
	getch();
}

