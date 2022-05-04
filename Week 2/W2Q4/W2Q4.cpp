/*
Erik Debye || 25.01.2022
Week 2 -- Problem 4
Basic Mathematics
New commands: pow( base, exponent )
*/

#include <iostream>
#include <cmath> //Needed to use the pow() command - source https://www.cplusplus.com/reference/cmath/pow/
using namespace std;

int main()
{
    //Inital Variables
	int x{ 0 };
	int y{ 0 };
	//Calculated Variables
	double sum{ 0 };
	double difference{ 0 };
	double product{ 0 };
	double quotient{ 0 };


	//Query User for two numbers
	cout << endl;
	cout << "Please enter a number: ";
	cin >> x;
	cout << "Please enter a second number: ";
	cin >> y;

	//Calculations
	sum = x + y;
	difference = x - y; //this is an assumption. A better solution is to check which number is bigger OR find the absolute difference.
	product = x * y;
	quotient = x / y;

	
	cout << endl;

	//Output Calculations
	cout << "The sum of your numbers is " << sum << "." << endl
		<< "The difference of your numbers is " << difference << "." << endl
		<< "The product of your numbers is " << product << "." << endl
		<< "The quotient of your numbers is " << quotient << "." << endl;

	cout << endl;

	//In-line calculations - Power - source: https://www.cplusplus.com/reference/cmath/pow/
	cout << "The power of raising " << x << " to the exponent " << y << " is " << pow(x, y) << "." << endl
		<< "The power of rasing " << y << " to the exponent " << x << " is " << pow(y, x) << "." << endl;

	cout << endl;

	//In-line calculations - Modulo - source: https://www.cplusplus.com/doc/tutorial/operators/
	cout << "The remainder of " << x << " % 2 is " << x % 2 << "." << endl
		<< "If 0, than " << x << " is even. Else, your number is odd." << endl

		<< endl

		<< "The remainder of " << y << " % 2 is " << y % 2 << "." << endl
		<< "If 0, than " << y << " is even. Else, your number is odd." << endl;

	cout << endl;

	cout << "The remainder of " << x << " % " << y << " is " << x % y << "." << endl
		<< "The remainder of " << y << " % " << x << " is " << y % x << "." << endl;

	cout << endl;	 
}
