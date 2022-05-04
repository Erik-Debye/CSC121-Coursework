/*
Erik Debye || 31.01.2022
Week 3 -- Problem 3
Conditional Operations
New commands: conditional ? true : false
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Functions
// Query user for Score
void query(void);

//Outputs for grades
void a(void);
void b(void);
void c(void);
void d(void);
void f(void);

//Output for out of range
void outOfRange(void);

int main() {
	//Declare variables 
	double score{ 0 };

	//Collect score and save
	query();
	cin >> score;
	cout << endl;

	//Check range 
	(score >= 0 && score <= 100)
		//If true
		? (score >= 89.5 ? a() :
			(score >= 79.5 ? b() :
				(score >= 69.5 ? c() :
					(score >= 59.5 ? d() : f())))) : outOfRange(); //Note: I tried to put a cout statement here but I think it 'overloads' the operator?
	                                                               //Or perhaps I need TO overload it? IDK, but placing it into a function worked.
		
}

void query(void) {
	cout << endl << setw(45) << "Please enter a score between 0 and 100: ";
}

void a(void) {
	cout << setw(33) << "Terrific! You achieved an A!" << endl;
}

void b(void) {
	cout << setw(30) << "Congrats! You earned a B!" << endl;
}

void c(void) {
	cout << setw(30) << "Good Job! You earned a C." << endl;
}

void d(void) {
	cout << setw(50) << "One bad test is okay, don't make D's a habit." << endl;
}

void f(void) {
	cout << setw(54) << "Please go to office hours; I want to help you. F." << endl;
}

void outOfRange(void) {
	cout << setw(52) << "Your score is out of range. Program TERMINATED." << endl;
}