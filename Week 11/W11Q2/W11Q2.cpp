
/*Erik Debye
  09.04.2022
  Week 11 Q2
  Pass by Ref Pointers*/

#include <iostream>
using namespace std;

int tripleVal(int num);
int tripleRef(int* num);


int main() {
	//vars 1)normal 2)pointer to i
	int i = 372, * iptr = &i;

	cout << "\n\n\tThe value of i is set to " << i << ".\n";
	cout << "\n\tThe memory address of i is " << iptr << ".\n\n";
	cout << "\tWhen tripled via pass by value via function, the function returns " << tripleVal(i) << ".\n";
	cout << "\tBut the value of i stays the same, " << i << ".\n\n";
	cout << "\tWhen tripled via pass by reference (via pointer iptr), the function returns = " << tripleRef(iptr) << ".\n";
	cout << "\tBut here the value of i is changed to " << i << ".\n\n";
}

int tripleVal(int num) {
	num *= 3;
	return num;
}

int tripleRef(int* num) {
	*num *= 3;
	return *num;
}