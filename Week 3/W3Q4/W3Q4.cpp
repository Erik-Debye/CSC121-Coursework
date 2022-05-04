/*
Erik Debye || 02.02.2022
Week 3 -- Problem 4
Conditional Operations
New commands: if/else & c-ops
*/

#include <iostream>
#include <iomanip>
#include <array> 
using namespace std;

// Functions
//Displays our data
void displayArr(string arr[5]);
//Asks user to pick num and returns pick
string findChoice(void);
//error message
void errorMess(void);

int main() {
	//Create inital data
	string nums[5] = { "1", "2", "3", "4", "5"};
	int numsSize = sizeof nums / sizeof nums[0]; //This finds the number of elements in an array (size of array / size of each element)
												

	//Create loop to call function 5 times
	for (int i{ 0 }; i <= numsSize; ++i) {

		//Check Data to see if numbers exist still
		if (nums[0] == "X" && nums[1] == "X" && nums[2] == "X" && nums[3] == "X" && nums[4] == "X") {
			displayArr(nums);
			cout << setw(57) << endl << "All data has been converted. Program terminated." << endl;
			break;
		}
		else {

			//display data
			displayArr(nums);

			//ask & save choice 
			string userChoice = findChoice();

			//Check if choice = x
			if (userChoice == "X" || userChoice == "x") {
				cout << setw(42) << "X is not a number... pick again. " << endl;
				--i;
			}
			//Check if choice = each index....
			else if (userChoice == nums[0]) {
				nums[0] = "X";
			}
			else if (userChoice == nums[1]) {
				nums[1] = "X";
			}
			else if (userChoice == nums[2]) {
				nums[2] = "X";
			}
			else if (userChoice == nums[3]) {
				nums[3] = "X";
			}
			else if (userChoice == nums[4]) {
				nums[4] = "X";
			}
			//if no match, than print error
			else {
				--i;
				errorMess();
			}
		}
	}
	return 0;
}

void displayArr(string arr[5]) {
	cout << endl;
	
	cout << setw(25) << "Data: " << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << endl;
}

string findChoice(void) {
	//Create variable 
	string choice{};

	cout << endl;
	//Query
	cout << setw(48) << "Please choose a number from the list : ";
	//Save choice
	cin >> choice; 
	cout << setw(51) << "--------------------------------------------" << endl;
	//Return
	return choice;
}

void errorMess(void) {
	cout << setw(44) << endl << "Please enter an available option..." << endl;
}
