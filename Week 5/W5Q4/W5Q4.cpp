/*
Erik Debye || 17.02.2022
Week 5 -- Problem 4
Telling Time
New commands: nesting loops -- https://www.cplusplus.com/reference/ctime/
*/

#include <iostream>
#include <Windows.h>

using namespace std;

// FUNCTIONS


int main()
{
    //hours
    for (int hours = 0; hours <= 24; hours++) {
        //minutes
        Sleep(1000);
        for (int minutes = 0; minutes <= 59; minutes++) {
            //seconds
            Sleep(500);
            for (int seconds = 0; seconds <= 59; seconds++) {
                cout << "\n\t" << hours << "::" << minutes << "::" << seconds;
                Sleep(100);
            }
        }
    }
    return 0;
};


