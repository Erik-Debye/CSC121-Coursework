/*
Week 6 -- Lab
Erik Debye || 27.02.2022
TicTacToe - Protect Data
New commands : While Loops, cin.fail(), cin.ignore
*/

#include <iostream>
#include <cctype> //Necessary to use tolower()
using namespace std;

//Functions
//Display title info
void displayInfo(void);
//Displays Keyword
void displayWord(string key);
//Querys User to enter letter
char qLetter(void);
//Check for match
string matcher(string key, string xKey, char letter);
//Check Winner
bool winner(string xKey);

int main()
{
    //display title info
    displayInfo();

    //Game Data Initialization
    string key{ "elephant" };
    string xKey{ "XXXXXXXX" };
    //User Choice
    char choiceLetter{' '};
    //win checker trigger
    bool isWon{};   

    for (int i = 0; i < 9; i++) {

        isWon = winner(xKey);

        if (isWon) {
            cout << "\n\tCongrats! You have won!\n\n"; 
            break;
        }

        //Display hidden key
        displayWord(xKey);

        //Guess a letter
        choiceLetter = qLetter();

        //Set hidden key to new hidden key after matching 
        xKey = matcher(key, xKey, choiceLetter);

    }
    
    return 0;
}


void displayInfo(void) {
    //Print Title
    cout << "\n\tErik Debye - 27.02.2022 - Lab 5";
    cout << "\n\tWeek 6 - TicTacToe - Protect Data";
    cout << "\n\tCommands: While Loops, cin.fail(), cin.ignore";

    //Print a seperation spacer
    cout << endl;
}

void displayWord(string xKey) {
    cout << "\n\t" << xKey << endl;
}

char qLetter(void) {
    //Create variable 
    char choice{' '};

    cout << endl;
    //Query
    cout << "\n\tPlease select a letter: ";
    //Save choice
    cin >> choice;
    cout << endl;

    //ensure lowercase letter
    choice = tolower(choice);
    
    return choice;
}

string matcher(string key, string xKey, char letter) {
    //trigger no match 
    bool foundLetter{ false };

    //iterate through normalized string to search for vowels at current index
    for (int l = 0; l < key.length(); l++) {
        if (key[l] == letter) {
            xKey[l] = letter;
            foundLetter = true;
        } 
    }

    if (!foundLetter) {
        cout << "\tNo matching letter found, try again!" << endl;
    }

    return xKey;
}

bool winner(string xKey) {
    //Set to default true
    bool winner = true;

    //iterate through hidden key
    for (int i = 0; i <= xKey.length(); i++) {
        //if X is found change bool to false (no winner) - stop loop
        if (xKey[i] == 'X') {
            winner = false;
            break;
        }
    }

    return winner;
}