//Problem Solving With C++ - Walter Savitch
//Chapter 4
//Programming Project #3
//This program tells what coins to give out for any amount of change from 1 cent to 
//99 cents.

#include <iostream> 
#include <conio.h>
#include <string>

void compute_coin(int coin_value, int& number, int& amount_left);
//Precondition: 0 < coin_value < 100; 0 < amount_left < 100.
//Postcondition: number has been set equal to the maximum number of coins of 
//denomination coin_value cents that can be obtained from amount_left cents.
//amount_left has been decreased by the value of the coins, i.e.,
//decreased by the number coin value.

using namespace::std;

int main()
{
	char ans;
	int coin_value;
	int number, amount_left;
	
	do{
		//checks coin denominations of 1, 10 and 25 only
		do{
			cout << "Enter coin value..." << endl;
			cin >> coin_value;
		}while(coin_value != 1 && coin_value != 10 && coin_value != 25);

		//checks 0 < amount_left < 100 
		do{
			cout << "Enter amount left..." << endl;
			cin >> amount_left;
		}while(amount_left > 99 || amount_left < coin_value);
		
		number = amount_left%coin_value;

		compute_coin(coin_value, number, amount_left);
				
		cout << "Again?" << endl;
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}

void compute_coin(int coin_value, int& number, int& amount_left)
{
	int inter_val = amount_left - number;

	int final = inter_val/coin_value;

	if(coin_value == 25){		//calcs for quarters
			cout << "QUARTER: " << final << endl;
			if(number){
				if(number > 10){
					int dime = number/10;
					int cent = number%10;
					cout << "DIME: " << dime << endl;
					cout << "PENNY: " << cent << endl;
				}
				else{
					cout << "PENNY: " << number << endl;
				}
			}
			//else{
				//cout << "DONE!" << endl;
			//}
		}
	else if(coin_value == 10){		//calcs for dimes
			cout << "DIME: " << final << endl;
			if(number){
				cout << "PENNY: " << number << endl;
			}
		}
	else{		//for pennies
			cout << "PENNY: " << amount_left << endl;
		}
}