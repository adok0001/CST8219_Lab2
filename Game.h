/**
* Name: Adokeme Tamara
* Student Number: 040873188
**/

#pragma once
#include <iostream>
using namespace std;
const double NO_TIMEOUT(-1);


namespace CST8219 {
	class Game {
	private:
		//Class private properties declaration
		string name;
		int numPlayers;
		double timeout = NO_TIMEOUT;

	public:
		//Class constructors declaration
		Game(string gName, int nPlayers, double duration) {
			this->name = gName;
			this->numPlayers = nPlayers;
			this->timeout = duration;
			//cout << "In constructor with 3 parameters" << endl;
		}
		Game(string gName, int nPlayers) {
			this->name = gName;
			this->numPlayers = nPlayers;
			this->timeout = NO_TIMEOUT;
			//cout << "In constructor with 2 parameters, nPlayers= " << nPlayers << " Name - " << gName << endl;
		}
		Game(string gName) {
			this->name = gName;
			//Game(gName, 1);
			//cout << "In constructor with 1 parameter. Name: " << gName << " | nPlayers: " << numPlayers << " | Timeout: " << timeout << endl;
		}
		//default
		Game() {
			this->name = "[Noname]";
			this->timeout = NO_TIMEOUT;
			this->numPlayers = 1;
			//cout << "In constructor with 0 parameters. Name: " << name << " | nPlayers: " << numPlayers << " | Timeout: " << timeout << endl;
		}

		/*~Game() {
			cout << "In destructor" << endl;
		}*/
		void printGame();
		void createOneGame();
		

	};
}

