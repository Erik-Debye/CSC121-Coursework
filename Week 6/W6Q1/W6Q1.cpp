/*
Erik Debye || 27.02.2022
Week 6 -- Problem 1
Protected Data
New commands: While Loops
*/

#include <iostream>
using namespace std;

// FUNCTIONS
//1 
int scoreCheck(void);

int main()
{
    //Variables
    //1. score, accumulator == total
    int score{ 0 }, total{ 0 };
    //2. enter another score?
    char choice{ 'y' };
    bool again{ true };

    while(again){
        //Find Score
        score = scoreCheck();
        //Add normalized score to total
        total += score;
        //output score
        cout << "\n\tScore = " << score;

        //see if user has another score
        cout << "\n\tWould you like to enter another score? (y or n)";
        cin >> choice;

        //if yes, set bool flag to true
        if (choice == 'y' || choice == 'Y') {
            again = true;
        }
        else {
            //if no, set bool flag to false (exits loop)
            again = false;
        }
    }
                                        

    return 0;
};

int scoreCheck(void) {
    //scoped score var
    int score{};

    //query score
    cout << "\n\tPlease enter a score: ";
    cin >> score;

    //Check conditions of score [type, >0, <100]
    while (cin.fail() || score < 0 || score > 100) {
        //if type != int
        if (cin.fail()) {
            //clear error flag source: https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
            cin.clear();
            //ingore last input 
            cin.ignore(1000, '\n');

            //Query new score
            cout << "\n\tYou entered something other than a whole number. Try again: ";
            cin >> score;
        }
        //if out of range
        else if (score < 0 || score > 100) {
            //Query new score
            cout << "\n\tYou entered a score less than 0 or above 100. Try again: ";
            cin >> score;
        }
        else {
            //report an error in conditional logic
            cout << "\n\tThere was an error.";
            return 0;
        }
    }

    //return normalized data;
    return score;
}