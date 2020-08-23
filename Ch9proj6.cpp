//Problem Solving With C++ - Walter Savitch
//Chapter 9
//Programming Project #6
//THIS PROGRAM WILL READ A LINE OF TEXT AND OUTPUTS A LIST OF LETTERS
//THAT OCCUR IN THE TEXT TOGETHER WITH THE NUMBER OF TIMES EACH 
//LETTER OCCURS IN THE LINE.

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>

using namespace std;

struct letter_count {
	char letter;
	int count;
};

void sort(letter_count arr[]);
void swap(letter_count *arr_1, letter_count *arr_2);
void print(letter_count arr[], int tot);

int main() {
	letter_count arr[26];
	int i;
	int total = 0;
	int ch;

	//Initialize an array of structs
	for (i = 0; i < 26; i++) {
		/* letter fields get 26 letters. */
		arr[i].letter = (char)(i + 'a');
		arr[i].count = 0;
	}

	cout << "Enter a sentence followed by a period. (100 characters of less)" << endl;

	while ((ch = getchar()) != '.') {
		if (isalpha(ch)) {
			total++;
			arr[ch - 'a'].count++;
		}
	}
		sort(arr);
		print(arr, total);

		_getch();
	
}

//sort array into decreasing order 
void sort(letter_count arr[]) {
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25; j++)
			if (arr[j].count < arr[j + 1].count)
				swap(&arr[j], &arr[j + 1]);
}

//interchange two structs 
void swap(letter_count *arr_1, letter_count *arr_2) {
	letter_count temp;
	temp = *arr_1;
	*arr_1 = *arr_2;
	*arr_2 = temp;
}

//print the table 
void print(letter_count arr[], int total) {
	system("CLS");
	int i;
	cout << "Frequency of letters, out of a total of " << total << endl;
	cout << endl;
	cout << setw(2) << "Letter" << setw(8) << "Count" << endl;
	cout << setfill('-') << setw(20) << '-' << endl;
	cout << setfill('\0') << endl;
	for (i = 0; i < 26; i++) {
		cout << arr[i].letter << setw(10) << (double)arr[i].count << endl;
	}
}
