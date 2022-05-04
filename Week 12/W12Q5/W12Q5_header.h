//directive to say that this .h file only needs to be included once (default behavior when creating .h in VS)
#pragma once
#include <iostream>
using namespace std;

//Define class
class Account {
public:
	//create constructor
	Account(string accName, double intitialBalance)
		//sets object name to inputted name
		:name{ accName } {

		//validate initialbalance is greater than 0 (valid)
		if (intitialBalance > 0 ) {
			balance = intitialBalance;
		}
	}

	//Method to deposit more $
	void deposit(double deposited) {
		//ensure deposited money is > 0 
		if (deposited > 0) {
			//if so, add to balance
			balance += deposited;
		}
		else {
			cout << "\n\tError: Deposit amount under minimum.\n";
		}
	}

	//Method to withdrawal $
	void withdrawal(double withdrawn) {
		//ensure withdraw amount is > 0
		if (withdrawn > 0) {
			balance -= withdrawn;
		}
		else {
			cout << "\n\tError: Withdrawal amount under minimum.\n";
		}
	}

	//method to get balance -- getter()
	double getBalance() const {
		return balance;
	}

	//Set name of account -- setter()
	void setname(string nameInput) {
		name = nameInput;
	}

	//method to get name -- getter()
	string getName() const {
		return name;
	}

private:
	//define private variables w/ defaults as needed
	string name{};
	double balance = 0;
};