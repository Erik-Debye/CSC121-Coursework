/*
Erik Debye || 27.02.2022
Week 6 -- Problem 4
Counters
New commands: While Loops
*/

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    //Variables
    int hour{ 0 }, minute{ 0 }, second{ 0 };
    
    //Create a while loop for the hours
    while (hour < 24) {
        //While loop for minutes
        while (minute < 59) {
            //While loop for the seconds
            while (second < 59) {
                //output time
                cout << "\n\tTime: " << hour << ":" << minute << ":" << second << endl;
                //add one to second
                second++;
                //sleep program for one second
                Sleep(1000);
            }
            //add one to minute
            minute++;
            //zero out seconds
            second = 0;
        }
        //Add one to hours
        hour++;
        //zero out minutes
        minute = 0;
    }
    return 0;
};
