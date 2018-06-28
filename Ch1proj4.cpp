//Problem Solving With C++ - Walter Savitch
//Chapter 1
//Programming Project #4

#include <iostream>
#include <conio.h>

using namespace::std;

int main()
{
	int sum, product, first_num, second_num;

	cout << "This program sums/multiplies two numbers\n";
	cout << "Press return after entering a number.\n";
	cout << "Enter the first number:\n";
	cin >> first_num;
	cout << "Enter the second number:\n";
	cin >> second_num;

	sum = first_num + second_num;
	product = first_num * second_num;

	cout << "The two numbers added together are: " << sum << "\n";
	cout << "The two numbers multiplied together are: " << product << "\n";
		
	cout << "Press any key to eascape...";
	getch();
}