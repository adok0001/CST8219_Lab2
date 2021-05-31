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
		int numPlayers;
		double timeout;

	public:
		Game(int nPlayers, double duration) {
			numPlayers = nPlayers;
			timeout = duration;
			cout << "In constructor with 2 parameters" << endl;
		}
		Game(int nPlayers) {
			timeout = NO_TIMEOUT;
			cout << "In constructor with 1 parameter, nPlayers= " << endl;
		}
		Game() {
			numPlayers = 1;
			timeout = NO_TIMEOUT;
			cout << "In constructor with 0 parameters" << endl;
		}
		~Game() {
			cout << "In destructor" << endl;
		}
	};
}



