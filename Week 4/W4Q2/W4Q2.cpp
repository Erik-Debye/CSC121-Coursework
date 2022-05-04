/*
Erik Debye || 09.02.2022
Week 4 -- Problem 2
Boolean
New commands: &&
*/

#include <iostream>
#include <iomanip>
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
	double avg = (score1 + score2 + score3) / 3;

	cout << setw(76) << "The next grade printed is your average letter grade for all three scores." << endl << endl;

	//Calculate and print grade for average
	findGrade(avg);


	return 0;
}

void findGrade(double score) {
	if (score <= 105 && score >= 100) {
		cout << setw(31) << "Congrats, you acheived an A+!" << endl << endl;
	}
	else if(score >= 89.5 && score < 100) {
		cout << setw(26) << "You got an A, terrific!" << endl << endl;
	}
	else if (score >= 79.5 && score < 89.5) {
		cout << setw(25) << "Great, you earned a B." << endl << endl;
	} 
	else if (score >= 69.5 && score < 79.5) {
		cout << setw(18) << "You earned a C." << endl << endl;
	}
	else if (score >= 59.5 && score < 69.5) {
		cout << setw(20) << "Oof, you got a D." << endl << endl;
	}
	else {
		cout << setw(30) << "Ouch, you failed with an F." << endl << endl;
	}
}

