/*
Erik Debye || 07.03.2022
Week 8 -- Problem 2
Functions
New commands: functions
*/

#include <iostream>
#include <vector> 
#include<string>
using namespace std;

//Functions
int sumNameAge(string name, int age);

int main()
{
    //Local variables
    string name{};
    int age{};

    cout << "\n\n\tPlease enter your name: ";
    cin >> name;

    cout << "\n\tPlease enter your age: ";
    cin >> age;

    cout << "\n\tLength of your name: " << name.length();

    cout << "\n\n\tYour age + the number of letters in your name sums to: " << sumNameAge(name, age) << "\n\n";

    return 0;
}

//function defined
int sumNameAge(string name, int age) {
    //local variable
    int total{};

    total = age + name.length();

    return total;
}