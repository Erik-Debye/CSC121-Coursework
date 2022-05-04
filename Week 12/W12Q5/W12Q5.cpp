/*Erik Debye
  13.04.2022
  Week 12 Q4
  Constructors*/

#include <iostream>
#include "W12Q5_header.h"
using namespace std;

int main() {
	//create instance of class using constructor
	Account account01("Erik Debye", 1540);
	Account account02("My Cat Shakira", -1002);


	//display names and initial balances
	cout << "\n\taccount01: " << account01.getName();
	cout << "\n\t  balance: " << account01.getBalance();

	cout << "\n\n";

	cout << "\n\taccount02: " << account02.getName();
	cout << "\n\t  balance: " << account02.getBalance();

	cout << "\n\n";

	//deposit funds
	double deposit;
	cout << "\n\t" << account01.getName() << ", please enter a deposit amount : ";
	cin >> deposit;
	account01.deposit(deposit);
	//deposit acc02
	cout << "\n\t" << account02.getName() << ", please enter a deposit amount : ";
	cin >> deposit;
	account02.deposit(deposit);

	cout << "\n\n";

	//display new balances
	cout << "\n\t  account01: " << account01.getName();
	cout << "\n\tnew balance: " << account01.getBalance();

	cout << "\n\n";

	cout << "\n\t  account02: " << account02.getName();
	cout << "\n\tNew balance: " << account02.getBalance();

	cout << "\n\n";


	//deposit funds
	double withdraw;
	cout << "\n\t" << account01.getName() << ", please enter a withdrawal amount : ";
	cin >> withdraw;
	account01.withdrawal(withdraw);
	//deposit acc02
	cout << "\n\t" << account02.getName() << ", please enter a withdrawal amount : ";
	cin >> withdraw;
	account02.withdrawal(withdraw);


	cout << "\n\n";

	// display new balances
	cout << "\n\t  account01: " << account01.getName();
	cout << "\n\tnew balance: " << account01.getBalance();

	cout << "\n\n";

	cout << "\n\t  account02: " << account02.getName();
	cout << "\n\tNew balance: " << account02.getBalance();

	cout << "\n\n";

	return 0;
}