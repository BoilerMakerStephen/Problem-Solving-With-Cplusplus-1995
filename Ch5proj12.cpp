//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #12

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace::std;

void open_infile(ifstream& fin, string const inFile);
//Precondition:
//Postcondition:

void open_outfile(ofstream& fout, string const outFile);
//Precondition:
//Postcondition: 

const int NUMBER_OF_CHAPTERS = 3;
const string inFile = "inFile.dat";
const string outFile = "outFile.dat";

int main()
{
	ifstream fin;
	ofstream fout;
	string str;
	char ans;
	int i = NUMBER_OF_CHAPTERS;

	open_infile(fin, inFile);
	open_outfile(fout, outFile);

	do{
	system ("CLS");
	
	cin.clear();				//return to beginning after getline
	cin.seekg(0, ios::beg);
	
	cout << "Ask a one line question..." << endl;
	getline(cin, str);
	
	getline(fin, str);

	string num = boost::lexical_cast<string>(i);
	
	boost::replace_all(str, "#N", num);
	
	fout << str << endl;

	if(fin.eof()){
		cout << "No more answers!" << endl;
		cout << "Press any key to escape..." << endl;
		getch();
		exit(1);
	}
	else{
		cout << str << endl;
	}

	i--;

	if(i == 0){
		cout << "All done!" << endl;
	}

	cout << "Again?" << endl;
	cin >> ans;
	}while(ans=='Y' || ans=='y');

	fin.close();
	fout.close();

	cout << "Press any key to escape..." << endl;
	getch();
}

void open_infile(ifstream& fin, string const inFile)
{
	fin.open(inFile);
	if(fin.fail()){
		cout << "Input file opening failed!" << endl;
		cout << "Press any key to escape..." << endl;
		getch();
		exit(1);
	}
}

void open_outfile(ofstream& fout, string const outFile)
{
	fout.open(outFile);
	if(fout.fail()){
		cout << "Output file opening failed!" << endl;
		cout << "Press any key to escape..." << endl;
		getch();
		exit(1);
	}
}

void replace_number(ifstream& fin, ofstream& fout, string str)
{
	while(!fin.eof()){
		getline(fin, str);
		boost::replace_all(str, "#N", "#1");
		fout << str << endl;
	}	
}