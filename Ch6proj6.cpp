//Problem Solving With C++ - Walter Savitch
//Chapter 6
//Programming Project #6


#include <iostream>
#include <stdio.h> 
#include <conio.h>

using namespace std;

class Month
{
private:
	char firstLetter;
	char secondLetter;
	char thirdLetter;


public:

	Month(char letterOne, char letterTwo, char letterThree) {
		firstLetter = letterOne;
		secondLetter = letterTwo;
		thirdLetter = letterThree;
	};

	Month()
	{
		firstLetter = 'a';
		secondLetter = 'b';
		thirdLetter = 'c';
	};

	char getletterOne() { return firstLetter; };

	char getletterTwo() { return secondLetter; };

	char getletterThree() { return thirdLetter; };

	void getValue()
	{ 
		cout << getletterOne();
		cout << getletterTwo();
		cout << getletterThree();
	};

	Month::~Month() {};

	void input();

	void chooseMonth();

	void escape();

};

int main()
{
	
	char ans;
	Month month;
	
	do {
		month.input();
		month.chooseMonth();
		
		cout << "Again? -> ";
		cin >> ans;
	} while (ans == 'Y' || ans == 'y');

	month.escape();
	
	_getch();
}

void Month::input()
{
	system("CLS");
	cout << "Enter first letter->\n";
	cin >> firstLetter;
	cout << "Enter second letter-> \n";
	cin >> secondLetter;
	cout << "Enter third letter->\n";
	cin >> thirdLetter;
}

void Month::chooseMonth()
{
	cout << "Month entered: ";
	
	if ((firstLetter == 'j') && (secondLetter == 'a') && (thirdLetter == 'n'))
		cout << "January" << endl;
	else if ((firstLetter == 'f') && (secondLetter == 'e') && (thirdLetter == 'b'))
		cout << "February" << endl;
	else if ((firstLetter == 'm') && (secondLetter == 'a') && (thirdLetter == 'r'))
		cout << "March" << endl;
	else if ((firstLetter == 'a') && (secondLetter == 'p') && (thirdLetter == 'r'))
		cout << "April" << endl;
	else if ((firstLetter == 'm') && (secondLetter == 'a') && (thirdLetter == 'y'))
		cout << "May" << endl;
	else if ((firstLetter == 'j') && (secondLetter == 'u') && (thirdLetter == 'n'))
		cout << "June" << endl;
	else if ((firstLetter == 'j') && (secondLetter == 'u') && (thirdLetter == 'l'))
		cout << "July" << endl;
	else if ((firstLetter == 'a') && (secondLetter == 'u') && (thirdLetter == 'g'))
		cout << "August" << endl;
	else if ((firstLetter == 's') && (secondLetter == 'e') && (thirdLetter == 'p'))
		cout << "September" << endl;
	else if ((firstLetter == 'o') && (secondLetter == 'c') && (thirdLetter == 't'))
		cout << "October" << endl;
	else if ((firstLetter == 'n') && (secondLetter == 'o') && (thirdLetter == 'v'))
		cout << "November" << endl;
	else if ((firstLetter == 'd') && (secondLetter == 'e') && (thirdLetter == 'c'))
		cout << "December" << endl;
	else
		cout << "Non-month" << endl;
}

void Month::escape() 
{ 
	cout << endl;
	cout << "Press any key to escape...\n"; 
}















