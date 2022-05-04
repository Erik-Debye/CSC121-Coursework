/*
Erik Debye || 05.03.2022
Week 7 -- Problem 2
Random Pushback Names
New commands: vector<string>
*/

#include <iostream>
#include <vector>  //needed for vector
#include<string>
#include <algorithm> //needed for sort()

using namespace std;

int main()
{
   //create variables
   //1. vector of strings
   vector<string> names;
   //2. Name to push
   string needsPush;


   //Grab name
   cout << "\n\tPlease enter a name: ";
   cin >> needsPush;
   cout << "\n";

   //normalize data
   for (int i = 0; i <= needsPush.length(); i++) {
       needsPush[i] = tolower(needsPush[i]);
   }

   //do while loop until user hits crtl z
    do{       
        //normalize data
        for (int i = 0; i <= needsPush.length(); i++) {
            needsPush[i] = tolower(needsPush[i]);
        }

        //push into vector
        names.push_back(needsPush);

        //Grab name
        cout << "\n\tPlease enter a name (ctrl + z to quit): ";
    } while (cin >> needsPush);

    //sort 
    sort(names.begin(), names.end());

    //begin output
    cout << "\n\tNames in alphabetical order: \n\n\t";

    //iterate through vector
    for(string name : names)
    {
        //Capitalize first letter
        name[0] = toupper(name[0]);

        //print name
        cout << name << "\n\t";
    }

    cout << "\n\n";

    return 0;
}
