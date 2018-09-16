//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #7
//This program searches the text of a letter and inserts 
//the name the user provides where directed.

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

void add_name(ifstream& fin, ofstream& fout);
//Precondition: fin and fout have been connected to files.
//Postcondition: "#N#" encountered in the input file has been replaced in the output file 
//by the name that the user entered.

int main()
{
	ifstream fin;
	ofstream fout;
		
	fin.open("in_file.dat");
	if(fin.fail()){
		cout << "Input file opening failed.\n";
		getch();
		exit(1);
	}

	fout.open("out_file.dat");
	if(fout.fail()){
		cout << "Input file opening failed.\n";
		getch();
		exit(1);
	}
	
	add_name(fin, fout);
		
	fin.close();
	fout.close();
	
	cout << endl;
	cout << "Press any key to quit...";
	getch();
}

void add_name(ifstream& fin, ofstream& fout)
{
	char name[30];
	char position[30];
	char company[30];
	
	cout << "This program is designed to personalize a letter.\n";
	cout << endl;
	cout << "Enter first name (max 30 characters)--> ";
	cin >> name;
		
	string strReplace_Name = "#N#";
	string strNew_Name = name;
	string strTemp;
		
	while(fin >> strTemp){
		if(strTemp == strReplace_Name){
			strTemp = strNew_Name;
		}
		strTemp += " ";
		fout << strTemp;
	}
}