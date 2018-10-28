//Problem Solving With C++ - Walter Savitch
//Chapter 7
//Programming Project #3
//Astrology Program

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

void openFile(ifstream& fin);
//Precondition: Input file exists.
//Postcondition: fin has been connected to input file.
void horoscope(ifstream& fin, int month, int day);
//Precondition: The user has been prompted for thier birthdate.
//Postcondition: The readHoroscope function has been called.
void readHoroscope(ifstream& fin, string sign);
//Precondition: An input file exists.
//Postcondition: The appropriate horoscope has been printed to the screen.
void cusp(int month, int day);
//Precondition: The users birth date has been entered.
//Postcondition: The users birth date has been determined to be on/off the cusp. This information
//has been printed to the screen.

int main()
{
	char ans;
	int month, day;
	ifstream fin;
	
	openFile(fin);

	cout << "This program is designed to tell you your sign and horoscope based on your birthdate.\n";
	cout << "Press any key to continue..." << endl;
	getch();
	do{
		system("CLS");
		cout << "Enter the month you were born as a number: \n";
		cin >> month;
		cout << "Enter the day you were born as a number: \n";
		cin >> day;
		horoscope(fin, month, day);
		cusp(month, day);
		cout << endl;
		cout << "Do you want another horoscope?(Y/N)\n";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
	
	fin.close();

	cout << "Press any key to escape...";
	getch();
}

void openFile(ifstream& fin)
{
	fin.open("horoscope.dat");
	if(fin.fail()){
		cout << "Input file opening failed\n"
			 << "Press any key to escape...";
		getch();
		exit(1);
	}
}

void horoscope(ifstream& fin, int month, int day)
{
	if((month == 1 && day >= 21 && day <= 31) || (month == 2 && day >= 1 && day <= 18)){
		
		string sign = "AQUARIUS";
		system("CLS");
		cout << "You are an AQUARIUS and your horoscope is:" << endl;
		readHoroscope(fin, sign);
	}
	else if((month == 2 && day >= 19 && day <= 28) || (month == 3 && day <= 20 && day >= 1)){
			
		string sign = "PISCES";
		system("CLS");
		cout << "You are a PISCES and your horoscope is:" <<endl;
		readHoroscope(fin, sign); 
	}
	else if((month == 3 && day >= 21 && day <= 31) || (month == 4 && day <= 20 && day >= 1)){
		
		string sign = "ARIES";
		system("CLS");
		cout << "You are an ARIES and your horoscope is:" <<endl;
		readHoroscope(fin, sign);
	}
	else if((month == 4 && day >= 21 && day <= 30) || (month == 5 && day <= 21 && day >= 1)){
		
		string sign = "TAURUS";
		system("CLS");
		cout << "You are a TAURUS and your horoscope is:" << endl;
		readHoroscope(fin, sign);
	}
	else if((month == 5 && day >= 22 && day <= 31) || (month == 6 && day <= 21 && day >= 1)){

		string sign = "GEMINI";
		system("CLS");
		cout << "You are a GEMINI and your horoscope is:" <<endl;
		readHoroscope(fin, sign);
	}
	else if((month == 6 && day >= 22 && day <= 30) || (month == 7 && day <= 23 && day >= 1)){

		string sign = "CANCER";
		system("CLS");
		cout << "You are a CANCER and your horoscope is:" <<endl;
		readHoroscope(fin, sign);
	}
	else if((month == 7 && day >= 24 && day <= 30) || (month == 8 && day <= 23 && day >= 1)){

		string sign = "LEO";
		system("CLS");
		cout << "You are a LEO and your horoscope is:" <<endl;
		readHoroscope(fin, sign);
	}
	else if((month == 8 && day >= 24 && day <= 31) || (month == 9 && day <= 23 && day >= 1)){

		string sign = "VIRGO";
		system("CLS");
		cout << "You are a VIRGO and your horoscope is:" <<endl;
		readHoroscope(fin, sign);
	}
	else if((month == 9 && day >= 24 && day <= 30) || (month ==10 && day <= 23  && day >= 1)){

		string sign = "LIBRA";
		system("CLS");
		cout << "You are a LIBRA and your horoscope is:" <<endl;
		readHoroscope(fin, sign);
	}
	else if((month == 10 && day >= 24 && day <= 31) || (month == 11 && day <= 22 && day >= 1)){

		string sign = "SCORPIO";
		system("CLS");
		cout << "You are a SCORPIO and your horoscope is:" <<endl;
		readHoroscope(fin, sign);
	}
	else if((month == 11 && day >= 23) || (month == 12 && day <= 22)){

		string sign = "SAGITTARIUS";
		system("CLS");
		cout << "You are a SAGITTARIUS and your horoscope is:" <<endl;
		readHoroscope(fin, sign);
	}
	else if((month == 12 && day >= 23 && day <= 30) || (month == 1 && day <= 17 && day >= 1)){

		string sign = "CAPRICORN";
		system("CLS");
		cout << "You are a CAPRICORN and your horoscope is:" <<endl;
		readHoroscope(fin, sign);
	}
	else{
		cout << "Not a possible date" <<endl;
	}
}

void readHoroscope(ifstream& fin, string sign)
{
	string strTemp;
	char next;

	while(fin >> strTemp){
		if(strTemp == sign){
			fin.get(next);
			while(fin){
				cout << next;
				fin.get(next);
				if(next == '*'){
					break;
				}
			}
		}
	}
	fin.clear();
	fin.seekg(0, ios::beg);
}

void cusp(int month, int day)
{
	if(month == 1 && day <= 20 && day >= 17){
		cout << endl;
		cout << "You are on the cusp of AQUARIUS." << endl;
	}
	else if(month == 2 && day <= 18 && day >= 15){
		cout << endl;
		cout << "You are on the cusp of PISCES." << endl;
	}
	else if(month == 3 && day <= 20 && day >= 17){
		cout << endl;
		cout << "You are on the cusp of ARIES." << endl;
	}
	else if(month == 4 && day <= 20 && day >= 17){
		cout << endl;
		cout << "You are on the cusp of TAURUS." << endl;
	}
	else if(month == 5 && day <= 21 && day >= 18){
		cout << endl;
		cout << "You are on the cusp of GEMINI." << endl;
	}
	else if(month == 6 && day <= 21 && day >= 18){
		cout << endl;
		cout << "You are on the cusp of CANCER." << endl;
	}
	else if(month == 7 && day <= 23 && day >= 20){
		cout << endl;
		cout << "You are on the cusp of LEO." << endl;
	}
	else if(month == 8 && day <= 23 && day >= 20){
		cout << endl;
		cout << "You are on the cusp of VIRGO." << endl;
	}
	else if(month == 9 && day <= 23 && day >= 20){
		cout << endl;
		cout << "You are on the cusp of LIBRA." << endl;
	}
	else if(month == 10 && day <= 23 && day >= 20){
		cout << endl;
		cout << "You are on the cusp of SCORPIO." << endl;
	}
	else if(month == 11 && day <= 22 && day >= 19){
		cout << endl;
		cout << "You are on the cusp of SAGITTARIUS." << endl;
	}
	else if(month == 12 && day <= 22 && day >= 19){
		cout << endl;
		cout << "You are on the cusp of CAPRICORN." << endl;
	}
	else{
		cout << endl;
		cout << "You are not on a cusp!" << endl;
	}
}
