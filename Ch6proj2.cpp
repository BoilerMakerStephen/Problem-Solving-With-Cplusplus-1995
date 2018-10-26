//Problem Solving With C++ - Walter Savitch
//Chapter 6
//Programming Project #2
//Test of bank account using class CDAccount.

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

//class for a bank account
class CDAccount
{
public:
	CDAccount(int dollars, int cents, double rate, int term);
	//Initializes bank account to $dollars.cents and
	//initializes the interest rate to rate percent.
	CDAccount(int dollars, double rate, int term);
	//Initializes bank account to $dollars.00 and 
	//initializes the interest rate to rate percent.
	CDAccount();
	//Initializes bank account to $0.00 and 
	//initializes the interest rate to 0.0%.
	void initialBalance(ofstream& fout);
	//Returns the initial balance.
	void maturityBalance(ofstream& fout);
	//Returns the balance at maturity.
	double interestRate();
	//Returns the interest rate.
	int accountTerm();
	//Returns the term.
	void closeFile(ofstream& fout);
	//Postcondition: Output file has been created and
	//fin has been connected.
private:
	int dollars_part;
	int cents_part;
	double interest_rate;
	int maturity_term;//months until maturity;
};

int main()
{
	CDAccount account(200, 0, 2.2, 11);
	ofstream fout;

	account.closeFile(fout);
		
	account.initialBalance(fout);
	account.maturityBalance(fout);

	fout.close();

	cout << "Data has been printed to the output file." << endl;
	cout << "Press any key to continue...";
	getch();
}

CDAccount::CDAccount(int dollars, int cents, double rate, int term)
{
	dollars_part = dollars;
	cents_part = cents;
	interest_rate = rate;
	maturity_term = term;
}

CDAccount::CDAccount(int dollars, double rate, int term)
{
	dollars_part = dollars;
	cents_part = 0;
	interest_rate = rate;
	maturity_term = term;
}

CDAccount::CDAccount()
{
	dollars_part = 0;
	cents_part = 0;
	interest_rate = 0;
	maturity_term = 0;
}

void CDAccount::initialBalance(ofstream& fout)
{
	double initBalance = dollars_part + 0.01 * cents_part;
	
	fout << "Account initialized as follows:\n";
	fout << "Account balance $" << initBalance << endl;
	fout << "Account interest rate " << interestRate() << "%" << endl;
	fout << "Account term " << accountTerm() << " months" << endl;
	fout << "*******************************" << endl;
}

void CDAccount::maturityBalance(ofstream& fout)
{
	double initBalance = dollars_part + 0.01 * cents_part;
	double matBalance = initBalance + initBalance * interestRate() * 0.01 * accountTerm();
	
	fout << "Account updated as follows:\n";
	fout << "Account balance $" << matBalance << endl;
	fout << "*******************************" << endl;
}

double CDAccount::interestRate()
{
	return(interest_rate);
}

int CDAccount::accountTerm()
{
	return(maturity_term);
}

void CDAccount::closeFile(ofstream& fout)
{
	char outfileName[25];

	cout << "Enter the output file name(25 characters max): " << endl;
	cin >> outfileName;
	
	fout.open(outfileName);
	if(fout.fail()){
		cout << "Output file opening failed";
		exit(1);
	}
}

