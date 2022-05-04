/*Erik Debye
  13.04.2022
  Week 12 Q4
  Constructors*/

#include <iostream>
#include<Windows.h>
#include "artist.h"
using namespace std;

int main() {
	//create instance of class using the contructor too add a name and age.
	Artist hiphop("SchoolboyQ", 35);

	//call public method to display all object info
	hiphop.display();

	//set birthplace
	hiphop.setBirthplace("Wiesbaden, West Germany");
	//create albums vector
	vector<string> schoolboyAlbums{ "Setbacks", "Habits and Contradictions", "Oxymoron", "Blank Face LP", "Crash Talk" };
	//set albums
	hiphop.setAlbums(schoolboyAlbums);

	cout << "\n\tSetting birthplace and discography...\n";
	Sleep(1500);
	cout << "\n\tCompleted.\n\n";
	Sleep(1500);

	//redisplay info
	hiphop.display();
	return 0;
}