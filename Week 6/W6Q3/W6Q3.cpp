/*
Erik Debye || 27.02.2022
Week 6 -- Problem 3
Palindromes
New commands: Loops
*/

#include <iostream>
using namespace std;

//Functions
//1 Print a square
void printSq(int value);

int main()
{
    //Variables
    //1. bool flag
    bool palindrome{ false };

    while (!palindrome) {
        //Variables
        //1. numbers
        int constNum{}, mutNum{}, partNum{}, reversed{ 0 };
        //2 acc. flag + center value
        int i{ 0 }, center{};

        //Query 5 digit num
        cout << "\n\tPlease enter a positive five digit number greater than 0: ";
        cin >> constNum;

        //save to a new, mutable, variable
        mutNum = constNum;

        //The plan: Seperate one digit from num at a time (from the right) and reassemble the number in reverse
        while (mutNum > 0) {
            //Grab digit when acc. == 2, indicating we are at the 3rd index of a 5 digit num
            if (i == 2) {
                center = mutNum % 10;
            }

            //take off the right most value 
            partNum = mutNum % 10;
            //multiple reversed value by 10 (to add an 'empty' space, add the removed value to the reversed number
            reversed = (reversed * 10) + partNum;
            //Take digit off orginal value by dividing by 10 (truncated because of int type)
            //when original value gets truncated to 0, loop ends.
            mutNum = mutNum / 10;

            //add 1 to our accumulator
            i++;
        }

        //evaluate if orignal value == new reversed value
        if (constNum == reversed) {
            //change while loop flag to true
            palindrome = true;
            //output palindrome
            cout << "\n\tThis number, " << constNum << " is a palindrome\n";
            //print square
            printSq(center);
            cout << endl;
        }
        else {
            cout << "\n\tThis number, " << constNum << " is not a palindrome\n";
        }
    }
    
    return 0;
};


void printSq(int value) {
//switch case to print squares dependant of center number of palindrome
    switch (value) {
    case 9:
        cout << "\n\t* * *";
        cout << "\n\t* * *";
        cout << "\n\t* * *";

        break;
    case 8:
        cout << "\n\t* * *";
        cout << "\n\t*   *";
        cout << "\n\t* * *";
        break;
    case 7:
        cout << "\n\t*   *";
        cout << "\n\t* * *";
        cout << "\n\t*   *";
        break;
    case 6:
        cout << "\n\t*   *";
        cout << "\n\t*   *";
        cout << "\n\t*   *";
        break;
    case 5:
        cout << "\n\t*   *";
        cout << "\n\t  *  ";
        cout << "\n\t*   *";
        break;
    case 4:
        cout << "\n\t*   *";
        cout << "\n";
        cout << "\n\t*   *";
        break;
    case 3:
        cout << "\n\t    *";
        cout << "\n\t  *  ";
        cout << "\n\t*    ";
        break;
    case 2:
        cout << "\n\t  *  ";
        cout << "\n\t *   ";
        break;
    case 1:
        cout << "\n\t  *  ";
        break;
    default: cout << "\n";
    }
}