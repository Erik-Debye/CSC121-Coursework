/*Erik Debye 20.04.2022 Lab 13
TicTacToe - Classes
New Commands: Constructors & Classes*/

#include "TTT.h"
#include <iostream>
#include <windows.h>
#include <string> //Needed for to_string
#include <vector>
#include <algorithm>
#include <time.h>
#include <fstream> //Needed to read/write files
using namespace std;


//Functions
void theme();                                                                        //Adjusts Output Theme
void outputBoard(vector<string> square);                                             //Displays Game Board
int  playerChoice(vector<int>& remaining);                                           //Grabs Player choice, Validates
int  computerChoice(vector<int>& remaining);		                                 //Grabs Computer Choice (srand & pass-by-ref)
void convertToXO(vector<string>& square, string letter, int value);                  //Converts square vector values to x or o's
bool winCheck(vector<string> square, string letter, string place);                                 //Flag that checks for Wins
void secondPlace(vector<int>& remaining, vector<string>& square);                    //Computer can get second place when player wins
void tieEvent();                                                                     //In the event of a tie, this event triggers
void writeSummaryToFile(int playWins, int computerWins, int ties, int gameCount);    //Writes a summary to a TTTwins.txt file
void readToFile();                                                                   //reads from TTTwins.txt file
string determinePlayer(string letter);                                               //Determines player or computer based on letter entering square. Useful for wincheck and writing plays to file
void writePlaysToFile(string player, string num, vector<string> square);			 //Writes each play to a gamePlays.txt file, takes in the play string
void writeOutComesToFile(string outcome);                                            //Writes each win to a gamePlays.txt file, takes in the winning string   

int main() {
	//initialize class
	TTT Game;
	//Print header
	Game.header();
	//Change theme
	theme();

	//Variable to determine 2+ games
	string anyKey{ "" };

	//Running the game
	cout << "\n\n\tWELCOME TO TIC TAC TOE!\n";

	/*WEEK 10 LAB 10 Vars*/
	int playerWins{ 0 }, computerWins{ 0 }, ties{ 0 }, gameCount{ 0 };

	do {
		//add to gameCount
		gameCount++;

		//write new game to gamesplays.txt
		if (gameCount > 1) {
			writeOutComesToFile("\n\n\n\tPlayer chose to play a new game.");
			writeOutComesToFile("--------------------------------------------");
		}

		//variables that will need resetting when 2+ games played
		vector<string> square{ "1", "2", "3", "4", "5", "6", "7", "8", "9" };			//Data that is displayed (supports X & O)															
		vector<int> remaining{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };                             //Data used for choice validation
		bool playerWin{ false }, compWin{ false };                                      //Flags that mark wins
		int turns = square.size();                                                      //Sets turns to number of elements

		for (int i = 0; i < turns; i++) {
			if (i % 2 == 0) {
				outputBoard(square);
				convertToXO(square, "X", playerChoice(remaining));
			}
			else {
				outputBoard(square);
				convertToXO(square, "O", computerChoice(remaining));
			}

			//check and change win bool flags
			playerWin = winCheck(square, "X", "first");
			compWin = winCheck(square, "O", "first");

			if (playerWin || compWin) {
				break;
			}
		}
		//recording wins and ties
		if (!playerWin && !compWin) {
			tieEvent();
			ties++;
		}
		else if (playerWin && !compWin) {
			playerWins++;
			secondPlace(remaining, square);
		}
		else {
			/*comp win*/
			computerWins++;
		}

		cout << "\n\n\tEnter any key to play again or CRTL + Z to quit: ";
	} while (cin >> anyKey);

	//Writes summary to file
	writeSummaryToFile(playerWins, computerWins, ties, gameCount);

	//Reads file to console
	readToFile();

	//Prints summary PART OF WINDOWS.H LIBRARY source - https://docs.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-shellexecutea 
	ShellExecute(0, 0, L"TTTWins.txt", 0, 0, SW_SHOW);
	ShellExecute(0, 0, L"gamePlays.txt", 0, 0, SW_SHOW);

	return EXIT_SUCCESS;
}


