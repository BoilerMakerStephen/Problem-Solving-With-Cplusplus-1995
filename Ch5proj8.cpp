//Problem Solving With C++ - Walter Savitch
//Chapter 5
//Programming Project #8
//This program averages students test scores

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	fstream fin;
	ofstream fout;

	stringstream iss;

	int grade, sum = 0, count = 0;
	string line, lname, fname;

	double avg;

	fin.open("student_score.dat");
		if(fin.fail()){
			cout << "Input file opening failed.\n";
			getch();
			exit(1);
		}

	fout.open("avg_score.dat");
	if(fout.fail()){
		cout << "Output file opening failed.\n";
		getch();
		exit(1);
	}
	
	while(getline(fin, line)){
		iss.clear();
		iss.str("");
		iss << line;

		if(iss >> lname >> fname){
			fout << lname << " " << fname << " "; // endl;
			cout << lname << " " << fname << " "; //endl;
			while(iss >> grade){
				cout << grade << " "; // << endl;
				fout << grade << " "; // << endl;
				sum += grade;
				count++;
				avg = sum/count;
			}
			fout << "Average Grade: " << avg << endl;
			fout << "------------------------------\n";
			fout << endl;
			cout << "Average Grade: " << avg << endl;
			cout << "------------------------------\n";
			cout << endl;
		}
	}

	fin.close();
	fout.close();

	cout << "Press any key to escape...\n";
	getch();
}