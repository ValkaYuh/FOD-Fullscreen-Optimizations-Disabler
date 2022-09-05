
#include <iostream>
#include "FilePathDialog.h"
#include "CreateRegKeyValue.h"

using namespace std;

int main()
{
	bool check = true;
	int count = 0;
	char answer;
	while(check == true) {  //loop until the user answers with N/n
		if(count < 1) {
			cout << "Select an exe file. \n\n";
			CreateR();                     //used just for selecting the first program/game
			count++;
		}
		if (count > 0) {
			cout << "Do you still wish to add files?  y/n: \n\n";
			cin >> answer;
			while (answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N') {
				cout << "Please answer with Y, N or y, n. \n\n";                             //just checking that a valid answer is given
				cin >> answer;
			}
			if (answer == 'y' || answer == 'Y') {
				CreateR();                         //continue adding games/programs if answered with Y/y
				count++;
			}
			else {
				cout << "You have removed Fullscreen Optimization from " << count << " programs/games.\n\n";   //stop adding stuff, give a count of programs/games that have been modified
				check = false;
			}
		}

	}
	
	
}

