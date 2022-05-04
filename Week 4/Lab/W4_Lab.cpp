/*
Week 6 -- Lab
Erik Debye || 27.02.2022
TicTacToe Game -- Protecting Data
New commands : While Loops, cin.fail(), cin,ignore()
*/

#include <iostream>
#include <Windows.h> 
#include <string>
using namespace std;

//Functions

//Change theme
void theme(void);
//Displays Title Info
void displayInfo(void);
//Displays TicTacToe board
void displayBoard(string sq[10]);
//Querys User to start playing
string findChoice(void);                           //<-- Lab 6 takes place in this function
//computer choice
string computerChoice(void);
//Check for player wins
bool winsChecker(string sq[10]);

int main()
{
    //Run themes + info
    theme();
    displayInfo();

    //Game Data Initialization
    string square[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    //set to num of squares aka number of elements. 
    int numSqs = sizeof square / sizeof square[0];
    //Determines if game needs to go on
    bool ifPlaying;
    //User Choice
    string choice;

    //Create an iterable to run through turns - Source: Beginning iterable foundations on page 218 (chaper 6 part 5) 
    for (int i{ 0 }; i <= numSqs; ++i) {

        // 1) Check for wins, save bool return
        ifPlaying = winsChecker(square);

        // 2)Conditional based whether game is t/f
        if (!ifPlaying) {
            break;
        }

        if (i % 2 == 0) {
            //display game
            displayBoard(square);
            //Query and save user choice 
            choice = findChoice();

            //Check if choice equals an X or O
            if (choice == "X" || choice == "x" || choice == "O" || choice == "o") {
                cout << "\n\tSquare is already chosen, choose a valid square.\n\n";
                --i;
            }
            else {

                //Create trigger bool
                bool foundSq{ false };

                //Search through squares
                for (int j{ 0 }; j <= numSqs; j++) {

                    //Convert sqs to Xs or Os if match found
                    if (choice == square[j]) {
                        //change game data to X
                        square[j] = "X";
                        //trigger flag
                        foundSq = true;
                        //exit loop
                        break;
                    }
                }
                //Check bool to see if match found
                if (!foundSq) {
                    //if not
                    --i;
                    cout << "\n\tYou didn't pick an available square, choose again." << endl << endl;
                }
            }
        }
        //computer turns whenever turn is even (every other turn)
        else {

            cout << "\n\tComputer Choosing....\n";
            Sleep(1000);

            //call computer choice
            choice = computerChoice();

            //Create trigger bool
            bool foundSq{ false };

            //Search through squares
            for (int j{ 0 }; j <= numSqs; j++) {

                //Convert sqs to Xs or Os if match found
                if (choice == square[j]) {
                    //change game data to O
                    square[j] = "O";
                    //trigger flag
                    foundSq = true;
                    //print choice
                    cout << "\n\tComputer chose " << choice << "\n";
                    //end loop
                    break;
                }
            }
            //Check bool to see if match found
            if (!foundSq) {
                //if not
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
    cout << "\n\tErik Debye - 27.02.2022 - Lab 6\n";
    cout << "\n\tWeek 6 - TicTacToe -- Protected Data\n";
    cout << "\n\tNew commands : While Loops, cin.fail(), cin,ignore()\n\n";

}

void displayBoard(string sq[10]) {
    //Print TicTacToe Board
    cout << "\n\t ¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯";
    cout << "\n\t|  " << sq[0] << "  |  " << sq[1] << "  |  " << sq[2] << "  |  ";
    cout << "\n\t ¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯";
    cout << "\n\t|  " << sq[3] << "  |  " << sq[4] << "  |  " << sq[5] << "  |  ";
    cout << "\n\t ¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯";
    cout << "\n\t|  " << sq[6] << "  |  " << sq[7] << "  |  " << sq[8] << "  |  ";
    cout << "\n\t ¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯\n";
}

//lab - 6 
string findChoice(void) {
    //Create variable 
    string choice{};

    //query choice
    cout << "\n\n\tPlease select a square: ";
    //Save choice
    cin >> choice;

    //LAB 6 - Protect Data
    //while cin.fail() exists, loop until valid data is entered.
    while (cin.fail()) {
        //clear error
        cin.clear();
        //reset input
        cin.ignore(1000, '\n');

        //re-query choice
        cout << "\n\tInvalid choice, please try again: ";
        cin >> choice;
    }

    cout << endl;
    //Return
    return choice;
}

string computerChoice(void) {
    //Create variables for random number
    int random{ 0 };
    string randomStr{""};

    //find random num from 1 - 9
    random = (rand() % 9) + 1;
    //using to_string() from std::string -> https://en.cppreference.com/w/cpp/string/basic_string/to_string
    randomStr = to_string(random);

    return randomStr;

}

bool winsChecker(string sq[10]) {
    //If the top, middle, or bottom rows are full of X's -- This is a player win
    if (sq[0] == "X" && sq[1] == "X" && sq[2] == "X" || sq[6] == "X" && sq[7] == "X" && sq[8] == "X" || sq[3] == "X" && sq[4] == "X" && sq[5] == "X") {
        //Displays board (with win)
        displayBoard(sq);

        //Specify win by row
        if (sq[0] == "X") {
            cout << "\n\tPlayer with a horizontal win on the top row!\n";
        }
        else if (sq[3] == "X") {
            cout << "\n\tPlayer with a horizontal win on the center row!\n";
        }
        else {
            cout << "\n\tPlayer with a horizontal win on the last row!\n";
        }
        //Returns false - saved to ifplaying 
        return false;
    }
    //If the top, middle, or bottom rows are full of O's -- This is a computer win
    else if (sq[0] == "O" && sq[1] == "O" && sq[2] == "O" || sq[6] == "O" && sq[7] == "O" && sq[8] == "O" || sq[3] == "O" && sq[4] == "O" && sq[5] == "O") {
        //Displays winning board
        displayBoard(sq);
        
        //Specify win by row
        if (sq[0] == "O") {
            cout << "\n\tComputer with a horizontal win on the top row!\n";
        }
        else if (sq[3] == "O") {
            cout << "\n\tComputer with a horizontal win on the center row!\n";
        }
        else {
            cout << "\n\tComputer with a horizontal win on the last row!\n";
        }

        return false;
    }
    //If the left, middle, or right column is filled with X's -- This is a player win
    else if (sq[0] == "X" && sq[3] == "X" && sq[6] == "X" || sq[2] == "X" && sq[5] == "X" && sq[8] == "X" || sq[1] == "X" && sq[4] == "X" && sq[7] == "X") {
        //display winning board
        displayBoard(sq);

        //Specifiy win by column
        if (sq[0] == "X") {
            cout << "\n\tPlayer with a vertical win on the first column!\n";
        }
        else if (sq[1] == "X") {
            cout << "\n\tPlayer with a vertical win on the second column!\n";
        }
        else {
            cout << "\n\tPlayer with a vertical win on the third column!\n";
        }

        return false;
    }
    //If the left, middle, or right column is filled with o's -- This is a computer win
    else if (sq[0] == "O" && sq[3] == "O" && sq[6] == "O" || sq[2] == "O" && sq[5] == "O" && sq[8] == "O" || sq[1] == "O" && sq[4] == "O" && sq[7] == "O") {
        //display winning board
        displayBoard(sq);
        
        //Specifiy win by column
        if (sq[0] == "O") {
            cout << "\n\tComputer with a vertical win on the first column!\n";
        }
        else if (sq[1] == "O") {
            cout << "\n\tComputer with a vertical win on the second column!\n";
        }
        else {
            cout << "\n\tComputer with a vertical win on the third column!\n";
        }

        return false;
    }
    //If the diagonal from the left top to the bottom right OR the diagonal from the right top to the bottom left are full of X's -- player win
    else if (sq[0] == "X" && sq[4] == "X" && sq[8] == "X" || sq[2] == "X" && sq[4] == "X" && sq[6] == "X") {
        //display winning board
        displayBoard(sq);
        
        //specifiy diagonal direction
        if (sq[0] == "X") {
            cout << "\n\tPlayer with a diagonal win from the left rightwards!\n";
        }
        else {
            cout << "\n\tPlayer with a diagonal win from the right leftwards!\n";
        }

        return false;
    }
    //If the diagonal from the left top to the bottom right OR the diagonal from the right top to the bottom left are full of O's -- computer win
    else if (sq[0] == "O" && sq[4] == "O" && sq[8] == "O" || sq[2] == "O" && sq[4] == "O" && sq[6] == "O") {
        displayBoard(sq);
        
        //specifiy diagonal direction
        if (sq[0] == "O") {
            cout << "\n\tComputer with a diagonal win from the left rightwards!\n";
        }
        else {
            cout << "\n\tComputer with a diagonal win from the right leftwards!\n";
        }

        return false;
    }
    else {
        //if no win, return true to ifplaying (game runs through another input)
        return true;
    }
}