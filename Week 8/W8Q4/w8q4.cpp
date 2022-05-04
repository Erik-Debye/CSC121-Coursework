/*
Erik Debye || 12.03.2022
Week 8 -- Problem 4
Recusion & Factorials
New commands: 
*/

#include <iostream>
#include <vector>
using namespace std;

//functions
int findFact(int num);

int main()
{
    //all nums to be factorialed
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int num : nums) {
        cout << "\n\n\tThe factorial of " << num << " is " << findFact(num) << ".";
    }

    cout << "\n";

    return 0;
}

int findFact(int num) {
    if (num == 0) {
        return 1;
    }
    else return findFact(num - 1) * num;
}