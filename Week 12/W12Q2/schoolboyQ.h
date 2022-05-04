//directive to say that this .h file only needs to be included once (default behavior when creating .h in VS)
#pragma once
#include <iostream>
#include <vector>
using namespace std;

//Define class and class name
class Artist {
	//define the following as part of the public space
public:

	//create a constructor
	Artist(string artistName, int artistAge)
		//sets object name to inputted name
		:name{ artistName } {
		
		//validate age is greater than 0, less than 120
		if (age > 0 && age < 120) {
			age = artistAge;
		}
	}
	
	//define public methods (display public vars)
	void Display() {
		cout << "\n\n\tName: " << name << "\n";
		cout << "\n\tAge: " << age << "\n";
	}

	//Setters
	void setBirthplace(string birthLocation) {
		birthPlace = birthLocation;
	}
	void setAlbums(vector<string> inputAlbums) {
		albums = inputAlbums;
	}
	//Getters (const after the () indicates that methods don't modify the object
	string getBirthPlace() const {
		return birthPlace;
	}
	//the first const is required to infer that the vector value won't change
	const vector<string>& getAlbums() const {
		return albums;
	}

private:
	//define private variables
	string name{};
	int age = 35;
	string birthPlace = "unkown";
	vector<string> albums{"unknown"};
};