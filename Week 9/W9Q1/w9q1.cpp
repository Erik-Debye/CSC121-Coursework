/*
Erik Debye || 17.03.2022
Week 9 -- Problem 1
New commands: sort(), begin(), end(), size()
*/

#include <iostream>
#include <vector> 
#include<string>
#include <algorithm>
using namespace std;

//functions
//display names
void disNames(vector<string> data);
//display chars
void disLetters(vector<char> data);
//display nums
void disNums(vector<int> data);


int main()
{
    //Local variables
    vector<string> names {"Ali", "Zack", "Marie", "Lisa", "Kesha", "Alix"};
    vector<char> letters {'g', 'h', 'y', 'i', 'p', 'b'};
    vector<int> nums {456, 44, 98, 311, 23, 6, 8, 112};

    //NAMES

    //display names
    cout << "\n\n\tThis is the original vector of names: \t";
    disNames(names);

    //print size
    cout << "\n\n\tWhich is composed of " << names.size() << " elements\n";

    //sort names 
    sort(names.begin(), names.end());

    //display names again
    cout << "\n\tWith sorted(), the vector is reordered: ";
    disNames(names);
    cout << "\n\n";

    //CHARS
    
    //display chars
    cout << "\n\n\tThis is the original character vector:  ";
    disLetters(letters);

    //print size
    cout << "\n\n\tWhich is composed of " << letters.size() << " elements\n";

    //sort chars
    sort(letters.begin(), letters.end());

    //display sorted chars
    cout << "\n\tWith sorted(), the vector is reordered: ";
    disLetters(letters);
    cout << "\n\n";

    //NUMS

    //display nums
    cout << "\n\n\tThis is the original numbers vector: ";
    disNums(nums);

    //print size
    cout << "\n\n\tWhich is composed of " << nums.size() << " elements\n";

    //sort nums
    sort(nums.begin(), nums.end());

    //print sorted nums
    cout << "\n\tWith sorted(), the vector is reordered: ";
    disNums(nums);
    cout << "\n\n";

    return 0;
}

void disNames(vector<string> data) {
    for (string item : data) {
        cout << item << " ";
    }
}

void disLetters(vector<char> data) {
    for (char item : data) {
        cout << item << " ";
    }
}

void disNums(vector<int> data) {
    for (int item : data) {
        cout << item << " ";
    }
}