/*Erik Debye
W13Q1 Member Functions
New Commands: .bad(), .good(), .rdstate()*/

#include <iostream>
using namespace std;

int main() {
	int integerValue{};

	cout << "\n\tBefore a bad input operation:"
		<< "\n\tcin.rdstate():" << cin.rdstate()
		<< "\n\tcin.eof():" << cin.eof()
		<< "\n\tcin.fail():" << cin.fail()
		<< "\n\tcin.bad():" << cin.bad()
		<< "\n\tcin.good():" << cin.good()
		<< "\n\n\tExpects an integer, but enter a character: ";
	cin >> integerValue;
	cout << "\n\tAfter a bad input operation:"
		<< "\n\tcin.rdstate():" << cin.rdstate()
		<< "\n\tcin.eof():" << cin.eof()
		<< "\n\tcin.fail():" << cin.fail()
		<< "\n\tcin.bad():" << cin.bad()
		<< "\n\tcin.good():" << cin.good();
	cin.clear();
	cout << "\n\n\tAfter cin.clear()" << "\n\tcin.fail():" << cin.fail()
		<< "\n\tcin.good():" << cin.good() << endl;
	return 0;
}