//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #6
//This program merges the numbers in two files and writes all the 
//sorted numbers to a third file.

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void count_num(ifstream& fin_1, ifstream& fin_2, ofstream& fout);
//Precondition: The file names have been entered by the user and each file has a specific number
//of integers.
//Postcondition: The integers from each file have been read into the program, merged into one list,
//sorted and printed to a third file.

int main()
{
	ifstream fin_1, fin_2;
	ofstream fout;
	char in_file1[25];
	char in_file2[25];
	char out_file[25];

	cout << "Enter name of #1 in file\n";
	cin >> in_file1;

	fin_1.open(in_file1);
	if(fin_1.fail()){
		cout << "#1 Input file opening failed.\n";
		cout << "Press any key to escape...\n";
		getch();
		exit(1);
	}

	cout << "Enter name of #2 in file.\n";
	cin >> in_file2;

	fin_2.open(in_file2);
	if(fin_2.fail()){
		cout << "#2 Input file opening failed.\n";
		cout << "Press any key to escape...\n";
		getch();
		exit(1);
	}

	cout << "Enter name of out file\n";
	cin >> out_file;
	
	fout.open(out_file);
	if(fout.fail()){
		cout << "Output file opening failed.\n";
		cout << "Press any key to escape...\n"; 
		getch();
		exit(1);
	}

	count_num(fin_1, fin_2, fout);

	fin_1.close();
	fin_2.close();
	fout.close();


	cout << "Press any key to escape.... " << endl;
	getch();
}

void count_num(ifstream& fin_1, ifstream& fin_2, ofstream& fout)
{
	int temp1_array[4], temp2_array[2], num_array[6];
	int num_1, num_2;
	
	for(int i = 0; i < 4; i++){  
		fin_1 >> temp1_array[i];
	}
	
	sort(temp1_array, temp1_array + 4);   

	for(int i = 0; i < 2; i++){  
		fin_2 >> temp2_array[i];
	}
	
	sort(temp2_array, temp2_array + 2);  

	merge(temp1_array, (temp1_array + 4), temp2_array, (temp2_array + 2), num_array);   

	for(int i = 0; i < 6; i++){   
		fout << num_array[i] << endl;
	}
}
	
	


