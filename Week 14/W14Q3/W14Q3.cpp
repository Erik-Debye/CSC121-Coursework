/*Erik Debye
W14Q3 BlackJack*/

#include "records.h"
#include "round.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	//vars
	string playAgain{ "" };
	string choice{ "" };
	int pValue{}, dValue{};

	//initialize classes
	Records gameRecords;
	Round gameRound;
	
	do {
		gameRecords.setRecord("Rounds");

		cout << "\n\n\t\t\tWELCOME TO BLACKJACK\n\n";

		cout << "\n\tLet's get you some cards!\n";
		cout << "\n\tShuffling...";
		gameRound.createDeck();
		Sleep(1000);
		cout << "\t...";
		Sleep(2000);

		/*Get 2 random cards for Dealer & Player*/
		for (int i = 0; i < 2; i++) {
			gameRound.getCard("Player");
			gameRound.getCard("Dealer");
		}

		/*GAME */
		cout << "\n\n\tDealer's Hand: ";
		gameRound.printHand("Dealer", 0);

		cout << "\n\tPlayer's Hand: ";
		gameRound.printHand("Player");

		bool pDone{ false }, dDone{ false };

		do {
			dValue = gameRound.getDHandValue();

			if (!pDone) {
				choice = gameRound.getChoice();

				if (choice == "hit") {
					gameRound.getCard("Player");
					cout << "\n\tPlayer chose to hit!\n";
					cout << "\n\tLet's grab a card...";
					Sleep(1000);
					cout << "\n\tYour hand now: \n";
					gameRound.printHand("Player");
					Sleep(3000);
				}
				else if (choice == "stand") {
					pDone = true;
				}
			}

			//dealer logic
			cout << "\n\n\tDealer's turn!";

			if (dValue >= 17) {
				cout << "\n\n\tDealer chooses to stand!";
				dDone = true;
			}
			else {
				cout << "\n\n\tDealer chooses to hit!";
				Sleep(2000);
				gameRound.getCard("Dealer");
				gameRound.printHand("Dealer", 0);
			}
			
			Sleep(1000);
		} while (!(pDone && dDone));

		pValue = gameRound.getPHandValue();
		dValue = gameRound.getDHandValue();

		cout << "\n\n\t///////////////////////////////////////////////////////////////////////////////////////////////////////////\n";

		//win conditions
		if (pValue == 21 && dValue != 21) {
			cout << "\n\tPlayer Wins!";
			gameRecords.setRecord("Player");
		}
		else if (dValue == 21 && pValue != 21) {
			cout << "\n\tDealer Wins!";
			gameRecords.setRecord("Dealer");
		}
		else if (pValue > 21 and dValue > 21 || pValue == 21 && dValue == 21) {
			cout << "\n\tGame was a draw!";
			gameRecords.setRecord("Draws");
		}
		else if (pValue > 21 && dValue < 21) {
			cout << "\n\tDealer Wins!";
			gameRecords.setRecord("Dealer");
		}
		else if (pValue < 21 && dValue > 21) {
			cout << "\n\tPlayer Wins!";
			gameRecords.setRecord("Player");
		}
		else if (pValue < 21 && dValue < 21 && pValue == dValue) {
			cout << "\n\tGame was a draw!";
			gameRecords.setRecord("Draws");
		}
		else if (pValue < 21 && dValue < 21 && pValue < dValue) {
			cout << "\n\tDealer Wins!";
			gameRecords.setRecord("Dealer");
		}
		else {
			cout << "\n\tPlayer Wins!";
			gameRecords.setRecord("Player");
		}

		cout << "\n\n\tPlayer Hand Value: " << pValue << "\n";
		gameRound.printHand("Player");
		cout << "\n\t--------------------------------------------------------------------------------------------------------------\n";
		cout << "\n\n\tDealer Hand Value: " << dValue << "\n";
		gameRound.printHand("Dealer");

		//reset class object --source: https://stackoverflow.com/questions/2664031/shortest-and-best-way-to-reinitialize-clean-a-class-instance
		gameRound = Round();
		//reset choice
		choice = { "" };

		cout << "\n\tEnter any key to play again or enter CRTL+Z to quit:";
	} while (cin >> playAgain);

	gameRecords.display();

	exit(EXIT_SUCCESS);
}