//This program accepts a string of letters terminated by a period and will
//determine whether or not the word is a palindrome.

#include <iostream>
#include <conio.h>
const int MAX_LIST_SIZE = 20;

using namespace std;

int main()
{
	char ans;
	char word[MAX_LIST_SIZE];
	char temp_arr[MAX_LIST_SIZE];
	int number_used;

	cout << "This program will identify whether a word is a palindrome.\n";
	cout << "Press any key to continue...\n";
	getch();
	do{
		system("CLS");

		//Fills array
		char next;
		int index = 0;
		
		cout << "Enter up to " << MAX_LIST_SIZE << " letters, followed by a period.\n";
		cin >> next;
		
		while((next != '.') && (index < MAX_LIST_SIZE)){
			word[index] = next;
			index++;
			cin >> next;
		}

		number_used = index;

		cout << endl;
		cout << "Filled array: \n";
		for(int i = 0; i < number_used; i++){
			cout << word[i] << endl;
		}
		
		//Duplicates array
		char temp;
		char temp_arr[MAX_LIST_SIZE];
	
		for(int i = 0; i < number_used; i++){
			temp = word[i];
			temp_arr[i] = temp;
		}
		
		cout << endl;
		cout << "Duplicate array: \n"; 
		for(int i = 0; i < number_used; i++){
			cout << temp_arr[i] << endl;
		}

		//Reverses array original array
		for(int i = 0; i < (number_used/2); i++){
			float temp = word[i];
			word[i] = word[(number_used - 1) - i];
			word[(number_used - 1) - i] = temp;
		}

		cout << endl;
		cout << "Reversed array: \n";
		for(int i = 0; i < number_used; i++){
			cout << word[i] << endl;
		}

		//Test arrays
		int count = 0;
		cout << endl;
		cout << "Test array: \n";
		for(int i = 0; i < number_used; i++){
			if(word[i] == temp_arr[i]){
				count++;
			}
			else{
				break;
			}
		}
		if(count == number_used){
			cout << "Is palindrome";
		}else{
			cout << "Not a palindrome!";
		}
		
		cout << endl;		
		cout << "Would you like to test another word?(Y/N)\n";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
	cout << "Press any key to escape...";
	getch();
}

