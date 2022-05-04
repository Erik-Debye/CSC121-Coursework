/*
Erik Debye || 17.03.2022
Week 9 -- Problem 3
New commands: functions
*/

#include <iostream>
#include <vector> 
#include<string>
#include <time.h>
#include <Windows.h>
using namespace std;

//functions
//player choosing
int chooseChoice(void);
//computer choosing
int randChoice(void);
//define choices
string defineChoice(int choice);

int main()
{
    //Local variables
    enum choices {Rock = 1, Paper = 2, Scissors = 3};
    //choices
    int playerChoice{}, compChoice{};
    //accumulators
    int playerWins{ 0 }, compWins{ 0 }, draws{ 0 }, acc{ 1 };

    //Print rules
    cout << "\n\t  ROCK, PAPER, SCISSORS, GO!\n";
    cout << "\n\t\t  GAME RULES\n\n";
    cout << "\tRock = 1  Paper = 2  Scissors = 3\n\n";

    while (acc <= 5) {
        //let player choose a number
        playerChoice = chooseChoice();

        cout << "\n\tPlayer chose " << defineChoice(playerChoice) << "\n";

        //let computer choose
        cout << "\n\tComputer making a choice...\n";

        compChoice = randChoice();

        Sleep(1000);

        cout << "\n\tComputer chose " << defineChoice(compChoice) << "\n";

        Sleep(1500);

        //eval winner and/or draw
        if (playerChoice > compChoice) {
            cout << "\n\tPlayer wins! " << defineChoice(playerChoice) << " beats " << defineChoice(compChoice);
            playerWins++;
        }
        else if (compChoice > playerChoice) {
            cout << "\n\tComputer wins! " << defineChoice(compChoice) << " beats " << defineChoice(playerChoice);
            compWins++;
        }
        else {
            cout << "\n\tIt's a draw! Reload to play again!\n";
            draws++;
        }
        //add to game count
        acc++;

        cout << "\n\n\n\tPlayer Wins: " << playerWins;
        cout << "\n\n\tComputer Wins: " << compWins;
        cout << "\n\n\tDraws: " << draws << "\n\n";
    }

    cout << "\n\n";
    return 0;
}

int chooseChoice(void)
{
    int chosenNum{};

    cout << "\n\tPlease pick a number from 1 to 3: ";
    cin >> chosenNum;

    while (cin.fail() || chosenNum < 1 || chosenNum > 3)
    {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }

        cout << "\n\n\tReenter a valid number from 1 to 3: ";
        cin >> chosenNum;
    }

    return chosenNum;
}

int randChoice(void) {
    
    int chosenNum{};
    
    //rng
    srand(time(0));
    chosenNum = (rand() % 3) + 1;
    
    return chosenNum;

}

string defineChoice(int choice) {
    switch (choice) {
    case 1:
        return "Rock";
        break;
    case 2:
        return "Paper";
        break;
    case 3:
        return "Scissors";
        break;
    }
}