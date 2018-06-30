//Problem Solving With C++ - Walter Savitch
//Chapter 2
//Programming Project #5
//This program determines whether a meeting room is in violation
//of fire regulations regarding the maximum room capicity.

#include <iostream>
#include <conio.h>

using namespace::std;

int main()
{
	char ans;
	int rm_cap, people, remove;

	do{
		cout << "Enter the capacity of the room: \n";
		cin >> rm_cap;
		cout << "Enter the amount people planning to attend: \n";
		cin >> people;

		if(people <= rm_cap){
			cout << "Good to go!\n";
		}
		else{
			remove = people - rm_cap;
			cout << "Too many, remove " << remove << " people!\n";
		}
		
		cout << "Do you wish to perform another calculation?(Y/N)\n";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}