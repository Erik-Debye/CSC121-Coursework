/*
Erik Debye || 09.02.2022
Week 4 -- Problem 3
Logic Tables
New commands: &&, ||, ^
*/

#include <iostream>
#include <iomanip>
using namespace std;

void andLogic(bool x, bool y);

void orLogic(bool x, bool y);

void xorLogic(bool x, bool y);

int main() {
	//Create inital data
	bool x{ false }, y{ false };

	cout << endl;
	cout <<  setw(31) << "0's are false, 1's are true" << endl;

	cout << endl;
	//Display AND Table
	andLogic(x, y);

	cout << endl;
	//Display OR Table
	orLogic(x, y);

	cout << endl;
	//Display XOR Table
	xorLogic(x, y);

	return 0;
}

void andLogic(bool x, bool y) {
	cout << setw(30) << "x is False && y is False: " << ((x = 0) && (y = 0)) << endl;
	cout << setw(29) << "x is True && y is False: " << ((x = 1) && (y = 0)) << endl;
	cout << setw(29) << "x is False && y is True: " << ((x = 0) && (y = 1)) << endl;
	cout << setw(29) << "x is True && y is True: " << ((x = 1) && (y = 1)) << endl;
}

void orLogic(bool x, bool y) {
	cout << setw(30) << "x is False || y is False: " << ((x = 0) || (y = 0)) << endl;
	cout << setw(29) << "x is True || y is False: " << ((x = 1) || (y = 0)) << endl;
	cout << setw(29) << "x is False || y is True: " << ((x = 0) || (y = 1)) << endl;
	cout << setw(28) << "x is True || y is True: " << ((x = 1) || (y = 1)) << endl;
}


void xorLogic(bool x, bool y) {
	cout << setw(29) << "x is False ^ y is False: " << ((x = 0) ^ (y = 0)) << endl;
	cout << setw(28) << "x is True ^ y is False: " << ((x = 1) ^ (y = 0)) << endl;
	cout << setw(28) << "x is False ^ y is True: " << ((x = 0) ^ (y = 1)) << endl;
	cout << setw(27) << "x is True ^ y is True: " << ((x = 1) ^ (y = 1)) << endl;
}

