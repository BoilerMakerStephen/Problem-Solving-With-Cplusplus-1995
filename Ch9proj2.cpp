//Problem Solving With C++ - Walter Savitch
//Chapter 9
//Programming Project #2
//Reads rainfall data

#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>

const int MAX_LIST_SIZE = 12;

using namespace std;

int main()
{
	string month_name[MAX_LIST_SIZE] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
										"Sep", "Oct", "Nov", "Dec"};
	double month_avg_rain[MAX_LIST_SIZE] = {12.30, 12.00, 9.23, 7.45, 6.41, 6.88, 8.88, 9.63, 5.69,
											10.55, 8.78, 7.78};
	double month_rain[MAX_LIST_SIZE];
	double difference[MAX_LIST_SIZE];
	char ans;
	
	do{
	system ("CLS");

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Enter the monthly rain fall..." << endl;
	
	for(int i = 0; i < MAX_LIST_SIZE; i++){
		cout << month_name[i] << ": ";
		cin >> month_rain[i];			
	}
	
	system("CLS");

	cout << endl;
	cout << setw(80) << "MONTHLY RAIN FALL" << endl;
	cout << endl;
		 
	for(int i = 0; i < MAX_LIST_SIZE; i++){
		difference[i] = month_avg_rain[i] - month_rain[i]; 
	}

	cout << "                       ";
	for(int i = 0; i < MAX_LIST_SIZE; i++){
		cout << right
			 << setw(10) << month_name[i]; 		     	
	}
	cout << endl;

	for(int i = 0; i < 145; i++){
		cout << "-";
	}
	cout << endl;
	
	cout << "Monthly Rain Fall:     ";
	for(int i = 0; i < MAX_LIST_SIZE; i++){
		cout << right
		     << setw(10) << month_rain[i];
	}
	cout << endl;

	cout << "Mnthly Avg Rain Fall:  ";
	for(int i = 0; i < MAX_LIST_SIZE; i++){
		cout << right
		     << setw(10) << month_avg_rain[i];
	}	
	cout << endl;
	
	cout << "Difference:            ";
	for(int i = 0; i < MAX_LIST_SIZE; i++){
		cout << right
		     << setw(10) << difference[i];
	}

	cout << endl; 
	cout << endl;
	cout << "Again(Y/N)..." << endl;
	cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}



