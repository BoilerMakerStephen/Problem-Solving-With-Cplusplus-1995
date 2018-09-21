//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #9
//This program averages students test scores. The data is supplied by an input file and 
//the results are printed to the screen and to an output file. The contents of the output
//file are then overwitten on the original input file.

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

void read_grades(ifstream& fin, ofstream& fout);
//Precondition: Input file has been opened.
//Postcondition: Names and grades have been read into program.

void copy_file(ifstream& in, ofstream& out);
//Precondition: The outfile has been created filed with the desired output. 
//Postcondition: The infile has been overwritten with the contents of the outfile.

void finFail(ifstream& fin);
//Precondition: fin.open has been called to connect to a file.
//Postcondition: The file opening has failed and a message has been printed to the screen. 

void foutFail(ofstream& fout);
//Precondition: fout.open has been called to connect to a file.
//Postcondition: The file opening has failed and a message has been printed to the screen.

int main()
{
	ifstream fin;
	ofstream fout; 
	
	cout << "This program inputs student's marks and outputs student's averages.\n";
	cout << endl;
	fout << "This program inputs student's marks and outputs student's averages.\n";
	fout << endl;

	fin.open("student_score.dat");
	finFail(fin);

	fout.open("avg_score.dat");
	foutFail(fout);
		
	read_grades(fin, fout);
		
	fin.close();
	fout.close();

	fin.clear();             
	fin.seekg(0, fin.beg);

	fin.open("avg_score.dat");
	finFail(fin);

	fout.open("student_score.dat");
	foutFail(fout);

	copy_file(fin, fout);

	fin.close();
	fout.close();
	
	
	cout << "Press any key to escape...\n";
	getch();
}

void read_grades(ifstream& fin, ofstream& fout){
	
	stringstream iss;

	int grade, sum = 0, count = 0, new_count = 0;
	string line, lname, fname;

	double avg;
	
	while(getline(fin, line)){
		iss.clear();
		iss.str("");
		iss << line;

		if(iss >> lname >> fname){
			fout << lname << " " << fname << " "; 
			cout << lname << " " << fname << " "; 
			while(iss >> grade){
				cout << grade << " "; 
				fout << grade << " ";
				sum += grade;
				count++;
			}
			avg = sum/10;
			sum = 0;			
		}
		
		if(count < 10){
			new_count = (10 - count);
		}
		
		fout << endl;
		cout << endl;

		fout << "Average Grade: " << avg << endl;
		fout << "Missed Quizzes: " << new_count << endl;
		cout << "Average Grade: " << avg << endl;
		cout << "Missed Quizzes: " << new_count << endl;
		cout << endl;
		fout << endl;

		count = 0;
		new_count = 0;
	}
}

void copy_file(ifstream& fin, ofstream& fout)
{
	string str;
	
	while(getline(fin, str)){
		fout << str << endl;
	}
}

void finFail(ifstream& fin)
{
	if(fin.fail()){
		cout << "Input file opening failed!" << endl;
		getch();
		exit(1);
	}
}

void foutFail(ofstream& fout)
{
	if(fout.fail()){
		cout << "Output file opening failed!" << endl;
		getch();
		exit(1);
	}
}