#pragma once
#include <iostream>
using namespace std;

class PlayerStats
{
public:
	PlayerStats(string submittedName) {
		name = name;
	}
	void displayScores() {
		cout << "\n\t\tPlayer: " << name << endl;
		cout << "\t\tCurrent Scores:" << endl;
		cout << "\t\t1 - Chance: " << chance_total_score << endl;
		cout << "\t\t2 - Full House: " << fullHouse_total_score << endl;
		cout << "\t\t3 - Yahtzee: " << yahtzee_total_score << endl;
	}

private:
	int chance_total_score{ 0 };
	int fullHouse_total_score{ 0 };
	int yahtzee_total_score{ 0 };
	string name;
};
