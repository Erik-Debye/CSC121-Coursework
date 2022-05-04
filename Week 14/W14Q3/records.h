#pragma once
#include <iostream>
#include <map>
using namespace std;

class Records {
public: 

	Records() {
		//insert pairs into Map when class initialized
		gameRecords.insert(pair<string, int>("Rounds", 0));
		gameRecords.insert(pair<string, int>("Player", 0));
		gameRecords.insert(pair<string, int>("Dealer", 0));
		gameRecords.insert(pair<string, int>("Draws", 0));
	};

	//methods
	void setRecord(string str) {
		gameRecords.at(str) += 1;
	};
	int getRecord(string str) {
		return gameRecords.at(str);
	};

	void display() {
		//write data into file
		cout << "\n\n\tRounds played: " << getRecord("Rounds") << "\n";
		cout << "\n\tPlayer Wins: " << getRecord("Player") << "\n";
		cout << "\n\tPlayer Losses: " << (getRecord("Rounds") - getRecord("Draws") - getRecord("Player")) << "\n";
		cout << "\n\tDealer Wins: " << getRecord("Dealer") << "\n";
		cout << "\n\tDealer Losses: " << (getRecord("Rounds") - getRecord("Draws") - getRecord("Dealer")) << "\n";
		cout << "\n\tDraws: " << getRecord("Draws") << "\n";
	};


private:
	map<string, int> gameRecords;
};