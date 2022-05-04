/*
Erik Debye || 05.03.2022
Week 7 -- Problem 3
Ranged Loops
New commands: elem loops
*/

#include <iostream>
#include <vector> 
#include<string>


using namespace std;

int main()
{
    //Create vars
    //1. int arr
    vector<int> nums{ 4, 2, 6, 8, 5 ,9 };
    //2.Accum
    int sum{ 0 };

    //for each num elem in nums object
    for (int num : nums) {
        sum += num;
        //output sum
        cout << "\n\tTotal: " << sum << "\n\n";
    }  

    return 0;
}
