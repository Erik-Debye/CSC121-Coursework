/*
Erik Debye || 17.02.2022
Week 5 -- Problem 2
Counters - Accumulation
New commands: for loops
*/

#include <iostream>
#include <math.h>
using namespace std;

//Function that returns and entered score
double enterScore();
//sorter
void sort(double scores[5], int length);

int main()
{
    //variables
    
    //1. inputted Score 
    double score;
    //2. All inputted scores
    double scores[5];                                                                     
    //3. sum of all scores -- accumulator
    double sum{ 0 };
    //4. avg of scores
    double avg;
    //5. iterator + length
    int i{ 0 }, currLength{1};

    //while loop to regulate how many times this runs (5)
    while (i < 5) {
        //query user 
        score = enterScore();
        //populate array using i to reference array index
        scores[i] = score;
        //calc and print sum
        sum += score;
        cout << "\n\tThe current total of all scores is " << sum << ".\n";
        //calc average 
        avg = sum / currLength;
        cout << "\n\tThe current average of all scores is " << avg << ".\n";
        i++;
        currLength++;
    };

    //call sort function 
    sort(scores, 5);
};

double enterScore() {
    //create variable to hold value
    double enteredScore{};
    cout << "\n\tPlease enter a score: ";
    cin >> enteredScore;
    cout << endl;

    return enteredScore;
}

void sort(double scores[5], int length) {

    for (int j = 0; j < length; j++ ) {
        //interate thru array
        for (int i = 0; i < length - 1; i++) {
            //if current index is > next index
            if (scores[i] < scores[i + 1]) {
                //save value at curr index
                double temp = scores[i];
                //set curr index to next index value
                scores[i] = scores[i + 1];
                //apply saved value to next index
                scores[i + 1] = temp;
            };
        };
    };

    cout << "\n\tHere are your scores, in ascending order: ";

    for (int j = 0; j <= length - 1; j++) {
        cout << scores[j] << " ";
    }
}

