#include <stdio.h> //needed for fopen
#pragma warning(disable : 4996) //disable warning 4996
#include <string> //needed for fgets
#include <iostream>
using namespace std;

void writeNames(FILE* file, char name[80]);
void readNames(FILE* file);

int main() {
	//Create a pointer that references our file
	//set equal to a created file called 'names.txt' in the mode of 'w' (writing mode)
	FILE* fptr = fopen("names.txt", "a+");
	//create a var (char array) to hold names
	char name[80]{ "" };

	//write names to file
	writeNames(fptr, name);
	//close file
	fclose(fptr);

	//open file in read mode
	fptr = fopen("names.txt", "r+");
	//read file
	readNames(fptr);
	//close file
	fclose(fptr);


	return 0;
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

void readNames(FILE* file) {
	//create buffer
	char buffer[80]{ "" };

	//print title
	cout << "\n\n\tNAMES ON FILE";

	//read from file (30chars at a time)
	while (fgets(buffer, 80, file) != NULL)
	{
		//print name
		printf("%s        ", buffer);
	}

	cout << "\n\n";
}