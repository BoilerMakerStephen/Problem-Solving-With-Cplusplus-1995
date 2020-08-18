//Problem Solving With C++ - Walter Savitch
//Chapter 9
//Programming Project #6
//THIS PROGRAM WILL READ A LINE OF TEXT AND OUTPUTS A LIST OF LETTERS
//THAT OCCUR IN THE TEXT TOGETHER WITH THE NUMBER OF TIMES EACH 
//LETTER OCCURS IN THE LINE.

#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <cctype>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100;

int main()
{
	string myString;
	char arr[MAX_SIZE];	
	//int letterCounts[MAX_SIZE];
	int alpha[26] = {0};
	
	cout << "Enter string followed by a period (100 characters max)" << endl;
	getline(cin, myString);
	
	strcpy(arr, myString.c_str());

	//remove spaces
	for(int i = 0; arr[i] != '.'; i++){
		if(isspace(arr[i])){
			for(int j = i; arr[j] != '.'; j++){
				arr[j] = arr[j + 1];
			}
		}
	}

	//print list of unique letters
	for(int i = 0; arr[i] != '.'; i++){
		int a = arr[i];
		if(a >= 'a' && a <= 'z'){
			alpha[a - 'a']++;
		}
	}
	cout << "LETTER FREQUENCY" << endl
		 << "------ ---------" << endl;

	//sort numerically
	for(int i = 0; i < 26; i++){
		if(alpha[i]){
			cout << right << setw(4) << char('a' + i) << setw(7) << right << alpha[i] << endl;
		}
	}
	
	cout << "Press any key to escape..." << endl;
	getch();
}