/*
Erik Debye || 27.02.2022
Week 6 -- Problem 2
Common Chars
New commands: Loops
*/

#include <iostream>
#include <cctype> //string:: erase()
#include <string> //to_lower()
using namespace std;

int main()
{
    //Variables
    //1. names, chars in common
    string fName{ " " }, lName{ " " }, commonChars{ "" };

    //Query First Name
    cout << "\n\tPlease enter your first name: ";
    cin >> fName;

    //Query Last Name
    cout << "\n\tPlease enter your last name: ";
    cin >> lName;

    //loop through the first name
    for (int i = 0; i < fName.length(); i++) {
        //loops through the last name
        for (int k = 0; k < lName.length(); k++) {
            //convert current char to lowercase for both names. 
            //This allows users to enter uppercase letters
            char currFirstName = tolower(fName[i]);
            char currLastName = tolower(lName[k]);
       
           //if a letter in lName == any letter in first name
            if (currLastName == currFirstName) {
                commonChars += lName[k];
            }

        }
    }

    //sort commonchars alphabetically -- bubblesort
    //loop through once
    for (int i = 0; i < commonChars.length(); i++)
    {
        //
        for (int k = 0; k < commonChars.length()- 1; k++)
        {
            // check if first index value is larger than next index value
            if (commonChars[k] > commonChars[k + 1]){
                //if yes, swap values
                char temp = commonChars[k + 1];
                commonChars[k + 1] = commonChars[k];
                commonChars[k] = temp;
            }

            //remove duplicates
            if (commonChars[k] == commonChars[k + 1]) {
                //using std.erase() -- source: https://www.cplusplus.com/reference/string/string/erase/
                commonChars.erase(k, 1);
            }
        }
    }
    cout << "\n\tThe common letters in your names are: ";

    //output common chars
    for (int i = 0; i < commonChars.length(); i++) {
        cout << commonChars[i];
    };


    return 0;
};
