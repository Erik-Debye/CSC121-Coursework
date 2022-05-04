/*
Week 3 -- Lab
Erik Debye || 11.02.2022
TicTacToe Display
New commands : If-Else, C-Ops
*/

/*
Note that the below section will need to be edited to allow for a second player (or computer player). I believe that this will be immplemented
using a boolean similar to how I've implemented the ifPlaying logic above
*/

#include <iostream>
#include <iomanip> 
#include <Windows.h> 
#include <array> //Necessary to use arrays
using namespace std;

//Functions

//Change theme
void theme(void);
//Displays Title Info
void displayInfo(void);
//Displays TicTacToe board -- NOTE: must passed saved game data in main to displayBoard
void displayBoard(string sq[10]);
//Querys User to start playing
string findChoice(void);


int main()
{   
    //Run themes + info
    theme();
    displayInfo();

    //Game Data Initialization
    string square[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    //set to num of squares aka number of elements. 
    int numSqs = sizeof square / sizeof square[0];
    //User Choice
    string choice;

    //Create an iterable to run through turns - Source: Beginning iterable foundations on page 218 (chaper 6 part 5) 
    for (int i{ 0 }; i <= numSqs; ++i) {
        //display game
        displayBoard(square);
        //Query and save user choice 
        choice = findChoice();

        //Check if choice equals an X or O
        if (choice == "X" || choice == "x" || choice == "O" || choice == "o") {
            cout << setw(53) << "Square is already chosen, choose a valid square." << endl << endl;
            --i;
        }
        else {
            //Search through squares
            if (choice == square[0]) {
                square[0] = "X";
            }
            else if (choice == square[1]) {
                square[1] = "X";
            }
            else if (choice == square[2]) {
                square[2] = "X";
            }
            else if (choice == square[3]) {
                square[3] = "X";
            }
            else if (choice == square[4]) {
                square[4] = "X";
            }
            else if (choice == square[5]) {
                square[5] = "X";
            }
            else if (choice == square[6]) {
                square[6] = "X";
            }
            else if (choice == square[7]) {
                square[7] = "X";
            }
            else if (choice == square[8]) {
                square[8] = "X";
            }
            else {
                cout << setw(55) << "You didn't pick an available square, choose again." << endl << endl;
                --i;
            }
        }
    }
    return 0;
}

void theme(void) {
    //Change Colors
    system("Color B5");
}

void displayInfo(void) {
    //Print Title
    cout << setw(39) << "Erik Debye - 07.02.2022 - Lab 3" << endl;
    cout << setw(41) << "  Week 3 - Implement TicTacToe Logic" << endl;
    cout << "Commands: If-Else, Loops (Chapter 6 Part 7), Booleans" << endl;

    //Print a seperation spacer
    cout << endl;
}

void displayBoard(string sq[10]) {
    //Print TicTacToe Board
    cout << setw(26) << "¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯\n";
    cout << "       |  " << sq[0] << "  |  " << sq[1] << "  |  " << sq[2] << "  |  " << endl;
    cout << setw(26) << "¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯\n";
    cout << "       |  " << sq[3] << "  |  " << sq[4] << "  |  " << sq[5] << "  |  " << endl;
    cout << setw(26) << "¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯\n";
    cout << "       |  " << sq[6] << "  |  " << sq[7] << "  |  " << sq[8] << "  |  " << endl;
    cout << setw(26) << "¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯\n" << endl;
}

string findChoice(void) {
    //Create variable 
    string choice{};

    cout << endl;
    //Query
    cout << setw(29) << "Please select a square: ";
    //Save choice
    cin >> choice;
    cout << endl;
    //Return
    return choice;
}
