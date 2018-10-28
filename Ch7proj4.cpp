//Problem Solving With C++ - Walter Savitch
//Chapter 7
//Programming Project #4
//Program computes the cost of a long distance phone 
//calls and outputes the payment due to a customer bill.

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

void outFile(ofstream& fout);
//Precondition: Output file exists.
//Postcondition: fout has been connected to output file.
void inFile(ifstream& fin);
//Precondition: Input file exists.
//Postcondition: fin has been connected to input file.
void get_infoScreen();
//Precondition: Input has been requested from input file.
//Postcondition: Input has been received from input file.
void get_infoFile(ifstream& fin);
//Precondition: Input has been requested from input file.
//Postcondition: Input has been received from input file.
void printBill(ofstream& fout);
//Precondition: Function has been asked to send data to output file.
//Postcondition: Data has been sent to output file.
double day_week_charge(int time, double length, int amt);
//Precondition: Function has received time and length of call.
//Postcondition: Call charge has been calculated.
double day_weekend_charge(double length, int amt);
//Precondition: Function has received length of call.
//Postcondition: Call charge has been calculated.
void calcBill(string day, int time, double length);
//Precondition: Function has requested day, time and length variable.
//Postcondition: Total call charge has been calculated.

string day;
int time;
double length;
double amt = 0;

int main()
{
	ifstream fin;
	ofstream fout;
	string day;
	int time;
	double length, amt = 0;
	char ans;
	
	cout << "This program reads in customer long distance phone calls "
		 << "from a file and prints a customer bill to another file." <<endl;

	inFile(fin);
	outFile(fout);
	
	do{
	get_infoFile(fin);

	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2);
		
	printBill(fout);

	cout << "The customer's bill has been printed." << endl;
	cout << "Do you want to prepare another bill?(Y/N)" <<endl;
	cin >> ans;
	}while(ans == 'Y' || ans == 'y');
	
	cout <<endl;
	fin.close();
	fout.close();
	cout << "Press any key to escape...";
	getch();
}

void outFile(ofstream& fout)
{
	char callInfo[25];
	
	cout << "Enter the output file name(25 characters max)" <<endl;
	cin >> callInfo;
	
	fout.open(callInfo);
	if(fout.fail()){
		cout << "Output file opening failed." <<endl;
		cout << "Press any key to escape..." <<endl;
		getch();
	}
}

void inFile(ifstream& fin)
{
	char custBill[25];

	cout << "Enter the input file name(25 characters max)" << endl;
	cin >> custBill;

	fin.open(custBill);
	if(fin.fail()){
		cout << "Input file opening failed." << endl;
		cout << "Press any key to continue..." << endl;
		getch();
	}
}

void get_infoScreen()
{
	cout << "Enter day:" << endl;
	cin >> day;
	cout << "Enter time:" << endl;
	cin >> time;
	cout << "Enter length:" << endl;
	cin >> length;
	return;
}

void get_infoFile(ifstream& fin)
{
	while(!fin.eof()){
		fin >> day;
		fin >> time;
		fin >> length;
	}
	return;
}

void printBill(ofstream& fout)
{
	calcBill(day, time, length);
	fout << "The amount of the bill is $" << amt << endl;
    return;
}

double day_week_charge(int time, double length)
{
	if(time <= 24){
		if(time >= 8 || time <= 18){
			amt = length * 0.40;
		}
		else if(time >= 24 || time <= 7) 
		{
			amt = length * 0.25;
		}
	}
	else{
		cout << "Invalid time entry." << endl;
	}
	return amt;
}

double day_weekend_charge(double length)
{
	amt = length * 0.25;

	return amt;
}

void calcBill(string day, int time, double length)
{	
	if(day == "mo"){
		day_week_charge(time, length);
		return;
	}
	else if(day == "tu"){
		day_week_charge(time, length);
		return;
	}
	else if(day == "we"){
		day_week_charge(time, length);
		return;
	}
	else if(day == "th"){
		day_week_charge(time, length);
		return;
	}
	else if(day == "fr"){
		day_week_charge(time, length);
		return;
	}
	else if(day == "sa"){
		day_weekend_charge(length);
		return;
	}
	else if(day == "su"){
		day_weekend_charge(length);
		return;
	}
	else{
		cout << "Not a possible day." <<endl;
	}
}