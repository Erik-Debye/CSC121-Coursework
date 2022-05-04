/*
Erik Debye || 05.03.2022
Week 7 -- Problem 1
Random #'s
New commands: Random Number Engine
*/

#include <iostream> 
#include <random> 
#include<ctime>
using namespace std;

int main()
{
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randNumLoop1{ 1, 100 };

	//first loop - run 20 times
    for (int i = 1; i <= 20; i++) { 
        //output random number from 1 >= x <= 100 as defined in ln 16
        cout << "Loop #1: " << randNumLoop1(engine) << endl;                                 
    }

    cout << "\n\n";

    //Create a new randNum
    //redefine range to 1 <= x <= 12
    uniform_int_distribution<unsigned int> randNumLoop2{ 1, 12 };
    
    //second loop - run 20 times
    for (int i = 1; i <= 20; i++) { 
        //output random number from range defined in ln 27 
        cout << "Loop #2: " << randNumLoop2(engine) << endl;                                 
    }

    cout << "\n\n";
    
    //Create a new randNum
    //Redefine Range to 1 <= x <= 6
    uniform_int_distribution<unsigned int> randNumLoop3{ 1, 6 };

    //third loop - run 20 times
    for (int i = 1; i <= 20; i++) {   
        //output random number from range defined in ln 34
        cout << "Loop 3: " << randNumLoop3(engine) << endl;                                 
    }

    cout << "\n\n";

    //Create a new randNum
    //Redefine Range to 1 <= x <= 3
    uniform_int_distribution<unsigned int> randNumLoop4{ 1, 3 };

    //forth loop - run 20 times
    for (int i = 1; i <= 20; i++) {                                                       
        cout << "Loop 4: " << randNumLoop4(engine) << endl;                                 
    }

    cout << "\n\n";

	return 0;
}