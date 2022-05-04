/*Erik Debye
  13.04.2022
  Week 12 Q4
  Constructors*/

#include <iostream>
#include "artist.h"
using namespace std;

int main() {
	//create instance of class using the contructor too add a name and age.
	Artist hiphop ("SchoolboyQ", 35);
	//call public method
	hiphop.Display();

	//display using getters
	cout << "\n\n\tBirthplace: " << hiphop.getBirthPlace() << "\n";
	cout << "\n\tAlbums: ";
	for (string album : hiphop.getAlbums()) {
		cout << album << " ";
	}
	cout << "\n\n";

	//set birthplace
	cout << "\n\tSetting birthplace as Weisbaden, West Germany....";
	hiphop.setBirthplace("Wiesbaden, West Germany");
	cout << "\n\n\t\tCompleted.";
	//create albums vector
	vector<string> schoolboyAlbums{ "Setbacks", "Habits and Contradictions", "Oxymoron", "Blank Face LP", "Crash Talk" };
	//set albums
	cout << "\n\n\tPassing discography to artist profile....";
	hiphop.setAlbums(schoolboyAlbums);
	cout << "\n\n\t\tCompleted.";

	//display using getters
	cout << "\n\n\tBirthplace: " << hiphop.getBirthPlace() << "\n";
	cout << "\n\tAlbums: ";
	for (string album : hiphop.getAlbums()) {
		cout << album << ", ";
	}
	cout << "\n\n";

	return 0;	
}