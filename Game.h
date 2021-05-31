/**
* Name: Adokeme Tamara
* Student Number: 040873188
**/

#include <iostream>
using namespace std;
const double NO_TIMEOUT(-1);

namespace CST8219 {
	class Game {
	private:
		string name;
		int numPlayers;
		double timeout;

	public:
		Game(string name, int nPlayers, double duration) {
			this->name = name;
			numPlayers = nPlayers;
			timeout = duration;
		}
		Game(string name, int nPlayers) {
			this->name = name;
			numPlayers = nPlayers;
			timeout = NO_TIMEOUT;
		}
		Game(string name):Game(name, 1) {
			timeout = NO_TIMEOUT;
		}
		Game():Game("[NoName]") {}

		void printGame() {
			cout << "Name: " << name << " - Numplayers: " << numPlayers << " - Timeout: " << timeout << endl;
		}
	};
}



