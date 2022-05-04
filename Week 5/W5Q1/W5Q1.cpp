/*
Erik Debye || 16.02.2022
Week 5 -- Problem 1
Counters
New commands: for loops
*/

#include <iostream>
#include <math.h>

using namespace std;

//check primeness
bool isPrime(int num);
//going down
void up();
//going downward
void down();

int main()
{
    string choice{ " " };
    int i = 0;

    while (i < 3) {
        cout << "\n\tPlease choose up or down: ";
        cin >> choice;
        cout << endl;

        if (choice == "up") {
            up();
            i++;
        }
        else if (choice == "down") {
            down();
            i++;
            cout << endl;
        }
        else {
            cout << "\n\tPlease choice a valid choice." << endl;;
        };
    };
};

bool isPrime(int num) {
    //Must be non-prime
    if (num <= 2) {
        return false;
    };

    //prime numbers are not divisible by any prime <= it's sqrt
    int maxRoot = floor(sqrt(num));

    //Cycle through iterator until it reaches the max sqrt value, check divisibility. If divisible = nonprime
    for (int j = 2; j <= maxRoot; j++) {
        if (num % j == 0) {
            return false;
        };
    };

    return true;
};

void up() {
    for (int k = 1; k <= 100; k++) {
        //if prime?
        bool prime = isPrime(k);

        cout << "\t" << k << " ";

        //if prime = true, print new line
        if (prime) {
            cout << "\n";
        }
    }
};

void down() {
    for (int k = 100; k > 0; k--) {
        //if prime?
        bool prime = isPrime(k);
        //if prime = true, skip prime
        if (!prime) {
            cout << k << " ";
        }
        
    }
}