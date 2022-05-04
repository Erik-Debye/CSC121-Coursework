/*
Erik Debye || 09.02.2022
Week 4 -- Problem 1
Switch Cases
New commands: switch => case
*/

#include <iostream>
#include <iomanip>
#include <math.h>  //to truncate
using namespace std;

// Functions
void findGrade(double score);

int main() {
	//Create inital data
	double score1{}, score2{}, score3{};

	//Query Scores
	cout << setw(25) << "Please enter a score: ";
	cin >> score1;
	cout << endl;
	//print letter grade
	findGrade(score1);

	cout << setw(25) << "Please enter a score: ";
	cin >> score2;
	cout << endl;
	//print letter grade
	findGrade(score2);

	cout << setw(25) << "Please enter a score: ";
	cin >> score3;
	cout << endl;
	//print letter grade
	findGrade(score3);

	//Find average
	int avg = trunc((score1 + score2 + score3) / 3);

	cout << setw(76) << "The next grade printed is your average letter grade for all three scores." << endl << endl;
	
	//Calculate and print grade for average
	findGrade(avg);

		
	return 0;
}

void findGrade(double score) {
	//Important to save as int
	int simplifiedScore = trunc(score / 10); 
	
	switch (simplifiedScore) {
	case 10: cout << setw(32) << "Congrats, you acheived an A+!" << endl << endl; // 100 / 10 => 10
		break;
	case 9: cout << setw(26) << "You got an A, terrific!" << endl << endl; // 90 to 99 / 10 => 9
		break;
	case 8: cout << setw(25) << "Great, you earned a B." << endl << endl; // 80 to 89 / 10 => 8
		break;
	case 7: cout << setw(18) << "You earned a C." << endl << endl; // 70 to 79 / 10 => 7
		break;
	case 6: cout << setw(20) << "Oof, you got a D." << endl << endl; // 60 to 69 / 10 => 6
		break;
	default: cout << setw(30) << "Ouch, you failed with an F." << endl << endl; //else
	}
}

