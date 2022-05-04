/*Erik Debye
02.04.2022
Week 10 Question 3
Fstream*/

#include <iostream>
#include <string>
#include <fstream> //Needed for all filestream functions
using namespace std;

int main()
{
    fstream employees("employee.txt", ios::out);;

    if (!employees) {
        cerr << "Error opening file.";
        exit(EXIT_FAILURE);
    }

    //if file exists create a strings
    string fName{ "" };
    string lName{ "" };
    string email{ "" };

    //query for first name
    cout << "\n\n\tPlease enter your first name: ";
    cin >> fName;

    do {
        //query for last name
        cout << "\n\tPlease enter your last name: ";
        cin >> lName;

        //create email
        email = fName + "." + lName + "@company.com";

        //place email into file
        employees << email << "\n";

        //print the email
        cout << "\n\tYour email is: " << email << "\n\n";

        //query user again with quit option
        cout << "\n\tEnter your first name (Ctrl-Z to exit): ";
    } while (cin >> fName);

    //Once exited, close the file
    employees.close();

    //create filebuf object and open the file (using ios::in) - source: pages 619, 621 - 622 C++ How to Program
    fstream data("employee.txt", ios::in);

    string emailData{ "" };

    cout << "\n\n\tEmails On File\n\n";

    //while not at the end of the file
    while (data >> emailData)
    {
        //print variable
        cout << "\t" << emailData << "\n";
    }

    //Once exited, close the file
    data.close();
    
    return 0;
}