/*
Week 1 -- Lab 1
Erik Debye || 24.01.2022
TicTacToe Display 
New commands: \escape sequences, cout, setw(), & system("Color ##")
*/

#include <iostream> //Necessary for IO
#include <iomanip> //Neceassary for IO manipulation
#include <Windows.h> //Necessary to change colors || source: https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/
using namespace std;

int main()
{
    //Change Colors
    system("Color B5");

    //Print Title
    cout << setw(36) << "Erik Debye - 21.01.2022 - Lab#1\n";
    cout << "  Week 1 - Create a TicTacToe Display\n";
    cout << setw(35) << "Commands: \escape and setw()\n";

    //Print a seperation spacer
    cout << "\n";

    //Print TicTacToe Board
    cout << setw(26) << "----- ----- -----\n";
    cout << "       |  1  |  2  |  3  |\n";
    cout << setw(26) << "----- ----- -----\n";
    cout << "       |  4  |  5  |  6  |\n";
    cout << setw(26) << "----- ----- -----\n";
    cout << "       |  7  |  8  |  9  |\n";
    cout << setw(26) << "----- ----- -----\n";

    //Print a seperation spacer
    cout << "\n"; 

    //Print query to user
    cout << "Please select a square to start the game...\n";
}

