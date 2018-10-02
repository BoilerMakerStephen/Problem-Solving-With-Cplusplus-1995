//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #11

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace::std;

void replace_subString(ifstream& fin, ofstream& fout, string &str);
//Precondition: fins has been connected to an input file. The boost library has been installed on
//the system. The input file exists.
//Postcondition: The input file has been read into the program and the output has been sent to the 
//specified output file.

int main()
{
	ifstream fins;
	ofstream fouts;
	string strs;
	
	fins.open("inFile.dat");
	if(fins.fail()){
		cout << "Input file opening failed!" << endl;
		getch();
		exit(1);
	}

	fouts.open("outfile.dat");
	if(fouts.fail()){
		cout << "Output file opening failed!" << endl;
		getch();
		exit(1);
	}

	replace_subString(fins, fouts, strs);

	fins.close();
	fouts.close();
	
	cout << "Press any key to escape..." << endl;
	getch();
}

void replace_subString(ifstream& fin, ofstream& fout, string &str)
{
	while(!fin.eof()){
		getline(fin, str);
		boost::replace_all(str, "cin <<", "cin >>");
		boost::replace_all(str, "cout >>", "cout <<");
		fout << str << endl;
	}	
}


	
	
	
