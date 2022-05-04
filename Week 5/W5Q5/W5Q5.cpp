/*
Erik Debye || 17.02.2022
Week 5 -- Problem 5
Whats in a name
New commands: For-Loops
*/

#include <iostream>
using namespace std;

// FUNCTIONS
//1. Query First Name
string qFName();
//2. Query Last Name
string qLName();
//3. Print name backwards
void backwards(string name);

int main()
{        
    //Variables
    //1. User's First, last, & fullName
    string firstName{ " " }, lastName{" "}, fullName{" "};

    //query user
    firstName = qFName();
    lastName = qLName();
    fullName = firstName + " " + lastName;


    cout << "\n\tYou have these vowels in your name: ";
    //iterate through normalized string to search for vowels at current index
    for (int l = 0; l < fullName.length(); l++) {         
        if (fullName[l] == 'a' || fullName[l] == 'e' || fullName[l] == 'i' || fullName[l] == 'o' || fullName[l] == 'u') {
            //if found vowel, print it
            cout << fullName[l] << " ";        
        }
    }

    //Call backwards func
    backwards(fullName);


    return 0;
};

string qFName() {
    string fName{ " " };
    cout << "\n\tPlease enter your first name: ";
    cin >> fName;
    cout << endl;

    //normalization of fName => needed because A != a
    int i{ 0 };
    char curr;
    while (fName[i]) {
        curr = fName[i];
        curr = tolower(curr);
        fName[i] = curr;
        i++;
    };

    return fName;
}

string qLName() {
    string fName{ " " };
    cout << "\n\tPlease enter your last name: ";
    cin >> fName;
    cout << endl;

    //normalization of fName => needed because A != a
    int i{ 0 };
    char curr;
    while (fName[i]) {
        curr = fName[i];
        curr = tolower(curr);
        fName[i] = curr;
        i++;
    };

    return fName;
}

void backwards(string name) {

    cout << "\n\n\tThis is your name backwards: ";

    for (int i = name.length(); i >= 0; i--) {
        cout << name[i];
    }

    cout << endl << endl;
}