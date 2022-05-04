  /*Erik Debye
  02.04.2022
  Week 10 Question 1
  OFstream*/

#include <iostream>
#include <string>
#include <fstream> //Needed for all filestream functions
using namespace std;

int main()
{
    //Use Ofstream constructor to create a filebuf object called names - source:https://www.cplusplus.com/reference/fstream/ofstream/ 
    ofstream names;

    //create a txt file called list_of_names.txt, assign it to the ios::out mode (opening file for output) - source: pages 618 - 619 C++ How To Program
    names.open("list_of_names.txt", ios::out);

    //Test to see if file was created
    if (!names) {
        //If not, output an error sentence. cerr is the fstream's output command
        cerr << "Error opening file.";
        //Used in the book on page 618. Seems to be a way to indicate an error (similar to return 1) - source https://en.cppreference.com/w/c/program/EXIT_status
        exit(EXIT_FAILURE); 
    }

    //if file exists create a string
    string enteredName{ "List of Names" };

    do {
        //place entered name into file
        names << enteredName << "\n";
        //query user again with quit option
        cout << "Enter your name (Ctrl-Z to exit): ";
    } while (cin >> enteredName); 

    //Once exited, close the file
    names.close();

    return 0;
}