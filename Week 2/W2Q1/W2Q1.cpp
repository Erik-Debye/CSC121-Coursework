/*
Week 2 -- Problem 1
Data Types and Basic Mathematics
Erik Debye || 24.01.2022
*/


#include <iostream>
using namespace std;

int main()
{
    //Declaration of variables
    string name{" "};
    int age{ 0 }; //Assuming Whole Numbers
    double gpa{ 0 }; //Needs to be a double for partial numbers

    //Querying user for their information
    cout << "Please enter your name.\n";
    cin >> name;
    cout << "Please enter your age.\n";
    cin >> age;
    cout << "Please enter your GPA.\n";
    cin >> gpa;

    //Calculation stage (add 3 to age & add 1.2 to gpa)
    age += 3;
    gpa += 1.2;

    //Spacer
    cout << "\n";

    //Printing out the name, calculated age, and calculated gpa
    cout << "Hi " << name << ", your new age is " << age << ", and your new GPA is " << gpa << ".\n";
}
