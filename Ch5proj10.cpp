//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #10
//This program calculates the average word length from a text file. The programs only function takes an 
//argument of type ifstream. The ifstream variable is then converted to std::cin and then the contents
//of the input file are read into the program. 

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

void calcWordLength(ifstream& fin);
//Precondition: The input file stream has been connected to a file.
//Postcondition: Each word from the file has been read into the program and the average word length
//has been calculated and that number has been printed to the screen.

int main()
{
	ifstream file("avg_dat.dat");
	
	calcWordLength(file);
		
	cout << "Press any key to escape...\n";
	getch();
}

void calcWordLength(ifstream& fin)
{
	string word;
	int sum = 0, count = 0, avg_length = 0;

	if(fin.fail()){
		cout << "Input file opening failed!" << endl;
		getch();
		exit(1);
	}
		
		cin.rdbuf(fin.rdbuf());
		
		while(cin >> word){
			sum += word.length();
			count++;
		}
		avg_length = sum/count;
	
	cout << "The average word length is "<< avg_length << ".\n";
	cout << endl;
}

