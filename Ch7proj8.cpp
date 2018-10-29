//Problem Solving With C++ - Walter Savitch
//Chapter 7
//Programming Project #8
//This program uses the Fibonacci numbers to calculate population growth

#include <iostream>
#include <conio.h>

void growth(double& weight, int& days);
//Precondition: The weight and number of days have been entered by the user.
//Postcondition: The fibonacci sequence for n days have been multiplied by the 
//weight of the population.

using namespace std;

int main()
{
	double weight;
	int days;
	char ans;

	cout << "This program uses the Fibonacci numbers to calculate population growth. ";
	cout << "Press  any key to begin..." << endl;
	getch();
	do{
	system("CLS");
	cout << "Enter initial weight of population: ";
	cin >> weight;
	cout << "Enter number of days of growth: ";
	cin >> days;
	cout << "The weight of the population after each day in lbs is: "; 
	cout << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	growth(weight, days);
	cout << "Do you want to calculate another population(Y/N)" << endl;
	cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}

void growth(double& weight, int& days)
{
	int next, fib_n1 = 0, fib_n2 = 1;
	double pop_wght;
	
	for(int i = 0; i < days; i++){
		
		if(i <= 1){
			next = i;
		}
		else{
			next = fib_n1 + fib_n2;
			fib_n1 = fib_n2;
			fib_n2 = next;
		}
		pop_wght = next * weight;
		cout << pop_wght <<endl;
	} 

	return;
}