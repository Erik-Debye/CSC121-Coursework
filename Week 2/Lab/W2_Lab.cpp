/*
Week 2 -- Lab
Erik Debye || 30.01.2022
TicTacToe Display
New commands: Functions, Arrays, Loops (Chapter 6 Part 7)
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
void displayBoard(int sq[10]);
//Querys User for number
void askNumber(void);

int main()
{
    theme();
    displayInfo();

    //Create Board Array -- Syntax source: Class Lecture on 26.01.2022
    int square[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    displayBoard(square);

    //LAB #2 - Query user for 5 numbers, save into Array, and output. Syntax source -- Page 288
    array <int, 10> numbers{};
    
    //Create an iterable to fill five spaces - Source: Beginning iterable foundations on page 218 (chaper 6 part 5) 
    for (int i{ 0 }; i <= 4; ++i) {
        askNumber();
        //Save response to current index
        cin >> numbers[i];
        //Print the number
        cout << "You entered a " << numbers[i] << "." << endl << endl;
    }
}

void theme(void) {
    //Change Colors
    system("Color B5");
}

void displayInfo(void) {
    //Print Title
    cout << setw(40) << "Erik Debye - 30.01.2022 - Lab" << endl;
    cout << setw(43) << "  Week 1 - Create a TicTacToe Display" << endl;
    cout << "Commands: Functions, Arrays, Loops (Chapter 6 Part 7)" << endl;

    //Print a seperation spacer
    cout << endl;
}

void displayBoard(int sq[10]) {
    //Print TicTacToe Board
    cout << setw(26) << "¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯\n";
    cout << "       |  " << sq[0] << "  |  " << sq[1] << "  |  " << sq[2] << "  |  " << endl;
    cout << setw(26) << "¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯\n";
    cout << "       |  " << sq[3] << "  |  " << sq[4] << "  |  " << sq[5] << "  |  " << endl;
    cout << setw(26) << "¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯\n";
    cout << "       |  " << sq[6] << "  |  " << sq[7] << "  |  " << sq[8] << "  |  " << endl;
    cout << setw(26) << "¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯\n" << endl;
}

void askNumber(void) {
    cout << setw(25) << "Please select a square by typing in its' number: ";
}