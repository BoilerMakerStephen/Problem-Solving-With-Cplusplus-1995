//Problem Solving With C++ - Walter Savitch
//Chapter 3
//Programming Project #2
//Calculates the value of one share holding

#include <iostream>
#include <conio.h>

using namespace std;

double share_price(int whole_price, int num, int denom);

int main()
{
	char ticker[4], ans;
	int number, whole_price, num, denom;
	double holdings, price;

	do{
		system("cls");
		cout << "Enter the ticker symbol of the stock you own." << endl;
		cin >> ticker;
		cout << "Enter the number of shares " << ticker << " you own." << endl;
		cin >> number;
		cout << "Enter the price of the stock.\n";
		cout << "The whole number price should be entered first\n";
		cout << "and if there is a fractional share the numerator\n";
		cout << "should first be entered followed by the denominator.\n";
		cout << "Enter the whole number price now:\n";
		cin >> whole_price;
		cout << "Enter the numerator now\n";
		cin >> num;
		cout << "Enter the denominator now\n";
		cin >> denom;

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		price = share_price(whole_price, num, denom);
		holdings = number * price;

		cout << "The price per share of " << ticker << " is $" << price << endl;
		cout << "The value of your holdings in " << ticker << " is $" << holdings << endl;
		cout << "Would you like to evaluate another position? (Y/N)" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');

	cout << "Goodbye!" << endl;
	cout << "Press any key to escape..." << endl;
	getch();
}

double share_price(int whole_price, int num, int denom)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	float fraction = (float)num/(float)denom;
	return(whole_price + fraction);
}