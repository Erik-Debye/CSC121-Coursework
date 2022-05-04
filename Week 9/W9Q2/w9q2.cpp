/*
Erik Debye || 17.03.2022
Week 9 -- Problem 2
New commands: 
*/

#include <iostream>
#include <vector> 
#include<string>
#include<windows.h>
using namespace std;

//functions
int protectData(void);


int main()
{
    //variables
    int color{};
    enum colors {Red, Green, Pink, Blue, Violet, Yellow, White};

    //query user to pick a num 0 - 6
    color = protectData();
   
    //output chosen color
    switch (color) {
    case Red: 
        system("color 47");
        cout << "\n\tYou picked RED";
        break;
    case Green: 
        system("color 27");
        cout << "\n\tYou picked GREEN";
        break;
    case Pink:
        system("color C0");
        cout << "\n\tYou picked PINK";
        break;
    case Blue:
        system("color 17");
        cout << "\n\tYou picked BLUE";
        break;
    case Violet:
        system("color D0");
        cout << "\n\tYou picked VIOLET";
        break;
    case Yellow:
        system("color E0");
        cout << "\n\tYou picked YELLOW";
        break;
    case White:
        system("color F0");
        cout << "\n\tYou picked WHITE";
        break;
    }

    cout << "\n\n";
}

int protectData(void)
{
    int chosenNum{};

    cout << "\n\tPlease pick a color by entering a whole number from 0 to 6: ";
    cin >> chosenNum;

    while (cin.fail() || chosenNum < 0 || chosenNum > 6)
    {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }

        cout << "\n\n\tReenter a valid whole number from 0 to 6: ";
        cin >> chosenNum;
    }

    return chosenNum;
}