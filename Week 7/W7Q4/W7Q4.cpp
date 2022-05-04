/*
Erik Debye || 05.03.2022
Week 7 -- Problem 4
Accounting
New commands: do while & vectors
*/

#include <iostream>
#include <vector> 
#include<string>


using namespace std;

int main()
{
   //Create vars
   //1. name of bill
    vector<string> names;
   //2. bill amount
    vector<double> amounts;
   //3. name to push
    string pushName{};
   //4. $ to push
    double pushAmount{};
   //5. total bill amount
    double total{ 0 };

    //Grab name
    cout << "\n\tPlease enter a name: ";
    cin >> pushName;
    cout << "\n";

    do {
        //push into vector
        names.push_back(pushName);

        //Grab amount
        cout << "\n\tPlease enter the bill amount: ";
        cin >> pushAmount;
        cout << "\n";

        //push into vector
        amounts.push_back(pushAmount);

        //add to total
        total += pushAmount;

        //Grab name
        cout << "\n\tPlease enter a name (or press crtl + z to quit): ";

    } while (cin >> pushName);

    //output total
    cout << "\n\n\tThe total bill is: $" << total << "\n\n";

    return 0;
}
