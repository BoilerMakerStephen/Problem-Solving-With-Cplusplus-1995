//Problem Solving With C++ - Walter Savitch
//Chapter 6
//Programming Project #7
///////////////////////////////////////////////////////////////
//Program to demonstrate class Month from Ch6proj5 reworked  //
//into Ch6proj7.                                             //
///////////////////////////////////////////////////////////////

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

class DayOfYear
{
public:
	DayOfYear(char firstLetter1, char secondLetter2, char thirdLetter3, int day1);
	//Initializes month according to arguments for first three letters.
	DayOfYear(int day1);
	//Constructor
	DayOfYear();
	//Constructor
	void input();
	//Precondition: User is prompted for input.
	//Postcondition: The first three letters of the current month and the current day have been entered.
	void output(ofstream& fout);
	//Returns month and day. 
	int get_month();
	//Returns the month, 1 for January, 2 for February, etc.
	int get_day();
	//Returns the day of the month.
	int letters_to_integer(char firstLetter, char secondLetter, char thirdLetter);
	//Precondition: First three letters of month have been input.
	//Postcondition: Month has been converted to integer.
	string integer_to_letters(int month_number);
	//Precondition: First three letters of month have been converted to an integer.
	//Postcondition: Integer has been converted to a month string. 
private:
	char firstLetter, secondLetter, thirdLetter;
	int day;
	int month_number;//Represents the month as an integer.
	string month_letters;//Represents the month in terms of it's first three letters.
};

void output_file(ofstream& fout);
//Sends output to a file.

int main()
{
	DayOfYear bach_birthday('m', 'a', 'r', 21), today;
	ofstream fout;

	output_file(fout);

	today.input();
	cout << "You have entered today's date as:" << endl;
	fout << "You have entered today's date as:" << endl;
	today.output(fout);
	
	cout << "J. S. Bach's birthday is " << endl;
	fout << "J. S. Bach's birthday is " << endl;
	bach_birthday.output(fout);


	if(today.get_month() == bach_birthday.get_month() &&
		today.get_day() == bach_birthday.get_day()){
		cout << "Happy Birthday Johann Sebastian!\n";
	    fout << "Happy Birthday Johann Sebastian!\n";
	}
	else{
		cout << "Happy Unbirthday Johann Sebastian!\n";
		fout << "Happy Unbirthday Johann Sebastian!\n";
	}

	cout << "Press any key to escape..." << endl;
	getch();

	return 0;
}

DayOfYear::DayOfYear(char firstLetter1, char secondLetter2, char thirdLetter3, int day1)
{
	firstLetter = firstLetter1;
	secondLetter = secondLetter2;
	thirdLetter = thirdLetter3;
	day = day1;
}

DayOfYear::DayOfYear(int day1)
{
	day = day1;
}

DayOfYear::DayOfYear()
{}

//Uses iostream
void DayOfYear::input()
{
	cout << "Enter the first three letters of the month" << endl;
	cin >> firstLetter >> secondLetter >> thirdLetter;
	cout << "Enter the day of the month: ";
	cin >> day;
}

void DayOfYear::output(ofstream& fout)
{
	cout << "month = " << firstLetter << secondLetter << thirdLetter << endl;
	fout << "month = " << firstLetter << secondLetter << thirdLetter << endl;
	cout << "day = " << day << endl;
	fout << "day = " << day << endl;
}

int DayOfYear::letters_to_integer(char firstLetter, char secondLetter, char thirdLetter)
{
	if((firstLetter == 'j') && (secondLetter == 'a') && (thirdLetter == 'n'))
		month_number = 1;
	if((firstLetter == 'f') && (secondLetter == 'e') && (thirdLetter == 'b'))
		month_number = 2;
	if((firstLetter == 'm') && (secondLetter == 'a') && (thirdLetter == 'r'))
		month_number = 3;
	if((firstLetter == 'a') && (secondLetter == 'p') && (thirdLetter == 'r'))
		month_number = 4;
	if((firstLetter == 'm') && (secondLetter == 'a') && (thirdLetter == 'y'))
		month_number = 5;
	if((firstLetter == 'j') && (secondLetter == 'u') && (thirdLetter == 'n'))
		month_number = 6;
	if((firstLetter == 'j') && (secondLetter == 'u') && (thirdLetter == 'l'))
		month_number = 7;
	if((firstLetter == 'a') && (secondLetter == 'u') && (thirdLetter == 'g'))
		month_number = 8;
	if((firstLetter == 's') && (secondLetter == 'e') && (thirdLetter == 'p'))
		month_number = 9;
	if((firstLetter == 'o') && (secondLetter == 'c') && (thirdLetter == 't'))
		month_number = 10;
	if((firstLetter == 'n') && (secondLetter == 'o') && (thirdLetter == 'v'))
		month_number = 11;
	if((firstLetter == 'd') && (secondLetter == 'e') && (thirdLetter == 'c'))
		month_number = 12;
	return month_number;
}

string DayOfYear::integer_to_letters(int month_number)
{
	string month_letters;

	switch(month_number)
	{
	case 1:
		month_letters = "Jan\n";
		break;
	case 2:
		month_letters = "Feb\n";
		break;
	case 3:
		month_letters = "Mar\n";
		break;
	case 4:
		month_letters = "Apr\n";
		break;
	case 5:
		month_letters = "May\n";
		break;
	case 6:
		month_letters = "Jun\n";
		break;
	case 7:
		month_letters = "Jul\n";
		break;
	case 8:
		month_letters = "Aug\n";
		break;
	case 9:
		month_letters = "Sep\n";
		break;
	case 10:
		month_letters = "Oct\n";
		break;
	case 11:
		month_letters = "Nov\n";
		break;
	case 12:
		month_letters = "Dec\n";
		break;
	default:
		cout << "Invalid integer for month";
		break;
	}
	return month_letters;
}

int DayOfYear::get_month()
{
	return month_number;
}

int DayOfYear::get_day()
{
	return day;
}

void output_file(ofstream& fout)
{
	char fileName[25];
	
	cout << "Enter the name of the output file(25 characters max)" << endl;
	cin >> fileName;

	fout.open(fileName);
	if(fout.fail()){
		cout << "Output file open failed" << endl;
		cout << "Press any key to escape..." << endl;
		getch();
	}
	
}


