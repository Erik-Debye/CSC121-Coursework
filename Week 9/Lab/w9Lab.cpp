/*
Erik Debye || 17.03.2022
Week 9 -- Lab
Tower of Hanoi - 4
New Commands: enums, pass by reference
*/

#include <iostream>
#include <vector> 
using namespace std;

//functions
//print towers
void printTowers(vector<char> T1, vector<char> T2, vector<char> T3);
//pick source tower
int pickSource(void);
//pick destination tower
int pickDest(void);
//remove value with Bool Flag
bool removeValue(char value, vector<char>& vec);
//source error
void sourceErr(void);
//dest error
void destErr(void);
//fix dest error
void fixSource(char value, int source, vector<char>& T1, vector<char>& T2, vector<char>& T3);

//Global Enums - Towers
enum towers { towerOne = 1, towerTwo = 2, towerThree = 3};

int main()
{
    //Local variables
    //Source Tower & Destination Tower, and value to move
    int source{}, dest{};
    char value{};
    //flag for wether value removed from source
    bool sourceFlag{};
    //counter
    int moves{ 0 };
    //solution
    vector<char> solution{ ' ', 'A', 'B', 'C', 'D' };

    //Vectors (one per pole)                                                Might need a " " at the begining for for each loops
    vector<char> T1{ ' ', 'A', 'B', 'C', 'D'}, T2{' '}, T3{' '};

    //Print rules
    cout << "\n\t\t\tTHIS IS THE TOWER OF HANOI!\n\n";
    cout << "\t\t\tGAME RULES\n";
    cout << "\n\tPick numbers to move characters from Tower 1 to Tower 3.\n";
    cout << "\n\tPick a source tower first, than a destination tower next for each complete move.\n";
    cout << "\n\tTPick towers by refering to their numbers (i.e. To pick Tower 2 enter '2'.\n";
    cout << "\n\tCharacters must remain in alphabetical order.\n";
    cout << "\n\t\t\tGAME BEGINS BELOW\n\n\n";

    //do-while T3 != solution
    do {

        //add to moves
        moves++;

        //Print Towers
        printTowers(T1, T2, T3);

        //choose source
        source = pickSource();
        //choose Destination
        dest = pickDest();

        //remove value from source tower
        switch (source) {
        //if source = 1
        case towerOne:
            //grab last value of vector
            value = T1[T1.size() - 1];
            //create flag holder
            sourceFlag = removeValue(value, T1);
            //check flag
            if (sourceFlag) {
                //if value removed no further action
                break;
            }
            else {
                //remove move
                moves--;
                //break switch and current loop
                goto stop;
            }
        case towerTwo:
            value = T2[T2.size() - 1];

            sourceFlag = removeValue(value, T2);
            if (sourceFlag) {
                break;
            }
            else {
                moves--;
                goto stop;
            }
        case towerThree:
            value = T3[T3.size() - 1];

            sourceFlag = removeValue(value, T3);
            if (sourceFlag) {
                break;
            }
            else {
                moves--;
                goto stop;
            }
        default:
            //default error
            cout << "\n\n\tERROR REMOVING VALUE.";
        }

        //Add value to destination tower
        switch (dest) {
        //if dest = towerOne (1)
        case towerOne:
            //value added must be larger than existing last value
            if (value < T1[T1.size() - 1]) {
                //call error
                destErr();
                //re-add value to source vector
                fixSource(value, source, T1, T2, T3);
                //remove move
                moves--;
                //break switch and loop
                goto stop;
            }
            else {
                //add value to dest
                T1.push_back(value);
            }
            break;
        case towerTwo:
            if (value < T2[T2.size() - 1]) {
                destErr();
                fixSource(value, source, T1, T2, T3);
                moves--;
                goto stop;
            }
            else {
                T2.push_back(value);
            }
            break;
        case towerThree:
            if (value < T3[T3.size() - 1]) {
                destErr();
                fixSource(value, source, T1, T2, T3);
                moves--;
                goto stop;
            }
            else {
                T3.push_back(value);
            }
            break;
        default:
            //default error statement
            cout << "\n\n\tERROR ADDING VALUE.";
        }

        cout << "\n\n\t\tMoves: " << moves << "\n";
    
    //label set to nothing. Used to break nested code.
    stop:;

    } while (T3 != solution);

    //print congrats
    cout << "\n\n\tCongrats! You solved it in " << moves << " moves!\n";

    //Print Towers
    printTowers(T1, T2, T3);

    //evaluate num moves user made
    if (moves > 15) {
        //if more than minimun, inform user of minimum
        cout << "\n\tLeast moves required to solve this puzzle is 15.\n";
        cout << "\n\tReload to play again and lower your moves!\n";
    }
    else {
        cout << "\n\tYou solved it in the minimum amount of moves!\n";
    }


    cout << "\n\n";

    return 0;
}

void printTowers(vector<char> T1, vector<char> T2, vector<char> T3) {
    //Print Label for t1
    cout << "\n\n\tTower 1: ";

    for (char item : T1) {
        cout << item << " ";
    }
    cout << "\n";

    //Print Label for t2
    cout << "\n\n\tTower 2: ";

    for (char item : T2) {
        cout << item << " ";
    }
    cout << "\n";

    //Print Label for t3
    cout << "\n\n\tTower 3: ";

    for (char item : T3) {
        cout << item << " ";
    }
    cout << "\n\n\n";
}

int pickSource(void)
{
    int source{};

    cout << "\n\tPlease choose a source tower: ";
    cin >> source;

    while (cin.fail() || source < 1 || source > 3)
    {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }

        cout << "\n\n\tPlease pick a valid source tower: ";
        cin >> source;
    }

    return source;
}

int pickDest(void)
{
    int dest{};

    cout << "\n\tPlease choose a destination tower: ";
    cin >> dest;

    while (cin.fail() || dest < 1 || dest > 3)
    {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }

        cout << "\n\n\tPlease pick a valid destination tower: ";
        cin >> dest;
    }

    return dest;
}

bool removeValue(char value, vector<char>& vec) {
    //check if value exists
    if (value == ' ') {
        //call error
        sourceErr();
        //break switch and current loop
        return false;
    }
    else {
        //take value off t1
        vec.pop_back();
        return true;
    }
}

void fixSource(char value, int source, vector<char>& T1, vector<char>& T2, vector<char>& T3) {
    //readd value to source
    switch (source) {
        //if 1
    case towerOne:
        //push value to it
        T1.push_back(value);
        break;
    case towerTwo:
        T2.push_back(value);
        break;
    case towerThree:
        T3.push_back(value);
        break;
    default: cout << "\n\tError in replacing source character.\n";
    }
}

void sourceErr(void) {
    cout << "\n\n\t\t\tERROR!\n";
    cout << "\n\tThe chosen Tower had no characters! Retry Move.\n\n";
}

void destErr(void) {

    cout << "\n\n\t\t\tERROR!\n";
    cout << "\n\tThe chosen destination will result in a non-alphabetical order! Retry Move.\n\n";
}