//Problem Solving With C++ - Walter Savitch
//Chapter 9
//Programming Project #5

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cmath> 

using namespace::std;

const int MAX = 4;

int ret_int() {
	char arr[MAX];
	int i(0);
	int count(0);
	int sum(0);
	
		cout << "Enter number-> ";
		while ((arr[i] = getchar()) != '\n') {
			i++;
			if (i > 4) {
				cout << "BUFFER EXCEEDED" << endl;
				cout << endl;
				cout << "PRESS ANY KEY TO ESCAPE..." << endl;
				_getch();
				exit(1);
			}else
				count++;
		}
	

	// sets unused elements in array to char zero
	for (char j = i; j <= MAX; j++) // start at i rather than i + 1 in order 
		arr[j] = '0';				    // in order to replace '\n'

	// converts ascii elements to type int
	int k(0);
	while (arr[k] != '0') // may need to change to '\n'
	{
		int num(0);
		char temp = arr[k];
		num = (temp - '0') + (num * 10);
		arr[k] = num;
		k++;
	}

	//converts elements of array to single int variable
	int place = count;
	for (int i = 0; i <= count; i++) {
		sum += arr[i] * pow(10, (place - 1));
		--place;
	}

	return sum;
}

int main()
{
	char ans;
	int arr_sum[2];
	do {
		system("CLS");

		for (int i = 0; i < 2; i++) {
			arr_sum[i] = ret_int();
		}

		int total_sum = arr_sum[0] + arr_sum[1];

		cout << "The sum of the two numbers is " << total_sum << endl;
		cout << endl;
		cout << "Again(Y/N)-> ";
		cin >> ans;
		cin.ignore();
	} while (ans == 'Y' || ans == 'y');

	cout << "Press any key to escape..." << endl;
	_getch();

	return 0;
}
