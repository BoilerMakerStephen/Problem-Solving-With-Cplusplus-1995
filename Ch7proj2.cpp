//Problem Solving With C++ - Walter Savitch
//Chapter 7
//Programming Project #2
//This program computes the interest due,total amount due, and the minimum 
//payment for a revolving credit account.

#include <iostream>
#include <conio.h>

using namespace std;

void introduction();

double calc_int(double acct_bal);

int main()
{
	char ans;
	double acct_bal;

	introduction();
	
	do{
		cout << "Enter the account balance: \n";
		cin >> acct_bal;

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "The payment is $" << calc_int(acct_bal) << endl;
	
		cout << "Do you want to perform another calculation?(Y/N)\n";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');

	cout << endl;

	cout << "Press any key to escape...";
	getch();
}

void introduction()
{
	cout << "This program computes the interest due, total amount due,\n"
		 << "and the minimum payment for a revolving credit account.\n" << endl;
	cout <<endl;
	cout << "INTEREST RATE SCHEDULE\n"
		 << "*1.5% <= $1000.00\n"
		 << "*Additional 1% on any amount over $1000.00\n" << endl;
    cout << "MINIMUM PAYMENT SCHEDULE\n"
		 << "*Balance <= $10.00 Payment due is total balance\n"
		 << "*Balance > $10.00 Payment due is 10% of total balance" << endl;
	cout << endl;
}

double calc_int(double acct_bal)
{
	double pmnt, month_pmnt;

	if(acct_bal <= 1000.00){
		pmnt = acct_bal * 1.015;
	}
	else{
		pmnt = acct_bal * 0.10;
	}

	if(pmnt <= 10.00){
		return pmnt;
	}
	else{
		month_pmnt = pmnt * 1.10;
	}
	return month_pmnt;
}