void theme() {
	system("Color B5");
}

void outputBoard(vector<string> square) {
	cout << "\n\t ¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯";
	cout << "\n\t|  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << "  |  ";
	cout << "\n\t ¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯";
	cout << "\n\t|  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << "  |  ";
	cout << "\n\t ¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯";
	cout << "\n\t|  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << "  |  ";
	cout << "\n\t ¯¯¯¯¯ ¯¯¯¯¯ ¯¯¯¯¯\n";
}

int playerChoice(vector<int>& remaining) {
	//variable to save choice and index
	int value{ }, index{ };
	//query choice 
	cout << "\n\n\tPlease select a square by entering its' number: ";
	cin >> value;

	//flag for do while
	bool valid{ false };
	do {
		//Validate choice (test type, range)
		while (cin.fail() || value < 0 || value > 9) {
			//if wrong type
			if (cin.fail()) {
				//clear error flag
				cin.clear();
				//reset input buffer
				cin.ignore(1000, '\n');
			}
			else {
				//re-ask for valid choice
				cout << "\n\tInvalid choice, please try again: ";
				cin >> value;
			}
		}
		//search remaining choices for chosen value
		vector<int>::iterator itr = find(begin(remaining), end(remaining), value);

		if (itr != end(remaining)) {
			index = itr - remaining.begin();
			valid = true;
		}
		else {
			cout << "\n\nPlease select a square by entering its' number: ";
			cin >> value;
		}


	} while (!valid);

	//erase index from remaining data
	remaining.erase(remaining.begin() + index);

	return value;
}

int computerChoice(vector<int>& remaining) {
	//create random number enviroment
	int vectorSize{ }, index{ }, value{ };
	vectorSize = remaining.size();

	//create engine
	srand(static_cast <unsigned int> (time(0)));

	//use engine to find random index
	index = rand() % vectorSize;
	value = remaining[index];
	//erase from future choices
	remaining.erase(remaining.begin() + index);

	cout << "\n\tComputer chose.... ";
	Sleep(1000);
	cout << value << "!\n";

	return value;
}

void convertToXO(vector<string>& square, string letter, int value) {
	//convert to string
	string strValue = to_string(value);
	int squareIndex{};

	//find index of value in square
	vector<string>::iterator itr = find(begin(square), end(square), strValue);
	squareIndex = itr - square.begin();
	//replace with "o" or "x"
	square[squareIndex] = letter;

	//pass play into plays file writer
	writePlaysToFile(letter, strValue, square);
}

bool winCheck(vector<string> square, string letter, string place) {
	//Create var to store player
	string winOutput{"\n\t"};
	//bool flag (to not repeat code per each win scenario)
	bool win{};
	//create outcome string for win
	winOutput += determinePlayer(letter);
	//HORIZONTAL WINS
	if (square[0] == letter && square[1] == letter && square[2] == letter) {
		//add to winOutput
		winOutput += " won " + place + " place on the top row of squares!";
		win = true;
	}
	else if (square[3] == letter && square[4] == letter && square[5] == letter) {
		winOutput += " won " + place + " place on the middle row of squares!";
		win = true;
	}
	else if (square[6] == letter && square[7] == letter && square[8] == letter) {
		winOutput +=" won " + place + " place on the last row of squares!";
		win = true;
	}
	//VERTICAL WINS
	else if (square[0] == letter && square[3] == letter && square[6] == letter) {
		winOutput += " won " + place + " place on the first column of squares!";
		win = true;
	}
	else if (square[1] == letter && square[4] == letter && square[7] == letter) {
		winOutput += " won " + place + " place on the second column of squares!";
		win = true;
	}
	else if (square[2] == letter && square[5] == letter && square[8] == letter) {
		winOutput += " won " + place + " place on the third column of squares!";
		win = true;
	}
	//DIAGONAL WINS 
	else if (square[0] == letter && square[4] == letter && square[8] == letter) {
		winOutput += " won " + place + " place on the decreasing diagonal!";
		win = true;
	}
	else if (square[2] == letter && square[4] == letter && square[6] == letter) {
		winOutput += " won " + place + " place on the increasing diagonal!";
		win = true;
	}
	else {
		win = false;
	}

	if (win) {
		outputBoard(square);
		cout << "\n\t" << winOutput << "\n";
		writeOutComesToFile(winOutput);
		return true;
	}
	else {
		return false;
	}
}

