/*
Erik Debye || 26.01.2022
Week 2 -- Problem 5
Trigonomitry
New commands: atan(param), acos(), functions, sqrt()
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//Functions
void queryUser( string query);
void calcTheta(double base, double height);
void calcHypot(double base, double height);

int main()
{
	//declare variables
	double uBase{ 0 };
	double uHeight{ 0 };
	double uHypot{ 0 };
	double uTheta{ 0 };
	double uThetaRads{ 0 };
	double calcBase{ 0 };
	double calcHeight{ 0 };

	cout << endl;

	//Query User for Base
	queryUser("the base length");
	cin >> uBase;
	
	//Query User for Height
	queryUser("the height length");
	cin >> uHeight;

	cout << endl;

	//Print Output 
	cout << setw(27) << "With a base of " << uBase << " and a height of " << uHeight << ", your theta is ";
	calcTheta(uBase, uHeight);
	cout << " degrees." << endl;
	cout << setw(46) << "Additionally, your hypothenuse is ";
	calcHypot(uBase, uHeight);
	cout << " units." << endl << endl;

	//Query User for Hypothenuse
	queryUser("the hypotenuse");
	cin >> uHypot;

	//Query User for Theta
	queryUser("the theta");
	cin >> uTheta;
	//convert to radians 
	uThetaRads = uTheta * ((acos(-1)) / 180);

	//calculations
	calcBase = cos(uThetaRads) * uHypot;
	calcHeight = sin(uThetaRads) * uHypot;

	cout << endl;

	cout << setw(33) << "With a hypotenuse of " << uHypot << " and a theta of " << uTheta << ", your base is " << calcBase << " units." << endl;
	cout << setw(27) << " Your height is " << calcHeight << " units." << endl;

}

//Query User Function
void queryUser(string query) {
	cout << setw(25) << "Please enter " << query << " : ";
}

//Calculate Theta
void calcTheta(double base, double height) {
	//Declare variables
	double theta{ 0 };
	
	//calc theta using atan -> convert to degrees - acos(-1) = pi
	theta = (atan(height / base)) * (180 / acos(-1));

	//print theta
	cout << theta;
}

//Calculate Hypotenuse
void calcHypot(double base, double height) {
	//Declare variables
	double hypot{ 0 };

	//calc hypotenuse
	hypot = sqrt(pow(base, 2) + pow(height, 2));

	//print hypotenuse
	cout << hypot;
}
