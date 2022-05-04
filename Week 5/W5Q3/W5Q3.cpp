/*
Erik Debye || 17.02.2022
Week 5 -- Problem 3
Bubble Sort
New commands: for loops
*/

#include <iostream>
#include <cctype> //needed for toLower()
using namespace std;

// FUNCTIONS
//1. Query Name
string qName(string type);
//3. Sort through name & output
void bubbleOut(string fullName, int length);

int main()
{
    //variables
    string first{ " " }, last{ " " }, fullName{ " " };
    int length{ 0 };

    first = qName("first");
    last = qName("last");

    //concat strings
    fullName = first + last;
    length = fullName.length();

    //call sort function 
    bubbleOut(fullName, length);

    return 0;
};

string qName(string type) {
    string name{" "};
    cout << "\n\tPlease enter your " << type << " name: ";
    cin >> name;
    cout << endl;

    //normalization of fName => needed because A != a
    int i{ 0 };
    char curr;
    //if fName[index] is a truthy value
    while (name[i]) {
        //save char @ index
        curr = name[i];
        //use toLower
        curr = tolower(curr);
        //save index as curr
        name[i] = curr;
        i++;
    };

    return name;
}

void bubbleOut(string fullName, int length) {

    for (int i = 0; i < length; i++) {
        //interate thru array
        for (int j = 0; j < length - 1; j++) {
            //if current index is > next index
            if (fullName[j] > fullName[j + 1]) {
                //save value at curr index
                char temp = fullName[j];
                //set curr index to next index value
                fullName[j] = fullName[j + 1];
                //apply saved value to next index
                fullName[j + 1] = temp;
            };
        };
    };

    cout << "\n\tHere are the letters of your name in alphabetical order: ";
    for (int i = 0; i <= length - 1; i++) {
        cout << fullName[i] << " ";
    }
    cout << endl << endl;
}

