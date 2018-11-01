//Problem Solving With C++ - Walter Savitch
//Chapter 9
//Programming Project #3
//delete repeated letters

#include <iostream>
#include <conio.h>

int const MAX_LIST_SIZE = 100;

void delete_repeats(char letter[], int& length);
//Precondition: The array has been filled by the user.
//Postcondition: The new array with deleted repeats has been returned.

using namespace std;

int main()
{
	char arr[MAX_LIST_SIZE];
	char ans;
	int length;
				
	do{
	system ("CLS");
	cout << "How many letters will be entered: ";
	cin >> length;

	cout << "Enter " << length << " letters." << endl;
	for(int i = 0; i < length; i++){
		cin >> arr[i];
	}
	
	cout << "You entered " << endl;
	for(int i = 0; i < length; i++){
		cout << arr[i] << endl;
	}
	
	delete_repeats(arr, length);

	cout << "Again(Y/N)" << endl;
	cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}

void delete_repeats(char arr[], int& length)
{
	int count = 0;   
	
	for(int i = 0; i < length; i++){
		for(int j = i + 1; j < length;){
			if(arr[i] == arr[j]){
				for(int k = j; k < length; k++){
					arr[k] = arr[k+1];
				}
				length--;
				count++;
			}
			else
				j++;
		}
	}
	
	if(count == 1){
		cout << "There was " << count << " repeat." << endl;
	}
	else{
		cout << "There were " << count << " repeats." << endl;
	}
	
	cout << "New Array: " << endl;
    for(int i = 0; i < length; ++i)
        cout << arr[i] << endl;
}
	
	
	

