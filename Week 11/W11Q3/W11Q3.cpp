
/*Erik Debye
  09.04.2022
  Week 11 Q3
  Fopen()*/

#include <stdio.h> //needed for fopen
#pragma warning(disable : 4996) //disable warning 4996
#include <iostream>
using namespace std;

int main() {
	//Create a pointer that references our file
	//set equal to a created file called 'names.txt' in the mode of 'w' (writing mode)
	FILE* filePointer = fopen("names.txt", "w");

	//create a var (char array) to hold names
	char name[80]{""};

	//query user for name 1
	//save to char array name
	cout << "\n\n\tPlease enter a name: ";
	cin >> name;

	do {
		//print name into file via pointer, add a new line, then add name
		fprintf(filePointer, "\n%s", name);

		//ask user to quit or enter another name
		cout << "\n\tEnter another name or press CTRL + Z to quit: ";
	} while (cin >> name);

	//close file
	fclose(filePointer);


	exit(EXIT_SUCCESS);
}