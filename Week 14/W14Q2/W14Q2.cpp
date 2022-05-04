/*Erik Debye
W14Q2 Wheel of Fortune
*/

#include <iostream>
#include<string>
#include<vector>
using namespace std;

char guesser();
bool matcher(char, vector<char> , vector<char>&, vector<char>&);
void display(vector<char>);

int main()
{
	//vars
	//immutable to compare against
	const vector<char> phrase{ 'l','a','n','d',' ','o','f',' ','l','i','n','c','o','l','n' };
	//mutable to convert
	vector<char> correct{ 'x','x','x','x',' ','x','x',' ','x','x','x','x','x','x','x' };
	//guessed letters
	vector<char> incorrect{};
	//bool to check completely matched
	bool complete{ false };

	cout << "\n\n\t\t\tWheel of Fortune\n\n";

	//when complete = true, end loop
	while (!complete)												
	{
		//display mutable phrase
		display(correct);

		//display guessed nums
		cout << "\tPreviously Guessed Incorrect Letters: ";
		if (incorrect.size() > 0) {
			for (char e : incorrect) {
				cout << " " << e;
			}
		}
		else cout << "None";

		cout << "\n\n";

		//grab a guess
		char guess = guesser();

		//evaluate guess
		bool matched = matcher(guess, phrase, correct, incorrect);
		
		if (correct == phrase) {
			complete = true;
			cout << "\n\tCongrats! You solved it!\n\n";
		}

		cout << "\t";

		for (int k = 0; k < 81; k++) {
			cout << "-";
		}

		cout << "\n\n";
	}

	return 0;
}
void display(vector<char> c)
{
	cout << "\n\t";

	//check index (used for managing print
	int i{ 0 };
	for (char e : c)
	{
		if (i == 0) {
			cout << e;
		}
		else {
			cout << " " << e;
			i++;
		}
	}
	cout << "\n";
}

char guesser()
{
	cout << "\tPlease guess a letter: ";
	char x;
	cin >> x;

	return x;
}

bool matcher(char guess, vector<char> phrase, vector<char>& correct, vector<char>& incorrect)
{
	int i = 0;
	bool match = false;
	for (char e : phrase)
	{
		if (guess == e)
		{
			cout << "\n\tMatch found!";
			match = true;
			correct[i] = guess;
		}
		i++;
	}

	if (!match) {
		cout << "\n\tNo Match Found...";
		incorrect.push_back(guess);
	}

	cout << "\n\n";

	return match;
}