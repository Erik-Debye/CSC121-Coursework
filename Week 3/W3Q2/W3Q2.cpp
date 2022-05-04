/*
Erik Debye || 31.01.2022
Week 3 -- Problem 2
If & If-Else
New commands: if & if else statements
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Functions
// Query user for Score
void query(void);
//takes score and prints grade
void calcOutputGrade(double score);

int main() {
	double score{ 0 };

	//Collect score and save
	query();
	cin >> score;
	cout << endl;

	//Calc grade and print
	calcOutputGrade(score);
}

void query(void) {
	cout << endl << setw(45) << "Please enter a score between 1 and 100: ";
}

void calcOutputGrade(double score) {
	//Check range
	if (score >= 1 && score <= 100) {
		//Calculate grade
		if (score >= 89.5) {
			cout << setw(33) << "Terrific! You achieved an A!" << endl;
		}
		else if (score < 89.5 && score >= 79.5) {
			cout << setw(30) << "Congrats! You earned a B!" << endl;
		}
		else if (score < 79.5 && score >= 69.5) {
			cout << setw(30) << "Good Job! You earned a C." << endl;
		}
		else if (score < 69.5 && score >= 59.5) {
			cout << setw(50) << "One bad test is okay, don't make D's a habit." << endl;
		}
		else {
			cout << setw(54) << "Please go to office hours; I want to help you. F." << endl;
		}
	}
	else {
		cout << setw(52) << "Your score is out of range. Program TERMINATED." << endl;
		exit(0);
	}
}
