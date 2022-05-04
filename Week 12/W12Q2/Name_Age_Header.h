//directive to say that this .h file only needs to be included once (default behavior when creating .h in VS)
#pragma once
#include <iostream>
using namespace std;

//Define class and class name
class schoolboyQ {
	//define the following as part of the public space
public:
	//define public variables
	string name = "ScHoolboy Q";
	int age = 35;
	//define public methods (display public vars)
	void Display(string name, int age) {
		cout << "\n\n\tName: " << name << "\n";
		cout << "\n\tAge: " << age << "\n";
	}
};