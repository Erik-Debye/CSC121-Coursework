
/*Erik Debye
  08.04.2022
  Week 11 Q1
  Pointers*/

#include <iostream>
using namespace std;

int main() {

	//local int
	int num = 7;
	//pointer intialized to the address of int num.
	int* ptrNum = &num;

	cout << "\n\n\tThe value of int num is " << num << ".\n";
	cout << "\tThe value of (*)ptrNum is " << *ptrNum << ".\n";
	cout << "\tThe address of (&)num is " << &num << ".\n";
	cout << "\tThe address of ptrNum is " << ptrNum << ".\n\n";


	char name[30] = "Erik Debye";
	char* ptrName = name;

	cout << "\tThe value of char[30] name is " << name << ".\n";
	cout << "\tThe address of name is " << &name << ".\n\n";
	
	string animal{ "Perry the Platypus" };
	string* ptrAnimal = &animal;

	cout << "\tValue of string animal is = " << animal << "\n";
	cout << "\tAddress of ptrAnimal is = " << ptrAnimal << "\n\n";
}