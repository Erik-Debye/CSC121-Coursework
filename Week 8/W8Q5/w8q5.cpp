/*
Erik Debye || 12.03.2022
Week 8 -- Problem 5
Call By Reference
New commands: Global,static, & local variables
*/

#include <iostream>
#include<string>
using namespace std;

//Functions
int byValue(int x);
int byReference(int& y);

int main()
{
    //local variables
    int x{}, y{};

    //grab x
    cout << "\n\tPlease enter a positive, whole number: ";
    cin >> x;

    cout << "\n\tWhen " << x << " is passed by value into byValue(), the function returns " << byValue(x) << ".";
    cout << "\n\tHowever, " << x << " remains unchanged.";
    
    //grab y
    cout << "\n\n\tPlease enter another positive, whole number: ";
    cin >> y;

    cout << "\n\tWhen " << y << " is passed by reference into byRefernce(), the function returns ";
    //function here needs to be on a seperate line. Otherwise stack goes [byReference(y) -> print statement] & byReference mutates y before printed.
    cout << byReference(y) << ".";
    cout << "\n\tHowever, this also changes y to " << y << ".\n\n";

    return 0;
}

//Pass by value
int byValue(int x) {
    return x *= x;
}

//pass by reference
int byReference(int& y) {
    return y *= y;
}