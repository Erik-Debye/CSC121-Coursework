#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <time.h>

/*Needed on Windows to print unicode control Characters --source: http://cplusplus.com/forum/general/251203/ */
#include <string>
#include <io.h>
#include <fcntl.h>

/*Define names to UNI-16 codes*/
#define SPADE L"\u2660";
#define CLUB L"\u2663";
#define HEART L"\u2665";
#define DIAMOND L"\u2666";

using namespace std;

class Round {
public:

	void printHand(string str, int i = 1) {
		//player will always see hand, no need for i
		if (str == "Player") {
			for (auto& pair : playerHand) {
				cout << "\n\t ------ ";
				cout << "\n\t|";  printSuit(pair.first); cout << "     ";
				cout << "\n\t|  " << pair.second << "  ";
				cout << "\n\t|     ";  printSuit(pair.first); cout <<  "";
				cout << "\n\t ------ \n";
			};
			//if dealer
		}
		else {
			//check if i is 0 (indicating first card)
			if (i == 0) {
				cout << "\n\t ------ ";
				cout << "\n\t|"; printSuit(dealerHand.begin()->first); cout << "     ";
				cout << "\n\t|  " << dealerHand.begin()->second << "  ";
				cout << "\n\t|     "; printSuit(dealerHand.begin()->first); cout <<  "";
				cout << "\n\t ------ \n";

				//loop for ? cards (indicating existence but not revealing nums
				//needs to skip first hash...
				for (auto& pair : dealerHand) {
					if (pair == dealerHand[0]) {
						continue;
					}
					else {
						cout << "\n\t ----- ";
						cout << "\n\t|?    |";
						cout << "\n\t|  ?  |";
						cout << "\n\t|    ?|";
						cout << "\n\t ----- \n";
					};
				};
			}
			else {
				//if i is default, then no need to hide other cards
				for (auto& pair : dealerHand) {
					cout << "\n\t ------ ";
					cout << "\n\t|"; printSuit(pair.first); cout << "   ";
					cout << "\n\t|  " << pair.second << "  ";
					cout << "\n\t|   "; printSuit(pair.first); cout << " ";
					cout << "\n\t ----- \n";
				};
			};
		};
	};

	void printSuit(int suit) {
		//set text to U16 char mode
		_setmode(_fileno(stdout), _O_U16TEXT);
		//switch case
		switch (suit) {
			//using enum defns
			//need to use wcout because unicode16 are 'wider' chars that ANSI 8bit chars --source: https://stackoverflow.com/questions/32338496/what-is-the-difference-between-stdcout-and-stdwcout
		case Spade:
			wcout << SPADE;
			break;
		case Club:
			wcout << CLUB;
			break;
		case Heart:
			wcout << HEART;
			break;
		case Diamond:
			wcout << DIAMOND;
			break;
		default:
			cout << "\n\terror in fetching suit from printSuite()";
			exit(EXIT_FAILURE);
		}
		//reset char set to ANSI 8bit set
		_setmode(_fileno(stdout), _O_TEXT);
	};

	void getCard(string str) {

		//create srand engine and pick random num from deck 
		srand(static_cast <unsigned int> (time(0)));
		int randomCard = rand() % deck.size();
		
		int cardSuit = deck[randomCard].first;
		string cardRank = deck[randomCard].second;


		int cardValue{};
		if (cardRank == "A") {
			cardValue = 1;
		} else if(cardRank == "J" || cardRank == "Q" || cardRank == "K") {
			cardValue = 10;
		}
		else {
			cardValue = stoi(cardRank);
		}
		
		if (str == "Player") {
			playerHand.push_back(pair<int, string>(cardSuit, cardRank));
			pValue += cardValue;
		}
		else {
			dealerHand.push_back(pair<int, string>(cardSuit, cardRank));
			dValue += cardValue;
		};

		deck.erase(deck.begin() + randomCard);
		
	};

	string getChoice(void) {
		enum options { stand = 1, hit = 2 };
		cout << "\n\tPlease enter a 1 to stand, or 2 to hit: ";
		int i;
		cin >> i;

		//bool flag
		bool chosen{ false };

		switch (i) {
		case stand:
			chosen = true;
			return "stand";

		case hit:
			chosen = true;
			return "hit";
		default:
			cout << "\n\tInvalid option chosen. Please chose again.";
			return "invalid";
		};
	};

	void createDeck(void) {
		for (int i = 1; i < 5; i++) {
			deck.push_back(make_pair(i, "A"));
			deck.push_back(make_pair(i, "2"));
			deck.push_back(make_pair(i, "3"));
			deck.push_back(make_pair(i, "4"));
			deck.push_back(make_pair(i, "5"));
			deck.push_back(make_pair(i, "6"));
			deck.push_back(make_pair(i, "7"));
			deck.push_back(make_pair(i, "8"));
			deck.push_back(make_pair(i, "9"));
			deck.push_back(make_pair(i, "10"));
			deck.push_back(make_pair(i, "J"));
			deck.push_back(make_pair(i, "Q"));
			deck.push_back(make_pair(i, "K"));
		}
	};

	int getPHandValue() {
		return pValue;
	};

	int getDHandValue() {
		return dValue;
	};

private:
	enum suitRef { Spade = 1, Club = 2, Heart = 3, Diamond = 4 };

	//deck
	vector<pair<int, string>> deck;

	//playercards
	vector<pair<int, string>> playerHand;
	//player hand value
	int pValue{0};
	//Dealercards
	vector<pair<int, string>> dealerHand;
	//dealer hand value
	int dValue{0};

};