/*
Erik Debye || 24.01.2022
Week 2 -- Problem 3
Data Types and String Manipulation
New commands: getline(string) & to_string()
*/


#include <iostream>
#include <string> //needed to use getline(string) - source: https://www.cplusplus.com/reference/string/string/getline/
using namespace std;

int main()
{
    //Declare and initialize variables
    string fName{ "" };
    string lName{ "" };
    int nameLength = 0;
    string nameLengthStr{ "" };
    string shortEmail{ "" };
    string longEmail{ "" };

    //Query user for their name using getline() - source: Class Lecture '124_stringData' ~ 13:00 - end.
    cout << "Please enter your first name: ";
    getline(cin, fName);
    cout << "Please enter your last name: ";
    getline(cin, lName);


    //spacer
    cout << "\n";

    //Calculate short Email 
    shortEmail = fName.at(0) + lName + "@company.com";

    //Calculate length of name
    nameLength = fName.length() + lName.length();

    //Convert nameLength from an int type to a string type using to_string - source: https://www.cplusplus.com/reference/string/to_string/
    nameLengthStr = to_string(nameLength);

    //Calculate Long Email
    longEmail = fName[0];
    longEmail += lName[0];
    longEmail += nameLengthStr + "@WhatsinaName.com";

    //Output user's name and manipulated emails.
    cout << "Hi " << fName << " " << lName << ",\n";
    cout << "Your short email is: " << shortEmail << "\n";
    cout << "Your long email is: " << longEmail;

    //spacer
    cout << "\n";
}
