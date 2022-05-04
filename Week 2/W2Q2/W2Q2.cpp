/*
Week 2 -- Problem 2
Data Types and String Manipulation
New commands: string::length, string::at, string[#]
Erik Debye || 24.01.2022
*/

#include <iostream>
using namespace std;

int main()
{
    //Declare & initialize variables
    string name{" "};
    int nameLength{0};
    string firstChar{ " " };
    string lastChar{ " " };

    //Query User for name
    cout << "Please enter your name.\n";
    cin >> name;

    //Calculate namelength, firstChar, & lastChar
    nameLength = name.length() - 1; //using string::length -- source: https://www.cplusplus.com/reference/string/string/length/
    firstChar = name.at(0); //using string::at -- source: https://www.cplusplus.com/reference/string/string/at/
    lastChar = name[nameLength];

    //spacer
    cout << "\n";

    //Output the first and last chars
    cout << "Hi " << name << ". The first letter of your name is " << firstChar << ", and the last letter of your name is " << lastChar << ".";

    //spacer
    cout << "\n";

}

