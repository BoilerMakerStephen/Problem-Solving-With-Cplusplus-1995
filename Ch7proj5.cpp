//Problem Solving With C++ - Walter Savitch
//Chapter 7
//Programming Project #5
//////////////////////////////////////////////////////////////
//This program accepts a year written in Arabic and outputs //
//that year in roman numerals.                              //
//////////////////////////////////////////////////////////////

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


int main()
{
	int year, array[4];
	int first, second, third, fourth; 
	char ans;
	
	cout << "This program accepts a year written in Arabic and outputs "
		 << "that year in roman numerals. Please ensure that the year " 
		 << "is between 1000 and 3000." << endl;
	do{
		cout << "Please enter the year you would like to convert: " << endl;
		cin >> year;
		
		if(year >= 1000 && year <= 3000){
			 
			for(int i = 3; i >= 0; i--){
				array[i] = year%10;
				year/=10;
			}
		
			first = array[0] * 1000;
			second = array[1] * 100;
			third = array[2] * 10;
			fourth = array[3] * 1;

			switch(first){
				case 1000:
					cout << "M";
					break;
				case 2000:
					cout << "MM";
					break;
				case 3000:
					cout << "MMM";
					break;
				default:
					cout << "Error" <<endl;
				}

			switch(second){
				case 0:
					break;
				case 100:
					cout << "C";
					break;
				case 200:
					cout << "CC";
					break;
				case 300:
					cout << "CCC";
					break;
				case 400:
					cout << "CD";
					break;
				case 500:
					cout << "D";
					break;
				case 600:
					cout << "DC";
					break;
				case 700:
					cout << "DCC";
					break;
				case 800:
					cout << "DCCC";
					break;
				case 900:
					cout << "CM";
					break;
				default:
					cout << "Error" << endl;
				}

			switch(third){
				case 0:
					break;
				case 10:
					cout << "X";
					break;
				case 20:
					cout << "XX";
					break;
				case 30:
					cout << "XXX";
					break;
				case 40:
					cout << "XL";
					break;
				case 50:
					cout << "L";
					break;
				case 60:
					cout << "LX";
					break;
				case 70:
					cout << "LXX";
					break;
				case 80:
					cout << "LXXX";
					break;
				case 90:
					cout << "XC";
					break;
				default:
					cout << "Error" << endl;
			}

			switch(fourth){
				case 0:
					break;
				case 1:
					cout << "I";
					break;
				case 2:
					cout << "II";
					break;
				case 3:
					cout << "III";
					break;
				case 4:
					cout << "IV";
					break;
				case 5:
					cout << "V";
					break;
				case 6:
					cout << "VI";
					break;
				case 7:
					cout << "VII";
					break;
				case 8:
					cout << "VIII";
					break;
				case 9:
					cout << "IX";
					break;
				default:
					cout << "Error" << endl;
			}
		}
		else{
			cout << "Not a valid year" << endl;
		}
				
		cout << endl;
		cout << "Would you like to convert another number?(Y/N)" << endl;
		cin >> ans;
		cout << endl;
	}while(ans == 'Y' || ans == 'y');

	cout << "Press any key to escape..." << endl;
	getch();
}

