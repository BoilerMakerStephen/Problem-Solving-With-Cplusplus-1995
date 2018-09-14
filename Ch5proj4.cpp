//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #4
//This program will direct the user to enter a piece of advice in to a file.
//The program will then direct the user to exit the program. The next user
//to open the file will be read back the advice from the previous user. The 
//current user will be asked to enter another piece of advice and the process
//will repeat.

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void open_in_file(ifstream& fin);
//Precondition: Function to open input file has been called.
//Postcondition: Input file has been opened.

void open_out_file(ofstream& fout);
//Precondition: Function to open output file has been called.
//Postcondition: Output file has been opened.

void read_file(ifstream& fin);
//Precondition: File has been connected to ifstream.
//Postcondition: The data has been read from the file and printed 
//to the screen.

void write_file(ofstream& fout);
//Precondition: File has been connected to ofstream.
//Postcondition: The new data has been overwritten to the file.

int main(){

	ifstream fins;
	ofstream fouts;
	char ans;

	cout << "Once this program is launched it prints a piece of advice to the screen.\n";
	cout << endl;
	cout << "The progam then asks the user to enter another piece of advice. The next\n";
	cout << endl;
	cout << "time the program is executed it prints the previous piece of advice to the\n";
	cout << endl;
	cout << "screen. This process is repeated every time the program is ran.\n";
	cout << endl;
	cout << "Press any key to continue...\n";
	getch();
	
	open_in_file(fins);

	read_file(fins);

	open_out_file(fouts);

	write_file(fouts);
}

void open_in_file(ifstream& fin){
	fin.open("advice.dat");
	if(fin.fail()){
		system("CLS");
		cout << "Input file opening failed.\n";
		cout << endl;
		cout << "Press any key to escape.\n";
		cout << endl;
		getch();
		exit(1);
	}
}

void open_out_file(ofstream& fout){
	
	fout.open("advice.dat");
	if(fout.fail()){
		system("CLS");
		cout << "Output file opening failed.\n";
		cout << endl;
		cout << "Press any key to escape.\n";
		cout << endl;
		getch();
		exit(1);
	}
}

void read_file(ifstream& fin){
	
	string temp;
	
	system("CLS");
	
	while(!fin.eof()){
		getline(fin, temp);
		cout << temp;
	}
	
	fin.close();
}

void write_file(ofstream& fout){
	
	string temp;
	
	cout << endl;
	cout << "Pease enter the next piece of advice\n";
	
	getline(cin, temp);
	fout << temp;
		
	fout.close();
}

