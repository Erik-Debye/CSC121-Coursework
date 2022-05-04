//directive to say that this .h file only needs to be included once (default behavior when creating .h in VS)
#pragma once
#include <iostream>
using namespace std;

//Define class
class Account {
public:
	//use constructor to reset Balance to 0
	Account(double balanceAmt) {
		//calling set balance method
		setBalance(balanceAmt);
	}

	//methods
	//display info
	void display(void) {
		cout << "\n\n\n\n\tAccount Holder: " << getName();
		cout << "\n\t" << getName() << "'s Account ID Number: " << getID();
		cout << "\n\t" << getName() << "'s Account Balance: $" << getBalance();
		cout << "\n\n";
	}

	//deposit $
	void deposit(double amt) {
		balance += amt;
	}

	//withdraw $
	void withdrawal(double amt) {
		balance -= amt;
	}

	//return name
	string getName() {
		return name;
	}

	//returns ID
	int getID() {
		return id;
	}

	//initializes balance
	void setBalance(double num) {
		balance = num;
	}

	//retrieves balance
	double getBalance(void) {
		return balance;
	}

private:
	//define private variables w/ defaults as needed
	string name{"Erik Debye"};
	int id{ 123 };
	double balance{0.10};
};