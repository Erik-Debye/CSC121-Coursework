/*
Erik Debye || 31.01.2022
Week 3 -- Problem 1
If & If-Else
New commands: if & if else statements
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//Declare variables 
	double x{ 0 };
	double y{ 0 };

	//Query user
	cout << setw(26) << endl << "Please enter a number: ";
	cin >> x;
	cout << setw(32) << "Please enter another number: ";
	cin >> y;
	cout << endl;

	//Calculations
	//1. Check x sign & evenness (This is a good place for a loop)
	if (int(x) % 2 == 0) {
		if (x > 0) {
			cout << setw(4) << x << " is an even, positive number." << endl;
		}
		else if (x < 0) {
			cout << setw(4) << x << " is an even, negative number." << endl;
		}
		else {
			cout << setw(4) << x << " is 0 (neither negative nor postive)" << endl;
		}
	}
	else {
		if (x > 0) {
			cout << setw(4) << x << " is an odd, positive number." << endl;
		}
		else {
			cout << setw(4) << x << " is an odd, negative number." << endl;
		}
	}
	//2.Check y sign & evenness
	if (int(y) % 2 == 0) {
		if (y > 0) {
			cout << setw(4) << y << " is an even, positive number." << endl;
		}
		else if (y < 0) {
			cout << setw(4) << y << " is an even, negative number." << endl;
		}
		else {
			cout << setw(4) << y << " is 0 (neither negative nor postive)" << endl;
		}
	}
	else {
		if (y > 0) {
			cout << setw(4) << y << " is an odd, positive number." << endl;
		}
		else {
			cout << setw(4) << y << " is an odd, negative number." << endl;
		}
	}

	//2. Check difference
	if (x > y) {
		cout << setw(4) << x << " is larger than " << y << endl;
	}
	else if (y > x) {
		cout << setw(4) << y << " is larger than " << x << endl;
	}
	else {
		cout << setw(4) << x << " is equal to " << y << "." << endl;
	}

	//3. See if divisible
	if (int(x) % int(y) != 0 && int(y) % int(x) != 0) {
		cout << setw(7) << "Neither " << x << " nor " << y << " are perfectly divisable into one another." << endl;
	}
	else if (int(x) % int(y) == 0) {
		cout << setw(4) << y << " is divisible into " << x << "." << endl;
	}
	else {
		cout << setw(4) << x << " is divisible into " << y << "." << endl;
	}
}
