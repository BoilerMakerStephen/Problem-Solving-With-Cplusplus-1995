//Problem Solving With C++ - Walter Savitch
//Chapter 6
//Programming Project #1
//Reads in student number grade and outputs letter grade.

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <array>

using namespace std;

const int record_size = 4;

//Structure for a grading system
struct studentType
{
	string lastName;
	string firstName;
	char courseGrade;
	int quizz1;
	int quizz2;
	int exam1;
	int exam2;
	double finalGrade;
};

int main()
{
	ifstream fin;
	char file[25];
	//declare two variables of this type
	studentType newStudent;
	studentType student[50];
	int i = 0;
	int arraySize;
	
	cout << "Enter file name(max 25 characters):\n";
	cin >> file;

	fin.open(file);
	if(fin.fail()){
		cout << "Input file opening failed.\n";
		cout <<endl;
		cout << "Press any key to escape...\n";
		getch();
		exit(1);
	}
	
	//create input file of desired size and change const variable 'record_size' accordingly
	cout << "Enter the number of student files (max " << record_size << "):\n";
	do{
		cin >> arraySize;
		cout << "Student files must be less than " << record_size << "." << endl;
	}while(arraySize > 4);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//read in 6 data items
	while(fin){
	fin >> newStudent.lastName
	    >> newStudent.firstName
		>> newStudent.quizz1
	    >> newStudent.quizz2
	    >> newStudent.exam1
	    >> newStudent.exam2;
	
	//calculate the sixth field: final_grade
	newStudent.finalGrade=((newStudent.quizz1 * 0.125) + (newStudent.quizz2 * 0.125) + (newStudent.exam1 * 0.25)
		+ (newStudent.exam2 * 0.50));
		
	//calculate the seventh field: letter_grade
	if(newStudent.finalGrade >= 90)
		newStudent.courseGrade = 'A';
	else if(newStudent.finalGrade >= 80)
		newStudent.courseGrade = 'B';
	else if(newStudent.finalGrade >= 70)
		newStudent.courseGrade = 'C';
	else if(newStudent.finalGrade >= 60)
		newStudent.courseGrade = 'D';
	else
		newStudent.courseGrade = 'F';
	
	//assign student record to array
	student[i] = newStudent;
	i++;
	}

	//Loop through array and output student fields
	for(int i = 0; i < arraySize; i++){
		cout << student[i].lastName << " " << student[i].firstName << endl
		     << student[i].quizz1 << endl
		     << student[i].quizz2 << endl
		     << student[i].exam1 << endl
		     << student[i].exam2 << endl
		     << "Final Grade: " << student[i].finalGrade << endl
		     << "Letter Grade: " << student[i].courseGrade << endl
		     << "*******************************" << endl;
	}

	fin.close();

	cout << "Press any key to continue...\n";
	getch();
}
