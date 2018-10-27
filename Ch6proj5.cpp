//Problem Solving With C++ - Walter Savitch
//Chapter 6
//Programming Project #5
//Test of class Month which is an abstract data class for month

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>

using namespace std;

class Month
{
public:
	Month(char firstLetter, char secondLetter, char thirdLetter);
	//Initializes month according to arguments for first three letters
	Month(int month_number);
	//Initializes month according to argument for integer between 1 and 12
	Month();
	//Initializes month to January
	void input_integer();
	//Reads month as an integer
	void input_letter();
	//Reads month as first three letters in the name of the month
	int letters_to_integer(char firstLetter, char secondLetter, char thirdLetter);
	//Converts first three letters of the month to integer equivalent of the month
	string integer_to_letters(int month_number);
	//Converts month integer to the first three letters of the name of the month
	void output_integer();
	//Outputs the month as an integer
	void output_letter();
	//Outputs the month as first three letters of the name of the month
	void next_month();
	//Returns the next month in letters
private:
	int month_number; //Represents the month as an integer
	string month_letters; //Represents the month in terms of it's first three letters
	char firstLetter, secondLetter, thirdLetter;
	int next_month_number; //Represents the next month as a number
};

int main()
{
	Month month1('m', 'a', 'y'), month2(7), month3;

	cout << "Object month1 is initialized as follows:\n";
	month1.output_letter();
	cout << "Object month2 is initialized as follows:\n";
	month2.output_letter();
	cout << "Object month3 is initialized as follows:\n";
	month3.output_letter();

	cout << "Enter the first three letters of the month\n";
	month3.input_letter();
	cout << "That month expressed as an integer is:\n";
	month3.output_integer();
	cout <<endl;	

	cout << "Enter the month as an integer between 1 and 12:\n";
	month3.input_integer();
	cout << "That is equivalent to the month of:\n";
	month3.output_letter();
	cout << "in letters\n";
	cout << "The next month is: \n";
	month3.next_month();
	cout << endl;

	cout << "Press any key to continue..." << endl;
	getch();
}

Month::Month(char firstLetter, char secondLetter, char thirdLetter)
{
	month_number = letters_to_integer(firstLetter, secondLetter, thirdLetter);
	month_letters = integer_to_letters(month_number);
}

Month::Month(int month_number)
{
	month_letters = integer_to_letters(month_number);
}

Month::Month()
{
	month_number = 1;
	month_letters = "Jan\n";
}

void Month::input_integer()
{
	cin >> month_number;
	if(month_number < 12){
		month_letters = integer_to_letters(month_number);
		next_month_number = month_number + 1;
	}
	else if(month_number == 12){
		month_letters=integer_to_letters(month_number);
		next_month_number = 1;
	}
}

void Month::input_letter()
{
	cin >> firstLetter >> secondLetter >> thirdLetter;
	month_number = letters_to_integer(firstLetter, secondLetter, thirdLetter);
}

void Month::output_letter()
{
	cout << month_letters;
}

void Month::output_integer()
{
	cout << month_number;
}

int Month::letters_to_integer(char firstLetter, char secondLetter, char thirdLetter)
{
	if((firstLetter == 'j') && (secondLetter == 'a') && (thirdLetter == 'n'))
	{
		month_number = 1;
	}
	if((firstLetter == 'f') && (secondLetter == 'e') && (thirdLetter == 'b'))
	{
		month_number = 2;
	}
	if((firstLetter == 'm') && (secondLetter == 'a') && (thirdLetter == 'r'))
	{
		month_number = 3;
	}
	if((firstLetter == 'a') && (secondLetter == 'p') && (thirdLetter== 'r'))
	{
		month_number = 4;
	}
	if((firstLetter == 'm') && (secondLetter == 'a') && (thirdLetter == 'y'))
	{
		month_number = 5;
	}
	if((firstLetter == 'j') && (secondLetter == 'u') && (thirdLetter == 'n'))
	{
		month_number = 6;
	}
	if((firstLetter == 'j') && (secondLetter == 'u') && (thirdLetter == 'l'))
	{
		month_number = 7;
	}
	if((firstLetter == 'a') && (secondLetter == 'u') && (thirdLetter == 'g'))
	{
		month_number = 8;
	}
	if((firstLetter == 's') && (secondLetter == 'e') && (thirdLetter == 'p'))
	{
		month_number = 9;
	}
	if((firstLetter == 'o') && (secondLetter == 'c') && (thirdLetter == 't'))
	{
		month_number = 10;
	}
	if((firstLetter == 'n') && (secondLetter == 'o') && (thirdLetter == 'v'))
	{
		month_number = 11;
	}
	if((firstLetter == 'd') && (secondLetter == 'e') && (thirdLetter == 'c'))
	{
		month_number = 12;
	}
	return month_number;
}

string Month::integer_to_letters(int month_number)
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
		month_letters = "Invalid integer for month";
		break;
	}
	return month_letters;
}

void Month::next_month()
{
	cout << integer_to_letters(next_month_number);
}