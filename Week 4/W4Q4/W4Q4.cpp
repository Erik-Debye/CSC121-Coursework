/*
Erik Debye || 09.02.2022
Week 4 -- Problem 4
DeMorgan's Law of Inverse boolean
New commands: !(cond.) && !(cond.) === !(cond. || cond.)
*/

#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int x{ 4 }, y{ 5 }, a{ 3 }, b{ 3 }, g{ 8 }, i{5}, j{4};

	cout << setw(30) << "If x = 4, and y = 5, " << endl << endl;
	cout << setw(41) << "!(x < 5) && !(y >= 7) is false: " << (!(x < 5) && !(y >= 7)) << endl;
	cout << setw(55) << "Inversed as !(x < 5 || y >= 7) is also false: " << (!(x < 5 || y >= 7)) << endl << endl << endl;

	cout << setw(41) << "If a = 3, and b = 3, and g = 8, " << endl << endl;
	cout << setw(42) << "!(a == b) || !(g != 5) is false: " << (!(a == b || !(g != 5))) << endl;
	cout << setw(53) << "Inversed as a != b && g == 5 is also false: " << (a != b && g == 5) << endl << endl << endl;

	cout << setw(29) << "If x = 4 and y = 5, " << endl << endl;
	cout << setw(38) << "!(x <= 8 && y > 4) is false: " << (!(x <= 8 && y > 4)) << endl;
	cout << setw(52) << "Inversed as x >= 8 || y < 4 is also false: " << (x >= 8 || y < 4) << endl << endl << endl;

	cout << setw(30) << "If i = 5, and j = 4, " << endl << endl;
	cout << setw(38) << "!(i > 4 || j <= 6) is false: " << (!(i > 4 || j <= 6)) << endl;
	cout << setw(52) << "Inversed as i < 4 && j >= 6 is also false: " << (i < 4 && j >= 6) << endl << endl << endl;

	return 0;
}
