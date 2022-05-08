
#include "PlayerStats.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm> //transform function
using namespace std;

//points
// Full house: Get three of a kind and a pair, e.g. 1,1,3,3,3 or 3,3,3,6,6. Scores 25 points.

// YAHTZEE: Five of a kind. Scores 50 points.

//Chance: You can put anything into chance, it's basically like a garbage can when you don't have anything else you can use the dice for.
// The score is simply the sum of the dice.

//global variables
int chance_total_score{ 0 };
int fullHouse_total_score{ 0 };
int yahtzee_total_score{ 0 };
vector<int> diceValues{};


//prototypes
void displayScores();

int main() {
	//Declare variables
	const int DICE = 5;
	string rollDice{ "" };
	int currentTurn = 0;
	int rolls[5] = { 0 },
		num_count[6] = { 0 };
	bool two_kind = false,
		three_kind = false;
	char reroll[5];
	int roll[DICE];
	int scorecardInput;

	//seed the rng
	srand(time(NULL));

	cout << "\n\tWelcome to Yahtzee (ultra-simplified)!";


	while (currentTurn <= 2) {
		//roll dice
		cout << "\n\n\tPress 'r' to roll: ";
		cin >> rollDice;
		//to lower case
		transform(rollDice.begin(), rollDice.end(), rollDice.begin(), ::towlower);

		//fail safe --if user enters != r
		while (rollDice != "r" || cin.fail())
		{
			while (cin.fail()) {
				cin.clear(); // flush out bad data
				cin.ignore(); // reset buffer, ready for the next input
				cin.ignore(INT_MAX, '\n'); // ignore last input as a whole

			}

			cout << "\n\tYou have not indicated that you would like to start..." << endl;
			cout << "\n\tPress 'r' to roll: ";
			cin >> rollDice;
		}

		//generate random dice rolls, pass to roll array
		for (int i = 0; i < DICE; i++) {
			roll[i] = rand() % 6 + 1;
		}

		//outputting dice values of the first roll
		//add them to vector for comparison
		cout << "\n\t\tYou rolled: ";
		for (int i = 0; i < DICE; i++)
		{
	
			cout << roll[i] << ", ";
		}

		cout << "\n\tType y to reroll or n to keep - followed by the ENTER key...  \n\t[EX. 'y y n n n' would keep the last three dice]" << endl;
		cin >> reroll[0] >> reroll[1] >> reroll[2] >> reroll[3] >> reroll[4];

		//reroll loop
		for (int i = 0; i < DICE; i++) {
			if (reroll[i] == 'y') {
				roll[i] = rand() % 6 + 1;
			}
			else if (reroll[i] == 'n') {
				roll[i];
			}
			else cout << "\n\tSorry you entered an invalid letter." << endl;
		}

		//outputting dice values of the second roll
		//add them to vector for comparison
		cout << "\n\tYour second roll is: ";
		for (int i = 0; i < DICE; i++)
		{
			cout << roll[i] << ", ";
		}

		cout << "\n\tType y to reroll or n to keep - followed by the ENTER key...  \n\t[EX. 'y y n n n' would keep the first three dice]" << endl;
		cin >> reroll[0] >> reroll[1] >> reroll[2] >> reroll[3] >> reroll[4];

		for (int i = 0; i < DICE; i++) {
			if (reroll[i] == 'y') {
				roll[i] = rand() % 6 + 1;

			}
			else if (reroll[i] == 'n') {
				roll[i];
			}
			else cout << "\n\tSorry you entered an invalid letter." << endl;
		}

		//outputting dice values of the final roll
		//add them to vector for comparison
		cout << "\n\tThe values of your third roll are: ";
		for (int i = 0; i < DICE; i++)
		{
			diceValues.push_back(roll[i]);

			//TESTING

			//yahtzee example
			// vector<int> diceValues {5,5,5,5,5};

			//fullhouse example
			//vector<int> diceValues {3,3,5,5,5};

			num_count[diceValues[i] - 1]++;
			cout << diceValues[i] << ", ";
		}

		for (unsigned int i = 0; i < sizeof(num_count) / sizeof(int); ++i)
		{
			switch (num_count[i])
			{
			case 2:
				two_kind = true;
				break;
			case 3:
				three_kind = true;
				break;
			}
		}

		cout << endl;


		//displays scorecard categories
		cout << "Which category would you like to score this in" << endl;
		cout << "1 - Chance " << endl;
		cout << "2 - Full House " << endl;
		cout << "3 - Yahtzee " << endl;


		//asks player to choose where to score
		cout << "\nEnter 1-3 to choose a category." << endl;
		cin >> scorecardInput;

		//assigns points
		for (int i = 0; i < DICE; i++) {
			//determines score for chance category
			if (scorecardInput == 1) {
				//sum of all 5 dice
				chance_total_score += roll[i];
			}

			if (scorecardInput == 2) {
				if (two_kind && three_kind)
				{
					cout << "Yes Full House!" << endl;
					fullHouse_total_score += 25;
					break;
				}
				else
				{
					cout << "Not Full House" << endl;
					system("pause");
				}
			}
			//determines score for yahtzee category
			if (scorecardInput == 3) {
				if (adjacent_find(diceValues.begin(), diceValues.end(), std::not_equal_to<>()) == diceValues.end())
				{
					//update yahtzee score if yahtzee is found
					yahtzee_total_score += 50;
					break;
				}

				else
				{
					cout << "This is not a yahtzee" << endl;
					//allow retry
					return 0;
				}
			}

		}

		displayScores();
		currentTurn++;
	}

	system("pause");
	return 0;
}

void displayScores()
{
	//displays scorecard scores
	cout << "\n";
	cout << "\t\tCurrent Scores:" << endl;
	cout << "\t\t1 - Chance: " << chance_total_score << endl;
	cout << "\t\t2 - Full House: " << fullHouse_total_score << endl;
	cout << "\t\t3 - Yahtzee: " << yahtzee_total_score << endl;
}


