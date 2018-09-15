//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #5
//This program reads text from one file and writes an edited
//version of the same text to another file.

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

void edit_file();
//Precondition: The main program has been launched.
//Postcondition: the input file has been opened. The output file has been
//created. As the input file is read into the program all multi-tabbed spaces
//are eliminated. The edited results are printed to the newly created file.

int main()
{
		
	cout << "This program reads text from one file and writes\n";
	cout << endl;
	cout << "an edited version of the same text to another file.\n";
	cout << endl;
	cout << "Press any key to continue...\n";
	getch();
	
	edit_file();

	cout << endl;
	cout << "End of program.\n";
	cout << endl;
	cout << "Press any key to escape...";
	getch();
}

void edit_file()
{
	char next, ch;
	int count = 0;

	char inFile[25], outFile[25];

	ifstream fin;
	ofstream fout;
	
	system("CLS");
	cout << "Please enter the name of the file you would like to edit.(max 25 characters)\n";
	cout << endl;
	cin >> inFile;
	cout << endl;

	fin.open(inFile);
	if(fin.fail()){
		cout << "Input file opening failed.\n";
		exit(1);
	}

	cout << inFile << " opened.\n";
	cout << endl;
	cout << "Please enter the name of the file you would like to copy to.(max 25 characters)\n";
	cout << endl;
	cin >> outFile;
	cout << endl;

	fout.open(outFile);
	if(fout.fail()){
		cout << "Output file opening failed.\n";
		exit(1);
	}
	
	cout << outFile << " opened.\n";
	
	while (!fin.eof())
    {
        fin.get(next);
		if(next == '\t'){
			next == ' ';
		}
		if(next == ' '){
			count++;	
		}
		else{
			count = 0;
		}
		if(count <= 1){
			fout << next;
		}
    }
	
	fin.close();
	fout.close();
}

