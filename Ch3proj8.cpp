//Problem Solving With C++ - Walter Savitch
//Chapter 3
//Programming Project #8
//Asks users height, weight, and age and then computes clothing size
#include<iostream>
#include<conio.h>

using namespace::std;

double hat_size(double height, double weight);
double jacket_size(int age, double height, double weight);
double waist_size(int age, double weight); 

int main()
{
	char ans;
	double height, weight;
	int age;

	cout << "This program asks the users height, weight and age" << endl;
	cout << endl;
	cout << "and then computes clothing size." << endl;
	cout << endl;
	cout << "Press any key to continue..." << endl;
	
	getch();

	do{
		system("cls");
		cout << "Please enter your height in inches." << endl;
		cin >> height;
		cout << "Please enter your weight in pounds." << endl;
		cin >> weight;
		cout << "Please enter your age." << endl;
		cin >> age;
		cout << endl;

		double hat = hat_size(height, weight);
		double jacket = jacket_size(age, height, weight);
		double waist = waist_size(age, weight);

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "Your hat size is " << hat << "." << endl;
		cout << endl;
		cout << "Your jacket size is " << jacket << "." << endl;
		cout << endl;
		cout << "Your waist size is " << waist << "." << endl;
		cout << endl;
		cout << "Would like to recalculate Y/N." << endl;
		cin >> ans;

	}while(ans=='Y'||ans=='y');

	system("cls");
	cout << "Good bye!" << endl;
	cout << endl;
	cout << "Press any key to continue..." << endl;

	getch();
}

double hat_size(double height, double weight)
{
	double hat = (weight/height) * 2.9;

	return(hat);
}

double jacket_size(int age, double height, double weight)
{
	double jacket;

	if(age <= 39){
		jacket = (height * weight)/288;
	}else if(age <= 49){
		jacket = ((height * weight)/288) + 0.125;
	}else if(age <= 59){
		jacket = ((height * weight)/288) + 0.250;
	}else if(age <= 69){
		jacket = ((height * weight)/288) + 0.375;
	}else if(age <= 79){
		jacket = ((height * weight)/288) + 0.500;
	}else if(age <= 89){
		jacket = ((height * weight)/288) + 0.625;
	}else if(age <= 99){
		jacket = ((height * weight)/288) + 0.750;
	}

	return(jacket);
}

double waist_size(int age, double weight)
{
	double waist;
	int number;
	float fraction=0;

	if(age <= 29){
		waist = weight/5.7;
	}else{
		if(age % 2 == 0){
				number = (age - 28)/2;
		}else{
				number = ((age - 1) - 28)/2;
		}
		for(int i = 0; i <= number; i++){
			fraction += 0.10;
		}
		waist = (weight/5.7) + fraction;
	}
	return(waist);
}
