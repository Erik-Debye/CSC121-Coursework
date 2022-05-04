
/*Erik Debye
  09.04.2022
  Week 11 Q4
  Reading Files*/

#include <stdio.h> //needed for fopen - fgets
#pragma warning(disable : 4996) //disable warning 4996
#include <iostream>
using namespace std;

void writeNames(FILE* file, char name[80]);
void readNames(FILE* file, char name[80]);

int main() {
	//Create a pointer that references our file
	//set equal to a created file called 'names.txt' in the mode of 'w' (writing mode)
	FILE* filePointer = fopen("names.txt", "w");
	//check if file opened
	if (filePointer == NULL) {
		cout << "\n\tError opening file.";
		return 1;
	}
	//create a var (char array) to hold names
	char name[30]{ "" };

	//write names to file
	writeNames(filePointer, name);
	//close file
	fclose(filePointer);

	//open file in read mode
	FILE* filePointer2 = fopen("names.txt", "r");
	//check if file opened
	if (filePointer2 == NULL) {
		cout << "\n\tError opening file";
		return 1;
	}
	//read file
	readNames(filePointer2, name);
	//close file
	fclose(filePointer2);


	exit(EXIT_SUCCESS);
}

void writeNames(FILE* pfile, char name[80]) {
	//query user for name 1
	//save to char array name
	cout << "\n\n\tPlease enter a name: ";
	cin >> name;

	do {
		//print name into file via pointer, add a new line, then add name
		fprintf(pfile, "\n%s", name);

		//ask user to quit or enter another name
		cout << "\n\tEnter another name or press CTRL + Z to quit: ";
	} while (cin >> name);
}

void readNames(FILE* file, char name[80]) {
	//print title
	cout << "\n\n\tNAMES ON FILE";

	//read from file (80chars at a time)
	while(fgets(name, 80, file))
	{
		//print name
		printf("%s        ", name);
	}

	cout << "\n\n";
}