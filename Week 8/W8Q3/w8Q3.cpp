/*
Erik Debye || 12.03.2022
Week 8 -- Problem 3
Global Variables
New commands: Global,static, & local variables
*/

#include <iostream>
#include<string>
using namespace std;

//Functions
void a(void);
void b(void);
void c(int local);

//global counter
int global = 1;

int main()
{
    //local variables
    string answer{ " " };
    //local counter
    int local = 1;

    //print initial query
    cout << "\n\tPlease enter A, B, or C: ";
    cin >> answer;
    
    do {
        if (answer == "A") {
            //call function a
            a();
        }
        else if (answer == "B") {
            //call func b
            b();
        }
        else if (answer == "C") {
            //call func c
            c(local);
            //add one to local counter
            local++;
        }
        else {
            cout << "\n\tInvalid Choice, Try Again";
        }

        //print query with exit
        cout << "\n\tPlease enter A, B, or C (or CTRL + Z to quit): ";
    } while (cin >> answer);

    return 0;
}

//uses global counter
void a(void)
{
    cout << "\n\t\t";
    //loop until global counter hit
    for (int i = 0; i < global; i++) {
        cout << "A";
    }
    global++;

    cout << "\n";
}

//uses static local counter
void b(void)
{
    //create static var
    static int staticLocal = 1;
    cout << "\n\t\t";
    //loop until counter has been hit, -> counter = 1, output = B ; counter = 2, output = BB
    for (int i = 0; i < staticLocal; i++)
    {
        cout << "B";
    }
    //add one to counter (saved)
    staticLocal++;
    cout << "\n";
}

//takes the counter from int main() as a param
void c(int local)
{
    cout << "\n\t\t";
    //loop until counter hit
    for (int i = 0; i < local; i++)
    {
        cout << "C";
    }
    cout << "\n";
}