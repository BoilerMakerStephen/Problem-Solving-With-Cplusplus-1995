//Problem Solving With C++ - Walter Savitch
//Chapter 7
//Programming Project #1
//////////////////////////////
//                          //
//Paper, Rock Scissors Game //
//                          //
//////////////////////////////

#include <iostream>
#include <conio.h>

using namespace std;

void instructions();
//Prints introduction and game instruction to the screen.
void gamePlay(char choice_one, char choice_two);
//Precondition:
//Postcondition:

int main()
{
	char choice_one, choice_two;
	char ans;

	instructions();
	do{
	cout << "User one, enter your choice: ";
	cin >> choice_one;
	cout << "User two, enter your choice: ";
	cin >> choice_two;
	cout << endl;

	gamePlay(choice_one, choice_two);

	cout << "Do you want to play again?(Y/N)\n";
	cin >> ans;
	}while((ans == 'Y') || (ans == 'y'));
	cout << "Good-bye!\n";
	cout << "Press any key to escape...";
	getch();
}

void instructions()
{
	cout << "Welcome to Rock, Paper, Scissors!\n"
		 << "User one will be prompted to enter\n"
		 << "either an 'R', 'P' or 'S'.\n"
		 << "Then user two will be prompted to enter\n"
		 << "either an 'R', 'P' or 'S'.\n"
		 << "Once both users input has been entered a\n"
		 << "winner will be determined." << endl;
}

void gamePlay(char choice_one, char choice_two)
{
	if((choice_one == 'P' || choice_one == 'p') && (choice_two == 'R' || choice_two == 'r')){
		cout << "Paper covers rock, player one wins!\n" << endl;
	}	
	else if((choice_one == 'R' || choice_one == 'r') && (choice_two == 'P' || choice_two == 'p')){
		cout << "Paper covers rock, player two wins!\n";
	}
	else if((choice_one == 'S' || choice_one == 's') && (choice_two == 'P' || choice_two == 'p')){
		cout << "Scissors cuts paper, player one wins!\n";
	}
	else if((choice_one == 'P' || choice_one == 'p') && (choice_two == 'S' || choice_two == 's')){
		cout << "Scissors cuts paper, player two wins!\n";
	}
	else if((choice_one == 'R' || choice_one == 'r') && (choice_two == 'S' || choice_two == 's')){
		cout << "Rock breaks scissors, player one wins!\n";
	}
	else if((choice_one == 'S' || choice_one == 's') && (choice_two =='R' || choice_two == 'r')){
		cout << "Rock breaks scissors, player two wins!\n";
	}
	else{
		cout << "No winner!\n";
	}
}