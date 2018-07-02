//Problem Solving With C++ - Walter Savitch
//Chapter 4
//Programming Project #1
//This program converts from 24 hour notation to 12 hour notation

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace::std;

void input(int& hour, int& minute, char& input_3);
//Precondition: User is ready to enter data correctly.
//Postcondition: The input values have been set.

void convert(int& hour, int& minute, char& input_3);
//Postcondition: Input values have been converted.

void output(int& hour, int& minute, char& input_3);
//Postcondition: Converted values are printed to the screen.


int main()
{
	int hour = 0;
	int minute = 0;
	char meridian;
	char ans;
	
	system("cls");
	cout << "This program converts from 24 hour notation " << endl;
	cout << endl;
	cout << "to 12 hour notation." << endl;
	cout << endl;
	cout << "Press any key to continue..." << endl;

getch();

	do{
		system("cls");

		input(hour, minute, meridian);
		convert(hour, minute, meridian);
		output(hour, minute, meridian);

		cout << "Would you like to do another conversion 'Y'/'N'" << endl;
		cin >> ans;
	}while(ans=='Y'||ans=='y');

	system("cls");
	cout << "Good bye!" << endl;
	cout << endl;
	cout << "Press any key to continue..." << endl;

	getch();
}

void input(int& hour, int& minute, char& input_3)
{
	cout << "Please enter the time you wish to convert in 24 hour notation." << endl;
	cout << endl;
	cout << "Enter the hour." << endl;
	cin >> hour;
	cout << "Enter the minutes." << endl;
	cin >> minute;
	cout << "Enter 'A' for AM or 'P' for PM." << endl;
	cin >> input_3;
}

void convert(int& hour, int& minute, char& input_3)
{
	if((input_3 == 'P') && (hour > 12)){
		hour = hour - 12;
	}

	return;
}

void output(int& hour, int& minute, char& input_3)
{
	
	if(minute == 0){
		cout << "The converted time is " << hour << ":" << setfill('0') << setw(2) << minute << input_3 << "." << endl;
		cout << endl;
	}
	else{
		cout << "The converted time is " << hour << ":" << minute << input_3 << "." << endl;
		cout << endl;
	}
}