string determinePlayer(string letter) {
	if (letter == "X") {
		return "Player";
	}
	else {
		return "Computer";
	}
}

void secondPlace(vector<int>& remaining, vector<string>& square) {
	//vars
	bool win{ false };

	if (!remaining.empty()) {
		cout << "\n\tComputer trying for second place...\n";
		writeOutComesToFile("\n\n\tComputer trying for second place...\n");
	}

	//checks if vector is empty source - https://en.cppreference.com/w/cpp/container/vector/empty
	while (!remaining.empty()) {

		//make choice
		convertToXO(square, "O", computerChoice(remaining));
		outputBoard(square);

		//check wins
		win = winCheck(square, "O", "second");

		if (win) {
			break;
		}
	}
	if (!win) {
		cout << "\n\tPlayer is the only winner!\n";
		writeOutComesToFile("\n\tPlayer is the only winner!\n");
	}
}

void tieEvent() {
	cout << "\n\n\tGame was a tie!\n\n";
	writeOutComesToFile("\n\n\tGame was a tie!\n\n");
}

void writeSummaryToFile(int playerWins, int computerWins, int ties, int gameCount) {
	//opening file for writing
	fstream writing("TTTWins.txt", ios::out);

	//check if file is open 
	if (!writing) {
		cerr << "\n\tError opening file.";
		exit(EXIT_FAILURE);
	}

	//write data into file
	writing << "Games played: " << gameCount << "\n";
	writing << "Player Wins: " << playerWins << "\n";
	writing << "Player Losses: " << (gameCount - playerWins - ties) << "\n";
	writing << "Computer Wins: " << computerWins << "\n";
	writing << "Computer Losses: " << (gameCount - computerWins - ties) << "\n";
	writing << "Ties: " << ties << "\n";

	//close file
	writing.close();
}

void writePlaysToFile(string player, string num, vector<string> square) {
	//Assign player to the correct title dependant on letter being switched for number in ConvertToXO().
	player = determinePlayer(player);

	//open file to append
	fstream file("gamePlays.txt", ios::app);

	//check if file opened
	if (!file) {
		cerr << "\n\tError opening file";
		exit(EXIT_FAILURE);
	}

	//write play to file
	file << "\n\n\t" << player << " chose " << num << "!\n";
	file << "\n\t\tCurrent State of Squares:";

	//create accum to track index
	int i = 0;
	for (string item : square) {
		//aligns square
		if (i == 3 || i == 6) {
			file << "\n\t\t\t\t       ";
		}
		//prints item
		file << " " << item;
		i++;
	}

	//close file
	file.close();
}

void writeOutComesToFile(string outcome) {
	//open file to append
	fstream file("gamePlays.txt", ios::app);

	//check if file opened
	if (!file) {
		cerr << "\n\tError opening file";
		exit(EXIT_FAILURE);
	}

	file << "\n" << outcome << "\n\n";

	//close file
	file.close();
}

void readToFile() {
	//create empty string (used to store file lines)
	string fileLn{ "" };

	//open file for reading
	fstream fileData("TTTWins.txt", ios::in);
	//check if file opened
	if (!fileData) {
		cerr << "Error opening file.";
		exit(EXIT_FAILURE);
	}
	//print title
	cout << "\n\n\tGames Summary\n\n";
	//print each line in file by line - getline() checks for eof && '\n' - source: https://www.cplusplus.com/reference/string/string/getline/
	while (getline(fileData, fileLn)) {
		cout << "\t" << fileLn << "\n";
	}
}
