

#include <iostream>
using namespace std;

void a(int);
int b(void);
void c(void);

int x = 1; 											//Global x

int main()
{
	int x = 5;										// Local x has jurisdiction
	cout << "x = " << x;
	x *= 3;

	{
		int x = 7;									// start a new scope within main( )
		cout << "\nx = " << b();
	}

	a(10);
	x = b();
	c();					// Add second set of function calls

	a(8);
	x = b();
	c();

	cout << "\nlocal x in main() = " << x;
	return 0;
}
void a(int x) {
	// local x takes jurisdiction
	cout << "\n\tx = " << x;
	x *= 5;
	cout << "\n\tx = " << x;
}
int b(void) {
	static int v = 3;							// Static is NOT destroyed when leaving  ==> global ability to remember ==> only run the first time
	cout << "\n\t\tv = " << v;
	v *= 4;
	cout << "\n\t\tv = " << v;
	return v;
}
void c(void) {
	int x = 5;	// no local declarations for x – global will “fill in”
	cout << "\n\t\t\tx = " << x;
	x *= 7;
	cout << "\n\t\t\tx = " << x;
}