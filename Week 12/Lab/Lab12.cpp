/*Erik Debye
  21.04.2022
  Week 12 Lab
  Constructors*/

#include <iostream>
#include "Lab12.h"
using namespace std;

//functions
//alerts user to possible options
void options(void); 

int main() {
	//local vars
	double amt{};
	int accID{};
	int choice{};
	enum choices{BALANCE, DEPOSIT, WITHDRAWAL };

	//create instance, set balance to 0
	Account myAcc{0};
	
	//obtain account login
	cout << "\n\n\tHi " << myAcc.getName() << ", please enter your account number to login : ";
	cin >> accID;

	//do-while to allow for mutliple log-in attempts
	do {
		//if id is correct, display success message and account info
		if (accID = myAcc.getID()) {
			cout << "\n\n\t\t\tLOGIN SUCCESSFUL";
			myAcc.display();

			//display user choices and save choice
			options();
			cout << "\n\n\n\tPlease enter a choice: ";
			cin >> choice;

			//do-while that allows multiple deposit/withdrawal/balance changes
			do {
				//using enums for switch
				switch(choice) {
				case BALANCE: {
					cout << "\n\n\tEnter the new balance: ";
					cin >> amt;
					//reset balance
					myAcc.setBalance(amt);
					break;
				}
				case DEPOSIT: {
					cout << "\n\n\tEnter the deposit amount: ";
					cin >> amt;
					//deposit
					myAcc.deposit(amt);
					break;
				}
				case WITHDRAWAL: {
					cout << "\n\n\tEnter the withdrawal amount: ";
					cin >> amt;
					//withdraw
					myAcc.withdrawal(amt);
					break;
				}
				//if choice isn't a possible option
				default: cout << "\n\n\t\t\tError in processing choice.";
				}

				//end for each option, display success, acc info, options, and quit option
				cout << "\n\n\tTransaction Successful!";
				myAcc.display();
				options();
				cout << "\n\n\tPlease make another choice or press 4 to quit: ";
				cin >> choice;

			} while (choice != 4);

		}
		//if ID is wrong
		else {
			cout << "Wrong ID number, please try again or press CTRL + Z to quit: ";
		};

		//reset for new login with quit option
		cout << "\n\n\tHi " << myAcc.getName() << ", please enter your account ID number to login or CTRL + Z to quit: ";

	} while (cin >> accID);

	cout << "\n\n";

	return 0;
}

void options(void) {
	cout << "\n\n\t\t\tChoice Options";
	cout << "\n\n\t\tPress 0 to reset balance";
	cout << "\n\n\t\tPress 1 to deposit money";
	cout << "\n\n\t\tPress 2 to withdraw money";
}